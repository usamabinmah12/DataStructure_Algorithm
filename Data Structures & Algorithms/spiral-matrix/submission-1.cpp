class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& v) {
        int n  = v.size() , m = v[0].size();
        vector<int> ans;
        int sti = 0 , stj = 0 , edi = n - 1 , edj = m - 1;
        for(int i =0  ; i < n ; i++) {
            for(int j  =0 ;  j < m ; j++) {
                cout << v[i][j] << ' ';
            }
            cout << '\n';
        }
        while(sti <= edi and stj <=edj) {
            for(int j = stj ; j <= edj ; j++) {
                ans.push_back(v[sti][j]);
            }
            for(int k = sti + 1 ; k <= edi ; k++) {
                ans.push_back(v[k][edj]) ;
            }
            for(int j = edj - 1 ; j >= stj ; j--) {
                if(sti == edi) break;
               ans.push_back(v[edi][j]) ;
             }
            for(int k = edi - 1 ; k >= sti + 1 ; k--) {
                if(stj == edj) break;
               ans.push_back(v[k][stj]) ;
            }
            sti++ , stj++ , edi--, edj--;
        }
        return ans;
    }
};
