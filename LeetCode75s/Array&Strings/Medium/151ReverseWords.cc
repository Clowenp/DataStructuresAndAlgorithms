/*
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Constraints:

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.
*/

#include <iostream>
#include <sstream>
#include <string>

using std::string;
using std::istringstream;
using std::cout;
using std::endl;

class Solution {
public:
    string reverseWords(string s) {
        istringstream iss {s};
        string newS;
        string word;
        bool start = true;
        while (iss >> word) {
            if (start) newS = word;
            else newS = word + " " + newS;
            start = false;
        }
        return newS;
    }
};

// leading/trailing space
// multiple middle spaces
// 1 word
// even words
// odd words

int main () {
    cout << Solution{}.reverseWords("the sky is blue") << endl;
    cout << Solution{}.reverseWords("  hello world  ") << endl;
    cout << Solution{}.reverseWords("a good   example") << endl;
}