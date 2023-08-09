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

int main()
{
    int n,m;
    cin>>n>>m;
    //bool ans;
    //cin>>ans;

     bool ans = true; // considering as an undirected graph

    int arr[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=0;


    int u,v;
    for(int i=0;i<m;i++)
    {
       cin>>u>>v;
       if(ans==true)
            arr[u][v]=arr[v][u]=1;
       else
            arr[u][v]=1;
    }

      for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<arr[i][j]<<"   ";
            cout<<endl;
        }
}
