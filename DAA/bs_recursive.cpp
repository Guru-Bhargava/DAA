#include<bits/stdc++.h>
using namespace std;

int rec(vector<int>&v,int low,int high,int ele)
{
    if(high>=low)
    {
        int mid=(low+high)/2;
        if(v[mid]==ele) return mid;
        else if(v[mid]>ele) return rec(v,low,mid-1,ele);
        return rec(v,mid+1,high,ele);
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;++i) cin>>v[i];
    int k;
    cin>>k;
    cout<<rec(v,0,n,k);
}