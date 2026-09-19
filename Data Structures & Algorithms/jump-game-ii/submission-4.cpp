class Solution {
public:
    int jump(vector<int>& v) {
        int n = v.size();
        int l = 0, r = 0 , cnt = 0;
        while(r < n - 1) {
            int range = 0;
            for(int i = l ; i <= r ; i++) {
                range = max(range , i + v[i]);
            }
            l = r + 1;
            r = range;
            cnt++;
        }
        return cnt;
    }
};
