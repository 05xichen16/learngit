// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <iostream>
// #include "commoncppproblem707.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList {
public:
    // 定义链表节点结构体
    struct LinkedNode {
        int val;
        LinkedNode *next;
        LinkedNode() : val(0), next(nullptr) {}
        LinkedNode(int x) : val(x), next(nullptr) {}
        LinkedNode(int x, LinkedNode *next) : val(x), next(next) {}
    };


    MyLinkedList() {
        _dummyHead = new LinkedNode(0);
        _size = 0;
    }
    
    int get(int index) {
        if (index < 0 || index > (_size-1)) {
            return -1;
        } else {
            LinkedNode* cur = _dummyHead;
            for (int i = 0; i <= index; i++) {
                cur = cur->next;
            }
            return cur->val;
        }
        
        

    }
    
    void addAtHead(int val) {
        LinkedNode* head = new LinkedNode(val);
        head->next = _dummyHead->next;
        _dummyHead->next = head;
        _size++;
    }
    
    void addAtTail(int val) {
        LinkedNode* cur = _dummyHead;
        // 计算当前链表最后一个元素的地址
        for (int i = 0; i < _size; i++) {
            cur = cur->next;
        }
        LinkedNode* newnode = new LinkedNode(val);
        cur->next = newnode;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > (_size)) {
            return;
        } else if (index == _size) {
            addAtTail(val);
        } else {
            LinkedNode* cur = _dummyHead;
            for (int i = 0; i < index; i++) {
                cur = cur->next;
            }
            LinkedNode* newnode = new LinkedNode(val);
            newnode->next = cur->next;
            cur->next = newnode;
            _size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index > (_size - 1)) {
            return;
        } else {
            LinkedNode* cur = _dummyHead;
            for (int i = 0; i < index; i++) {
                cur = cur->next;
            }
            LinkedNode* temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
            _size--;
        }
    }

private:
    LinkedNode* _dummyHead;
    int _size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end





