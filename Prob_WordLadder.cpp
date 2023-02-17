/**
 *    author:  Suresh Kumar
 *    created: 17.02.2023
 **/
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string beginWord, endWord;
    cin >> beginWord >> endWord;
    int numberOfWords;
    cin >> numberOfWords;
    vector<string> words;
    unordered_map<string, int> mp;
    for (int i = 0; i < numberOfWords; i++)
    {
        string s;
        cin >> s;
        words.push_back(s);
        mp[s] = 0;
    }

    queue<string> q;
    int step = 0;
    mp[beginWord] = 1;
    q.push(beginWord);

    while (!q.empty())
    {
        step++;
        int sz = q.size();

        for (int i = 0; i < sz; i++)
        {
            string curr = q.front();
            q.pop();

            for (int j = 0; j < curr.length(); j++)
            {
                for (char x = 'a'; x <= 'z'; x++)
                {
                    if (x != curr[j])
                    {
                        char last = curr[j];
                        curr[j] = x;

                        if (mp.find(curr) != mp.end() && mp[curr] == 0)
                        {
                            mp[curr] = 1;
                            q.push(curr);
                        }
                        if (curr == endWord && mp.find(curr) != mp.end())
                        {
                            cout << step + 1 << endl;
                            return;
                        }
                        curr[j] = last;
                    }
                }
            }
        }
    }

    cout << -1 << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
