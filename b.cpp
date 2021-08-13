#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

/*Number of distinct ways you can produce a money sum x using the available coins.*/
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 
  int n, target;
  cin >> n >> target;
  int coin[n];
  for (int i = 0; i < n; i++)
    cin >> coins[i];
 
  vector<int> dp(target + 1, 0);  //no of ways to produce sum 'target'
 
  dp[0]=1;    //we initialize dp[0] = 1, saying the empty set is the only way to make 0

  for(int i=1 ;i<=target ;++i){
    for(int x: coins){                // can swap order of loops to get no of ordered ways to produce sum target
      if(i-x>=0){
      dp[i] += dp[i-x];
      dp[i] =dp[i]%mod;
      }
    }
  }

  cout<< dp[target];
}