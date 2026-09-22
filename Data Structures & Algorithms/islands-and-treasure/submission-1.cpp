class Solution {
    int n , m;

public:
    // void rec(vector<vector<int>>& g , int i , int j , int d) {
    //     if(i < 0 or j < 0 or j >= m or i >= n) return;
    //     if(g[i][j] == -1 or g[i][j] < d) return;
    //     g[i][j] = d;
    //     rec(g , i + 1 , j , d + 1);
    //     rec(g , i - 1 , j , d + 1);
    //     rec(g , i , j + 1 , d + 1);
    //     rec(g , i , j - 1 , d + 1);
    //     return;
    // }
    void islandsAndTreasure(vector<vector<int>>& g) {
        const int N = 1e2 +12;
        n = g.size();
        m = g[0].size();
        queue<pair<int , int >> q;
        int d[N][N] , vis[N][N];
         for(int i = 0 ; i < N ; i++) {
            for(int j = 0 ;  j < N; j++) {
                vis[i][j] = 0;
                d[i][j] = 0;
            }
        }
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ;  j < m; j++) {
                if(g[i][j] == 0) {
                    q.push({i , j});
                }
            }
        }
        vector<vector<int>> v = {{1 , 0} , {-1 , 0} , {0 , 1} , {0 , -1}};
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            for(int k = 0 ; k < v.size() ; k++) {
                int i = cur.first + v[k][0] , j = cur.second + v[k][1];
                if((i >= 0 and i < n and j >= 0 and j < m) and !vis[i][j] and d[i][j] < g[i][j] and g[i][j] != -1) {
                    d[i][j] = 1 + d[cur.first][cur.second];
                    vis[i][j] = 1;
                    g[i][j] = d[i][j];
                    q.push({i , j});
                }
            }
        }
    }
};
