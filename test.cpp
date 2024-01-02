
#include <vector>
#include <string>
#include <iostream>


using namespace std;

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

void testMyLinkedList() {
    MyLinkedList linkedList; // 创建 MyLinkedList 实例

    // 添加节点测试
    linkedList.addAtHead(5);
    linkedList.addAtTail(10);
    linkedList.addAtIndex(1, 7);

    // 获取节点值测试
    std::cout << "Value at index 0: " << linkedList.get(0) << std::endl; // 预期输出: 5
    std::cout << "Value at index 1: " << linkedList.get(1) << std::endl; // 预期输出: 7
    std::cout << "Value at index 2: " << linkedList.get(2) << std::endl; // 预期输出: 10

    // 删除节点测试
    linkedList.deleteAtIndex(1);
    std::cout << "After deleting index 1:" << std::endl;
    std::cout << "Value at index 0: " << linkedList.get(0) << std::endl; // 预期输出: 5
    std::cout << "Value at index 1: " << linkedList.get(1) << std::endl; // 预期输出: 10

    // 添加节点测试（在索引为0处添加）
    linkedList.addAtIndex(0, 2);
    std::cout << "After adding at index 0:" << std::endl;
    std::cout << "Value at index 0: " << linkedList.get(0) << std::endl; // 预期输出: 2
    std::cout << "Value at index 1: " << linkedList.get(1) << std::endl; // 预期输出: 5
    std::cout << "Value at index 2: " << linkedList.get(2) << std::endl; // 预期输出: 10
}

int main() {
    testMyLinkedList(); // 执行测试
    return 0;
}