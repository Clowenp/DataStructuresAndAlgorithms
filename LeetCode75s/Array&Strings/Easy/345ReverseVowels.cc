/*
Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 

Example 1:

Input: s = "hello"
Output: "holle"
Example 2:

Input: s = "leetcode"
Output: "leotcede"
 

Constraints:

1 <= s.length <= 3 * 105
s consist of printable ASCII characters.
*/

/**
 * Solution 1: O(2n)
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution1 {
public:
    string reverseVowels(string s) {
        vector<char> vowels;
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'
            || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                vowels.emplace_back(s[i]);
                s[i] = '\0';
            }
        }
        size_t vowelIndex = vowels.size();
        bool nostop = true;
        if (vowelIndex == 0) {
            nostop = false;
        }
        --vowelIndex;
        for (size_t i = 0; nostop && i < s.size(); ++i) {
            if (s[i] == '\0') {
                s[i] = vowels[vowelIndex];
                --vowelIndex;
            }
        }
        return s;
    }
};

/**
 * Solution 2: O(n) => Two Pointer
*/

class Solution {
public:
    string reverseVowels(string s) {
        int startIndex = 0;
        int endIndex = s.size() - 1;
        while (startIndex < endIndex) {
            if (!(s[startIndex] == 'a' || s[startIndex] == 'e' || 
            s[startIndex] == 'i' || s[startIndex] == 'o' || s[startIndex] == 'u' ||
            s[startIndex] == 'a' - 32 || s[startIndex] == 'e' - 32 || 
            s[startIndex] == 'i' - 32 || s[startIndex] == 'o' -32 || s[startIndex] == 'u' - 32)) {
                ++startIndex;
            } else if (!(s[endIndex] == 'a' || s[endIndex] == 'e' || 
            s[endIndex] == 'i' || s[endIndex] == 'o' || s[endIndex] == 'u' ||
            s[endIndex] == 'a' - 32 || s[endIndex] == 'e' - 32 || 
            s[endIndex] == 'i' - 32 || s[endIndex] == 'o' -32 || s[endIndex] == 'u' - 32)) {
                --endIndex;
            } else {
                swap(s[startIndex], s[endIndex]);
                ++startIndex;
                --endIndex;
            }
        }
        return s;
    }
};

int main () {
    cout << Solution{}.reverseVowels("leetcode") << endl;
}