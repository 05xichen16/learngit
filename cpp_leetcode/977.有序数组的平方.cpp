// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
// #include "commoncppproblem977.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // for (int fast = 0; fast < nums.size(); fast++) {
        //     nums[fast] = nums[fast] * nums[fast];
        //     // for (int i = fast; i > 0; i--) {
        //     //     if (nums[i] < nums[i - 1]) {
        //     //         int temp = nums[i - 1];
        //     //         nums[i-1] = nums[i];
        //     //         nums[i] = temp;
        //         // }
        //     // }
        // }
        // sort(nums.begin(), nums.end());
        // return nums;
        vector<int> temp_vector(nums.size(), 0);
        int i = 0; 
        int j = nums.size() - 1;
        int k = nums.size() - 1;  // 指向temp_vector存放的位置
        while(k >= 0) {            
            if ((nums[i] * nums[i]) >= (nums[j] * nums[j])) {
                temp_vector[k] = nums[i] * nums[i];
                i++;
            }
            else {
                temp_vector[k] = nums[j] * nums[j];
                j--;
            }
            k--;
        }
        return temp_vector;

    }
};
// @lc code=end

