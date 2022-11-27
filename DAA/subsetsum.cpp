#include<bits/stdc++.h>
using namespace std;

bool f(int ind,int target,vector<int>&v,vector<vector<int>>&dp)
{
    if(target==0) return 1;
    if(ind==0) return(v[0]==target);
    if(dp[ind][target]!=-1) return dp[ind][target];
    bool nottake=f(ind-1,target,v,dp);
    bool take=false;
    if(v[ind]<=target)
    {
        take=f(ind-1,target-v[ind],v,dp);
    }
    return(dp[ind][target]=(take|nottake));
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;++i)
    {
        cin>>v[i];
    }
    int target;
    cin>>target;
    vector<vector<int>>dp(n,vector<int>(target+1,-1));
    cout<<f(n-1,target,v,dp);
}