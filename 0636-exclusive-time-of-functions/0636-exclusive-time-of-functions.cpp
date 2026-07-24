class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<int> answer(n, 0);
        stack<int> st;
        int prev = 0;

        for (int i = 0; i < logs.size(); i++) {
            int c1 = logs[i].find(':');
            int c2 = logs[i].find(':', c1 + 1);

            int fnum = stoi(logs[i].substr(0, c1));
            string state = logs[i].substr(c1 + 1, c2 - c1 - 1);
            int t = stoi(logs[i].substr(c2 + 1));

            if (state == "start") {
                if (!st.empty()) {
                    answer[st.top()] += t - prev;
                }
                st.push(fnum);
                prev = t;
            } else {
                answer[st.top()] += t - prev + 1;
                st.pop();
                prev = t + 1;
            }
        }
        return answer;
    }
};