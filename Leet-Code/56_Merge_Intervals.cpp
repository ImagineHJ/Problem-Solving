class Solution {
public:

    bool comp(vector<int> a, vector<int> b){
        if(a[0]<b[0]) return true;
        return false; 
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        // start 순으로 인터벌을 정렬
        sort(intervals.begin(), intervals.end());


        // 정렬된 인터벌을 순회하면서, 앞과 곂치면 합쳐주기
        for(int i=intervals.size()-2; i>=0; i--){
            while(intervals.size()>i+1 && intervals[i][1]>=intervals[i+1][0]){
                intervals[i][1] = max(intervals[i+1][1], intervals[i][1]);
                intervals.erase(intervals.begin()+i+1);
            }
        }
        return intervals;
    }
};
