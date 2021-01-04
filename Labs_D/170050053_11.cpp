#include<iostream> 
#include <list> 

using namespace std; 

class G{
public:
	int N;
	list<int> *adj; 
 
	G(int v){
		this->N = v; 
		adj = new list<int>[N]; 
	}

	void addEdge(int v, int w){
		adj[v].push_back(w);
	} 

	bool  isConnected(int u, int v){
		bool *visited = new bool[N], anC =false; 
		for(int i = 0; i < N; i++) 
			visited[i] = false; 

		list<int> q; 
 
		visited[u] = true; 
		q.push_back(u); 

		list<int>::iterator i; 

		while(!q.empty()){  
			int s = q.front(); 
			if( s == v){
				anC = true;
				break;
			}
			q.pop_front(); 
 
			for (i = adj[s].begin(); i != adj[s].end(); ++i){ 
				if (!visited[*i]){ 
					visited[*i] = true; 
					q.push_back(*i); 
				} 
			} 
		}
		return anC; 
	}

	bool  part1(int a[], int n, int u, int v){
		bool oddC = false;
		if(!isConnected(u,v)){
			return false;
		}
		
		else if(isConnected(u, v)){
			a[u] +=1;
			if(u==v){
				oddC = true ;
				return true;
			}
			else{
				bool *v1 = new bool[N];
				for(int i = 0; i < N; i++) 
					v1[i] = false;

				list<int> q1; 
 
				v1[u] = true; 
				q1.push_back(u); 

				list<int>::iterator j; 

				while(!q1.empty()){  
					int s = q1.front(); 
					q1.pop_front(); 
 
					for (j = adj[s].begin(); j != adj[s].end(); ++j){
						if(isConnected(*j, v)){
							if (v1[*j]){
								int o = a[s] - a[*j];
								if(o%2 == 0){
									oddC = true;
									return true;
								}
							}
							else if (!v1[*j]){
								a[*j] = a[s] +1; 
								v1[*j] = true; 
								q1.push_back(*j);
								oddC = !part1(a, n, *j, v);
								if(oddC)
									return true; 
							} 
						}
						else
							continue;	
					}
				}
			}	
		}
		return oddC;
	}
}; 
 

int main(){
	int n, m, u, v;
	cin>>n>>m>>u>>v;

	G g(n);
	int x,y;
	for(int i=0; i<m; i++){
		cin>>x>>y;
		g.addEdge(x, y);
	} 

	int a[n] = { 0 };

	if(!g.part1(a, n, u, v))
		cout<<"impossible";
	else if(g.part1(a, n, u, v))
		cout<<"possible";

	return 0; 
} 
