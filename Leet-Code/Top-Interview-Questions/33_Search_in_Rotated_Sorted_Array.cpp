class Solution {
public:
    // do binary search to find the pivot
    int find_end(vector<int>& nums){
        int start, end, mid;
        start = 0; end = nums.size()-1;
        while(start<=end){
            mid = (start+end)/2;
            if(mid==nums.size()-1) return nums.size()-1;
            if(nums[mid]>nums[mid+1]) return mid;
            if(nums[start]>nums[mid]) end = mid -1;
            else start = mid+1;
        }
        return nums.size()-1;
    }
    int binary_search(vector<int>& nums, int start, int end, int target){
        int mid;
        while(start<=end){
            mid = (start+end)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]<target) start = mid+1;
            else end = mid-1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int end = find_end(nums);
        cout<<end;
        if(nums[0]<=target && target<=nums[end]) return binary_search(nums, 0, end, target);
        else return binary_search(nums, end+1, nums.size()-1, target);
    }
};
