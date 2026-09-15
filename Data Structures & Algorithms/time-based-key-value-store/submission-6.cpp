map<string , int> mp;
vector<pair<int , string>> v[112];
class TimeMap {
public:
    TimeMap() {
        
         mp.clear();
            for(int i = 0 ; i < 112 ; i++) {
                v[i].clear();
            }
           
    }
    
    void set(string key, string value, int timestamp) {
        // map<string , int> mp1;
        // vector<pair<int , string>> v1[112];
        // static int f =0;
        // if(f == 0) {
           
        // }
        
        if(mp.find(key) != mp.end()) {
            int idx = mp[key];
            auto p =  make_pair(timestamp , value);
            v[idx].push_back(p);
        }
        else {
            mp[key] = mp.size() + 1;
            int idx = mp[key];
            auto p =  make_pair(timestamp , value);
            v[idx].push_back(p);
          
        }
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()) return "";
        int idx = mp[key];
        auto &cur = v[idx];
        int l = 0, r = cur.size() - 1 , ans = -1;

        // for(auto u: cur){
        //     cout << u.first << ' '  << u.second<<'\n';
        // }
        while(l <= r) {
            int mid = (l + r) / 2;
            if(cur[mid].first <= timestamp) {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
       if(ans != -1) return cur[ans].second;
       else return "";
    }
};
