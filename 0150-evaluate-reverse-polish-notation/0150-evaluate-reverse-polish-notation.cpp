class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int answer;
        stack<int> st;

        for (int i = 0; i < tokens.size(); i++) {
            string str = tokens[i];
            if ((str[0] >= '0' && str[0] <= '9') ||
                (str.length() >= 2 && str[0] == '-')) {
                int num = stoi(str);
                st.push(num);
            }

            else {
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();
                int n3 = 0;
                if (str == "+") {
                    n3 = n1 + n2;
                } else if (str == "-") {
                    n3 = n2 - n1;
                } else if (str == "*") {
                    n3 = n2 * n1;
                } else if (str == "/") {
                    n3 = n2 / n1;
                }
                st.push(n3);
            }
        }

        answer = st.top();
        return answer;
    }
};