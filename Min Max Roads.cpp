#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 9;
const int LOGMAX = 18;
int n;
int st[MAX][LOGMAX + 1];
vector<pair<int, int>> gr[MAX];
int level[MAX];
int MaxTable[MAX][LOGMAX + 1];
int MinTable[MAX][LOGMAX + 1];
int ansmin = INT_MAX, ansmax = INT_MIN;

void dfs(int node, int par, int edge)
{
    st[node][0] = par;
    if (par != -1)
    {
        level[node] = level[par] + 1;
        MaxTable[node][0] = edge;
        MinTable[node][0] = edge;
    }

    for (int k = 1; k < LOGMAX; ++k)
    {
        if (st[node][k - 1] != -1)
        {
            st[node][k] = st[st[node][k - 1]][k - 1];
            MaxTable[node][k] = max(MaxTable[node][k - 1], MaxTable[st[node][k - 1]][k - 1]);
            MinTable[node][k] = min(MinTable[node][k - 1], MinTable[st[node][k - 1]][k - 1]);
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
int lca(int u, int v)
{
    if (level[v] > level[u])
    {
        swap(u, v);
    }

    for (int k = LOGMAX - 1; k >= 0; --k)
    {
        if (level[st[u][k]] >= level[v] && st[u][k] != -1)
        {

            ansmax = max(MaxTable[u][k], ansmax);
            ansmin = min(MinTable[u][k], ansmin);
            u = st[u][k];
        }
    }
    if (u == v)
    {
        return u;
    }
    for (int k = LOGMAX - 1; k >= 0; --k)
    {
        if (st[u][k] != st[v][k])
        {
            ansmax = max(MaxTable[u][k], ansmax);
            ansmax = max(MaxTable[v][k], ansmax);

            ansmin = min(MinTable[u][k], ansmin);
            ansmin = min(MinTable[v][k], ansmin);
            u = st[u][k];
            v = st[v][k];
        }
    }
    ansmax = max(MaxTable[u][0], ansmax);
    ansmax = max(MaxTable[v][0], ansmax);
    ansmin = min(MinTable[v][0], ansmin);
    ansmin = min(MinTable[u][0], ansmin);

    return st[u][0];
}
int32_t main()
{
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc)
    {
        cout << "Case " << tc << ":\n";
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j <= LOGMAX; ++j)
            {
                st[i][j] = -1;
                MaxTable[i][j] = INT_MIN;
                MinTable[i][j] = INT_MAX;
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            gr[i].clear();
        }
        memset(level,0,sizeof level);
        for (int i = 1; i < n; ++i)
        {
            int u, v, d;
            cin >> u >> v >> d;
            gr[u].push_back({v, d});
            gr[v].push_back({u, d});
        }
        dfs(1, -1, 0);
        // buildTable();
        int q;
        cin >> q;
        while (q--)
        {
            int u, v;
            cin >> u >> v;
            lca(u, v);
            printf("%d %d\n", ansmin, ansmax);
            ansmin = INT_MAX, ansmax = INT_MIN;
        }
    }
}

