#include<iostream>
#include<queue>

#include<algorithm>
#include<vector>
#include<iterator>

using namespace std;


//helper function part1
long long int ithSo(int arr[], long long int n, long long int i){
	long long int lcount =0, rcount=0;

	if(i==0){
		for(long long int j=i+1; j<n; j++){
			if(arr[j]>=arr[i]) break;
			else if(arr[j]<arr[i])
				rcount++;
		}
	}
	else if(i==n-1){
		for(long long int j=i-1; j>=0; j--){
			if(arr[j]>=arr[i]) break;
			else if(arr[j]<arr[i])
				lcount++;
		}
	}
	else{
		for(long long int j=i-1; j>=0; j--){
			if(arr[j]>=arr[i]) break;
			else if(arr[j]<arr[i])
				lcount++;
		}
		for(long long int j=i+1; j<n; j++){
			if(arr[j]>=arr[i]) break;
			else if(arr[j]<arr[i])
				rcount++;
		}
	}

	long long int ans = lcount+ rcount+lcount*rcount + 1;
	return ans;	
}



//helper function part2
long long int wfs_ith(int arr[], long long int n, long long int i){
	long long int supAns =0;

	if(i==n-1){
		supAns += 1;	
	}
	else{
		long long int tempC =0;
		int currMax = arr[i];
		for(long long int j=i; j<n; j++){
			if(arr[j] < currMax) break;
			else{
				currMax = arr[j];
				tempC++;
			}
		}
		supAns +=tempC;		
	}
	return supAns;	
}



int main(){
	long long int n;
	cin>>n;

	int  flat[n];
	for(int i=0; i<n; i++){
		cin>>flat[i];

	}


	//Printing  part1 solutions 
	for(long long int i=0; i<n; i++){
		cout<<ithSo(flat, n, i)<<" ";
	}


	cout<<'\n';


	//part2

	long long int ans=0;
	for(long long int i=0; i<n; i++){
		ans +=wfs_ith(flat,n,i);
	}
	cout<<ans;


	
}