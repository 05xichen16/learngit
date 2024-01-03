// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
// #include "commoncppproblem1.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            // 在key中存放数值，在value中存放下标
            int complement = target - nums[i];
            auto iter = map.find(complement);
            if (iter != map.end()) {
                return vector<int>{map[complement], i};
            }
            // map.insert(pair<int, int>(nums[i], i));
            map[nums[i]] = i;
        }
        return vector<int>{};
    }
};
// @lc code=end

