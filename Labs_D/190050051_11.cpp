#include <bits/stdc++.h>


#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define fori(i,n) for(ll i=0;i<n;i++)
#define pb push_back
#define ll long long int
#define mod 1000000007
#define pi pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define item ll
using namespace std;
int sz = 0;
void add_edge(vector<int> adj[], 
              int src, int dest) 
{ 
    adj[src].push_back(dest); 
    adj[dest].push_back(src); 
} 
  
// Function which finds all the paths 
// and stores it in paths array 
void find_paths(vector<int> &midpoints, 
		vector<int>& path, 
                vector<int> parent[], 
                int n, int u) 
{ 
    // Base Case 
    if (u == -1) { 
        int l = path.size();
        if(l!=0)
        {
          midpoints.pb(path[l/2]/2);
          sz = l/2;
        } 
        return; 
    } 
  
    // Loop for all the parents 
    // of the given vertex 
    for (int par : parent[u]) { 
  
        // Insert the current 
        // vertex in path 
        path.push_back(u); 
  
        // Recursive call for its parent 
        find_paths(midpoints, path, parent, 
                   n, par); 
  
        // Remove the current vertex 
        path.pop_back(); 
    } 
} 
  
// Function which performs bfs 
// from the given souce vertex 
void bfs(vector<int> adj[], 
         vector<int> parent[], 
         int n, int start) 
{ 
    // dist will contain shortest distance 
    // from start to every other vertex 
    vector<int> dist(n, INT_MAX); 
  
    queue<int> q; 
  
    // Insert source vertex in queue and make 
    // its parent -1 and distance 0 
    q.push(start); 
    parent[start] = { -1 }; 
    dist[start] = 0; 
  
    // Untill Queue is empty 
    while (!q.empty()) { 
        int u = q.front(); 
        q.pop(); 
        for (int v : adj[u]) { 
            if (dist[v] > dist[u] + 1) { 
  
                // A shorter distance is found 
                // So erase all the previous parents 
                // and insert new parent u in parent[v] 
                dist[v] = dist[u] + 1; 
                q.push(v); 
                parent[v].clear(); 
                parent[v].push_back(u); 
            } 
            else if (dist[v] == dist[u] + 1) { 
  
                // Another candidate parent for 
                // shortes path found 
                parent[v].push_back(u); 
            } 
        } 
    } 
} 
  
// Function which prints all the paths 
// from start to end 
void print_paths(vector<int> adj[], 
                 int n, int start, int end) 
{ 
    vector<int> mids;
    vector<int> path; 
    vector<int> parent[n]; 
  
    // Function call to bfs 
    bfs(adj, parent, n, start); 
  
    // Function call to find_paths 
    find_paths(mids, path, parent, n, end); 
    if(sz==0)
    {
      cout << "impossible\n";
    }
    else
    {
      cout << "possible\n";
      cout << sz << "\n";
      sort(mids.begin(),mids.end());
      for(auto &x:mids)
      {
        cout << x << " ";
      }
      cout << "\n";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,u,v;
    cin >> n >> m >> u >> v;
    vector<int> adj[2*n];
    fori(i,m)
    {
      int a,b;
      cin >> a >> b;
      adj[2*a].pb(2*b+1);
      adj[2*b+1].pb(2*a);
      adj[2*a+1].pb(2*b);
      adj[2*b].pb(2*a+1);
    }
    print_paths(adj,2*n,2*u,2*v);
}
