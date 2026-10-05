class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string , vector<string>> mp;
        wordList.push_back(beginWord);
        for(auto word : wordList) {
            for(int i = 0;  i < word.size(); i++) {
                string pattern = word.substr(0 , i) + '*' + word.substr(i  + 1 );
                mp[pattern].push_back(word);
            }
        }
        int ans = 1;
        queue<string> q;
        q.push(beginWord);
        set<string>s;
        s.insert(beginWord);
        while(!q.empty()) {
            int size = q.size();
            for(int j = 0 ;  j < size; j++) {
                string word = q.front();
                q.pop();
                if(word == endWord) {
                    return ans;
                }
                
                for(int i = 0;  i < word.size(); i++) {
                    string pattern = word.substr(0 , i) + '*' + word.substr(i  + 1 );
                     for(auto u : mp[pattern]) {
                        if(s.find(u) == s.end()) {
                            s.insert(u);
                            q.push(u);
                        }
                     }
                        
                
            }
            

            }
            ++ans;
        }
        return 0;
    }
};
