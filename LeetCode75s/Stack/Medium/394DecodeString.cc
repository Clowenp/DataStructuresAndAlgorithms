/*
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.

 

Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
 

Constraints:

1 <= s.length <= 30
s consists of lowercase English letters, digits, and square brackets '[]'.
s is guaranteed to be a valid input.
All the integers in s are in the range [1, 300].
*/

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class SolutionFail {

    // returns index of first digit of number
    bool findNumberInString (vector<int>& indexAndNum, string s) {
        // find integer and index
        istringstream iss {s};
        int n = 0;
        int index = 0; // the index of the first char character
        while (!(iss >> n) && !iss.eof()) {
            ++index;
            iss.clear();
            iss.ignore();
        }

        if (n == 0) return false;

        indexAndNum.emplace_back(index);
        indexAndNum.emplace_back(n);
        return true;
    }

    // n MUST be greater than 0
    int numberOfDigits (int n) {
        int digits = 0;
        while (n > 0) {
            ++digits;
            n /= 10;
        }
        return digits;
    }

    int charsInBrackets (string& s, int startIndex) {
        int counter = 0;
        while (s[startIndex] != ']' && counter < 10) {
            ++counter;
            ++startIndex;
        }
        return counter;
    }

    string processString(int k, string s) {
        string final;
        for (int i = 0; i < k; ++i) {
            final += s;
        }
        return final;
    }
public:
    string decodeString(string s) {



        // find number of digits of 
        vector<int> indexAndNum;
        if (!findNumberInString(indexAndNum, s)) return s; // base case / stopping condition

        // number of digits in num
        int digits = numberOfDigits(indexAndNum[1]);

        // number of characters inside []
        int numCharsInBrackets = charsInBrackets(s, indexAndNum[0] + digits + 1);

        string final = processString(indexAndNum[1], s.substr(indexAndNum[0] + digits + 1, numCharsInBrackets));
        if (indexAndNum[0] - 1 > 0) final = s.substr(0, indexAndNum[0] - 1) + final; 
        if (static_cast<int>(s.size()) > indexAndNum[0] + digits + numCharsInBrackets) final += s.substr(indexAndNum[0] + digits + numCharsInBrackets + 2);
        return decodeString(final);
    }
};

class Solution {

    string duplicateString(int k, string s) {
        string newS;
        for (int i = 0; i < k; ++i) {
            newS += s;
        }
        return newS;
    }
    void printStack (vector<int>& s) {
        for (int n : s) {
            cout << n << " ";
        }
        cout << endl;
    }
public:
    string decodeString(string s) {
        vector<int> stack; // holds k ( number of duplicate of substrings)
        
        string noNumS;

        // remove all the numbers
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0') {
                int num = s[i] - '0';
                ++i;
                while (s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0') {
                    num = 10 * num + (s[i] - '0');
                    ++i;
                }
                stack.emplace_back(num);
            }
            noNumS += s[i];
        }

        // printStack(stack);
        // cout << "noNumS: " << noNumS << endl;

        // start replacing each [string] with k x string
        int index = noNumS.size() - 1;
        for (int i = static_cast<int>(stack.size()) - 1; i >= 0; --i) {
            while (noNumS[index] != '[') {
                --index;
            }
            int endIndex = index;
            while (noNumS[endIndex] != ']') {
                ++endIndex;
            }
            noNumS = noNumS.substr(0, index) + duplicateString(stack[i], noNumS.substr(index + 1, endIndex - index - 1)) + (static_cast<int>(noNumS.size()) > endIndex + 1 ? noNumS.substr(endIndex + 1) : "");
        }
        return noNumS;
    }
};

int main () {
    cout << Solution{}.decodeString("100[leetcode]") << endl;
    cout << Solution{}.decodeString("3[a]2[bc]") << endl;
    cout << Solution{}.decodeString("3[a2[c]]") << endl;
    cout << Solution{}.decodeString("2[abc]3[cd]ef") << endl;
}