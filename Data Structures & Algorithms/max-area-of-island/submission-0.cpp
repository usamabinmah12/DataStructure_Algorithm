class Solution {
    int n , m;
    static const int N = 1e2 + 12;
    int vis[N][N];
public:
    int rec(vector<vector<int>>& matrix ,int i , int j) {
        int cnt = 0;
        if(i < 0 or i >= n or j < 0 or j >= m) return 0;
        if(matrix[i][j] == 0 or vis[i][j] == 1) return 0;
        vis[i][j] = 1;
        cnt++;
        cnt += rec(matrix ,i + 1 , j);
        cnt += rec(matrix ,i - 1 , j);
        cnt += rec(matrix ,i , j+ 1);
        cnt += rec(matrix ,i , j - 1);
        return cnt;

    }
    int maxAreaOfIsland(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        int ans = 0;
        for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            vis[i][j] = 0;
        }
       } 
       for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            if(matrix[i][j] == 1 and vis[i][j] == 0) {
                
                ans = max(ans , rec( matrix , i , j));
            }
        }
       } 
       return ans;
    }
};
