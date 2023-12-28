// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem209.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT32_MAX;
        int sum = 0;
        int i = 0;
        int sub_length = 0;
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            while (sum >= target) {
                sum -= nums[i];
                sub_length = j - i + 1;
                if (sub_length < result) {
                    result = sub_length;
                }
                i++;
            } 
        }
        if (result == INT32_MAX) {
            return 0;
        }
        else {
            return result;
        }

    }
};
// @lc code=end

