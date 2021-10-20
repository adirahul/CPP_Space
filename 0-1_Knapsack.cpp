/* 0-1 knapsack -> Function to return max value that can be put in knapsack of capacity W. */

template <class T, class C>
void mx(T &a, C b) { a > b ?: a = b; }
using ll = long long;

class Solution
{
    public:
    int knapSack(int W, int wt[], int val[], int N) 
    {

    vector<vector<int>> dp(N + 1, vector<int> (W + 1, 0));
    // dp[i][j] = max val obtained using first i items, max capacity being j
    
    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j <= W; j++)
        {
            dp[i][j] = dp[i - 1][j];      //leave it
          
            if(j >= wt[i - 1])
            mx(dp[i][j], dp[i - 1][j - wt[i - 1]] + val[i - 1]);    //pick it
        }
    }
   
    return dp[N][W];
    }
};
