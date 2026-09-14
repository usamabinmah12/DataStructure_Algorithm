class Solution {
public:
    int binarySearch(vector<int>& v,int l , int r , int  t) {
        while(l <= r) {
            int mid = (l + r) / 2;
            if(v[mid] == t) {
                return mid;
            }
            else if(v[mid] < t){
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return -1;
    } 
    int search(vector<int>& v, int t) {
        int n = v.size();
        int i = 0;
        int  j = n -1;
        int l =0 , r = 0;
        while(i <= j) {
            int mid = (i + j) / 2;
            if(v[0] <= v[mid]) {
                r = mid;
                i = mid  + 1;


            }
            else j = mid - 1;
        }
       // cout << r << '\n';
        if(r == n - 1) {
            int ans = binarySearch(v , l , r , t);
            return ans;
        }
        else {
            if(t >= v[0] and t <= v[r]) {
                int ans = binarySearch(v , l , r , t);
                return ans;
            }
            else {
                int ans = binarySearch(v , r + 1 , n - 1 , t);
                return ans;
            }
        }
    }
};