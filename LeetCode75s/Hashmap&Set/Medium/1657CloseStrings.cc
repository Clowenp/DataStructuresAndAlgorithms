/*
Two strings are considered close if you can attain one from the other using the following operations:

Operation 1: Swap any two existing characters.
For example, abcde -> aecdb
Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
You can use the operations on either string as many times as necessary.

Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.

 

Example 1:

Input: word1 = "abc", word2 = "bca"
Output: true
Explanation: You can attain word2 from word1 in 2 operations.
Apply Operation 1: "abc" -> "acb"
Apply Operation 1: "acb" -> "bca"
Example 2:

Input: word1 = "a", word2 = "aa"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.
Example 3:

Input: word1 = "cabbba", word2 = "abbccc"
Output: true
Explanation: You can attain word2 from word1 in 3 operations.
Apply Operation 1: "cabbba" -> "caabbb"
Apply Operation 2: "caabbb" -> "baaccc"
Apply Operation 2: "baaccc" -> "abbccc"
 

Constraints:

1 <= word1.length, word2.length <= 105
word1 and word2 contain only lowercase English letters.
*/

#include <iostream>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false; // check length
        
        // word1 as [char, occurence ] map
        map<char, int> m1;
        for (char c : word1) {
            if (m1.count(c)) ++m1[c];
            else m1[c] = 1;
        }

        // word1 as [char, occurence ] map
        map<char, int> m2;
        for (char c : word2) {
            if (m2.count(c)) ++m2[c];
            else m2[c] = 1;
        }

        if (m1.size() != m2.size()) return false;

        auto it1 = m1.begin();
        auto it2 = m2.begin();
        unordered_map<int, int> um1;
        unordered_map<int, int> um2;
        for (size_t i = 0; i < m1.size(); ++i) { // check all letters are the same
            if (it1->first != it2->first) return false;
            // add occurences to map [int, int]
            /**
             * Eg. [3,2] means that there are 2 letters exactly 3 times
            */
            ++um1[it1->second];
            ++um2[it2->second];
            ++it1;
            ++it2;
        }

        for (auto& p : um1) { // check same number of occurences
            if (p.second != um2[p.first]) return false;
        }

        return true;
    }
};

int main () {
    cout << Solution{}.closeStrings("abc", "bca") << endl;
    cout << Solution{}.closeStrings("a", "aa") << endl;
    cout << Solution{}.closeStrings("cabbba", "abbccc") << endl;
}

/**
 * Two words are close if:
 *  1) They have the same length
 *  2) They have the same letters
 *  3) They have the same number of occurences for the letters
*/

