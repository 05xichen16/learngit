// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem344.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        char temp;
        while (left < right) {
            temp = s[right];
            s[right] = s[left];
            s[left] = temp;
            left++;
            right--;
        }
        // return s;
    }
};
// @lc code=end

