#include<iostream>
#include<queue>

using namespace std;

void merge(queue<int>&q1, queue<int>&q2, queue<int>&ans){
	if(q2.empty()){
		while(!q1.empty()){
			ans.push(q1.front());
			q1.pop();
		}
		return;
	}
	else if(q1.empty()){
		while(!q2.empty()){
			ans.push(q2.front());
			q2.pop();
		}
		return;
	}
	else{
		if(q1.front()<= q2.front()){
			ans.push(q1.front());
			q1.pop();
			merge(q1, q2, ans);			
		}
		else if(q1.front()> q2.front()){
			ans.push(q2.front());
			q2.pop();
			merge(q1,q2,ans);
		}
		return;
	}
}




int main(){
	int k, n;
	cin>>k>>n;


	queue<int>Q[k];

	int x;
	for(int i=0; i<k; i++){
		for(int j=0; j<n; j++){
			cin>>x;
			Q[i].push(x);
		}
	}
	
	queue<int>ansx;	
	for(int i=0; i<k; i++){
		queue<int>temp;
		temp = ansx;
		queue<int>temp2;
		ansx = temp2;
		merge(Q[i],temp, ansx);
	}
	while(!ansx.empty()){
		cout<<ansx.front()<<" ";
		ansx.pop();
	}		
}