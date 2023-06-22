#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int n, q;
int arr[N];
int bit[N];

int query(int idx)
{
    int ans = 0;
    while (idx > 0)
    {
        ans += bit[idx];
        idx -= (idx & -idx);
    }
    return ans;
}
void update(int idx, int val)
{
    while (idx <= n)
    {
        bit[idx] += val;
        idx += (idx & -idx);
    }
}
int main()
{
    int text = 0;
    int tc;
    cin >> tc;
    while (tc--)
    {
        cout << "Case " << ++text << ":\n";
        cin >> n >> q;
        for (int i = 1; i <= n; ++i)
        {
            cin >> arr[i];
            update(i, arr[i]);
        }
        while (q--)
        {
            int check;
            cin >> check;
            if (check == 1)
            {
                int idx;
                cin >> idx;
                idx++;
                cout << arr[idx] << "\n";
                update(idx, (-arr[idx]));
                arr[idx] = 0;
            }
            else if (check == 2)
            {
                int idx, val;
                cin >> idx >> val;
                ++idx;
                arr[idx] += val;
                update(idx, val);
            }
            else
            {
                int i, j;
                cin >> i >> j;
                int a = query(++j);
                int b = query(i);
                cout << a - b << "\n";
            }
        }
        memset(arr, 0, sizeof(arr));
        memset(bit, 0, sizeof(bit));
    }
}
