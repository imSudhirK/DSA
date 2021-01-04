#include<iostream>
#include<tuple>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;


struct compare{
	bool operator()(tuple<long int, long int, int>const &t1,
		tuple<long int, long int, int>const &t2) const{
		// comparison for elements of type T
		return get<0>(t1) < get<0>(t2);
	}
};

struct compare2{
	bool operator()(tuple<long int, long int, int>const &t1,
		tuple<long int, long int, int>const &t2) const{
		// comparison for elements of type T
		return get<1>(t1) > get<1>(t2);
	}
};


void PQ(vector< tuple<long int, long int, int> > &v1,
	vector< tuple<long int, long int, int> > &v2){

	int n = v1.size();
	queue<int>p, q;
	vector< tuple<long int, long int, int> > A,C;

	bool unique = true;
	for(int i=0; i<n-1; i++){
		if(((get<0>(v1[i])==get<0>(v1[i+1])) && (get<1>(v1[i])==get<1>(v1[i+1])))
			||((get<0>(v2[i])==get<0>(v2[i+1])) && (get<1>(v2[i])==get<1>(v2[i+1])))){
			unique = false;
			break;
		}
	}

	while( !A.empty() || !C.empty() || !v1.empty() ||  !v2.empty()){

		if(A.empty()){
			A.push_back(v1.front());
			v1.erase(v1.begin());
			while(!v1.empty()){
				if(get<0>(A[0])==get<0>(v1[0])){
					A.push_back(v1.front());
					v1.erase(v1.begin());
				}
				else
					break;			
			}
		}
		if(C.empty()){
			C.push_back(v2.front());
			v2.erase(v2.begin());
			while(!v2.empty()){
				if(get<0>(C[0])==get<0>(v2[0])){
					C.push_back(v2.front());
					v2.erase(v2.begin());
				}
				else
					break;			
			}
			sort(C.begin(), C.end(), compare2());
		}

		if(A.size() <= C.size()){
			while(!A.empty()){
				bool check = false;
				for(int i=0; i<C.size(); i++){
					if(get<1>(C[i]) <= get<1>(A[0])){
						p.push(get<2>(A[0]));
						q.push(get<2>(C[i]));
						A.erase(A.begin());
						C.erase(C.begin()+i);
						check = true;
						break;
					}
					else
						continue;
				}
				if(!check){
					return;
				}
			}
		}
		else if(A.size() > C.size()){

			vector< tuple<long int, long int, int> > C1;
			C1.push_back(v2.front());
			v2.erase(v2.begin());
			while(!v2.empty()){
				if(get<0>(C1[0])==get<0>(v2[0])){
					C1.push_back(v2.front());
					v2.erase(v2.begin());
				}
				else
					break;			
			}
			sort(C1.begin(), C1.end(), compare2());
	
			while(!C1.empty()){
				C.push_back(C1.front());
				C1.erase(C1.begin());
			}
		}
	}


	if(p.size() < n){
		cout<<"impossible";
	}
	else{
		while(!p.empty()){
			cout<<p.front()+1<<" ";
			p.pop();
		}
		cout<<endl;
		while(!q.empty()){
			cout<<q.front()+1<<" ";
			q.pop();
		}
		cout<<endl;
		if(unique){
			cout<<"unique"<<endl;

		}
		else if(!unique){
			cout<<"not unique"<<endl;
		}
	}
}



int main(){
	int n;
	cin>>n;
	long int ai[n], bi[n], ci[n], di[n];

	for(int i=0; i<n; i++){
		cin>>ai[i];
	}
	for(int i=0; i<n; i++){
		cin>>bi[i];
	}
	for(int i=0; i<n; i++){
		cin>>ci[i];
	}
	for(int i=0; i<n; i++){
		cin>>di[i];
	}


	vector< tuple<long int, long int, int> > S1, S2;
	for(int i=0; i<n; i++){
		S1.push_back(make_tuple(ai[i], bi[i], i));
		S2.push_back(make_tuple(ci[i], di[i], i));		
	}

	/*for(int i=0; i<n; i++){
		cout <<get<0>(S1[i]) <<" "<<get<1>(S1[i])<<" "<<get<2>(S1[i])<<endl;
	}
	cout<<endl;*/

	sort(S1.begin(), S1.end(), compare());
	sort(S2.begin(), S2.end(), compare());

	/*for(int i=0; i<n; i++){
		cout <<get<0>(S1[i]) <<" "<<get<1>(S1[i])<<" "<<get<2>(S1[i])<<endl;
	}
	cout<<endl;
	*/

	vector< tuple<long int, long int, int> > s1 = S1, s2=S2;

	/*for(int i=0; i<n; i++){
		cout <<get<0>(s1[i]) <<" "<<get<1>(s1[i])<<" "<<get<2>(s1[i])<<endl;
	}
	cout<<endl;
	*/

	//answer for part1
	PQ(s1, s2);	
} 
