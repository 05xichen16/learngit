// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem59.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector< vector<int> > arr(n); 
            for(int i = 0; i<arr.size(); i++)
                arr[i].resize(n);
        int startx = 0;  // 每一圈对于数组的起始位置
        int starty = 0;  
        int mid = n / 2;  // 矩阵中间的位置
        int fact_n = n;  // 实际的n
        int count = 1;  // 用于赋值的计数器
        int i, j;
        while (n / 2) {
            i = startx;
            j = starty;
            // 循坏根据每一圈来添加数据到数组中去
            for (i = startx; i < (fact_n - startx - 1); i++) {
                arr[startx][i] = count;
                count++;
            }
            for (j = starty; j < (fact_n - starty - 1); j++) {
                arr[j][i] = count;
                count++;
            }
            for (; i > startx; i--) {
                arr[j][i] = count;
                count++;
            }
            for (; j > starty; j--) {
                arr[j][i] = count;
                count++;
            }
            startx++;
            starty++;
            n -= 2;  // 下一圈处理时n-2
        }
        // 判断n是否为奇数
        if (n % 2) {
            arr[mid][mid] = count;
        }
        return arr;
    }
};
// @lc code=end

