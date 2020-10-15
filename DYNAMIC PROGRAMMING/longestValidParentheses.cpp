#include<bits/stdc++.h>
using namespace std;

// function returns size of the longest substring with valid parentheses
int longestValidParentheses(string s,int n) 
{
    int i;
    if(!n)
        return 0;
    vector<int> valid(n+1,0);
    stack<int> a;
    int ans=0;
    for(i=0;i<n;i++)
    {
        if(s[i]=='(')
            a.push(i);
        else if(!a.empty())
        {
            valid[i+1]=valid[a.top()]+2+valid[i];
            a.pop();
            ans=max(ans,valid[i+1]);
        }
    }
    return ans;
}

int main()
{
    int n; // n= size of string
    cin>>n;
    string s; // string 's' only contains '(' or ')' types of brackets
    cin>>s;
    cout<<longestValidParentheses(s,n);
    return 0;
}