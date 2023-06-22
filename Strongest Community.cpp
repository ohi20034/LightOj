#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = 1e5 + 10;
int arr[MAX * 4];
int tree[MAX * 4];
struct T
{
    int fastoc, lastoc;
} ocur[MAX * 4];
void init(int node, int b, int e)
{
    if (b == e)
    {
        tree[node] = arr[b];
        return;
    }
    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int mid = (b + e) / 2;
    init(left, b, mid);
    init(right, mid + 1, e);
    tree[node] = max(tree[left], tree[right]);
}
int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
    {
        return INT_MIN;
    }
    if (b >= i && e <= j)
    {
        return tree[node];
    }
    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int mid = (b + e) / 2;
    int leftSum = query(left, b, mid, i, j);
    int rightSum = query(right, mid + 1, e, i, j);
    return max(leftSum, rightSum);
}
void clear()
{
    for (int i = 0; i < MAX * 4; ++i)
    {
        ocur[i].fastoc = 0;
        ocur[i].lastoc = 0;
        arr[i] = 0;
        tree[i] = 0;
    }
}
int32_t main()
{
    clear();
    int tc;
    cin >> tc;
    int t = 0;
    while (tc--)
    {
        cout << "Case " << ++t << ":\n";
        int n, q, k;
        scanf("%lld %lld %lld", &n, &k, &q);
        map<int, int> mp;
        int br[n];
        for (int i = 0; i < n; ++i)
        {
            scanf("%lld", &arr[i]);
            br[i] = arr[i];
            mp[arr[i]]++;
        }
        for (int i = 0; i < n; ++i)
        {
            arr[i] = mp[arr[i]];
        }
        init(0,0,n-1);
        int c = 0;
        vector<int> temp(MAX);
        temp[br[0]] = 0;
        for (int i = 1; i < n; i++)
        {
            if (br[i] != br[i - 1])
            {
                temp[br[i]] = i;
            }
        }
        for (int i = 0; i < n; i++)
        {
            ocur[i].fastoc = temp[br[i]];
        }
        vector<int> temp2(MAX);
        temp2[br[n - 1]] = n - 1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (br[i] != br[i + 1])
            {
                temp2[br[i]] = i;
            }
        }
        for (int i = 0; i < n; i++)
        {
            ocur[i].lastoc = temp2[br[i]];
        }
        while (q--)
        {
            int x, y;
            scanf("%lld %lld", &x, &y);
            // cin >> x >> y;
            x--, y--;
            if (br[x] == br[y])
            {
                cout << y - x + 1 << "\n";
            }
            else
            {
                int a = ocur[x].lastoc - x + 1;
                int b = y - ocur[y].fastoc + 1;
                int left = ocur[x].lastoc + 1;
                int right = ocur[y].fastoc - 1;
                int c = query(0, 0, n - 1, left, right);
                cout << max({a, b, c}) << "\n";
            }
        }
    }
    return 0;
}
