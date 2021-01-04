#include <iostream>
using namespace std ;


int main(){
	unsigned int n , k;
	cin>>n>>k;
	unsigned int inpArray[n], finalArray[n];

	for (unsigned int i =0 ; i < k; i++){
		unsigned int x;
		cin>>x;
		inpArray[i] = x;
		finalArray[i] = x; 
	}

	for(unsigned int i =0 ; i<k; i++){
		unsigned int remainder, quotient;
		remainder = inpArray[i]%k;
		quotient  = inpArray[i]/k;

		finalArray[i] = finalArray[i] - inpArray[i];

		if(quotient >= 1){
			for(unsigned int j =0 ; j < k; j++)
				finalArray[j] = finalArray[j] + quotient;
		}

		if (remainder >= k-i){
			for(unsigned int j =i+1 ; j <k; j++)
				finalArray[j] = finalArray[j] + 1;
			for(unsigned int j =0 ; j <= (remainder -k + i); j++)
				finalArray[j] = finalArray[j] + 1; 
		}

		if (remainder < k-i){
			for(unsigned int j =1 ; j <= remainder; j++)
				finalArray[j+ i] = finalArray[j+ i] + 1;
		}
		for(unsigned int j =0 ; j<k; j++){
			cout<<finalArray[j]<<" ";
		}
		cout<<"\n";
	}
}
