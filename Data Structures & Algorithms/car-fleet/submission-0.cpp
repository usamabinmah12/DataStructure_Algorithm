class Solution {
public:
    int carFleet(int tr, vector<int>& pos, vector<int>& speed) {
        stack< double > st;
        int n = pos.size();
        vector<pair<int , int>> vp;
        for(int  i = 0 ; i < n ; i++) {
            vp.push_back({pos[i] , speed[i]});
        }
        sort(vp.rbegin() , vp.rend());
        for(auto u : vp) {
            int p = u.first , sp = u.second;
            int d = tr - p;
            double t = (1.0 * d )/ sp;
            cout << t << '\n';
            if(!st.empty() and st.top() >= t) {

            }
            else {
                st.push(t);
            }
        }
        return st.size();
    }
};
