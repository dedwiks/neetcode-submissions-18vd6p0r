class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0; 
        int r = nums.size() - 1;

        while (l < r) {
            int m = l + (r - l)/2;

            if (nums[m] > nums[r]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
            int pivot = r; // at the point at which l and converge

            int result = binarysearch(nums, target, 0, pivot - 1);

            if (result != -1) {
                return result;
            }
            return binarysearch(nums, target, pivot, nums.size() - 1);
        
    }

    int binarysearch(vector<int>& nums, int target, int left, int right) {
        while (left <= right) {
            int mid = left + (right - left)/2;

            if (target == nums[mid]) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};
