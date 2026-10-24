class Solution {
public:
    void merge(int l , int mid , int r , vector<int> &v) {
        int len1 = mid - l + 1 , len2 = r - mid;
        // cout << len1 << ' ' << len2 << '\n';
        vector<int> L(len1) , R(len2);
        for(int i = 0 ; i < len1 ; i++) L[i] = v[i + l];
        for(int i = 0 ; i < len2 ; i++) R[i] = v[i + mid + 1];
        int i = 0 , j = 0, k = l;
        while(i < len1 and j < len2) {
            if(L[i] <= R[j]) {
                v[k++] = L[i++];
            }
            else {
                v[k++] = R[j++];
            }
        }
        while(i < len1) {
             v[k++] = L[i++];
        }
        while(j < len2) {
             v[k++] = R[j++];
        }
        return;

    }
    void mergeSort(int l , int r ,vector<int> &v) {
        if(l >= r) return;
        int mid = (l + r) / 2;
        mergeSort(l , mid , v);
        mergeSort(mid + 1 , r , v);
        merge(l , mid ,r, v);
        return;
        
    }
    vector<int> sortArray(vector<int>& v) {
        int n= v.size();
        int l = 0 , r = n - 1;
        mergeSort(l , r , v);
        return v;
    }
};