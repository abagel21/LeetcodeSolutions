#include <vector>
using namespace std;
// https://leetcode.com/problems/container-with-most-water/
class Solution {
public:
    int maxArea(vector<int>& height) {
        // essentially, maximize the area of height * i -j
        // brute force, n^2 time
        // secondary thought, sort nlgn and maintain hash table of original positions n and then compare, but doesn't necessarily rule out n^2
        // third thought, 2 pointers move inward (maximize width first) and move the pointer of smaller height inward, maintaining max height.
        int i = 0;
        int j = height.size() - 1;
        int maxarea = 0;
        while (i < j) {
            bool ibigger = height[i] > height[j];
            int currarea = (j - i) * (ibigger ? height[j] : height[i]);
            if (currarea > maxarea) maxarea = currarea;
            if (ibigger) j--;
            else {
                i++;
            }
        }
        return maxarea;
    }
};