class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int r = numbers.size() - 1;
        int l = 0;
        int curr = numbers[l] + numbers[r];
        while (curr != target) {
            if (curr > target) --r;
            else if (curr < target) ++l;
            curr = numbers[l] + numbers[r];
        }
        return {l+1, r+1};
    }
};

// take advantage of sorting using 2 pointers, starting at each end and increment one end based on if the sum if < or > than target
