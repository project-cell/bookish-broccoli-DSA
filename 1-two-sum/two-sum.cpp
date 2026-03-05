class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        // Create a vector of pairs: {value, original_index}
        vector<pair<int, int>> indexedNums(n);
        for (int i = 0; i < n; i++) {
            indexedNums[i] = {nums[i], i};
        }

        // Sort the array based on values
        sort(indexedNums.begin(), indexedNums.end());

        // Two pointers: one at the start, one at the end
        int left = 0;
        int right = n - 1;

        while (left < right) {
            int sum = indexedNums[left].first + indexedNums[right].first;

            if (sum == target) {
                return {indexedNums[left].second, indexedNums[right].second};
            } else if (sum < target) {
                left++; // Sum too small, move left pointer up
            } else {
                right--; // Sum too large, move right pointer down
            }
        }

        return {};
        
    }
};