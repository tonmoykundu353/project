#include<bits/stdc++.h>
using namespace std;

/*
4 5
0 0
0 1
1 2
2 3
3 0
*/
vector<int> adj[50];
int visited[50];

void create(int m)
{
        for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

}
   vector<int> bfs_graph(int s)
    {
        queue<int> q;
        q.push(s);
        visited[s]=1;
        vector<int> bfs;
        while(!q.empty())
        {
            int node = q.front();
            bfs.push_back(node);
            q.pop();
            for(auto it : adj[node])
            {
                if(!visited[it])
                {
                    q.push(it);
                    visited[it]=1;
                }
            }
        }
        return bfs;
    }

void print(vector<int> bfs)
{
    for(auto it : bfs)
        cout<<it<<" ";
    cout<<endl;
}
int main()
{
    for(int i=0;i<50;i++)
        visited[i]=0;

    int n,m;
    cin>>n>>m;

    create(m);
    int start;
    cin>>start;

    vector<int> bfs=bfs_graph(start);
    print(bfs);

}
