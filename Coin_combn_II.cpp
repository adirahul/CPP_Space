#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

class solution{
	public:
   
	int coin_change( vector<int> coin, int target )
	{
 		 vector<ll> dp(target + 1, mod);  //minimum coins needed to get produce sum 'target'
 		 dp[0] = 0;  			  //0 way of getting sum = 0
		
 		 for(int i = 1; i <= target; ++i)
  			  for(int x : coin)
    				  if(i - x >= 0)
      				     dp[i] = min( dp[i], dp[i - x] + 1);
  
 		 return (dp[target] == mod ? -1 : dp[target]);
	}
};

int main() {
			/*Number of distinct ORDERED ways you can produce a money sum x using the available coins.*/
  int n, target;
  cin >> n >> target;
  vector<int> x(n);
  for (int &v : x) cin >> v;

  vector<vector<int>> dp(n+1, vector<int> (target+1,0));
  
 /*State        :     dp[i][x] -> no of ways of getting sum x using first i coins
   Base case    :     dp[i][0] =0 , we have empty set with sum zero
   Transition   :     consider the ith coin,Either we didn't pick the coin, then there are dp[i-1][x] ways, otherwise,
                       we picked the coin. Since we are allowed to pick it again, there are dp[i][x — value(ith coin)] (not dp[i-1][x —value(ith coin)]) ways*/
 
 for(int i=0;i<n;i++){
    dp[i][0]=1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= target; j++) {
      dp[i][j] = dp[i-1][j];                

      int left = j-x[i-1];                  // ith coin has value x[i-1]
      if (left >= 0) {
	        (dp[i][j] += dp[i][left]) %= mod;
      }
    }
  }
  cout << dp[n][target] << endl;
}
