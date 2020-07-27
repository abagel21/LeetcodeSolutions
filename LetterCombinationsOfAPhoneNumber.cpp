#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) {
            vector<string> x;
            return x;
        }
        PhoneKeys* y = new PhoneKeys();
        vector<string> letComb;
        addKeyCombos(digits, "", 0, letComb, y);
        return letComb;
    }
    class PhoneKeys {
    public:
        unordered_map<int, vector<int>> x;
        PhoneKeys() {
            x[2].push_back('a');
            x[2].push_back('b');
            x[2].push_back('c');
            x[3].push_back('d');
            x[3].push_back('e');
            x[3].push_back('f');
            x[4].push_back('g');
            x[4].push_back('h');
            x[4].push_back('i');
            x[5].push_back('j');
            x[5].push_back('k');
            x[5].push_back('l');
            x[6].push_back('m');
            x[6].push_back('n');
            x[6].push_back('o');
            x[7].push_back('p');
            x[7].push_back('q');
            x[7].push_back('r');
            x[7].push_back('s');

            x[8].push_back('t');
            x[8].push_back('u');
            x[8].push_back('v');

            x[9].push_back('w');
            x[9].push_back('x');
            x[9].push_back('y');
            x[9].push_back('z');
        }
    };
    void addKeyCombos(string digits, string seq, int i, vector<string>& letComb, PhoneKeys* y) {
        if (i == digits.length()) {
            letComb.push_back(seq);
            return;
        }
        for (char a : y->x[digits[i] - '0']) {
            addKeyCombos(digits, seq + a, i + 1, letComb, y);
        }
    }
};