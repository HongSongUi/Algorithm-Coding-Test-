class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> vec(26);

        for (int i = 0; i < s.length(); i++) {
            vec[s[i] - 'a']++;
        }
        int answer = -1;
        for (int i = 0; i < s.length(); i++) {
            if (vec[s[i] - 'a'] == 1) {
                answer = i;
                break;
            }
        }
        return answer;
    }
};