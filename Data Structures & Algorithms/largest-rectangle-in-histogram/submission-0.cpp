class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        int mx = 0;
        stack<pair<int , int>> st;
        int n = v.size();
        for(int i = 0 ; i < n ; i++) {
            int start = i;
            while(!st.empty() and st.top().second > v[i]) {
                auto p = st.top();
                int idx = p.first , val = p.second;
                st.pop();
                mx = max(mx , val * (i - idx));
                start = idx;
            }
            st.push({start , v[i]});
        }
        vector<pair<int , int>> vp;
        while(!st.empty()) {
            auto p = st.top();
            vp.push_back(p);
            st.pop();

        }
        reverse(vp.begin() , vp.end());
        for(int i = 0 ; i < vp.size() ; i++) {
             mx = max(mx , vp[i].second * (n - vp[i].first));
        }
        return mx;
    }
};
