#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cout<<"number of nodes and number of edges : "<<endl;
    cin>>n>>m;
    int arr[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
    {
        cout<<i<<"->"<<j<<" : ";
        cin>>arr[i][j];
        cout<<endl;
    }

      for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<arr[i][j]<<"   ";
            cout<<endl;
        }


}
