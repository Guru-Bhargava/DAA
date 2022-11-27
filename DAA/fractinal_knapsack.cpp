#include<bits/stdc++.h>
using namespace std;


void knapsack( vector<pair<int,int>>&vp,int w,int n)
{
    vector<pair<int,int>>ans;
    for(int i=0;i<n;++i)
    {
        double a=vp[i].first;
        double b=vp[i].second;
        double c=a/b;
        ans.push_back({c,i});
    }
    sort(ans.rbegin(),ans.rend());
    int curwt=0;
    double finalans=0;
    vector<pair<int,int>>temp;
    for(auto it:ans)
    {
        int a=it.second;
        int b=vp[a].first;
        int c=vp[a].second;
        temp.push_back({b,c});
    }
    for(int i=0;i<n;++i)
    {
        if(curwt+temp[i].second<=w)
        {
            curwt+=temp[i].second;
            finalans+=temp[i].first;
        }
        else
        {
            double wt_per_piece=temp[i].first/temp[i].second;
            int rem_wt=w-curwt;
            double i_can_take=(rem_wt)*(wt_per_piece);
            finalans+=i_can_take;
            break;
        }
    }
    cout<<finalans<<endl;
}

int main()
{
    vector<pair<int,int>>vp;
    vp.push_back({60,10});
    vp.push_back({100,20});
    vp.push_back({120,30});
    int w=50;
    int n=3;
    knapsack(vp, w,n);
}