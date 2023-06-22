#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    TrieNode *next[11];
    bool completedWord;
    TrieNode()
    {
        completedWord = false;
        for (int i = 0; i <= 11; ++i)
        {
            next[i] = NULL;
        }
    }
} *root;
void clear(TrieNode *node)
{
    for (int i = 0; i <= 10; ++i)
    {
        if (node->next[i] != NULL)
        {
            clear(node->next[i]);
            delete node->next[i];
            node->next[i] = NULL;
        }
    }
}
void deleteTrie()
{
    clear(root);
    delete root;
    root = NULL;
}
bool ans = true;
int cnt = 0;
void trieinsert(string s)
{
    TrieNode *curr = root;
    for (int i = 0; i < s.size(); ++i)
    {
        int x = s[i] - '0';
        if (curr->next[x] == NULL)
        {
            curr->next[x] = new TrieNode();
            cnt++;
        }
        curr = curr->next[x];
        if (curr->completedWord || ((s.size() - 1 == i) && cnt == 0))
        {
            ans = false;
        }
    }
    curr->completedWord = true;
}
int main()
{

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
    {
        cout << "Case " << tc + 1 << ": ";
        root = new TrieNode();
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            string x;
            cin >> x;
            trieinsert(x);
            cnt = 0;
        }
        if (ans)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
        ans = true;
        cnt = 0;
        deleteTrie();
    }
}
