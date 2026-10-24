class NumMatrix {
public:
    vector<vector<int>> pref;
    NumMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        pref = vector<vector<int>>(n ,vector<int>(m , 0));
        for(int i = 0 ; i < n ; i++) {
            
            for(int j = 0 ; j < m ; j++) {
                pref[i][j] = mat[i][j];
                if(i) {
                    pref[i][j] += pref[i - 1][j];
                }
                if(j) {
                    pref[i][j] += pref[i][j -1];
                }
                if(i and j) {
                     pref[i][j] -= pref[i - 1][j - 1];
                }
            }
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        int ans = pref[r2][c2];
        if(c1) ans -= pref[r2][c1- 1];
        if(r1) ans -= pref[r1 - 1][c2];
        if(r1 and c1) ans += pref[r1 - 1][c1 - 1];
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */