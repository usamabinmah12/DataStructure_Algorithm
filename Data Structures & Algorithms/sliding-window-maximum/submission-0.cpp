class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        vector<int> ans;
        int n = v.size();

        multiset<int> s;
        for(int i = 0 ; i < k ; i++) {
            s.insert(v[i]);
        }
        ans.push_back(*s.rbegin());
        for(int i = k , j = 0; i < n ; i++, j++) {
            s.erase(s.find(v[j]));
            s.insert(v[i]);
            ans.push_back(*s.rbegin());
        }
        return ans;
    }
};
