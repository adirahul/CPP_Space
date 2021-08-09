#include <bits/stdc++.h>
#define ll long long
#define all(a) (a).begin(), (a).end()
const int M= 1e9+7;
using namespace std;

int main(){
  string s;
  cin>>s;
  s =" "+s;
  int n=s.length();
  string t=" chokudai";
  int dp[n+1][9];  //no of combntn of j chars chosen out of first i chars of s to become equal to first j chars of t
  dp[0][0]=1;
  for(int i=1;i<=n;++i) dp[i][0] =1;
  for(int j=1;j<=8;j++) dp[0][j] =0;

  for(int i=1;i<=n;++i){
    for(int j=1;j<=8;++j){
        if(s[i]==t[j]){
          dp[i][j] =dp[i-1][j-1] +dp[i-1][j];
          dp[i][j] %=M;
        }

        else{
           dp[i][j] =dp[i-1][j];
           dp[i][j] %=M;
           }
    }
    
  }
  cout<<dp[n][8];
}
