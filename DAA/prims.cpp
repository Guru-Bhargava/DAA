#include<bits/stdc++.h>
#include <climits>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>adj[n];
    int a,b,wt;
    for(int i=0;i<a;++i)
    {
        cin>>a>>b>>wt;
        adj[a].push_back({b,wt});
        adj[b].push_back({a,wt});
    }
    int parent[n];
    int key[n];
    bool mstset[n];
    for(int i=0;i<n;++i)
    {
        parent[i]=-1;
        mstset[i]=false;
        key[i]=INT_MAX;
    }
    key[0]=0;
    for(int count=0;count<n-1;count++)
    {
        int mini=INT_MAX;
        int u;
        for(int v=0;v<n;++v)
        {
            if(mstset[v]==false and key[v]<mini)
            {
                mini=key[v];
                u=v;
            }//store minimal key value which is not part of mstset
        }
        mstset[u]=true;
        for(auto it:adj[u])
        {
            int v=it.first;
            int wt=it.second;
            if(mstset[v]==false and wt<key[v])
            {
                parent[v]=u;
                key[v]=wt;
            }
        }
    }
    for(int i=1;i<n;++i)
    {
        cout<<parent[i]<<"-"<<i<<endl;
    }
}