class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int res = 0;
        int l_max = 0, r_max = 0;

        while (l <= r) {
            if (height[l] <= height[r]) {
                if (height[l] > l_max) l_max = height[l];
                else res += l_max - height[l];
                ++l;
            } else {
                if (height[r] > r_max) r_max = height[r];
                else res += r_max - height[r];
                --r;
            }
        }

        return res;
    }
};

// We have a left and right pointer at both ends of the array
// The amount of rain water trapped is determined by the shorter side (limiting side) and the max height on each side
// If the left side is shorter than the right, water can only be held up to the left side's height
// We check if the left has a new max, and if it does, not water can be stored since we go higher
// Otherwise, if it's shorter, then water is stored, specifically l_max - height[l] water
// Then, since the left side is the limiting side, we increment the left pointer
// The else statement is the same exact logic but for the right pointer