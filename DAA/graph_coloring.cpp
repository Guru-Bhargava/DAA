#include<bits/stdc++.h>
using namespace std;

bool issafe(int node,vector<int>&color,bool graph[101][101],int n,int col)
{
    for(int i=0;i<n;++i)
    {
        if(i!=node and graph[i][node]==1 and color[i]==col) return 0;
    }
    return 1;
}

bool solve(int node,vector<int>&color,int m,int n,bool graph[101][101])
{
    if(node==n) return 1;
    for(int i=1;i<=m;++i)
    {
        if(issafe(node,color,graph,n,i))
        {
            color[node]=i;
            if(solve(node+1,color,m,n,graph)) return 1;
            else color[node]=0;
        }
    }
    return 0;
}

int main()
{
    bool graph[101][101];
    int n=4;//total nodes
    int m=3;//total avail colors
    int e=5;//total edges
    for(int i=0;i<101;++i)
    {
        for(int j=0;j<101;++j)
        {
            graph[i][j]=0;
        }
    }
    for(int i=0;i<e;++i)
    {
        int a,b;
        cin>>a>>b;
        graph[a-1][b-1]=1;
        graph[b-1][a-1]=1;
    }
    vector<int>color(n,0);
    if(solve(0,color,m,n,graph)) cout<<"True"<<endl;
    else cout<<"False"<<endl;

}