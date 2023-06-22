#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000 + 7;
#define int long long
#define ok cout << "OHi\n";
int arr[MAX];
struct T
{
    int idx, mVal;
} tree[MAX * 4];

void init(int node, int b, int e)
{
    if (b == e)
    {
        tree[node].mVal = arr[b];
        tree[node].idx = b;
        return;
    }
    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid + 1, e);

    tree[node].mVal = min(tree[left].mVal, tree[right].mVal);

    if (tree[node].mVal == tree[left].mVal)
    {
        tree[node].idx = tree[left].idx;
    }
    else
    {
        tree[node].idx = tree[right].idx;
    }
}
int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return -1;
    if (b >= i && e <= j)
        return tree[node].idx;
    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int mid = (b + e) / 2;
    int Lq = query(left, b, mid, i, j);
    int Rq = query(right, mid + 1, e, i, j);
    if (Lq == -1)
    {
        return Rq;
    }
    if (Rq == -1)
    {
        return Lq;
    }
    return arr[Lq] < arr[Rq] ? Lq : Rq;
}
int CalculateRarectangle(int start, int End, int n)
{
    if (start > End)
    {
        return -1;
    }
    if (start == End)
    {
        return arr[start];
    }
    int minIndex = query(0, 0, n - 1, start, End);
    int leftMax = CalculateRarectangle(start, minIndex - 1, n);
    int rightMax = CalculateRarectangle(minIndex + 1, End, n);
    int minMax = arr[minIndex] * (End - start + 1);

    return max({minMax, leftMax, rightMax});
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cin.tie(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc)
    {
        cout << "Case " << tc << ": ";
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
        init(0, 0, n - 1);
        cout << CalculateRarectangle(0, n - 1, n) << '\n';
    }
}
