#include <vector>
#include <string>
#include <unordered_map>


using std::vector;
using std::string;
using std::unordered_map;

// Runtime: O(mn)
// Runs through every singe string in strs -> O(n)
//  For each string s in strs, it takes O(m) to place into our charCount vector, O(1) [26] to hash charCount
class Solution {
public:
    struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        size_t hashVal = 0;
        for (int n : v) {
            hashVal += (n * 3000);
        }
        return hashVal;
    }
    };

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<vector<int>, vector<string>, VectorHash> map;

        for (string& s: strs) {
            vector<int> charCount(26);
            for (char c : s) {
                ++charCount[c - 'a'];
            }
            map[charCount].emplace_back(std::move(s));
        }

        vector<vector<string>> result;

        for (auto& p : map) {
            result.emplace_back(std::move(p.second));
        }

        return result;
    }
};