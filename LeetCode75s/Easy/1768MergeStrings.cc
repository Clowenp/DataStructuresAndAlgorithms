/**

You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.
 
Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
Example 2:

Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s
Example 3:

Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q 
merged: a p b q c   d
 

Constraints:
1 <= word1.length, word2.length <= 100
word1 and word2 consist of lowercase English letters.
*/

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s = ""; // final merged string
        size_t index_word = 0;

        while (true) {
            if (index_word == word1.size()) { // base case 1
                s += word2.substr(index_word);
                break;
            } else if (index_word == word2.size()) { // base case 2
                s += word1.substr(index_word);
                break;
            }
            /**
             * Discovery, cannot s += (s1 + s2)
            */
            s += word1[index_word];
            s += word2[index_word]; // recursive case
            ++index_word;
        }
        return s;
    }
};

int main () {
    string s1 = "hellooo";
    string s2 = "WOR";
    cout << Solution{}.mergeAlternately(s1, s2) << endl;;
}