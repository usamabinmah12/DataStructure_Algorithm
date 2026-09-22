class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        int vis[n][m] , d[n][m];
        // for(int i = 0)
        queue<pair<int , int>> q;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ;  j < m ; j++) {
                vis[i][j] = 0;
                d[i][j] = 0;
                if(g[i][j] == 2) {
                    q.push({i , j});
                }
            }
        }
        vector<vector<int>> v = {{1, 0} , {-1, 0} , {0 , 1} , {0 , -1}};
        int ans = 0;
        
        while(!q.empty()) {
            // ++ans;
            auto cur = q.front();
            q.pop();
            for(int k = 0 ; k < 4 ; k++) {
                int i = cur.first + v[k][0] , j = cur.second + v[k][1];
                if((i >= 0 and i < n and j >= 0 and j < m) and !vis[i][j] and g[i][j] == 1) {
                    vis[i][j] = 1;
                    d[i][j] = 1 + d[cur.first][cur.second];
                    ans = max(ans , d[i][j]);
                    q.push({i , j});
                }
            }
        }
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ;  j< m ; j++) {
                
                if(g[i][j] == 1 and !vis[i][j]) {
                   return -1;
                }
            }
        }
        return ans;
    }
};
