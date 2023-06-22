#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bug(x) cout << #x << "  " << x << '\n';
void _print(vector<int> v1)
{
    cout << "Your vector = ";
    for (auto i : v1)
    {
        cout << i << " ";
    }
    cout << "\n";
}
#define _ohi_                    \
    ios::sync_with_stdio(false); \
    cin.tie(0), cin.tie(0);
const int MOD = 1e9 + 7;
const int MAX = 100005;
int arr[MAX + 10];
vector<pair<int, int>> tree(MAX * 3);
void init(int node, int b, int e)
{
    if (b == e)
    {
        tree[node] = {arr[b], -1};
        return;
    }
    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid + 1, e);
    // main part
    int x[4];
    x[0] = tree[left].first;
    x[1] = tree[left].second;
    x[2] = tree[right].first;
    x[3] = tree[right].second;
    sort(x, x + 4);
    int a;
    for (int i = 0; i < 4; ++i)
    {
        if (x[i] > -1)
        {
            a = i;
            break;
        }
    }
    tree[node] = {x[a], x[3]};
}
pair<int, int> query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return {-1, -1};
    if (b >= i && e <= j)
        return tree[node];
    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int mid = (b + e) / 2;
    // main part
    auto A = query(left, b, mid, i, j);
    auto B = query(right, mid + 1, e, i, j);
    int x[4];
    x[0] = A.first;
    x[1] = A.second;
    x[2] = B.first;
    x[3] = B.second;
    sort(x, x + 4);
    int a;
    for (int i = 0; i < 4; ++i)
    {
        if (x[i] > -1)
        {
            a = i;
            break;
        }
    }
    return {x[a], x[3]};
}
void update(int node, int b, int e, int target, int val)
{
    if (target > e || target < b)
    {
        return;
    }
    if (b == e && b == target)
    {
        tree[node] = {val, -1};
        return;
    }
    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int mid = (b + e) / 2;
    update(left, b, mid, target, val);
    update(right, mid + 1, e, target, val);
    // main part
    int x[4];
    x[0] = tree[left].first;
    x[1] = tree[left].second;
    x[2] = tree[right].first;
    x[3] = tree[right].second;
    sort(x, x + 4);
    int a;
    for (int i = 0; i < 4; ++i)
    {
        if (x[i] > -1)
        {
            a = i;
            break;
        }
    }
    tree[node] = {x[a], x[3]};
}
int32_t main()
{
    //_ohi_
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; ++tc)
    {
        printf("Case %d: ", tc);
        int n, d;
        cin >> n >> d;

        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
        init(0, 0, n - 1);
        int ans = 0;
        for (int i = 0; i < n - d; ++i)
        {
            pair<int, int> an = query(0, 0, n - 1, i, i + d-1);
            ans = max(an.second - an.first, ans);
        }
        cout << ans << "\n";
    }
    return 0;
}
