#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

/*Number of distinct ORDERED ways you can produce a money sum x using the available coins.*/
int main() {
  int n, target;
  cin >> n >> target;
  vector<int> x(n);
  for (int &v : x) cin >> v;

  vector<vector<int>> dp(n+1, vector<int> (target+1,0));
  
  // state      :     dp[i][x] -> no of ways of getting sum x using first i coins
  // base case  :     dp[i][0] =0 , we have empty set with sum zero
  // transion   :     from i-1 th coin we can go to ith coin to either pick the coin or leave it
  for(int i=0;i<n;i++){
    dp[i][0]=1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= target; j++) {
      dp[i][j] = dp[i-1][j];                //if ith coin isn't added in sum

      int left = j-x[i-1];                  // ith coin has value x[i-1]
      if (left >= 0) {
	        (dp[i][j] += dp[i][left]) %= mod;
      }
    }
  }
  cout << dp[n][target] << endl;
}