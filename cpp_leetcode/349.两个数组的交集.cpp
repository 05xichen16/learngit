// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_set>
// #include "commoncppproblem349.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set;
        unordered_set<int> num_set(nums1.begin(), nums1.end());
        int num;

        for (int i = 0; i < nums2.size(); i++) {
            num = nums2[i];
            if (num_set.find(num) != num_set.end()) {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};
// @lc code=end

