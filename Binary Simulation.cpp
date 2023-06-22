#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = 1e5 + 10;
int arr[MAX * 4];
struct Tree
{
    int sum, prop = 0;

} tree[MAX * 4];
void init(int node, int b, int e)
{
    if (b == e)
    {
        tree[node].sum = arr[b];
        return;
    }
    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int mid = (b + e) / 2;
    init(left, b, mid);
    init(right, mid + 1, e);
}
int query(int node, int b, int e, int i, int j, int pro = 0)
{
    if (i > e || j < b)
    {
        return 0;
    }
    if (b >= i && e <= j)
    {
        return tree[node].sum + (e - b + 1) * pro;
    }
    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int mid = (b + e) / 2;
    int leftSum = query(left, b, mid, i, j, tree[node].prop + pro);
    int rightSum = query(right, mid + 1, e, i, j, tree[node].prop + pro);
    return leftSum + rightSum;
}
void update(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
    {
        return;
    }
    if (b >= i && e <= j)
    {
        tree[node].sum += (e - b + 1) * 1;
        tree[node].prop += 1;
        return;
    }
    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int mid = (b + e) / 2;

    update(left, b, mid, i, j);
    update(right, mid + 1, e, i, j);

    tree[node].sum = tree[left].sum + tree[right].sum;
}
void clear()
{
    for (int i = 0; i < MAX * 4; ++i)
    {
        tree[i].sum = 0,
        tree[i].prop = 0;
    }
}
int32_t main()
{
#define _ohi_                    \
    ios::sync_with_stdio(false); \
    cin.tie(0), cin.tie(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc)
    {
        cout << "Case " << tc << ":" << '\n';
        clear();
        string s;
        int q;
        cin >> s >> q;
        for (int i = 0; i < s.size(); ++i)
        {
            arr[i] = s[i] - '0';
        }
        int n = s.size();
        init(0, 0, n - 1);
        while (q--)
        {
            char ch;
            cin >> ch;
            if (ch == 'I')
            {
                int i, j;
                cin >> i >> j;
                i--, j--;
                update(0, 0, n - 1, i, j);
            }
            else
            {
                int a;
                cin >> a;
                int na = query(0, 0, n - 1, a - 1, a - 1);

                if (s[a - 1] == '1')
                {
                    if (na % 2 == 0)
                    {
                        cout << 0 << "\n";
                    }
                    else
                    {
                        cout << 1 << "\n";
                    }
                }
                else
                {
                    if (na % 2 == 0)
                    {
                        cout << 0 << "\n";
                    }
                    else
                    {
                        cout << 1 << "\n";
                    }
                }
            }
        }
    }
}

