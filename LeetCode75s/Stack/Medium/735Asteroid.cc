/*
We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

 

Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
 

Constraints:

2 <= asteroids.length <= 104
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0
*/

#include <iostream>
#include <vector>

using namespace std;

/*
Stack Solution
*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> afterColisions; // stack
        for (int n : asteroids) {
            if (n > 0) {
                afterColisions.emplace_back(n);
            }   
            else if (n < 0) {
                // add right moving asteroids
                if (afterColisions.empty() || afterColisions[afterColisions.size() - 1] < 0) {
                    afterColisions.emplace_back(n);
                    continue;
                }
                // blowup right asteroids until left get's blown up
                while (!afterColisions.empty() && afterColisions[afterColisions.size() - 1] > 0 && afterColisions[afterColisions.size() - 1] < abs(n)) {
                    afterColisions.erase(afterColisions.begin() + afterColisions.size() - 1);
                }
                // same size
                if (!afterColisions.empty() && afterColisions[afterColisions.size() - 1] > 0 && afterColisions[afterColisions.size() - 1] == abs(n))
                    afterColisions.erase(afterColisions.begin() + afterColisions.size() - 1);
                // asteroid not blown up
                else if (afterColisions.empty() || afterColisions[afterColisions.size() - 1] < 0) afterColisions.emplace_back(n);

            }
        }
        return afterColisions;
    }
};

void printVector(vector<int> num) {
    for (int n : num) {
        cout << n << " ";
    }
    cout << endl;
}

int main () {
    vector<int> num1 {5,10,-5};
    vector<int> num2 {8,-8};
    vector<int> num3 {10,2,-5};
    printVector(Solution{}.asteroidCollision(num1));
    printVector(Solution{}.asteroidCollision(num2));
    printVector(Solution{}.asteroidCollision(num3));

    vector<int> num4 {-1, -2};
    vector<int> num5 {10,9,9,8,9,8,-8,-9,-10};
    vector<int> num6 {-1,1,2,-5,1};
    printVector(Solution{}.asteroidCollision(num4));
    printVector(Solution{}.asteroidCollision(num5));
    printVector(Solution{}.asteroidCollision(num6));

}