class Solution {
public:
    bool isNStraightHand(vector<int>& v, int k) {
        priority_queue<int> pq;
        int n = v.size();
        if(n % k != 0) return false;
        map<int , int> mp;
        for(int i = 0 ; i < n ; i++) {
            mp[v[i]]++;
           
        }
        for(auto u : mp) {
            pq.push(-u.first);
        }
        while(!pq.empty()) {
            
            int val = pq.top() * -1;
            if(mp[val] == 0) {
                pq.pop();
                continue;
            }
            for(int i = val ; i < val + k ; i++) {
                if(mp[i] >= 1) {
                    mp[i]--;
                    
                }
                else {
                    cout << val << ' ' << "Usa\n";
                    return false;
                }
            }
            if(mp[val] == 0) {
                pq.pop();
            }


           // cout << '\n';
        }
        return true;
    }
};
