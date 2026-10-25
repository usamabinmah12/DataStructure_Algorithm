class Solution {
public:
    bool satisfied(int sum ,vector<int>& v, int k ) {
        long long cnt = 1, cur_sum = 0;
        
        for(long long i = 0 ; i < v.size() ; i++) {
            if(cur_sum + v[i] <= sum) {
                cur_sum += v[i];
            }
            else if(v[i] > sum) return false;
            else {
                cnt++;
                cur_sum = v[i];
            }
        }
        return cnt <= k;
    }
    int splitArray(vector<int>& v, int k) {
        long long l = 0 , r = accumulate(v.begin() , v.end() , 0LL);
        while(l<= r) {
            long long mid = (l + r) / 2;
            if(satisfied(mid , v , k)) {
                r = mid  -1;
            }
            else l = mid + 1;
        }
        return l;
    }
};