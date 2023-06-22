#include <bits/stdc++.h>
using namespace std;
#define MAX_S 1000005
#define MOD 1000000007
#define BASE 129
long long hashValue[MAX_S + 10], powerOfBase[MAX_S + 10];
void generatePrefixHash(string &s)
{
    hashValue[0] = s[0];
    for (int i = 1; i < s.size(); ++i)
    {
        hashValue[i] = ((hashValue[i - 1] * BASE) + s[i]) % MOD;
    }
    powerOfBase[0] = 1;
    for (int i = 1; i <= s.size(); ++i)
    {
        powerOfBase[i] = (powerOfBase[i - 1] * BASE) % MOD;
    }
}
long long getHash(int start, int end)
{
    if (start == 0)
        return hashValue[end];

    return (hashValue[end] - ((hashValue[start - 1] * powerOfBase[end - start + 1]) % MOD) + MOD) % MOD;
}
long long generateHash(string &s)
{
    long long hashVal = 0;
    for (auto &i : s)
    {
        hashVal = ((hashVal * BASE) + i) % MOD;
    }
    return hashVal;
}
int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        string s1, s2;
        cin >> s1 >> s2;
        generatePrefixHash(s1);
        int count = 0;
        long long hashValOfS2 = generateHash(s2);

        for (int i = 0; i + s2.size() <= s1.size(); i++)
        {
            if (getHash(i, i + s2.size() - 1) == hashValOfS2)
            {
                count++;
            }
        }
        printf("Case %d: %d\n", i, count);
    }
    return 0;
}
