#include<iostream>
#include<queue>


using namespace std;

bool findOn(int A[], int n){
	bool b=false;
	for(int i=0; i<n; i++){
		if(A[i] == i+1){
			b = true;
			break;
		}
		else
			continue;
	}
	return b;
}

bool findln(int A[], int n){
	bool b= false;
	if(n<1) return false;
	else if(n==A[0]==1) return true;
	else{
		int l =n/2;
		if(A[l-1] == l) return true;
		else if(A[l-1] > l){
			int Al[l-1];
			for(int i=0; i<l-1; i++){
				Al[i] = A[i];
			}
			b = findln(Al, l-1);
		}
		else if(A[l-1] < l){
			int Ar[n-l];
			for(int i=0; i<n-l; i++){
				Ar[i]=A[l+i];
			}
			b = findln(Ar, n-l);
		}
	}
	return b;
}


int main(){
	int n;
	cin>>n;
	int A[n];
	for(int i=0; i<n; i++){
		cin>>A[i];
	}

	cout<<findOn(A, n)<<'\n';
	cout<<findln(A, n);
}