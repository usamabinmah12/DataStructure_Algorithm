class Solution {
public:
    vector<int> asteroidCollision(vector<int>& v) {
        int n = v.size();
        stack<pair <int , int>> st1 ,st2;
        for(int i = 0 ; i < n ; i++) {
            if(v[i] > 0) st1.push({v[i] , i});
            else st2.push({v[i] , i});

            while(!st1.empty() and !st2.empty() and st1.top().second < st2.top().second) {
                auto u1 = st1.top();
                auto u2 = st2.top();
                if(u1.first == abs(u2.first)) {
                    st1.pop();
                    st2.pop();
                }
                else if(u1.first < abs(u2.first)) {
                    st1.pop();
                }
                else {
                    st2.pop();
                }
            }
        }
        vector<int> ans ,ans1;
        // while(!st1.empty() and !st2.empty()) {
        //     auto u1 = st1.top();
        //     auto u2 = st2.top();
        //     if(u1.second < u2.second) {
        //         st1.pop();
        //         ans.push_back(u1.first);
        //     }
        //     else {
        //         st2.pop();
        //         ans.push_back(u2.first);
        //     }
        // }
         while(!st2.empty()) {
            auto u1 = st2.top();

             ans.push_back(u1.first);
             st2.pop();
        }
         reverse(ans.begin() , ans.end());
        while(!st1.empty()) {
            auto u1 = st1.top();

             ans1.push_back(u1.first);
             st1.pop();
           
        }
       reverse(ans1.begin() , ans1.end());
        for(auto u : ans1) {
            ans.push_back(u);
        }
        
       return ans ;
        
    }
};