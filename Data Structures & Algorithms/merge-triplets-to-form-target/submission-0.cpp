class Solution {
public:
    static bool  cmp(vector<int>&a1 ,vector<int>&a2) {
        return a1[0] < a2[0];
        return  a1[0] == a2[0] and a1[1] < a2[1];
        return a1[0] == a2[0] and a1[1] == a2[1] and a1[2] < a2[2];
    }
    bool mergeTriplets(vector<vector<int>>& v, vector<int>& t) {
        // sort(v.begin() , v.end() , cmp);
        // auto cur = {INT_MIN , INT_MIN , INT_MIN};
        vector<vector<int>> cur;
        for(auto u : v) {
            bool ok = true;
            for(int i = 0 ;  i < 3 ; i++) {
                if(u[i] > t[i]) {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                cur.push_back(u);
            }
        }
        for(int i = 0 ; i < 3 ; i++) {
            bool ok = false;
            for(auto u : cur) {
               
                for(int j = i ; j <= i ; j++) {
                    if(t[i] == u[j] )ok = true;
                }
            }
            if(!ok) return false;
        }
        return true;
    }
};
