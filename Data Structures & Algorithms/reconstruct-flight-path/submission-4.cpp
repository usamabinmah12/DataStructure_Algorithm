class Solution {
    unordered_map<string, vector<string>> mp;
    vector<string> ans;

    void dfs(string root) {
        while(!mp[root].empty()) {
            string cur = mp[root].back();
            mp[root].pop_back();

            dfs(cur);
        }

        ans.push_back(root);
    }

public:
    vector<string> findItinerary(vector<vector<string>>& v) {
        for(auto u : v) {
            mp[u[0]].push_back(u[1]);
        }

        for(auto &u : mp) {
            sort(u.second.rbegin(), u.second.rend());
        }

        dfs("JFK");

        reverse(ans.begin(), ans.end());

        return ans;
    }
};