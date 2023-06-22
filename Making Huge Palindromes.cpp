#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int BASE = 129;
vector<long long> generateExponents(int N)
{
    vector<long long> po(N + 1, 1);
    for (int i = 1; i <= N; ++i)
    {
        po[i] = (po[i - 1] * BASE) % MOD;
    }
    return po;
}
vector<long long> generatePrefixHash(string &s)
{
    vector<long long> hashValue(s.size(), 0);
    hashValue[0] = s[0];
    for (int i = 1; i < s.size(); ++i)
    {
        hashValue[i] = ((hashValue[i - 1] * BASE) + s[i]) % MOD;
    }
    return hashValue;
}
long long getRangeHash(int L, int R, vector<long long> &hashValue, vector<long long> &po)
{
    if (!L)
        return hashValue[R];
    return (hashValue[R] - (hashValue[L - 1] * po[R - L + 1] % MOD) + MOD) % MOD;
}
int main()
{
    int tc,cnt=1;
    cin >> tc;
    while (tc--)
    {
        string s, rs;
        cin >> s;
        rs = s;
        int n = s.size();
        reverse(rs.begin(), rs.end());
        auto sHashValue = generatePrefixHash(s);
        auto rsHashValue = generatePrefixHash(rs);
        auto po = generateExponents(s.size());
        int ans = -1;
        for (int i = 0; i < s.size(); i++)
        {
            int start = i;
            int end = n - 1;
            int end1 = n - 1 - start;
            int start1 = end1 - end + start;

            if (getRangeHash(start, end, sHashValue, po) == getRangeHash(start1, end1, rsHashValue, po))
            {
                ans = i;
                break;
            }
        }
        ans+=n;
        printf("Case %d: %d\n",cnt,ans);
        cnt++;
    }
}
