class Solution {
    vector<vector<int>> adj;
    unordered_map<int , unordered_set<int>> mp;
public:
    unordered_set<int>& dfs(int crs) {
        if(mp.count(crs)) return mp[crs];
        mp[crs] = unordered_set<int>();
        for(auto u : adj[crs]) {
            auto cur = dfs(u);
            mp[crs].insert(cur.begin() ,cur.end());
        }
        mp[crs].insert(crs);
        return mp[crs];
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        adj = vector<vector<int>>(n , vector<int>());
        for(auto u : prerequisites) {
            adj[u[1]].push_back(u[0]);
        }
        for(int i = 0 ; i < n ; i++) {
            dfs(i);
        }
        vector<bool> res;
        for(auto query : queries) {
            res.push_back(mp[query[1]].count(query[0]));
        }
         return res;
        
    }
};