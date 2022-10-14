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
    ListNode* deleteMiddle(ListNode* head)
    {
        if(head->next==NULL)
            return NULL;
        ListNode* h = head;
        int count=0;
        while(h!=0)
        {
            h=h->next;
            count++;
        }
        h=head;
        int i=0;
        for(i=0;i<count/2-1;i++)
            h=h->next;
        h->next=h->next->next;
        return head;
    }
};