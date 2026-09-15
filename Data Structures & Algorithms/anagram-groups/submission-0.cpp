class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string , string>> vp;
        for(auto  u: strs) {
            auto s = u;
            sort(s.begin() , s.end());
            // cout << s << ' ' << u << '\n';
            vp.push_back({s , u});
        }
        sort(vp.begin() , vp.end());
        int j = 0;
        int n = vp.size();
        vector<vector<string>> ans;
        for(int i = 0 ; i < n ; i++) {
            j  = i;
            vector<string> cur;
            while(j < n and vp[i].first == vp[j].first) {
                cur.push_back(vp[j].second);
                j++;
            }
            ans.push_back(cur);
            i = j -  1;
        }
        return ans;
        }
        
};
