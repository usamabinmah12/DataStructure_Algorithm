class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& v, vector<int>& nv) {
        vector<vector<int>> vp;
        int n = v.size();
        int i = 0;
        while(i < n and v[i][1] < nv[0]) {
            vp.push_back({v[i][0] , v[i][1]});
            i++;
        }
        int l = nv[0] , r = nv[1];
        while(i < n and ((l >= v[i][0] and l <= v[i][1]) or (r >= v[i][0] and r <= v[i][1] ) or (l <= v[i][0] and r >= v[i][1]))) {
            l = min(l , v[i][0]);
            r = max(r , v[i][1]);
            ++i;

        }
        vp.push_back({l , r});
        while(i < n ) {
            vp.push_back({v[i][0] , v[i][1]});
            i++;
        }
        return vp;

    }
};
