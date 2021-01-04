#include <iostream>
#include<string>
#include<cmath>

using namespace std;


int main(){
	long int n, m;
	cin>>n>>m;

	long int N= pow(2, n);

	long int hash[N] = {0};
	
	for(long int mi=0; mi<m; mi++){
		
		long int count1 =0;
		
		string str;
		cin>>str; 

		string::iterator it; 
    	for (it=str.begin(); it!=str.end(); it++){
    		if(*it == '1')
    			count1 +=1;
    	} 
		hash[count1] +=1;
	}
	
	long int couter =0;
	for(long int ni=0; ni<N; ni++){
		if(hash[ni] ==0)
			continue;
		else
			couter +=1;
	}

	//part1
	cout<<couter<<"\n";
}