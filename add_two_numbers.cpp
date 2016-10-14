/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// https://leetcode.com/problems/add-two-numbers/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        // Init head of return listnode
        ListNode *l_re_head = (ListNode *) malloc(sizeof(struct ListNode));
        l_re_head->val = 0;
        l_re_head->next = nullptr;
        // Carry flag
        int i_carry = 0;
        // Float pointer
        ListNode *l_cur = l_re_head;
        do
        {
            auto l1_val = (l1 == nullptr)? 0 : l1->val;
            auto l2_val = (l2 == nullptr)? 0 : l2->val;
            
            ListNode *l_new = static_cast<ListNode *> (malloc(sizeof(struct ListNode)));
            // Nerver forget plus carry digit.
            l_new->val = (l1_val + l2_val + i_carry) % 10;
            i_carry = (l1_val + l2_val + i_carry) / 10;
            l_new->next = nullptr;
            
            l_cur->next = l_new;
            l_cur = l_new;
            if(l1)
            {
                l1 = l1->next;
            }
            if(l2)
            {
                l2 = l2->next;
            }
        }while(l1 != nullptr || l2 != nullptr);
        
        // If carry flag is 1, that means two ListNode end at the same time, We shoult make a carry ListNode.
        if(i_carry == 1)
        {
            ListNode *l_one = static_cast<ListNode *> (malloc(sizeof(struct ListNode)));
            l_one->val = 1;
            l_one->next = nullptr;
            l_cur->next = l_one;
        }
        
        return l_re_head->next;
    }
};
