class Solution {
public:
    vector<vector<int>> permute(vector<int>& v) {
        vector<vector<int>> ans;
        sort(v.begin() , v.end());
        do{
            vector<int> cur;
            for(auto u : v) cur.push_back(u);
            ans.push_back(cur);
        }while(next_permutation(v.begin() , v.end()));
        return ans;
    }

};
