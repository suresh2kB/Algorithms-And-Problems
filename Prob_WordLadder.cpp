/**
 *    author:  Suresh Kumar
 *    created: 17.02.2023
 **/

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 

Constraints:

1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.


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
