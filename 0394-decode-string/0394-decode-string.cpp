class Solution {
public:
    string decodeString(string s) {
        stack<string> buff;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ']') {
                buff.push(string(1, s[i]));
            } else {
                string str = "";
                while (buff.top() != "[") {
                    str = buff.top() + str;
                    buff.pop();
                }
                buff.pop();
                string n = "";
                while (!buff.empty() &&
                       (buff.top() >= "0" && buff.top() <= "9")) {
                    n = buff.top() + n;
                    buff.pop();
                }
                int num = stoi(n);
                string str2 = "";
                while (num-- > 0) {
                    str2 += str;
                }
                buff.push(str2);
            }
        }

        string answer = "";
        while (!buff.empty()) {
            answer = buff.top() + answer;
            buff.pop();
        }
        return answer;
    }
};