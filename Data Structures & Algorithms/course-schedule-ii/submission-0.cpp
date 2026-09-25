class Solution {
    vector<int> ans;
    vector<vector<int>> gp;
    vector<int> indeg;
    void dfs(int root) {
        ans.push_back(root);
        indeg[root]--;
        for(auto ch : gp[root]) {
            indeg[ch]--;
            if(indeg[ch] == 0) {
                dfs(ch);
            }
        }
    }
public:
    vector<int> findOrder(int crs, vector<vector<int>>& pr) {
       gp = vector<vector<int>>(crs);
        // vector<int> indeg(n , 0);
        indeg = vector<int>(crs , 0);
        for(auto u :pr) {
            gp[u[1]].push_back(u[0]);
            indeg[u[0]]++;
        }
        // gp = g;
        for(int i = 0 ; i  <  crs;  i++) {
            if(indeg[i] == 0) {
                dfs(i);
            }
        }
        vector<int> cur;
        return (ans.size() == crs) ? ans: cur ;


    }
};
