#include <string>
using namespace std;
// https://leetcode.com/problems/zigzag-conversion/
class Solution {
public:
    string convert(string s, int numRows) {
        int slength = s.length();
        if (slength == 0) return "";
        if (numRows == 1) return s;
        //array of strings for each row
        string x[numRows];
        // put in array one by one
        int i = 0;
        int j = 0;
        while (true) {
            while (j < numRows) {
                x[j] += s[i];
                i++;
                j++;
                if (i >= slength) break;
            }
            if (i >= slength) break;
            j -= 2;
            while (j >= 0) {
                x[j] += s[i];
                i++;
                j--;
                if (i >= slength) break;
            }
            if (i >= slength) break;
            j += 2;
        }
        // concatenate result
        string result = "";
        for (int i = 0; i < numRows; i++) {
            result += x[i];
        }
        return result;
    }
};