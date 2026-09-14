class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int tr) {
        int n = v.size(), m = v[0].size();
       int l =  0 , r = n -1 , val = 0;
       while(l <= r) {
        int mid = (l + r) / 2;
        if(v[mid][0] <= tr and v[mid][m - 1] >= tr) {
            val = mid;
            break;
        }
        else if(v[mid][0] > tr) {
            r = mid - 1;
        }
        else l = mid + 1;
       }
        cout << val << '\n';
       auto cur = v[val];
       l = 0, r = m  - 1;
       while(l <= r) {
        int mid = (l + r) / 2;
        if(v[val][mid] > tr) {
            r = mid - 1;
        }
        else if(tr > v[val][mid]) {
            l = mid + 1;
        }
        else return true;
       }
       return false;
         
    }
};
