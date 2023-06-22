#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
map<string, int> mp;
struct TrieNode
{
    TrieNode *next[55];
    bool completedWord;
    int cnt;
    TrieNode()
    {
        cnt = 0;
        completedWord = false;
        for (int i = 0; i < 54; ++i)
        {
            next[i] = NULL;
        }
    }
} *root;

void trieinsert(string &s)
{
    TrieNode *curr = root;
    for (int i = 0; i < s.size(); ++i)
    {
        int x;
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            x = s[i] - 'a';
        }
        else
        {
            x = s[i] - 'A';
            x += 26;
        }
        if (curr->next[x] == NULL)
            curr->next[x] = new TrieNode();

        curr = curr->next[x];
    }
    curr->completedWord = true;
    mp[s]++;
}
void reset(TrieNode *cur)
{
    for (int i = 0; i < 54; i++)
        if (cur->next[i])
            reset(cur->next[i]);
    delete (cur);
}
int main()
{
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t)
    {
        root = new TrieNode();
        cout << "Case " << t << ":\n";
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            string s;
            cin >> s;
            if (s.size() > 2)
                sort(s.begin() + 1, s.end() - 1);
            trieinsert(s);
        }
        int q;
        cin >> q;
        cin.ignore();
        for (int i = 0; i < q; ++i)
        {
            int ans = 1;
            string line;
            getline(cin, line);
            vector<int> arr;
            stringstream s(line);
            string word;
            while (s >> word)
            {
                if (word.size() > 2)
                    sort(word.begin() + 1, word.end() - 1);
                arr.push_back(mp[word]);
            }
            sort(arr.begin(), arr.end());
            if (arr[0] == 0)
            {
                cout << 0 << endl;
            }
            else
            {
                for (auto i : arr)
                {
                    ans *= i;
                }
                cout << ans << endl;
            }
        }
        reset(root);
        mp.clear();
    }
}
