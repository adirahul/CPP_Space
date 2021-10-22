#include <bits/stdc++.h>
using namespace std;


int main() {
    string S, T;
    cin >> S >> T;
    int M = S.size(), N = T.size();
    vector<vector<int>> dp(M + 1, vector<int> (N + 1, 0));

        for(int i = 0; i < M; i++)
            for(int j = 0; j < N; j++)

                if(S[i] == T[j])
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                else
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
        
    string ans;
        while(M > 0 and N > 0)

            if(S[M - 1] == T[N - 1])
            {
                ans += T[N - 1];
                M--;  N--;
            }
            else
                if(dp[M - 1][N] > dp[M][N - 1])M--;
                else N--;
            
        
    reverse(begin(ans), end(ans));
    cout << ans;

}
