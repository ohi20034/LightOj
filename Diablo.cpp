#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 10;
int arr[MAX * 4];
int tree[MAX * 4];

void init(int node, int b, int e)
{
    if (b == e)
    {
        tree[node] = 1;
        return;
    }
    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int mid = (b + e) / 2;
    init(left, b, mid);
    init(right, mid + 1, e);

    tree[node] = tree[left] + tree[right];
}
int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
    {
        return 0;
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
    return leftSum + rightSum;
}
void update(int node, int b, int e, int target, int val)
{
    if (target > e || target < b)
    {
        return;
    }
    if (b == e && b == target)
    {
        tree[node] = val;
        return;
    }
    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int mid = (b + e) / 2;

    update(left, b, mid, target, val);
    update(right, mid + 1, e, target, val);

    tree[node] = tree[left] + tree[right];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc)
    {
        //printf("Case %d: \n", tc);
        cout << "Case "<<tc<<": \n";
        int n, q;
        cin >> n >> q;
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
        init(0, 0, MAX);
        while (q--)
        {
            char a;
            cin >> a;
            if (a == 'a')
            {
                cin >> arr[n];
                n++;
            }
            else
            {
                int b;
                cin >> b;
                b--;
                int l = 0, r = n+1;
                while (l < r)
                {
                    int mid = (l + r) / 2;
                    if (query(0, 0, MAX, 0, mid) > b)
                    {
                        r = mid;
                    }
                    else
                    {
                        l = mid + 1;
                    }
                }
                if (r > n-1)
                {
                    cout << "none\n";
                }
                else
                {
                    // cout << r << "\n";
                    cout << arr[r] << "\n";
                    update(0, 0, MAX, r, 0);
                }
            }
        }
    }
}
