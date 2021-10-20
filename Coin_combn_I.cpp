const int mod = 1e9+7;

/*Number of distinct ways you can produce a money sum x using the available coins.*/
class solution {
  public:
  long long solve(vector<int> coins, int n, int target) 
  {
 
  vector<int> dp(target + 1, 0);  //no of ways to produce sum 'target'
 
  dp[0] = 1;    //we initialize dp[0] = 1, saying the empty set is the only way to make 0

  for(int i = 1; i <= target; ++i)
      for(int x: coins)                // can swap order of loops to get no of ordered ways to produce sum target
          if(i - x >= 0)
            {
              dp[i] += dp[i - x];
              dp[i] = dp[i] % mod;
            }
     
   
   return dp[target];
  }
};


//no of ordered ways to make sum = target  |  Also called Coin Change

class Solution {
  public:
  using ll = long long;
    long long coin_change(int S[], int N, int Target) {
        vector<ll> dp(Target + 1, 0);
        dp[0] = 1;
        
      for(int x = 0; x < N; x++)
      {
          for(int i = 0; i <= Target; i++)          // this code works coz we are processing every coin only once
          {
                  if(i - S[x] >= 0)
                  dp[i] += dp[i - S[x]];
                
        
          }
      }
    return dp[Target];
  }
};
