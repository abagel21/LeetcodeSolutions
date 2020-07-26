#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
// https://leetcode.com/problems/3sum/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> foundSums;
        cout << nums.size();
        // sort the array (to take advantage of it being sorted to avoid duplicates)
        // start one pointer at the beginning
        // skipping if nums[i] = nums[i - 1] (avoiding i duplicates)
        // start one pointer at i + 1, and one at the end
        // move the two pointers inward, skipping if nums[j] = nums[j-1] (avoiding j duplicates)
        // add every sum that adds to 0
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    vector<int> a;
                    a.push_back(nums[i]);
                    a.push_back(nums[j]);
                    a.push_back(nums[k]);
                    foundSums.push_back(a);
                    j++;
                    while (j < k && nums[j] == nums[j - 1]) j++;
                }
                else if (sum > 0) k--;
                else j++;
            }
        }
        return foundSums;
    }
};

