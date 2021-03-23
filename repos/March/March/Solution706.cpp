#include "Solution706.h"

Solution706::Solution706() {
    data = new Node[base];
}

void Solution706::put(int key, int value) {
    int bucket = key / 32;
    Node* loc = &data[bucket];
    Node* tmp = loc->next;
    while (tmp != NULL) {
        if (tmp->key == key) {
            tmp->val = value;
            return;
        }
        tmp = tmp->next;
    }
    Node* node = new Node(key, value);
    node->next = loc->next;
    loc->next = node;
}

int Solution706::get(int key) {
    int bucket = key / 32;
    Node* loc = &data[bucket];
    while (loc->next != NULL) {
        if (loc->next->key == key) {
            return loc->next->val;
        }
        loc = loc->next;
    }
    return -1;
}

void Solution706::remove(int key) {
    int bucket = key / 32;
    Node* loc = &data[bucket];
    Node* prev = loc;
    /*
    这样遍历会使得链表最后一个元素遍历不到
    while (loc->next != NULL) {
        if (loc->next->key == key) {
            prev->next = loc->next->next;
            return;
        }
        prev = loc;
        loc = loc->next;
    }*/
    Node* cur = loc->next;
    while (cur != NULL) {
        if (cur->key == key) {
            prev->next = cur->next;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}