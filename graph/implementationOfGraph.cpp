#include <iostream>
using namespace std;
#include <vector>
#include <queue>

vector<int> performBFS(int v, vector<int> adj[]) // THIS CODE IS FOR BREATH FIRST SEARCH IN A GRAPH
{
    // 1ST WE HAVE CREATE AN ARRAY OF BOOL TYPE CAUSE WE HAVE TO TRACK A RECORD THAT IS ANY NODE IS VISITED OR NOT
    bool isVisted[v];
    for (int i; i < v; i++)
        isVisted[i] = false;

    vector<int> bfsresult; // THIS STORE THE VALUES OF GRAPH WHICH ARE VISITED IN BFS SEQUENCE
    queue<int> q;
    isVisted[0] = 1;
    q.push(0);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfsresult.push_back(node);
        for (auto i : adj[node])
        {
            if (!isVisted[i])
            {
                isVisted[i] = true;
                q.push(i);
            }
        }
    }

    return bfsresult;
}
int main()
{
    int n; // NUMBER OF NODE OR VERTICES
    int m; // NUMBER OS EDGES

    cin >> n >> m;

    vector<int> adj[n]; // O-BASED INDEXING
    for (int i = 0; i < m; i++)
    {
        int u, v; // DIRECTION IS u TO v (u ---> v) FOR DIRECTED GRAPH
        cin >> u >> v;
        // THIS IS FOR UNDIRECTED GRAPH
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> bfs=performBFS(n,adj);
    for(int i:bfs)
    cout<<i<<" ";
}