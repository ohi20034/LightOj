#include <bits/stdc++.h>
using namespace std;
const int MOD = 100000007;
const int MAX = 100;
int coin[MAX], freq[MAX];
int n, k;
int dp[52][1020];
int f(int pos, int rem)
{
    if (pos == n)
        return (rem == 0);
    if (rem < 0)
        return 0;
    int &ret = dp[pos][rem];
    if(~ret){
        return ret;
    }
    int total = 0;
    for (int i = 0; i <= freq[ pos]; ++i)
    {
        total = (total + f(pos + 1, rem - (i * coin[pos]))) % MOD;
        if(total >= MOD) total %= MOD;
    }
    return dp[pos][rem] = total;
}
int main()
{
    int t;
    scanf("%d",&t);
    for (int tc = 1; tc <= t; ++tc)
    {
        cin >> n >> k;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d",&coin[i]);
        }
        for(int i=0; i<=n; ++i){
            for(int j=0; j<=k; ++j){
                dp[i][j]=-1;
            }
        }
        for (int i = 0; i < n; ++i)
        {
           scanf("%d",&freq[i]);
        }
        printf("Case %d: %d\n",tc,f(0,k));
    }
}
