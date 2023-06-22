#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;
int arr[MAX * 4];
struct Tree
{
    int sum, prop = 0;

} tree[MAX * 4];
void init(int node, int b, int e)
{
    if (tree[node].prop == -1)
        return;
    tree[node].sum = tree[node].prop * (e - b + 1);
    if (e > b)
    {
        int left = node * 2 + 1;
        int right = node * 2 + 2;
        tree[left].prop = tree[node].prop;
        tree[right].prop = tree[node].prop;
    }
    tree[node].prop = -1;
}
int query(int node, int b, int e, int i, int j)
{
    init(node, b, e);
    if (i > e || j < b)
    {
        return 0;
    }
    if (b >= i && e <= j)
    {
        return tree[node].sum;
    }
    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int mid = (b + e) / 2;
    int leftSum = query(left, b, mid, i, j);
    int rightSum = query(right, mid + 1, e, i, j);
    return leftSum + rightSum;
}
void update(int node, int b, int e, int i, int j, int val)
{
    init(node, b, e);
    if (i > e || j < b)
    {
        return;
    }
    if (b >= i && e <= j)
    {
        tree[node].prop = val;
        init(node, b, e);
        return;
    }
    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int mid = (b + e) / 2;
    update(left, b, mid, i, j, val);
    update(right, mid + 1, e, i, j, val);
    tree[node].sum = tree[left].sum + tree[right].sum;
}
void clear()
{
    for (int i = 0; i < MAX * 4; ++i)
    {
        tree[i].sum = 0;
        tree[i].prop = 0;
        arr[i] = 0;
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; ++tc)
    {
        clear();
        printf("Case %d: \n", tc);
        int n, q;
        cin >> n >> q;
        while (q--)
        {
            int a, i, j, x;
            cin >> a;
            if (a == 1)
            {
                cin >> i >> j >> x;
                update(0, 0, n - 1, i, j, x);
            }
            if (a == 2)
            {
                cin >> i >> j;
                int ans =  query(0, 0, n - 1, i, j);
                if(ans%(j-i+1)==0)
                {
                    cout << ans/(j-i+1) << "\n";
                }
                else{
                    int gcd = __gcd(ans,(j-i+1));
                    cout << ans/gcd <<"/"<<(j-i+1)/gcd <<"\n";
                }
            }
        }
    }
}
