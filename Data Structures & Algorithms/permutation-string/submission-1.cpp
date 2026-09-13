class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26, 0) , freq2(26, 0);
        if(s2.size() < s1.size()) return false;
        for(auto u : s1) {
            freq1[u - 'a']++;
        }
        int i = 0;
        while(i < s1.size()) {
            freq2[s2[i++] - 'a']++;
        }
        bool ok  = true;
        for(int j = 0 ; j < 26; j++) {
            if(freq1[j] != freq2[j]) {
                ok = false;
            }
        }
        if(ok) return true;
        for(int p = 0 ; i < s2.size() ; i++ , p++) {
            freq2[s2[p] - 'a']--;
            freq2[s2[i] - 'a']++;
            ok  = true;
            for(int j = 0 ; j < 26; j++) {
                if(freq1[j] != freq2[j]) {
                    ok = false;
                }
            }
            if(ok) return true;
        }
        return false;
     }
};
