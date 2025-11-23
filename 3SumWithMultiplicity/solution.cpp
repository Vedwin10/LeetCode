class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int, long> mp;
        for (const int& x : arr) mp[x]++;
        long res = 0, mod = 1e9 + 7;

        for (const auto& ele1 : mp) {
            for (const auto& ele2 : mp) {
                int i = ele1.first, j = ele2.first, k = target - i - j;
                if (mp.find(k) == mp.end()) continue;
                if (i == j && j == k) {
                    res += mp[i] * (mp[i] - 1) * (mp[i] - 2) / 6;
                } else if (i == j && j != k) {
                    res += mp[i] * (mp[i] - 1) / 2 * mp[k];
                } else if (i < j && j < k) {
                    res += mp[i] * mp[j] * mp[k];
                }
            }
        }

        return res % mod;
    }
};

// It's similar to 3Sum in that you take pairs (i, j) and compare it with k, using k = target - i - j
// However, since there's no uniqueness to counting, we don't need to keep track of indices, only # of occurences (use hashmap)
// Iterate through map via pairs i, j (double for loop), and k = target - i - j. If k doesn't exist in the map, continue
// There are 3 cases:
// Case 1: i == j == k. Choosing 3 elements from n occurrences, n choose 3, = n! / 3! (n-3)! = n * (n-1) * (n-2) / 6 -- the (n-3)! cancels out
// Case 2: i == j != k. Choosing 2 elements from n occurrneces, n choose 2 = n! / 2! = n * (n-1) / 2 -- since we loop over all pairs i,j, we only check j != k and not 
// i != j to avoid double counting. Then multiply nC2 by occurrences of k.
// Case 3: i < j < k: simply multiply count[i] * count[j] * count[k]
// Since A[i] only has ~101 characters, the time complexity is not O(n^2), but rather O(n) (hashmap population) + O(101^2) (double for loop)
