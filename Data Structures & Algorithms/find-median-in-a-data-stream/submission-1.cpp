class MedianFinder {
    priority_queue<int>pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    void clear() {
        while(!pq1.empty()) pq1.pop();
        while(!pq2.empty()) pq2.pop();
    }
public:
    MedianFinder() {
        // clear();
    }
    
    void addNum(int num) {
        if(pq2.size() < pq1.size()) {
            pq2.push(num);
        }
        else {
            pq1.push(num);
        }
        while(!pq2.empty() and !pq1.empty() and pq2.top() < pq1.top()) {
            auto p1 = pq1.top();
            pq1.pop();
            auto p2 = pq2.top();
            pq2.pop();
            pq2.push(p1);
            pq1.push(p2);
            // cout << p1 << ' ' << p2 << '\n';
            // cout << pq1.top() << ' ' << pq2.top() << '\n';
        }
    }
    
    double findMedian() {
        if(pq1.empty() and pq2.empty()) return 0.0;
        if(pq1.size() == pq2.size()) {
            auto p1 = pq1.top();
            // cout << pq1.top() << ' ' << pq2.top() << '\n';
            p1 += pq2.top();
            return (p1 * 1.0) / 2;
        }
        if(pq1.size() > pq2.size()) {
            return pq1.top();
        }
        else return pq2.top();
    }
};
