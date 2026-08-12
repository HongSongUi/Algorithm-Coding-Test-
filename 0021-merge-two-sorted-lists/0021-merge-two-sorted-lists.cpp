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

void SearchList(ListNode* node, vector<int>& vec) {
    if (node == nullptr) {
        return;
    }
    vec.emplace_back(node->val);
    SearchList(node->next, vec);
    return;
}
ListNode* MakeList(vector<int>& vec, int idx) {
    if (idx == vec.size()) {
        return nullptr;
    }
    return new ListNode(vec[idx], MakeList(vec, idx + 1));
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        vector<int> vec;
        SearchList(list1, vec);
        SearchList(list2, vec);
        sort(vec.begin(), vec.end());

        ListNode* node = MakeList(vec, 0);
        return node;
    }
};