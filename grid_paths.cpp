/*number of paths from the upper-left square to the lower-right square in n*n grid, can only move right or down.. */

#include <bits/stdc++.h>
using namespace std;
const int m = 1e9+7;


int main() {
  int n;
  cin >> n;

  vector<vector<int>> dp(n, vector<int> (n,0));
  
  // state      :     dp[i][j] -> no of ways of getting pos (i,j)
  // base case  :     dp[0][0] =1 , we have 1 way to reach (0,0)  and in case of obstacles ,0
  // transion   :     from (i,j) we can go to (i,j+1)  or (i+1,j)
  dp[0][0] =1;
  for(int i=0;i<n;i++){
    string row; cin>>row;
    for(int j=0; j<n;j++){

      if(row[j] =='.'){
        if(i>0){
          (dp[i][j] += dp[i-1][j]) %=m;
        }
        if(j>0){
          (dp[i][j] += dp[i][j-1]) %=m;
        }
      }

      else {
        dp[i][j]=0; }
    }
  }
  cout << dp[n-1][n-1] << endl;
}