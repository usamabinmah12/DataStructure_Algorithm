class Solution {
    set<vector<int>> res;
    vector<int> cur;
    // set<int> s;
    void dfs(int i ,vector<int> &v) {
        if(i == v.size()) {
            res.insert(cur);
            return ;
        }
       
        cur.push_back(v[i]);
        dfs(i + 1 , v);
        cur.pop_back();
        dfs(i + 1 , v);
        return;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& v) {
        res.clear();
        dfs(0 , v );
        vector<vector<int>> ans;
        set<vector<int>> s;
        for(auto u : res) {
            vector<int> p(u.begin() , u.end());
            auto cur_p = p;
            sort(cur_p.begin() , cur_p.end());
            if(s.find(cur_p) != s.end()) {
                continue;
            }
            else {
                s.insert(cur_p);
            }
            ans.push_back(p);
        }
        return ans;
    }
};
