// @before-stub-for-debug-begin
#include <algorithm>
#include <vector>
#include <string>
// #include "commoncppproblem151.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        int fast = 0;
        int slow = 0;
        while (s[fast] == ' ' && s.size() > 0 && fast < s.size()) {
            fast++;
        }
        for (fast; fast < s.size(); fast++) {
            if (fast - 1 > 0 && s[fast] == ' ' && s[fast-1] == ' ') {
                continue;
            } else {
                s[slow] = s[fast];
                slow++;
            }
        }
        if (s[slow - 1] == ' ' && slow - 1 > 0) {
            s.resize(slow - 1);
        } else {
            s.resize(slow);
        }
        
        reverse(s.begin(), s.end());  // 翻转字符串
        int left = 0;
        int right = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                right = i - 1;
                reverse(s.begin() + left, s.begin() + right + 1);
                left = i + 1;
            } 
        }
        right = s.size();
        reverse(s.begin() + left, s.begin() + right);

        return s;
    }
};
// @lc code=end

