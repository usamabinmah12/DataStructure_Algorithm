class Solution {
public:
    int lastStoneWeight(vector<int>& v) {
        priority_queue<int> pq;
        for(int i = 0 ; i < v.size() ; i++) {
            pq.push(v[i]);
        }
        while(pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            pq.push(a - b);
        }
        return pq.top();

    }
};
