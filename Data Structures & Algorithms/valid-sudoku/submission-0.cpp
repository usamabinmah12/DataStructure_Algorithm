class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& c) {
        for(int i = 0 ; i  < 9 ; i += 3) {
            int l = i;
            for(int j = 0; j < 9 ; j += 3) {
                
                // int p = l;
                i = l;
                map <char , int> mp;
                for( ; i < l + 3 ; i++) {

                    for(int k = j ; k < j + 3 ; k++) {
                        if(c[i][k] == '.') continue;
                        mp[c[i][k]]++;
                        // cout << c[i][k] << ' ';
                        if(mp[c[i][k]] >= 2) {
                            return false;
                        }
                    }
                    // cout << '\n';
                    
                }
                // cout << '\n';
                
            }
            i = l;
        }
        vector<char> row[9] , col[9];
        for(int i = 0 ; i <  9 ; i ++) {
            for(int j = 0 ; j < 9 ; j++) {
                if(c[i][j] == '.') continue;
                for(auto u : row[i]) {
                    if(u == c[i][j]) {
                        return false;
                    }
                }
                for(auto u : col[j]) {
                    if(u == c[i][j]) {
                        return false;
                    }
                }
                row[i].push_back(c[i][j]);
                col[j].push_back(c[i][j]);
            }
        }
        return  true;
    }
};
