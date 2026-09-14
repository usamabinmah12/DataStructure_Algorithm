class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        set<int> s(v.begin() , v.end());
        vector<int> a(s.begin() , s.end());
        int n = a.size();
        int j = 1 , ans = 0;
        for(int i = 0 ;  i< n ; i++) {
            j = max(j , i + 1);
            while(j < n and a[j] - a[j - 1] == 1) {
                j++;
            }
            ans = max(ans , j - i);
            i = j - 1;
        }
        return ans;
    }
};
