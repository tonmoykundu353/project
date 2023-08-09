
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

void print(vector<int> dfs)
{
    for(auto it : dfs)
        cout<<it<<" ";
    cout<<endl;
}

 void  dfs(int node, vector<int> &dfs_list)
 {
     visited[node]=1;
     dfs_list.push_back(node);

     for(auto it : adj[node])
     {
         if(!visited[it])
            dfs(it,dfs_list);
     }

 }


vector<int> dfs_graph(int node)
{
    vector<int> dfs_list;
    dfs(node,dfs_list);
    return dfs_list;
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

   vector<int> dfs= dfs_graph(start);
    print(dfs);

}
