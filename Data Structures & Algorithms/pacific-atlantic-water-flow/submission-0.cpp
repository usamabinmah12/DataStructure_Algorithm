class Solution {
    int n , m;
    static const int N = 1e2 + 12;
    map<pair < int , int> , int>pac , atl;
    vector<vector<int>> g;
    void dfs(int i , int j ,int  prev ,map<pair < int , int> , int> &visit) {
        if(i < 0  or i >= n or j < 0 or j >= m) return;
        auto p = make_pair(i , j);
        int current = g[i][j];
        if(current < prev or visit[p]) return;
        visit[p] = 1;
        dfs(i + 1 , j , current , visit);
        dfs(i - 1 , j , current , visit);
         
        dfs(i  , j + 1 , current , visit);
        dfs(i  , j - 1 , current , visit);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& gp) {
        g = gp;
        n = g.size() , m = g[0].size();
        // pac.assign(n , vector<int> (m , 0));
        // atl.assign(n , vector<int> (m , 0));
        for(int i = 0 ; i < n ;  i++) {
            dfs(i , 0 , g[i][0] , pac);
            dfs(n - i  - 1 , m - 1 , g[n - i - 1][m - 1] , atl);
        }
        for(int j = 0 ; j < m ;  j++) {
            dfs(0 , j , g[0][j] , pac);
            dfs(n - 1 , m - 1 - j , g[n - 1][m - 1 - j] , atl);
        }
        vector<vector<int>> ans;
        for(int i = 0 ; i < n ; i++) {
            for(int j =0 ;  j < m ; j++) {
                auto p = make_pair(i , j);
                vector<int> cur;
                if(pac[p] and atl[p]) {
                   cur.push_back(i);
                   cur.push_back(j);
                   
                    ans.push_back(cur);
                }
            }
        }
        
        return ans;
        
    }
};
