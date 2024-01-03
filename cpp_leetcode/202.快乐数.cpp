// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_set>
// #include "commoncppproblem202.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    // 取数值各个位上的单数之和
    int getSum(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> square_set;
        square_set.insert(n);
        int last_size = square_set.size();
        // int sum = getSum(n);
        while(square_set.size() == last_size) {
            n = getSum(n);
            if (n == 1) {
                return true;
            }
            square_set.insert(n);
            last_size++;
        }
        return false;
    }
};
// @lc code=end

