#include <bits/stdc++.h>
using namespace std;
//#define int long long int
struct TrieNode
{
    TrieNode *next[20];
    int cnt;
    TrieNode()
    {
        cnt = 0;
        for (int i = 0; i < 20; ++i)
        {
            next[i] = NULL;
        }
    }
} *root;
int ans = 0;
void trieinsert(string &s)
{
    TrieNode *curr = root;
    for (int i = 0; i < s.size(); ++i)
    {
        int x = s[i] - 'A';
        if (curr->next[x] == NULL)
        {
            curr->next[x] = new TrieNode();
        }

        curr = curr->next[x];
        curr->cnt++;
        ans = max(ans, (curr->cnt * (i + 1)));
    }
}
void reset(TrieNode *cur)
{
    for (int i = 0; i < 20; i++)
        if (cur->next[i])
            reset(cur->next[i]);
    delete (cur);
}

int32_t main()
{
    int tc;
    cin >> tc;
    for (int i = 1; i <= tc; ++i)
    {
        root = new TrieNode();
        cout << "Case " << i << ": ";
        int q;
        cin >> q;
        for (int j = 0; j < q; ++j)
        {
            string s;
            cin >> s;
            trieinsert(s);
        }
        cout << ans << endl;
        ans = 0;
        reset(root);
    }
}
}
