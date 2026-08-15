bool cmp(string a, string b) { return a.length() < b.length(); }

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string answer = "";

        sort(strs.begin(), strs.end(), cmp);

        int min_len = strs[0].length();

        bool flag = true;
        string tmp = "";
        for (int i = 0; i < min_len; i++) {
            flag = true;
            tmp += strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                string str = strs[j].substr(0, i + 1);
                if (tmp != str) {
                    flag = false;
                }
            }
            if (flag) {
                answer = tmp;
            }
        }
        return answer;
    }
};