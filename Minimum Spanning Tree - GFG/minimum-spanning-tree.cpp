// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        vector<bool> vis(V,false);
        vis[0]=true;
        for(auto neigh:adj[0]){
            if(!vis[neigh[0]]) pq.push({neigh[1],neigh[0]});
        }
        int cost=0, edgeCount=0;
        while(!pq.empty() && edgeCount!=V-1){
            auto edge=pq.top();
            pq.pop();
            if(vis[edge.second]) continue;
            vis[edge.second]=true;
            edgeCount++;
            cost+= edge.first;
            for(auto neigh:adj[edge.second]){
                if(!vis[neigh[0]]) pq.push({neigh[1],neigh[0]});
            }
        }
        return cost;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends