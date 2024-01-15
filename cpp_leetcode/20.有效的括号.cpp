// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
// #include "commoncppproblem20.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) {
            return false;
        }
        stack<char> st;
        int size = s.size();
        for (int i = 0; i < size; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else if (s[i] == ')') {
                if (st.empty()) return false;
                else if (st.top() == '(') {
                    st.pop();
                } else return false;
            } else if (s[i] == ']') {
                if (st.empty()) return false;
                else if (st.top() == '[') {
                    st.pop();
                } else return false;
            } else if (s[i] == '}') {
                if (st.empty()) return false;
                else if (st.top() == '{') {
                    st.pop();
                } else return false;
            }
        }
        return st.empty();
    }
};
// @lc code=end

