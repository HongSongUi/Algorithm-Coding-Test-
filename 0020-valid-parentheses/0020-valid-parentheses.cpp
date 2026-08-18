class Solution {
public:
    bool isValid(string s) {
        stack<char> tmp;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if (tmp.empty()) {
                tmp.push(ch);
                continue;
            }
            if (ch == ')' && tmp.top() == '(') {
                tmp.pop();
            } else if (ch == '}' && tmp.top() == '{') {
                tmp.pop();
            } else if (ch == ']' && tmp.top() == '[') {
                tmp.pop();
            } else {
                tmp.push(ch);
            }
        }
        return tmp.empty();
    }
};