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
class Solution {
public:
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode *t=head,*first=head;
        int i=0,j=0;
        while(t!=nullptr)
        {
            while(i<m-1 && t->next!=nullptr) {t=t->next; ++i;}
            first=t;
            while(j<n+1 && t!=nullptr) {t=t->next; ++j;}
            first->next=t;
            i=0;j=0;
        }
        first->next=t;
        return head;
    }
};