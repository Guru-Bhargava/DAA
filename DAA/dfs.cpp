#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;

vector<int> g[N];
bool vis[N];

void dfs(int vertex)
{
    vis[vertex]=1;
    for(auto child:g[vertex])
    {
        if(vis[child]) continue;
        cout<<child<<" ";
        dfs(child);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
}