/*
  Given two sequence of integers, A and B, find any one longest common subsequence.
*/

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    int s[n], t[m];
    for(int i=0; i<n; i++)  cin>>s[i];
    for(int i=0; i<m; i++)  cin>>t[i];
    int dp[m+1][n+1];
    for(int i=0; i<=m; i++) {
        for(int j=0; j<=n; j++) {
            if(i==0 || j==0)    dp[i][j]=0;
            else {
                if(t[i-1]==s[j-1])  dp[i][j]=dp[i-1][j-1]+1;
                else    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int len=dp[m][n];
    int lcs[len];
    int i=m, j=n, k=len-1;
    while(i>0 && j>0) {
        if(t[i-1]==s[j-1]) {
            lcs[k--]=t[i-1];
            i--;    j--;
        } else {
            if(dp[i-1][j]>dp[i][j-1])   i--;
            else    j--;
        }
    }
    for(i=0; i<len; i++)   cout << lcs[i] << " ";
    return 0;
}
