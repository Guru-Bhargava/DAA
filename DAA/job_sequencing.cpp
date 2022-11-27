#include<bits/stdc++.h>
using namespace std;

struct job{
    char id;
    int dead;
    int profit;
};

bool comp(job a,job b)
{
    return(a.profit>b.profit);
}

pair<int,int>jobscheduling(job arr[],int n)
{
    sort(arr,arr+n,comp);
    int maxi=arr[0].dead;
    for(int i=1;i<n;++i)
    {
        maxi=max(maxi,arr[i].dead);
    }
    int slot[maxi+1];
    for(int i=0;i<maxi+1;++i)
    {
        slot[i]=-1;
    }
    int cntjobs=0,totprofit=0;
    for(int i=0;i<n;++i)
    {
        for(int j=arr[i].dead;j>=0;++j)
        {
            if(slot[j]==-1)
            {
                slot[j]=i;
                cntjobs++;
                totprofit+=arr[i].profit;
                break;
            }
        }
    }
    return {cntjobs,totprofit};
}

int main()
{
    job arr[] = { { 'a', 2, 100 },{ 'b', 1, 19 },{ 'c', 2, 27 },{ 'd', 1, 25 },{ 'e', 3, 15 } };
    auto it=jobscheduling(arr,5);
    cout<<it.first<<" "<<it.second;
}