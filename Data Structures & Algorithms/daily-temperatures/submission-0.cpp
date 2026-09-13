class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& v) {
        int n = v.size();
        stack<pair<int , int>>st;
        vector<int> ans(n , 0);
        for(int i = 0 ; i < n ; i++) {
            if(st.empty()) {
                st.push({v[i] , i});
            }
            else {
                while(!st.empty() and st.top().first < v[i]) {
                    ans[st.top().second] = i - st.top().second;
                    st.pop();
                }
                st.push({v[i] , i});
            }
        }
        return ans;
    }
};
