#include<iostream>

using namespace std;




int findKth(int A[], int B[], int m, int n, int k){
	if(k==1) return min(A[0], B[0]);
	else{
		int midA = k/2 -1;
		int midB = k-2-midA;

		if(A[midA] > B[midB]){
			int Br[n-1-midB], Al[midA+1];
			for(int i=0; i<midA+1; i++){
				Al[i]= A[i];
			}
			for(int i=0; i<(n-1-midB); i++){
				Br[i]= B[midB+1+i];
			}
			return findKth(Al, Br, midA+1, n-1-midB, k-1-midB);			
		}
		else if(A[midA] < B[midB]){
			int Bl[midB+1], Ar[m-1-midA];
			for(int i=0; i<(m-1-midA); i++){
				Ar[i]= A[midA+1+i];
			}
			for(int i=0; i<midB+1; i++){
				Bl[i]= B[i];
			}
			return findKth(Ar, Bl, m-1-midA, midB+1, k-1-midA);
		}
		else if (A[midA] == B[midB]){
			return A[midA];
		}
	}
}





int main(){
	int m,n,k;
	cin>>m>>n>>k;
	int A[m], B[n];

	for(int i=0; i<m; i++){
		cin>>A[i];
	}
	for(int i=0; i<n; i++){
		cin>>B[i];
	}

	cout<<findKth(A, B, m, n, k);
}