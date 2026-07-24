class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<string> answer;
        unordered_set<int> s;
        for (int i = 0; i < target.size(); i++) {
            s.insert(target[i]);
        }
        vector<int> nums;
        bool flag = true;
        int i = 1;
        while (true) {
            flag = true;

            nums.emplace_back(i);
            answer.emplace_back("Push");

            if (s.find(i) == s.end()) {
                answer.emplace_back("Pop");
                nums.pop_back();
            }
            i++;
            if (nums.size() != target.size())
                continue;

            for (int i = 0; i < target.size(); i++) {
                if (target[i] != nums[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                break;
        }
        return answer;
    }
};