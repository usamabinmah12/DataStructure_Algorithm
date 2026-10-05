class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_map<string, vector<string>> mp;
        wordList.push_back(beginWord);
        map<string , int>cnt;
        for (auto word : wordList) {
            for (int i = 0; i < word.size(); i++) {
                string pattern = word.substr(0, i) + '*' + word.substr(i + 1);
                mp[pattern].push_back(word);
            }
        }
        int ans = 1;
        queue<string> q;
        q.push(beginWord);
        set<string> s;
        s.insert(beginWord);
        
        
        while (!q.empty()) {
           
                string word = q.front();
                q.pop();
                if (word == endWord) {
                    return cnt[endWord] + 1;
                }

                for (int i = 0; i < word.size(); i++) {
                    string pattern =
                        word.substr(0, i) + '*' + word.substr(i + 1);
                    for (auto u : mp[pattern]) {
                        if (s.find(u) == s.end()) {
                            cout << word << ' ' << u << '\n';
                            cnt[u] = 1 + cnt[word];
                            s.insert(u);
                            q.push(u);
                        }
                    }
                }
            
            
        }
        return cnt[endWord];
    }
};
