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
vector<int> tmp;
void SreachNode(ListNode* node) {
    if (node == nullptr) {
        return;
    }
    tmp.emplace_back(node->val);
    SreachNode(node->next);
    return;
}
ListNode* CreateList(int idx)
{
    if (idx < 0)
    {
        return nullptr;
    }

    return new ListNode(tmp[idx], CreateList(idx-1));
}
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        tmp.clear();
        SreachNode(head);
        ListNode* node = CreateList(tmp.size() - 1);
        return node;
    }
};