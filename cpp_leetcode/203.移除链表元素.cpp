// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem203.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* virtual_node = new ListNode(0);  // 设置一个虚拟头节点
        virtual_node->next = head;
        ListNode* cur = virtual_node;
        while (cur != NULL && cur->next != NULL) {
            if (cur->next->val == val) {
                ListNode* temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            } else {
                cur = cur->next;
            }
        }
        return virtual_node->next;
        // // 删除头节点
        // while (head != NULL && head->val == val) {
        //     ListNode* temp = head;  // 存储头节点
        //     head = head->next;
        //     delete temp; 
        // }

        // // 删除非头节点
        // ListNode* cur = head;
        // while (cur != NULL && cur->next != NULL) {
        //     if (cur->next->val == val) {
        //         ListNode* temp = cur->next;
        //         cur->next = cur->next->next; 
        //         delete temp;
        //     } else {
        //         cur = cur->next;
        //     }
        // }
        // return head;
    }
};
// @lc code=end

