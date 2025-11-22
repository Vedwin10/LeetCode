/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        
        for (ListNode*& head : lists) {
            ListNode* curr = head;
            while (curr) {
                pq.push(curr);
                curr = curr->next;
            }
        }

        ListNode* head = nullptr;
        ListNode* curr = nullptr;
        while (!pq.empty()) {
            ListNode* node = pq.top(); pq.pop();
            node->next = nullptr;
            if (!head) {
                head = node;
                curr = head;
            } else {
                curr->next = node;
                curr = curr->next;
            }
        }

        return head;
    }
};

// Pretty straightforward solution, we create a min-heap and just push all nodes
// Then we reconstruct the main linked list using the min-heap
// Be wary of the original next pointers, we set them to nullptr to avoid creating cycles and messing stuff up
