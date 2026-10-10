#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        while (curr != nullptr && curr->next != nullptr) {
            if (curr->val == curr->next->val) {
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;  // Free memory of duplicate node
            } else {
                curr = curr->next;
            }
        }
        return head;
    }
};

// Helper function to create linked list from array
ListNode* createList(const int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < n; ++i) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Helper function to print linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to delete linked list
void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Test case 1: 1 -> 1 -> 2
    int arr1[] = {1, 1, 2};
    ListNode* head1 = createList(arr1, 3);
    cout << "Original: ";
    printList(head1);
    
    Solution sol;
    head1 = sol.deleteDuplicates(head1);
    cout << "After removing duplicates: ";
    printList(head1);
    deleteList(head1);
    
    cout << endl;
    
    // Test case 2: 1 -> 1 -> 2 -> 3 -> 3
    int arr2[] = {1, 1, 2, 3, 3};
    ListNode* head2 = createList(arr2, 5);
    cout << "Original: ";
    printList(head2);
    
    head2 = sol.deleteDuplicates(head2);
    cout << "After removing duplicates: ";
    printList(head2);
    deleteList(head2);
    
    return 0;
}