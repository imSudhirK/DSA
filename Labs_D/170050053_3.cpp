#include<iostream>
#include<algorithm>

using namespace std;


int countRank(int arr[], int n, int MAX){
	int counter=0, tempC=0;

	for(int i=1; i<n; i++){
		
		int newArray[n-1];
		for(int j=0; j<n-1; j++){
			newArray[j]=arr[j+1];
		}

		int tempMAX = MAX;
		while (tempMAX+1 !=0){
			tempC + countRank(newArray, n-1, max(MAX, *max_element (arr, arr+i)));
			tempMAX -= 1;
		} 
	}
	return counter +tempC;
}


int main(){
	int n ;
	long long int t;
	cin>>n>>t;

	char code[t];
	int pattern[t][n];


	for(int i=0; i<t; i++){
		cin>>code[i];

		if(code[i] == 'U'){
			cin>>pattern[i][0];
		}
		else if(code[i]== 'R'){
			for(int j=0; j<n; j++){
				cin>>pattern[i][j];
			}
			cout<<countRank(pattern[i], n, 0);
		}
	}

}
