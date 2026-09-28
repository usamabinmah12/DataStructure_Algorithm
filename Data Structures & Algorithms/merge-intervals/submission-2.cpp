class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin() , v.end());
        int n = v.size();
        vector<vector<int>> ans;
        int l = 0, r = -1;
        int i = 0;
        while(i < n) {
            if(r > v[i][1]) {
                i++;
                continue;
            }
            if(r >= v[i][0] and r <= v[i][1] ) {
                r = v[i][1];
                auto u = ans.back();
                ans.pop_back();
                ans.push_back({u[0] , r});
            }
            else {
                l = v[i][0] , r = v[i][1];
                ans.push_back({l , r});
            }
            i++;
        }
        return ans;
    }
};
