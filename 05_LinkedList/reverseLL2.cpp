#include <bits/stdc++.h>
using namespace std;

ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;
    for(int i = 1; i < m; i++) {
        prev = prev->next;
    }
    ListNode* curr = prev->next;
    ListNode* next = curr->next;
    for(int i = m; i < n; i++) {
        curr->next = next->next;
        next->next = prev->next;
        prev->next = next;
        next = curr->next;
    }
    return dummy->next;
}