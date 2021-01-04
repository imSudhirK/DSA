#include<iostream>
#include<string>
#include<sstream>
#include<queue>
#include<stack>

using namespace std;

/*struct expT{
	char c;
	struct expT* l;
	struct expT* r;

	expT(char e1){
		c = e1;
		l = NULL;
		r = NULL;	
	}
};*/


//helper fucntions
bool isChar(char x){ 
	return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'); 
} 
string p2iOrder(string exp){ 
	stack<string> st; 

	for (int i=0; exp[i]!='\0'; i++){

      	if (isChar(exp[i])){ 
      		string st0(1, exp[i]); 
      		st.push(st0); 
      	}
      	else{ 
         	string st1 = st.top(); 
         	st.pop(); 
         	string st2 = st.top(); 
         	st.pop(); 
         	st.push(st2 + exp[i] + st1 ); 
      } 
   }
   return st.top(); 
}


//part 1 functions
int p1step(stack<char>&sk){

	bool prestar=false, isplus = false;
	int counter =0;

	while(!sk.empty()){
		if(sk.top() == '*' && !prestar){
			counter++;
			prestar = true;
		}
		else if(sk.top() == '+'){
			isplus = true;
			prestar = false;
		}
		sk.pop();
	}
	if(isplus)
		return counter+1;
	else
		return counter;
}


int p1Time(queue<char>&q){
	queue<char> q1 = q;

	bool star=false, plus= false;
	while(!q1.empty()){
		if(q1.front() == '*'){
			star = true;
		}
		else if(q1.front() == '+'){
			plus = true;
		}
		q1.pop();
	}
	if(star && plus)
		return 2;
	else if(star || plus)
		return 1;
	else
		return 0;
}

//part2 fucntions
long long int p2step(stack<char>&sk, int k){

	stack<char>skstar, skplus;
	skstar = sk; skplus = sk;

	bool prestar=false;
	long long int rmstar =0;

	long long int kcs =0;
	while(!skstar.empty()){
		
		if(skstar.top() == '*' && prestar){
			kcs++;
		}
		else if(skstar.top() == '*' && !prestar){
			kcs=1;
			prestar = true;
		}
		else if(skstar.top() == '+'){
			prestar = false;
			long long int d=0,r=0;
			while(kcs > k){
				d = kcs/k,  r= kcs%k;
				rmstar+= d;
				kcs = d+ r;
			}
			if(r>0){
				rmstar +=1;
			}
		}
		skstar.pop();
	}

	long long int rmplus =0;
	long long int kcp =0;
	while(!skplus.empty()){
		if(skplus.top() == '+'){
			kcp++;
		}	
		skplus.pop();
	}
	long long int d1=0,r1=0;
	while(kcp > k){
			d1 = kcp/k,  r1= kcp%k;
			rmplus+= d1;
			kcp = d1+ r1;
		}
	if(r1>0){
		rmplus +=1;
	}
	return rmstar + rmplus;	
}




int main(){
	string str;
	cin>>str;

	long long int  t;
	cin>>t;
	long long int arr[t];
	for(long long int i=0; i<t; i++){
		cin>>arr[i];
	}


	//time1
	queue<char> strQ;
	stringstream ss(str);
	char temp;
	while (ss >> temp)
    	strQ.push(temp);


    //steps1
   	string iostr= p2iOrder(str);

   	stack<char> sk;
	stringstream ss1(iostr);
	char temp1;
	while (ss1 >> temp1)
    	sk.push(temp1);

    stack<char> sk1 = sk;
    //Part 1 
    cout<<p1step(sk)<<" "<<p1Time(strQ)<<"\n";

    //Part 2
    cout<<p2step(sk1, arr[1]-1);



}