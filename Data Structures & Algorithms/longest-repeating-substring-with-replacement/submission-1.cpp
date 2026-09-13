class Solution {
public:
    int characterReplacement(string s, int k) {
        int j = 0 , ans = 0;
        int n = s.size();
        int l = 1 , r = n;
        while(l <= r) {
            int mid = (l + r ) / 2;
            vector<int> freq(26 , 0);
            int mx = 0;
            bool ok = false;
            for(int i = 0 ; i  < mid ; i++) {
                freq[s[i] - 'A']++;
                mx = max(mx,freq[s[i] - 'A']);
            }
            if(mid - mx <= k) {
               
                ans = mid;
                l = mid + 1;
                continue;
            }
        
            for(int i = mid , p = 0 ; i < n  ; i++ ,  p++) {
                freq[s[p] - 'A' ]--;
                freq[s[i] - 'A']++;
                for(int j = 0 ; j < 26 ; j++) {
                    if(mid - freq[j] <= k) {
                        //  if(mid == 5) {
                        //       cout << i << "\n";
                        //  }
                        ok = true;
                        break;
                    }
                }
                if(ok) break;
            }
            if(ok) {ans = mid ; l = mid + 1; }
            else r = mid - 1;
        }
        return ans;
    }
};
