#include<iostream>
#include<cmath>
#include<stack>


using namespace std;


void printStack(stack<int> &st){
	stack<int>st1 (st);
	while(!st1.empty()){
		cout<<st1.top()<<" ";
		st1.pop();
	}
	cout<<endl;
	return ;
}

void reverseStack(stack<int> &st){
	stack<int> st1;
	while(!st.empty()){
		st1.push(st.top());
		st.pop();
	}
	st = st1;
	return;
}

void printArray(long long int arr[], int n){
	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";

	cout<<"\n";
	return;
}

void printPowerSet(stack<int> powerSet[], int n){
	int p = pow(2, n);
	for(int i=0; i<p; i++){
		printStack(powerSet[i]);
	}
}


void S(int arr[], int n){
	for(int i=0; i<n; i++)
		arr[i] =i;
	return ;
}

void Set_2s(stack<int> powerSet[], int arr[], int n){
	if(n ==0){
		powerSet[0].push(-1);     // Assume -1  as   {} == phi
		return ;
	}

	int p = pow(2, n-1);
	stack<int>powerSet1[p] ;
	Set_2s(powerSet1, arr, n-1);

	for(int i=0; i<p; i++){
		powerSet[i] = powerSet1[i];

		powerSet1[i].push(n);
		powerSet[i+p] = powerSet1[i];
	}
	
	return;	
}


int FA_X(stack<int> powerSet[], stack<int> powerSetX[],  int x){
	stack<int> powerSet1;
	powerSet1 = powerSet[x];
	reverseStack(powerSet1);

	int siz = powerSet1.size();
	int temp_arr[siz];
	for(int i=0; i<siz; i++){
		temp_arr[i] = powerSet1.top();
		powerSet1.pop();
	}

	Set_2s(powerSetX, temp_arr, siz);

	int counter =0;

	int i=0, j=0, k=0;

	while(i <=x){
		if(powerSet[i] ==powerSetX[j]){
			i++;
			j++;
			counter +=1;
		}
		else
			i++;
	}
	return counter;
}

void part1(long long int ans[], int n){
	int p = pow(2, n);

	int S_arr[n];
	S(S_arr, n);

	stack<int> powerSet[p];
	Set_2s(powerSet, S_arr, n);

	

	for(int i=0; i<p; i++){

		stack<int> powerSetX[i];
		Set_2s(powerSetX, S_arr, i);

		ans[i] = FA_X(powerSet, powerSetX, i);
	}	
}


int main(){
	int n ;
	cin>>n;

	//int S_arr[n];
	//S(S_arr, n);
	//printArray(S_arr, n);

	int p = pow(2, n);

	//stack<int> powerSet[p];
	//Set_2s(powerSet, S_arr, n);
	//printPowerSet(powerSet, n);
	//printStack(powerSet[2]);

	long long int input1_A[p];
	for(int i=0; i<p; i++)
		cin>>input1_A[i];

	bool intput2_B[p];
	for(int i=0; i<p; i++)
		cin>>intput2_B[i];

	part1(input1_A , n);
	printArray(input1_A , p);

}