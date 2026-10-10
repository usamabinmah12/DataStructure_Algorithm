class Solution {
    set<vector<int>> res;
    vector<int> cur;
    void dfs(int i  , vector<int>& c, int t) {
        
        if(i == c.size()) {
            if(t == 0) {
                res.insert(cur);
            }
            return;
        }
        if(t < 0) return;
        
        cur.push_back(c[i]);
        dfs(i + 1 , c , t - c[i]);
        
        cur.pop_back();
        while(i + 1 < c.size() and c[i] == c[i + 1] ) i++;
        
        dfs(i + 1 , c , t);
        return;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        res.clear();
        sort(c.begin() , c.end());
        dfs(0 , c , t);
        vector<vector<int>> ans;
        int n = c.size();
        // set<vector<int>> res;
        // for(int i = n - 1 ; i >= 0 ; i--) {
        //     vector<int> cur;
        //     int d = t;
        //     for(int j = i ; j >= 0 ; j--) {
        //         if(v[j] >= d) {
        //             d -= v[i]
        //         }
        //     }
        // }
        for(auto u : res) {
            vector<int> v;
            for(auto d : u) v.push_back(d);
            ans.push_back(v);
        }
        return ans;
    }
};
