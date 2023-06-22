#include <bits/stdc++.h>
using namespace std;

void ifterParty(long long L, long long p)
{
    vector<long long> ans;

    long long l = L - p;

    for (long long i = 1; i * i <= l; i++)
    {
        if (l % i == 0)
        {
            if (i > p)
            {
                ans.push_back(i);
            }
            if (i * i != l)
            {
                if ((long long)(l / i) > p)
                {
                    ans.push_back(l / i);
                }
            }
        }
    }
    sort(ans.begin(), ans.end());
    if (ans.size() == 0)
    {
        cout << "impossible";
    }
    else
    {
        for (auto i : ans)
        {
            cout << i << ' ';
        }
    }
}
int main()
{
    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i)
    {
        long long l, p;
        cin >> l >> p;
        cout << "Case " << i << ": ";
        ifterParty(l, p);
        cout << '\n';
    }
}
