class Solution {
public:
    bool canJump(vector<int>& v) {
        int n = v.size();
        int range = 0;
        for(int i = 1 ; i < n ; i++) {
            range = max(range , v[i - 1]+ (i - 1));
            if(range < i) return false;
        }
        return true;
    }
};
