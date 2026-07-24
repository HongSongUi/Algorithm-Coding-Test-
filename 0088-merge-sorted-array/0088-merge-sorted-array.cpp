class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        nums1.resize(m);
        for (int i = 0; i < nums2.size(); i++) {
            nums1.emplace_back(nums2[i]);
        }
        sort(nums1.begin(), nums1.end());
    }
};