/**
 * LRU Cache — doubly linked list + hash map
 * LeetCode 146 style API
 */

#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int key, val;
    Node* next;
    Node* prev;

    Node(int x, int y) : key(x), val(y), next(nullptr), prev(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> mp;
    Node *tail, *head;

    void deleteNode(Node* ptr) {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
    }

    void pushFront(Node* ptr) {
        ptr->next = head->next;
        ptr->prev = head;
        head->next = ptr;
        ptr->next->prev = ptr;
    }

public:
    LRUCache(int capacity) : capacity(capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* ptr = mp[key];
            deleteNode(ptr);
            pushFront(ptr);
            return ptr->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            mp[key]->val = value;
            deleteNode(mp[key]);
            pushFront(mp[key]);
        } else {
            if ((int)mp.size() == capacity) {
                Node* lru = tail->prev;
                deleteNode(lru);
                mp.erase(lru->key);
                delete lru;
            }
            Node* ptr = new Node(key, value);
            mp[key] = ptr;
            pushFront(ptr);
        }
    }

    ~LRUCache() {
        Node* cur = head->next;
        while (cur != tail) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
        delete head;
        delete tail;
        mp.clear();
    }
};

/**
 * Usage:
 *   LRUCache* obj = new LRUCache(capacity);
 *   int param_1 = obj->get(key);
 *   obj->put(key, value);
 */
