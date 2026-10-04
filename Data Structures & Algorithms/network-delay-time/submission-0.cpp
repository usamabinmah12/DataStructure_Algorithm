class Solution {
    vector<vector<pair<int , int>>> gp;
    vector<int> dist;
    void bfs(int root) {
        queue<int> q;
        q.push(root);
        while(!q.empty()) {
            auto par = q.front();
            q.pop();
            for(auto v : gp[par]) {
                int ch = v.first , w = v.second;
                cout << ch << '\n';
                if(dist[ch] > dist[par] + w) {
                    q.push(ch);
                    dist[ch] = dist[par] + w;
                }
            }
        }
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        gp = vector<vector<pair<int, int>>>(n + 1);
        for(int i = 0 ; i < times.size() ; i++) {
            int u = times[i][0] , v = times[i][1] , w = times[i][2];
            gp[u].push_back({v , w});
        }
        dist = vector<int> (n + 1 , INT_MAX);
        dist[k] = 0;
        bfs(k);
        int ans = 0;
        for(int i = 1 ; i <= n ; i++) {
            ans = max(ans , dist[i]);
        }
        ans = (ans == INT_MAX) ? -1 : ans;
        return ans;
    }
};
