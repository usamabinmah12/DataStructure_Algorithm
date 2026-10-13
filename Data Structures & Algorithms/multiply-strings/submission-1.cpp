class Solution {
public:
    string multiply(string s1, string s2) {
        if(s2.size() > s1.size()) swap(s1 , s2);
        if(s1[0] == '0' or s2[0] == '0') return "0";
        int n = s1.size() , m = s2.size();
        reverse(s1.begin() , s1.end());
        reverse(s2.begin() , s2.end()); 
        vector<int> ans(n + m + 1, 0);
        for(int i = 0 ; i < m ; i++) {
            int val1 = s2[i] - '0';
            int k = i;
            for(int j = 0 ; j < n ; j++) {
                int val2 = s1[j] - '0';
                int cur = val1 * val2;
                ans[k] += cur;
                if(ans[k] > 9) {
                    ans[k + 1] += ans[k] / 10;
                    ans[k] %= 10;
                }
                k++;
            }
            
        }
        string res = "";
        int i = n + m - 1;
        while(ans[i] == 0) {
            i--;
        }
        for(; i >= 0 ; i--) {
            res += ans[i] + '0';
        }

        // cout << '\n';
        return res;
    }
};
