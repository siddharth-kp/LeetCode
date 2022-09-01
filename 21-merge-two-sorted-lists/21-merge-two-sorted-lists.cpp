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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        //bool one=false, two=false;
        ListNode *ptr1 = list1, *ptr2 = list2;
        ListNode* head = new ListNode;
        ListNode* h = head;
        while(ptr1!=NULL && ptr2!=NULL)
        {
            if(ptr1->val<=ptr2->val)
            {
                h->next = new ListNode(ptr1->val);
                h=h->next;
                ptr1=ptr1->next;
            }
            else
            {
                h->next = new ListNode(ptr2->val);
                h=h->next;
                ptr2=ptr2->next;
            }
        }
        if(ptr1==NULL)
            while(ptr2!=NULL)
            {
                h->next = new ListNode(ptr2->val);
                h=h->next;
                ptr2=ptr2->next;
            }
        if(ptr2==NULL)
            while(ptr1!=NULL)
            {
                h->next = new ListNode(ptr1->val);
                h=h->next;
                ptr1=ptr1->next;
            }
        return head->next;
    }
};