class Solution {
public:
    int firstMissingPositive(vector<int>& v) {
        int n = v.size();
        for(int i = 0 ;  i < n ; i++) {
            v[i] = v[i] < 0? 0 : v[i];
            // cout << v[i] << ' ';
        }
        // cout << '\n';
        for(int i = 0;  i < n ; i++) {
            long long cur = abs(v[i]) - 1;
            if(cur < 0 or cur >= n) continue;
            if(v[cur] < 0) {

            }
            else if( v[cur] == 0) {
                v[cur] = INT_MIN;
            }
            else if(v[cur] > 0) {
                v[cur] = -v[cur];
            }
        }
        for(int i = 0 ; i < n ; i++) {
            if(v[i] >= 0) return i + 1;
        }
        return n + 1;
       
    }
};