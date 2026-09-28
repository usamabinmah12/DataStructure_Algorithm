class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        vector<vector<int>> v;
        int n = mat.size();
        for(int j = 0 ; j < n ; j++) {
            vector<int> cur;
            for(int i = n -1 ; i >= 0 ; i--) {
                cur.push_back(mat[i][j]);
            }
            v.push_back(cur);
        }
        mat = v;
        // for(int i =0 ; i < n  ; i ++) {
        //     for(int j = 0 ; j < n ; j++) {
        //         mat[i][j] = 
        //     }
        // }
    }
};
