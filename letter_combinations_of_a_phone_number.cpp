#include "common.h"


/**
* Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
* A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return {};
        }
        unordered_map<char, string> map;
        map.insert(make_pair<char, string>('2', "abc"));
        map.insert(make_pair<char, string>('3', "def"));
        map.insert(make_pair<char, string>('4', "ghi"));
        map.insert(make_pair<char, string>('5', "jkl"));
        map.insert(make_pair<char, string>('6', "mno"));
        map.insert(make_pair<char, string>('7', "pqrs"));
        map.insert(make_pair<char, string>('8', "tuv"));
        map.insert(make_pair<char, string>('9', "wxyz"));

        vector<string> res;
        string cur;
        letterCombinations(digits, map, res, 0, cur);
        return res;


    }

    void letterCombinations(const string& digits, const unordered_map<char, string>& map, vector<string>& res, int i, string& cur) {

        if (i == digits.size()) {
            res.push_back(cur);
            return;
        }
        const string& letters = map.at(digits[i]);
        for (char letter : letters) {
            cur.push_back(letter);
            letterCombinations(digits, map, res, i + 1, cur);
            cur.pop_back();
        }
    }
};

//int main() {
//    Solution s;
//    s.letterCombinations("23");
//}