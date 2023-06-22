#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000+7;
#define ok cout <<"OHi\n";
int arr[MAX];
int tree[MAX * 4];

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

    tree[node] = min(tree[left], tree[right]);
}
int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return 100000000;
    if (b >= i && e <= j)
        return tree[node];
    int left = node * 2+1;
    int right = node * 2 + 2;
    int mid = (b + e) / 2;
    return min(query(left, b, mid, i, j),query(right, mid + 1, e, i, j));
}
void update(int node,int b,int e,int target,int val)
{
    if(target > e || target < b)
    {
        return;
    }
    if(b==e && b==target)
    {
        tree[node] = val;
        return;
    }
    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int mid = (b+e)/2;

    update(left,b,mid,target,val);
    update(right,mid+1,e,target,val);

    tree[node] = tree[left]+tree[right];
}
int main()
{
    int t; scanf("%d",&t);
    for(int tc=1; tc<=t; ++tc)
    {
        printf("Case %d:\n",tc);
        int n,q; cin >> n >> q;
        for(int i=0; i<n; ++i)
        {
            scanf("%d",&arr[i]);
        }
        init(0,0,n-1);
        for(int i=0; i<q; ++i)
        {
            int b,e; scanf("%d %d",&b,&e);
            printf("%d\n", query(0,0,n-1,b-1,e-1));
        }

    }
}
