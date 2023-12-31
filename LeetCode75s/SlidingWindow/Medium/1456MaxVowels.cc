/*
Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.


Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
Example 2:

Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
Example 3:

Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
1 <= k <= s.length
*/


#include <iostream>
#include <string>

using namespace std;

class Solution {
    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        else return false;
    }

    public:
    int maxVowels(string s, int k) {
        int max = 0;

        int currWindowVowels = 0;
        bool isVowelBeginWindow = isVowel(s[0]);
        // 0 to k-1 index
        for (int i = 0; i < k; ++i) {
            if (isVowel(s[i])) ++currWindowVowels;
        }
        max = currWindowVowels;

        for (size_t i = k; i < s.size(); ++i) {
            bool isVowelEndWindow = isVowel(s[i]);
            currWindowVowels = currWindowVowels + static_cast<int>(isVowelEndWindow) - static_cast<int>(isVowelBeginWindow);
            if (currWindowVowels > max) max = currWindowVowels;
            isVowelBeginWindow = isVowel(s[i - k + 1]);
        }

        return max;
    }
};

int main () {
    cout << Solution{}.maxVowels("abciiidef", 3) << endl;
    cout << Solution{}.maxVowels("aeiou", 2) << endl;
    cout << Solution{}.maxVowels("leetcode", 3) << endl;

}