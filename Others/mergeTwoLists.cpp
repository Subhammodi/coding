#include<stdio.h>
#include<stdlib.h>

struct ListNode {
      int val;
      ListNode *next;
 };

 ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
 {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        ListNode *head = (ListNode *)malloc(sizeof(ListNode));
        ListNode *temp = head;
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val <= l2->val)
            {
                temp->val = l1->val;
                l1 = l1->next;
                ListNode *tempp = (ListNode *)malloc(sizeof(ListNode));
                temp->next = tempp;
                temp = tempp;
            }
            else
            {
                temp->val = l2->val;
                l2 = l2->next;
                ListNode *tempp = (ListNode *)malloc(sizeof(ListNode));
                temp->next = tempp;
                temp = tempp;
            }
        }

        if(l1 == NULL)
        {
            while(l2 != NULL)
            {
                temp->val = l2->val;
                l2 = l2->next;
                if(l2 != NULL)
                {
                    ListNode *tempp = (ListNode *)malloc(sizeof(ListNode));
                    temp->next = tempp;
                    temp = tempp;
                }
                else
                    temp->next = NULL;
            }
        }
        else
        {
            if(l2 == NULL)
            {
                while(l1 != NULL)
                {
                    temp->val = l1->val;
                    l1 = l1->next;
                    if(l1 != NULL)
                    {
                        ListNode *tempp = (ListNode *)malloc(sizeof(ListNode));
                        temp->next = tempp;
                        temp = tempp;
                    }
                    else
                        temp->next = NULL;
                }
            }
        }
        return head;
}


 int main()
 {
    ListNode *l1 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *l2 = (ListNode *)malloc(sizeof(ListNode));
    l1->val = -9;
    l1->next = (ListNode *)malloc(sizeof(ListNode));
    l1->next->val = 3;
    l1->next->next = NULL;

    l2->val = 5;
    l2->next = (ListNode *)malloc(sizeof(ListNode));
    l2->next->val = 7;
    l2->next->next = NULL;
    ListNode *l3 = mergeTwoLists(l1, l2);
    while(l3 != NULL)
    {
        printf("%d\n", l3->val);
        l3 = l3->next;
    }
    printf("\n");
    return 0;
 }
