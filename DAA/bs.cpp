#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;++i)
    {
        cin>>v[i];
    }
    int item,f=1;
    cin>>item;
    int l=0,r=n-1,mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(v[mid]==item) 
        {
            f=0;
            break;
        }
        else if (v[mid]>item)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    if(f) cout<<"Not Found"<<endl;
    else cout<<"Found"<<endl;
}