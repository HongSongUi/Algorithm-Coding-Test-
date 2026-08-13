class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = tolower(s[i]);
                str += s[i];
            } else if ((s[i] >= 'a' && s[i] <= 'z') ||
                       (s[i] >= '0' && s[i] <= '9')) {
                str += s[i];
            }
        }
        string str2 = str;
        reverse(str2.begin(), str2.end());
        bool answer = true;
        if (str2 != str) {
            answer = false;
        }
        return answer;
    }
};