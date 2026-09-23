class Solution {
    const static int N = 1e3 + 12;
    vector<int>gp[N];
    map<int ,bool> visited;
    bool dfs(int root) {
        if(visited[root]) {
            return false;
        }
        if(gp[root].empty()) {
            return true;
        }
        visited[root] = true;
        for(auto ch : gp[root]) {
            if(!dfs(ch)) {
                return false;
            }
        }
        visited[root] = false;
        gp[root].clear();
        return true;
    }

public:
    bool canFinish(int tot, vector<vector<int>>& g) {
    //    gp = g;
        // gp.resize(g.size());
        for(int i = 0 ; i < g.size() ; i++) {
            gp[g[i][0]].push_back(g[i][1]);
        }
        for(int i = 0 ;i < tot ; i++) {
            if(!dfs(i)) {
                return false;
            }
        }
        return true;


    }
};
