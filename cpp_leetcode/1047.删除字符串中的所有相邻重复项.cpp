// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
// #include "commoncppproblem1047.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (st.empty() || st.top() != s[i]) {
                st.push(s[i]);
            } else st.pop();
        }
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result;
    }
};
// @lc code=end

