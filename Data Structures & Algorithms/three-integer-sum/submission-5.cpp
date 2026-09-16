class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        set<vector<int>> ans;
        int n = v.size();
        vector<vector<int>> res;
        for(int i = 0 ; i < n - 2 ; i++) {
            map<int , int> mp;
            
            for(int j = i + 2 ; j < n ; j++) {
                mp[v[j]]++;
            }
            for(int j = i + 1 ; j < n - 1 ; j++) {
                vector<int> a;
                int cur = v[i] + v[j];
                cur *= -1;
                // cur  = abs(cur);
                if(mp[cur] > 0) {
                    a.push_back(v[i]);
                    a.push_back(v[j]);
                    a.push_back(cur);
                    sort(a.begin() , a.end());
                    ans.insert(a);
                }
                
                
                while( j + 2 < n  and v[i] == v[j]) {
                    j++;
                    mp[v[j + 1]]--;
                    if(mp[v[j + 1]] == 0) mp.erase(v[j + 1]);
                }
               mp[v[j + 1]]--;
                    if(mp[v[j + 1]] == 0) mp.erase(v[j + 1]);
            }
            

        }
        for(auto  u: ans) {
            res.push_back(u);
        }
        return res;
    }
};
