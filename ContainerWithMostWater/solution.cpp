class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int l = 0;
        int r = height.size() - 1;
        while (l < r) {
            int area = (r - l) * min(height[l], height[r]);
            if (area > max) max = area;
            if (min(height[l], height[r]) == height[l]) ++l;
            else --r;
        }
        return max;
    }
};

// use 2 pointers starting from both ends to narrow the container, calculating the area at each step and checking if it beats the current
// max. Move l or r pointer based on whichever is shorter, since shortest tower determines area of tower, and we're trying to maximize
// that value
