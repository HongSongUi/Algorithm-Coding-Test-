class Solution {
public:
    int firstUniqChar(string s) {
        map<char, bool> tmp;
        int answer = -1;

        bool flag = true;
        for (int i = 0; i < s.length(); i++) {
            flag = true;
            if (tmp[s[i]] == true)
                continue;
            for (int j = i + 1; j < s.length(); j++) {
                if (s[i] == s[j]) {
                    flag = false;
                    tmp[s[i]] = true;
                    break;
                }
            }
            if (flag) {
                answer = i;
                break;
            }
        }

        return answer;
    }
};