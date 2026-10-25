class Solution {
public:
    int findJudge(int n, vector<vector<int>>& t) {
        vector<int> indeg(n + 1 , 0) , outdeg(n + 1 , 0);
        for(int i = 0 ; i < t.size() ; i++) {
            auto u = t[i][0] , v = t[i][1];
            outdeg[u]++, indeg[v]++;
        }
        for(int i = 1 ;i <= n ; i++) {
            if(outdeg[i] == 0 and indeg[i] == n - 1) return i;
        }
        return -1;
    }
};