class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        set<vector<int>> ans;
        int n = v.size();
        sort(v.begin() , v.end());
        vector<vector<int>> res;
        for (int i = 0; i < n - 2; i++) {
           
            for (int j = i + 1; j < n - 1; j++) {
                vector<int> a;
                int cur = v[i] + v[j];
                cur *= -1;
                // cur  = abs(cur);
                int l = j + 1 , r = n - 1;
                bool ok = false;
                while(l <= r) {
                    int mid = (l + r) /2;
                    if(v[mid] == cur) {
                        ok = true;
                        break;
                    }
                    else if(v[mid] > cur) r = mid- 1;
                    else l = mid + 1;
                }
                if (ok) {
                    a.push_back(v[i]);
                    a.push_back(v[j]);
                    a.push_back(cur);
                    sort(a.begin(), a.end());
                    ans.insert(a);
                }

                while (j < n and v[i] == v[j]) {
                    // j++;
                   
                    j++;
                }
               
            }
        }
        for (auto u : ans) {
            res.push_back(u);
        }
        return res;
    }
};
