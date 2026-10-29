class Solution {
public:
    string reorganizeString(string s) {
        map<char ,int > mp;
        for(auto u : s) {
            mp[u]++;
        }
        priority_queue<pair<int , int>> pq;
        for(auto u : mp) {
            pq.push({u.second, u.first});
        }
        string ans = "";
        while(pq.size() >= 2) {
            auto p1 = pq.top();
            pq.pop();
            auto p2 = pq.top();
            pq.pop();
            ans += p1.second;
            ans += p2.second;
            if(p1.first - 1 == 0) {

            }
            else {
                pq.push({p1.first - 1 , p1.second});
            }
            if(p2.first - 1 == 0) {

            }
            else {
                pq.push({p2.first - 1 , p2.second});
            }
        }
        if(!pq.empty() and pq.top().first > 1) ans = "";
        if(!pq.empty() and pq.top().first == 1) ans += pq.top().second;
        return ans;
    }
};