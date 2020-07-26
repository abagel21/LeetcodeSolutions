#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int n = s.length();
        vector<int> last(256, -1);
        int j = 0;
        for (int i = 0; i < n; i++) {
            j = max(j, last[s[i]] + 1);
            maxLength = max(maxLength, i - j + 1);
            last[s[i]] = i;
        }
        return maxLength;
    }
};

