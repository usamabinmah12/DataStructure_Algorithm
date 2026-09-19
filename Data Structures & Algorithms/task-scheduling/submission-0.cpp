class Solution {
public:
    int leastInterval(vector<char>& t, int n) {
       map<char , int> mp; 
       for(auto u : t) {
        mp[u]++;
       }
       priority_queue<int> pq;
       for(auto u : mp) {
        pq.push(u.second );
       }
       int time = 1;
       queue<pair<int , int>> q;
       while(!pq.empty() or !q.empty()) {
        if(pq.empty()) {
            time++;
                if(q.front().second <= time) {
                    pq.push(q.front().first);
                    q.pop();
                }
            continue;
        }
        int a = pq.top();
        pq.pop();
        time++;
        --a;
        if(a) {
            q.push(make_pair(a , time + n ));
        }
        if(!q.empty() and q.front().second <= time) {
            pq.push(q.front().first);
            q.pop();
        }
       }
       return time - 1;
    }
};
