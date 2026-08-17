class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int answerLen = 0;
        string answer = "";
        for (int i = 0; i < s.length(); i++) {
            int left = i;
            int right = i;

            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                int len = right - left + 1;
                if (len > answerLen) {
                    start = left;
                    answerLen = len;
                }
                left--;
                right++;
            }
            left = i;
            right = i + 1;
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                int len = right - left + 1;
                if (len > answerLen) {
                    start = left;
                    answerLen = len;
                }
                left--;
                right++;
            }
        }
        answer = s.substr(start, answerLen);
        return answer;
    }
};