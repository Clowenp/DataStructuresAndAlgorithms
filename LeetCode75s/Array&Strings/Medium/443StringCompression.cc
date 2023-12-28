/*
Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.

 

Example 1:

Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
Example 2:

Input: chars = ["a"]
Output: Return 1, and the first character of the input array should be: ["a"]
Explanation: The only group is "a", which remains uncompressed since it's a single character.
Example 3:

Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".
 

Constraints:

1 <= chars.length <= 2000
chars[i] is a lowercase English letter, uppercase English letter, digit, or symbol.
*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:

    int compress(vector<char>& chars) {
        
        int charCounter = 1;
        for (auto it = chars.begin(); it != chars.end();) {
            if (it + 1 == chars.end() || *it != *(it + 1)) {

                if (charCounter != 1) {
                    int emplaceCounter = 1;
                    while (charCounter > 0) {
                        chars.emplace(it + 1, charCounter % 10 + 48);
                        charCounter /= 10;
                        ++emplaceCounter;
                    }
                    it += emplaceCounter;
                    charCounter = 1;
                } else {
                    ++it;
                }
            } else {
                // same character
                chars.erase(it + 1);
                charCounter++;
            }
        }
        return chars.size();
    }
};

void printVector(vector<char>& vec) {
    for (auto c: vec) {
        cout << c << "_";
    }
    cout << endl;
} 

int main () {
    vector<char> a {'a','a','b','b','c','c','c'};
    vector<char> b {'a'};
    vector<char> c {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    cout << Solution{}.compress(a) << endl;
    printVector(a);
    cout << Solution{}.compress(b) << endl;
    printVector(b);
    cout << Solution{}.compress(c) << endl;
    printVector(c);
}