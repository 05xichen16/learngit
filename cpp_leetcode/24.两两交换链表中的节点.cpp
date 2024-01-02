// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem24.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
 // Definition for singly-linked list.
struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        // ListNode* temp;
        // ListNode* temp2;
        while (cur->next != NULL && cur->next->next != NULL) {
            ListNode* temp = cur->next->next->next;
            ListNode* temp2 = cur->next;
            cur->next = cur->next->next;
            cur->next->next = temp2;
            cur->next->next->next = temp;
            

            cur = cur->next->next;
        }
        return dummyHead->next;

    }
};
// @lc code=end

