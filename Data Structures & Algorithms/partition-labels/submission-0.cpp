class Solution {
public:
    vector<int> partitionLabels(string s) {
        int i = 0;
        int n = s.size();
        map<char , int>mp;
        for(int i = 0 ; i < n ; i++) {
            mp[s[i]] = i;
        }
        vector<int> ans;
        while(i < n) {
            int j = i;
            int mx =  j;
            for( ; j <= mx ;j++) {
                mx = max(mx , mp[s[j]]);
            }
            ans.push_back(j - i);
            i = j ;
            
        }
        return ans;
    }
};
