#include <bits/stdc++.h>
using namespace std;
const int MOD = 100000007;
int main()
{
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t)
    {
        int n, k;
        cin >> n >> k;
        vector<int> coins(n, 0);
        for (int i = 0; i < n; ++i)
        {
            cin >> coins[i];
        }
        printf("Case %d: ", t);
        vector<int> dp(k + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; ++i)
        {
            for (int curr = coins[i]; curr <= k; ++curr)
            {
                dp[curr] += dp[curr - coins[i]];
                if (dp[curr] >= MOD)
                {
                    dp[curr] %= MOD;
                }
            }
        }
        printf("%d\n", dp[k]);
    }
}
