#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = 2e5 + 7;
int arr[MAX];
struct query
{
    int inx, left, right;
} q[MAX];
int rootN;
bool cmp(query &a, query &b)
{
    if (a.left / rootN == b.left / rootN)
    {
        return a.right > b.right;
    }
    return a.left / rootN < b.left / rootN;
}
int32_t main()
{
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; ++tc)
    {
        printf("Case %d: \n", tc);
        int n, Q;
        cin >> n >> Q;
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
        rootN = sqrtl(n);
        for (int i = 0; i < Q; ++i)
        {
            cin >> q[i].left >> q[i].right;
            q[i].inx = i;
            q[i].left--;
            q[i].right--;
        }
        sort(q, q + Q, cmp);
        vector<int> ans(Q);
        vector<int> freq(10 * MAX);
        int curr_l = 0, curr_r = -1, l, r;
        int curr_ans = 0;
        for (int i = 0; i < Q; ++i)
        {
            l = q[i].left;
            r = q[i].right;
            while (curr_r < r)
            {
                curr_r++;
                freq[arr[curr_r]]++;
                if (freq[arr[curr_r]] == 1)
                    curr_ans++;
            }
            while (curr_l > l)
            {
                curr_l--;
                freq[arr[curr_l]]++;
                if (freq[arr[curr_l]] == 1)
                    curr_ans++;
            }
            while (curr_l < l)
            {
                freq[arr[curr_l]]--;

                if (freq[arr[curr_l]] == 0)
                    curr_ans--;
                curr_l++;
            }
            while (curr_r > r)
            {
                freq[arr[curr_r]]--;

                if (freq[arr[curr_r]] == 0)
                    curr_ans--;
                curr_r--;
            }
            ans[q[i].inx] = curr_ans;
        }
        for (int i = 0; i < Q; ++i)
        {
            cout << ans[i] << "\n";
        }
    }
}
