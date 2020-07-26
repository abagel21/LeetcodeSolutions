#include <string>
using namespace std;
// https://leetcode.com/problems/longest-palindromic-substring/
class Solution {
public:
    string longestPalindrome(string s) {
        // call both odd and even
        // for each element
        // try expanding two pointers outwards and comparing until not true
        // store palindrome if longest
        // find the next possible location of a palindrome center (hard part) by determining a palindromic suffix of the current 
        // palindrome that extends to the edge of the current palindrome
        // using a 2*n + 1 array to deal with both even and odd palindromes
        int i(0);
        int x[s.length() * 2 + 1];
        while (i < s.length() * 2 + 1) {
            // cout<<"running while loop "<<i<<" and "<<s[i/2]<<"\n";
            int j = i / 2;
            int k = (i - 1) / 2;
            while (j < s.length() && k >= 0) {
                // cout<<"k="<<s[k]<<" j="<<s[j]<<"\n";
                if (s[j] != s[k]) {
                    break;
                }
                j++;
                k--;
            }
            // adjust j and k because they go past the palindrome
            if (j > 0) j--;
            k++;
            x[i] = (j - k) + 1;
            // find next possible location of a palindrome
            int diff = x[i];
            if (x[i] > 1) {
                for (int n = i + 1; n <= i + diff; n++) {
                    // cout<<"n="<<n<<" opposite="<<(i - (n - i))<<" diff="<<diff<<"\n";
                    // if the left hand palindrome isn't a prefix, then it cannot extend past the current palindrome
                    if (x[i - (n - i)] < diff) x[n] = x[i - (n - i)];
                    // if it is a prefix
                    else if (x[i - (n - i)] == diff) {
                        // check if the rhs palindrome is a suffix of the overall string
                        if (x[i - (n - i)] / 2 + n >= s.length() * 2) x[n] = x[i - (n - i)];
                        // otherwise, check if it is a longer palindrome
                        else {
                            i = n - 1;
                            break;
                        }
                    }
                }
            }
            i++;
            // cout<<"\n";
        }
        // at this point the x array of palindrome lengths is complete
        // so scan through it to find largest index
        int max = 0;
        for (int l = 0; l < s.length() * 2 + 1; l++) {
            if (x[l] > x[max]) max = l;
            // cout<<x[l]<<" ";
        }
        if (x[max] == 1) {
            string str(1, s[max / 2]);
            return str;
        }
        // cout<<"\n";
        string pal = "";
        // scan string to return that palindrome
        if (max % 2 == 1) {
            int newdiff = x[max] / 2;
            max = max / 2;
            for (int l = max - newdiff; l <= max + newdiff; l++) {
                pal += s[l];
            }
        }
        else {
            int o = max / 2;
            int p = max / 2 - 1;
            while (o - p < x[max]) {
                o++;
                p--;
            }
            o--;
            p++;
            for (int r = p; r <= o; r++) {
                pal += s[r];
            }
        }
        return pal;
    }
};