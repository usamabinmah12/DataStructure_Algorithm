class Solution {
public:
    int findMin(vector<int> &v) {
        int n = v.size();
        int l = 0 , r = v.size() -1;
        
        while(l <=r ) {
            int mid = l + (r - l) / 2;
            if(v[mid] >= v[0]) {
                l = mid + 1;

            }
            else r = mid - 1;
        }
        if(r == n -1) return v[0];
        if(v[0] < v[r + 1]) return v[0];
        else return v[r + 1];
    }
};
