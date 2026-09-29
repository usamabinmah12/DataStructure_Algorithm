class Solution {
public:
    vector<int> plusOne(vector<int>& v) {
       int n = v.size(); 
       vector<int> ans;
       int left = 1;
       for(int i = n - 1 ; i >= 0 ; i--) {
        if(v[i] < 9 or !left) {
            ans.push_back(left + v[i]);
            left = 0;
        }
        else if(left and v[i] == 9) {
            ans.push_back(0);
        }
       }
       if(left) ans.push_back(left);
       reverse(ans.begin() , ans.end());
       return ans;
    }
};
