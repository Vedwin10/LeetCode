class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = 0, p2 = 0;
        vector<int> merged;
        
        while (p1 < m && p2 < n) {
            if (nums1[p1] <= nums2[p2]) merged.push_back(nums1[p1++]);
            else merged.push_back(nums2[p2++]);
        }

        while (p1 < m) merged.push_back(nums1[p1++]);
        while (p2 < n) merged.push_back(nums2[p2++]);

        nums1 = merged;
    }
};

// Kind of like two pointers, to keep track of the arrays, just append whichever element is smaller out of nums1[i] and nums2[j]
// If either i or j reached m or n respectively, just append all other elements of the other vector
// Since we "merge", just append all of this to a new array and set nums1 = merged_array