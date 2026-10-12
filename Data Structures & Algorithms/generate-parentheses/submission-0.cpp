class Solution {
    
    void dfs(int i , int j , int n , string cur , vector<string> &ans) {
        if(i == n and j == n) {
            cout << cur << '\n';
            ans.push_back(cur);
            return;
        }
        // if(i == n) {
        //     return;
        // }
    
        if(i + 1 <= n) dfs(i + 1 , j , n , cur + "(" , ans) ;
        if(i > j) {
            dfs(i , j + 1 , n , cur + ")" , ans);
        }
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string > ans;
        dfs(0 , 0 , n , "" , ans);
        cout << ans.size() << '\n';
        return ans;
    }
};
