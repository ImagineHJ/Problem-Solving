// non-binary solution O(N)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int prev=0;
        int cnt;
        for(int i=0; i<arr.size(); i++){
            cnt = arr[i]-prev-1;
            if(cnt>=k) return prev+k;
            k -= cnt;
            prev = arr[i];
        }
        return arr[arr.size()-1]+k;
    }
};

// binary solution O(logN)
class Solution {
public:
    int binarySearch(vector<int>& arr, int k, int s, int e){
        // if the missing number is larger than the last element
        int full = (arr[e]-arr[s])-(e-s);
        if(full<k) return arr[e]+(k-full);

        // no more steps to go
        if(s+1==e) return arr[s]+k;

        int m = (s+e)/2;
        int left = (arr[m]-arr[s])-(m-s); //num of missing ints in left side
        // missing num is in left side
        if(left>=k) return binarySearch(arr, k, s, m);
        // missing num is in right side
        return binarySearch(arr, k-left, m, e);
    }
    
    int findKthPositive(vector<int>& arr, int k) {
        int cnt = arr[0]-1;
        if(cnt>=k) return k;
        k -= cnt;
        return binarySearch(arr, k, 0, arr.size()-1);
    }
};
