class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& v, int k) {
        priority_queue<pair<double , pair<int , int>>> pq;
        
        for(auto u : v)  {
            int a = u[0] , b = u[1];
            double c = -1.0 * sqrt(a * a + b * b);
            auto p = make_pair(a , b);
            auto d = make_pair(c , p);
            pq.push(d);
        }
        vector<vector<int>> ans;
        while(k--) {
            vector<int> cur;
            auto d = pq.top();
            cur.push_back(d.second.first);
            cur.push_back(d.second.second);
            ans.push_back(cur);
            pq.pop();
        }
        return ans;
    }
};
