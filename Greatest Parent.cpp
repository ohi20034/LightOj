#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 9;
const int LOGMAX = 20;
int n, q;
int st[MAX][LOGMAX + 1];
vector<pair<int, int>> gr[MAX];
int level[MAX];
int nodeval[MAX];

void dfs(int node, int par, int edge)
{
    st[node][0] = par;
    level[node] = level[par] + 1;
    for (int k = 1; k <= LOGMAX; ++k)
    {
        if (st[node][k - 1] != -1)
        {
            st[node][k] = st[st[node][k - 1]][k - 1];
        }
    }
    for (auto child : gr[node])
    {
        if (child.first != par)
        {
            dfs(child.first, node, child.second);
        }
    }
}

int ans(int node, int val)
{
    for (int j = LOGMAX; j >= 0; --j)
    {
        int par = st[node][j];
        if (nodeval[par] >= val)
        {
            node = par;
        }
    }
    return node;
}
int32_t main()
{
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t)
    {
        cout << "Case " << t << ":\n";
        cin >> n >> q;
        for (int i = 0; i <= n; ++i)
        {
            gr[i].clear();
        }
        memset(level, 0, sizeof level);
        memset(st, -1, sizeof st);
        memset(nodeval,0,sizeof nodeval);
        nodeval[1] = 1;
        for (int i = 1; i < n; ++i)
        {
            int u, v;
            cin >> u >> v;
            nodeval[i + 1] = v;
            gr[u + 1].push_back({i + 1, v});
            gr[i + 1].push_back({u + 1, v});
        }
        dfs(1, -1, 0);
        while (q--)
        {
            int node, val;
            cin >> node >> val;
            node++;
            cout << ans(node, val) - 1 << "\n";
        }
    }
}
