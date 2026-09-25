class Solution {
    //     vector<int> vis;
    // vector<vector<int>> gp;
     vector<int> ans;
    // void dfs(int ch , int parent) {
    //     cout << ch << ' ' << parent << '\n' ;
    //     for(auto u : gp[ch]) {
    //         if(u != parent and vis[parent]) {
    //             ans[0] = u;
    //             ans[1] = parent;
    //         }
    //         if(u != parent) {
    //             dfs(u , ch);
    //         }
    //     }
    //     return;
    // }
    int find(vector<int>&par , int n) {
        int p = par[n];
        while(p != par[p]) {
            par[p] = par[par[p]];
            p = par[p];
        }
        return p;
    }
    bool Union(vector<int> & par , vector<int> & rank , int a , int b) {
        int p1 = find(par , a);
        int p2 = find(par , b);
        if(p1 == p2) {
            return false;
        }
        if(rank[p1] > rank[p2]) {
            par[p2] = p1;
            rank[p1] += rank[p2];
        }
        else {
            par[p1] = p2;
            rank[p2] += rank[p1];
        }
        return true;
        
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
            int n = edges.size();
            vector<int> rank(n + 1, 1) , par(n + 1);
            for(int i = 1 ; i <= n ; i++) par[i] = i;
            for(auto u : edges) {
                if(!Union(par , rank , u[0] , u[1])) {
                    return {u[0] , u[1]};
                }
            }
            return {};
            
    }
};

