#include <vector>
#include <algorithm>
using namespace std;
// https://leetcode.com/problems/3sum-closest/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closesum = INT_MAX - abs(target) - 1;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1, k = nums.size() - 1, sum;
            while (j < k) {
                sum = nums[i] + nums[j] + nums[k];
                if (abs(target - sum) < abs(target - closesum)) closesum = sum;
                if (sum < target) j++;
                else if (sum > target) k--;
                else {
                    return sum;
                }
            }
        }
        return closesum;
    }
};

