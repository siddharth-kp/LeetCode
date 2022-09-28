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
    
    int count(ListNode* head)
    {
        ListNode* h=head;
        int c=0;
        while(h!=NULL)
        {
            c++;
            h=h->next;
        }
        return c;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        int l = count(head);
        int c=0;
        ListNode* h = head;
        while(h!=NULL)
        {
            c++;
            if(l-n == 0)
            {
                h=h->next;
                return h;
            }
            if(c==(l-n))
            {
                h->next=h->next->next;
                break;
            }
            h=h->next;
        }
        return head;
    }
};