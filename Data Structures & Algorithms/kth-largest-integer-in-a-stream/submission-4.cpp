class KthLargest {
   int idx;
   multiset<int>v;
   int cur;
public:
    KthLargest(int k, vector<int>& nums) {
        idx = k;
        // k--;
        sort(nums.begin() , nums.end());
        while(k and !nums.empty()) {
            v.insert(nums.back());
            nums.pop_back();
            k--;
        }
        if(k > 0) v.insert(INT_MIN);
    }
    
    int add(int val) {
        // if(v.empty()) {
        //     v.insert(val);
        //       return *v.begin();
        // }
        if(idx == 1) {
            v.insert(val);
              return *v.rbegin();
        }
        if( val <=  *v.begin()) {
            return *v.begin();
        }
        else {
            v.erase(v.begin());
            v.insert(val);
            return *v.begin();
        }

    }
};
