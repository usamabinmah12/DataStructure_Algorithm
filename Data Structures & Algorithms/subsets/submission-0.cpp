class Solution {
    vector<int> cur;
    void knap(int i , vector<int> &v , vector<vector<int>> &ans) {
        
        if(i == v.size()) {
            ans.push_back(cur);
            return;
        }
        knap(i + 1 , v , ans);
        cur.push_back(v[i]);
        knap(i + 1 , v , ans);
        cur.pop_back();
       
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        knap(0 , nums , ans);
        return ans;
    }
};
