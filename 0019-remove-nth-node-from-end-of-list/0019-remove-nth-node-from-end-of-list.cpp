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
ListNode* MakeList(vector<int>& vec, int idx) {
    if (idx == vec.size()) {
        return nullptr;
    }
    return new ListNode(vec[idx], MakeList(vec, idx + 1));
}
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        vector<int> vec;

        while (head != nullptr) {
            vec.emplace_back(head->val);
            head = head->next;
        }
        vector<int> vec2;
        int tmp = vec.size() - n;
        for (int i = 0; i < vec.size(); i++) {
            if (i != tmp) {
                vec2.emplace_back(vec[i]);
            }
        }

        ListNode* node = MakeList(vec2, 0);
        return node;
    }
};