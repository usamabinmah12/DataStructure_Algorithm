class Solution {
public:
    int numRescueBoats(vector<int>& v, int limit) {
      sort(v.begin() , v.end()); 
      int cnt = 0; 
      int i =0, j = v.size() -1;
      while(i <= j) {
        int tmp = v[j];
        j--;
        if(tmp + v[i] <= limit) {
            i++;
        }
        cnt++;
      }
      return cnt;
      
    }
};