#include<iostream>
#include<cstdlib>

using namespace std;


/*
int J(int n, int k) {
	circular_list C;
	C.initialize(n);
	while (C.size() > 1) {
		for (int i = 1; i < k; i++) C++;
		C.remove();
		}
	return C.value();
}

*/

struct circular_list {
	long long int val;
	struct circular_list  *nxt;
};

circular_list *newCircular_list (long long int value){
	circular_list *temp = new circular_list;
	temp -> nxt = temp;
	temp -> val = value;
};

long long int J(long long int n, long long int k){
	circular_list *C = newCircular_list(1);
	circular_list *prevC = C;
	for (long long int i = 2; i <= n; i++){ 
    	prevC->nxt = newCircular_list(i); 
    	prevC = prevC->nxt; 
    } 
    prevC->nxt = C;

    circular_list *ptr1 = C, *ptr2 = C; 
    while (ptr1->nxt != ptr1) 
    { 
        int count = 1; 
        while (count != k) 
        { 
            ptr2 = ptr1; 
            ptr1 = ptr1->nxt; 
            count++; 
        } 
  
        ptr2->nxt = ptr1->nxt; 
        free(ptr1); 
        ptr1 = ptr2->nxt; 
    } 
  
    return ptr1->val;

}


int main(){
	long long int n , k;
	cin>>n>>k;
	cout<<J(n,k)<<endl;
}