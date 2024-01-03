// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
// #include "commoncppproblem454.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> umap;  //key中存放a+b的数值，value中存放a+b数值出现的次数
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                umap[nums1[i] + nums2[j]]++;
            }
        }
        int count = 0;
        int sum = 0;
        for (int i = 0; i < nums3.size(); i++) {
            for (int j = 0; j < nums4.size(); j++) {
                sum = 0 - nums3[i] - nums4[j];
                if (umap.find(sum) != umap.end()) {
                    count += umap[sum];
                }
            }
        }
        return count;
    }
};
// @lc code=end

