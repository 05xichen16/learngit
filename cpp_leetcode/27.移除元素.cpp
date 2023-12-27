// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem27.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        for (int fast = 0 ;fast < nums.size(); fast++) {
            if (nums[fast] != val) {
                nums[slow] = nums[fast];
                slow++;
            }
            
        }
        return slow;
        // int size = nums.size();
        // for (int i = 0; i < size; i++) {
        //     if (nums[i] == val) { // 发现需要移除的元素，就将数组集体向前移动一位
        //         for (int j = i + 1; j < size; j++) {
        //             nums[j - 1] = nums[j];
        //         }
        //         i--; // 因为下标i以后的数值都向前移动了一位，所以i也向前移动一位
        //         size--; // 此时数组的大小-1
        //     }
        // }
        // return size;
    }
};
// @lc code=end

