#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bug(x) cout << #x << "  " << x << '\n';
template <class T>
void _print(vector<T> v1)
{
    cout << "vector = ";
    for (T i : v1)
    {
        cout << i << "   ";
    }
    cout << "\n";
}
// #define _ohi_ ios::sync_with_stdio(false);cin.tie(0),cin.tie(0);
const int MOD = 1e9 + 7;
const int MAX = 1e6;
set<string> permutation;
int Case = 0;
int k;
void make_permutation(string s, int sz)
{
    if (sz >= s.size())
    {
        permutation.insert(s);
        return;
    }
    string temp = s;
    for (int i = sz; i < s.size(); ++i)
    {
        swap(s[sz], s[i]);
        make_permutation(s, sz + 1);
        swap(s[sz], s[i]);
        if (permutation.size() >= 40)
        {
            return;
        }
    }
}
void sol()
{
    cout << "Case " << ++Case << ":\n";
    int n;
    cin >> n >> k;
    string temp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string s = "";
    for (int i = 0; i < n; ++i)
        s += temp[i];

    make_permutation(s, 0);
    int cn=0;
    for(auto i:permutation){
        cout << i << endl;
        if(++cn==k){
            break;
        }
    }
    permutation.clear();
}
int32_t main()
{
    //_ohi_
    int t;
    cin >> t;
    while (t--)
    {
        sol();
        // cout << '\n';
    }
    return 0;
}
