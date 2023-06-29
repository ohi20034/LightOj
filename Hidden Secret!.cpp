#include <bits/stdc++.h>
using namespace std;
#define int long long

void sol()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    s1.erase(remove(s1.begin(), s1.end(), ' '), s1.end());
    s2.erase(remove(s2.begin(), s2.end(), ' '), s2.end());
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    if (s2 == s1)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}
int32_t main()
{
    int t;
    cin >> t;
    int test = 0;
    cin.ignore(1, '\n');
    while (t--)
    {
        cout << "Case " << ++test << ": ";
        sol();
    }
    return 0;
}
