class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map< int , int> mp;
        for(int i = 0 ;i < nums.size(); i++) {
            int need = target - nums[i];
            if(mp[need] > 0) {
                return {mp[need] - 1, i };
            }
            mp[nums[i]] = i + 1;
        }
        return {1 , 1};
    }
};
