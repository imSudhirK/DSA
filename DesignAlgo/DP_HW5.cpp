#include<iostream>
#include<climits>
#include<cmath>
#include <time.h>

using namespace std;
int M, E, OTC;
float S, OTPrice, C, W, Hcost, Fcost;
float stored, empNo;

// function to minimize cost
float mincost(int D[], int i, float tD, int maxE, int stored, int empNo) {
    // parameters demand, month number, total demand, max employees, stored from previous month, employees after previous month
    float minC = INT_MAX; //cost for the month i for optimumalgorithm
	int st1, emp1; // stored and employee number at the end of month i
    // base case
    if(i==M)
    {
        float tcost = 0; //making employees E at end and removing cost for stored carpets
        if ((E-empNo)>0)
    	    tcost += Hcost*(E-empNo);
    	else
    	    tcost += Fcost*(empNo-E);
    	tcost -= W*stored;
        return tcost;
    }
    else
    {
        for(int j=0; j<maxE; j++)
    	{
    		for(int k=0; k<j*OTC; k++)
    		{
    		    float localC; //cost for month i
    			if(j*C+k>tD)
    				continue;
    			else
    			{
    				int a = 0;
    				int stored1 = stored+j*C+k-D[i];
    				if (stored1<0)
    				    continue;
    				if ((j-empNo)>0)
    					localC = j*S + Hcost*(j-empNo) + k*OTPrice + W*(stored1);
    				else
    					localC = j*S - Fcost*(j-empNo) + k*OTPrice + W*(stored1);
    				float nextval = mincost(D, i+1, tD, maxE, stored1, j);
    				if (localC+nextval<minC)
    				{
    				    minC = localC+nextval;
    					emp1 = j;
    					st1 = stored1;
    				}
    			}
    		}
    	}
    	empNo = emp1;
    	stored = st1;
    	return minC; //cost for month i....M-1
    }

}

int main(){
    clock_t tStart = clock();
	// carpet demands for respective month
	int D[M+1];

	// taking required inputs
	cin>>M;
	for(int i=0; i<M; i++){
		cin>>D[i];
	}
	cin>>E>>Hcost>>Fcost;
	cin>>S>>C;
	cin>>OTC>>OTPrice;
	cin>>W;
    
	// summing over all demands
	int tD = 0;
	for(int i=0; i<M; i++)
	{
		tD += D[i];
	}

	// max number of employees possible
	int maxE = ceil(tD/C);
    float totcost = mincost(D, 0, tD, maxE, 0, E);
    // the total cost is calculated by calling the function to calculate the minimum cost starting at the 1st month
    // the function then takes the minimum of the sum of costs at the month and the subsequent months to find the optimumalgorithm
    // the table is of size (M * OTC * sum(D)^2)/(C^2)
    // the time is O((M*OTC*sum(D)^2)/(C^2))
    cout<<totcost<<" "<<(double)(clock() - tStart)/CLOCKS_PER_SEC<<endl;

}
