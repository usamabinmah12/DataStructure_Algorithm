class Solution {
public:
    vector<int> twoSum(vector<int>& v, int t) {
        int n = v.size();
        for(int i = n - 1 ; i >= 0 ; i--) {
            int req = t - v[i];
            int l  = 0 , r = i - 1;
            // if(req == 0) continue;
            while(l <= r) {
                int mid = (l + r) / 2;
                if(req < v[mid]) {
                    r = mid - 1;
                }
                else if(req == v[mid]) {
                    return { mid + 1 , i + 1};
                }
                else {
                    l = mid + 1;
                }
            }
            
        }
        return {};
        
    }
};
