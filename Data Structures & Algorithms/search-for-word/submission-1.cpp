class Solution {
    vector<vector<int>> vis;
    bool dfs(int i , int j , int k , vector<vector<char>>& v, string s) {
        if(k == s.size()) return true;
        if(i < 0 or i >= v.size() or j < 0 or j >= v[0].size()) {
            return false;
        }
        if(vis[i][j] or v[i][j] != s[k]) return false;
        vis[i][j] = 1;
        bool ans = dfs(i + 1 , j , k + 1 , v, s) || dfs(i - 1 , j , k + 1 , v, s) || dfs(i , j + 1 , k + 1 , v , s) || dfs(i  , j - 1, k + 1 , v, s);
        vis[i][j] = 0;
        return ans;
       
    }
public:
    bool exist(vector<vector<char>>& v, string s) {
        bool ans = false;
        vis = vector<vector<int>> (v.size() + 1, vector<int> (v[0].size() +1 , 0));
        for(int i = 0 ;  i < v.size() ; i++) {
            for(int j = 0 ; j < v[0].size() ;j++) {
            //    vis = vector<vector<int>> (v.size() + 1, vector<int> (v[0].size() +1 , 0));
               ans |=  dfs(i , j , 0 , v , s);
            }
        }
        return ans;
    }
};
