// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem19.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start

// * Definition for singly-linked list.
struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur_fast = dummyHead;
        ListNode* cur_slow = dummyHead;
        ListNode* temp;
        for (int i = 0; i < n-1; i++) {
            cur_fast = cur_fast->next;
        }
        while (cur_fast->next != NULL) {
            cur_fast = cur_fast->next;
            temp = cur_slow;
            cur_slow = cur_slow->next;

        }
        // 删除操作
        temp->next = cur_slow->next;
        delete cur_slow;

        return dummyHead->next;

    }
};
// @lc code=end

