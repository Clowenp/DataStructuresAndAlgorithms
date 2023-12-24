/*
For two strings s and t, we say "t divides s" if and only if s = t + ... + t (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

 

Example 1:

Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"
Example 2:

Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"
Example 3:

Input: str1 = "LEET", str2 = "CODE"
Output: ""
 

Constraints:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of English uppercase letters.

*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        vector<string> possibleSubstrings {""};
        // find all substrings in string 1
        for (size_t i = 1; i <= str1.size(); ++i) {
            string possibleSubstring = str1.substr(0,i);
            // cerr << "error: " << possibleSubstring << endl;
            if (str1.length() % possibleSubstring.length() == 0 
            && str2.length() % possibleSubstring.length() == 0) { //effeciency check
                // cerr << "inside" << endl;
                string s = possibleSubstring;
                bool isPossible1 = false;
                bool isPossible2 = false;
                // check substring of both
                while (s.length() <= str1.length() || s.length() <= str2.length()) {
                    // cerr << "string: " << s << endl;
                    if (s == str1) {
                        isPossible1 = true;
                        // cerr << "possible1" << endl;
                    }
                    if (s == str2) {
                        isPossible2 = true;
                        // cerr << "possible2" << endl;
                    }
                    s += possibleSubstring;
                }

                if (isPossible1 && isPossible2) {
                    possibleSubstrings.emplace_back(possibleSubstring);
                }
            }
        }
        return possibleSubstrings[possibleSubstrings.size() - 1];
    }
};

int main () {
    cout << "#1: " << Solution{}.gcdOfStrings("ABCABC", "ABC") << endl;
    cout << "#2: " << Solution{}.gcdOfStrings("ABABAB", "ABAB") << endl;
    cout << "#3: " << Solution{}.gcdOfStrings("LEET", "CODE") << endl;
}