#include<bits/stdc++.h>
using namespace std;

bool issafe(int row,int col,vector<string>&board,int n)
{
    int duprow=row;
    int dupcol=col;
    while(row>=0 and col>=0)
    {
        if(board[row][col]=='Q') return false;
        row--;
        col--;
    }

    col=dupcol;
    row=duprow;
    while(col>=0)
    {
        if(board[row][col]=='Q') return false;
        col--;
    }
    col=dupcol;
    row=duprow;
    while(row<n and col>=0)
    {
        if(board[row][col]=='Q') return false;
        row++;
        col--;
    }
    return true;
}

void solve(int col,vector<string>&board,vector<vector<string>>&ans,int n)
{
    if(col==n)
    {
        ans.push_back(board);
        return;
    }
    for(int row=0;row<n;++row)
    {
        if(issafe(row,col,board,n))
        {
            board[row][col]='Q';
            solve(col+1,board,ans,n);
            board[row][col]='.';//I Basically backtrack the things again
        }
    }
}

int main()
{
    int n;
    cin>>n;
    vector<vector<string>>ans;
    vector<string>board(n);
    string s(n,'.');
    for(int i=0;i<n;++i)
    {
        board[i]=s;
    }
    solve(0,board,ans,n);
    for(int i=0;i<ans.size();++i)
    {
        for(int j=0;j<ans[0].size();++j)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}