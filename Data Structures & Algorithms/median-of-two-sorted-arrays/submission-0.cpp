class Solution {
public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
        if(v1.size() > v2.size()) {
            swap(v1 , v2);
        }
        int n = v1.size() , m = v2.size();
        int l = 0, r = n;
        while(l <= r) {
            int i = (l + r ) / 2;
            int j = (n + m + 1) / 2 - i;
            int AL = (i == 0)? INT_MIN : v1[i - 1];
            int AR = (i == n)? INT_MAX : v1[i];
            int BL = (j == 0) ? INT_MIN : v2[j - 1];
            int BR = (j == m) ? INT_MAX : v2[j];
            if(AL <= BR and AR >= BL) {
                if((n + m) & 1) {
                    return max(AL , BL);
                }
                else {
                    return (max(AL, BL) + min(AR, BR)) / 2.0;
                }
            }
            else if(AL > BR) r = i -1;
            else l = i + 1;
        }
    }
};
