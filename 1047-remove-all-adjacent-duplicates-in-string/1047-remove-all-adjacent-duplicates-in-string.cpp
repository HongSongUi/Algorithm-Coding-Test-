class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> buffer;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if (!buffer.empty() && ch == buffer.top()) {
                while (!buffer.empty() && ch == buffer.top()) {
                    buffer.pop();
                }
            } else {
                buffer.push(ch);
            }
        }
        string answer = "";
        while (!buffer.empty()) {
            answer += buffer.top();
            buffer.pop();
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};