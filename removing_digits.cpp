/* min steps required to make  number  n equal to 0 by subtractong its digits
   27→20→18→10→9→0 */

#include <bits/stdc++.h>
using namespace std;
const int infinity = 1e9+7;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
 
  int n;
  cin >> n ;
 
  vector<int> dp(n + 1, infinity);  //no of ways to reach 0 from x'
 
  dp[0]=0;           //Base case ->0 step to zero from zero

 // for transition, we know from 324 ,we can go to 322, 321 and 320
  for(int i=1 ;i<=n ;++i){
      for(int x=i ; x>0; x/=10){
        int rem =x%10;
        dp[i] =min(dp[i], 1+ dp[i -(rem)]);
      }

      /*for(char c: to_string(i)){
        dp[i] =min(dp[i], 1+ dp[i -(c-'0')]);  // string version is also fine
      }*/
  }

  cout<< dp[n];
}