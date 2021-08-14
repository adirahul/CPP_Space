/* 0-1 knapsack -> To buy max pages of bunch of books using some amount of money x*/

#include <bits/stdc++.h>
using namespace std;
template <class T, class C>
void ckmax(T &a, C b) { a > b ?: a = b; }


int main() {
  int n,money;
  cin >> n >>money;

  vector<int> price(n) , pages(n);

  for(int &x:price)cin>>x;
  for(int &x:pages)cin>>x;

  vector<vector<int>> dp(n+1, vector<int> (money+1,0));
  
  /*state        :     dp[i][x]      ->   max pages we can get using sum atmost x only buying from first i books
    base case    :     dp[0][x] =0   ->   we cant get any pages without any books
    transition   :     we can goto ith item from (i-1)th to either pick the item or leave it                                
    answer       :     dp[n][money]                    */
 
  for(int i=1; i<=n; i++){
    for(int j=0; j<=money; j++){
      dp[i][j] = dp[i-1][j];  //leave it

      if(j-price[i-1]>=0){
        ckmax(dp[i][j] , dp[i-1][j- price[i-1]] +pages[i-1]);   //pick it
      }
    }
  }
  cout<< dp[n][money];
}