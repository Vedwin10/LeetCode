class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        if (n < 4 || n > 12) return {};
        vector<string> res;
        for (int i = 1; i < 4; ++i) {
            string str1 = s.substr(0, i);
            if ((str1.size() > 1 && str1[0] == '0') || stoi(str1) > 255) continue;
            for (int j = i + 1; j < i + 4 && j < n; ++j) {
                string str2 = s.substr(i, j - i);
                if ((str2.size() > 1 && str2[0] == '0') || stoi(str2) > 255) continue;
                for (int k = j + 1; k < j + 4 && k < n; ++k) {
                    string str3 = s.substr(j, k - j);
                    if ((str3.size() > 1 && str3[0] == '0') || stoi(str3) > 255) continue;
                    string str4 = s.substr(k);
                    if (str4.size() > 3 || (str4.size() > 1 && str4[0] == '0') || stoi(str4) > 255) continue;
                    else {
                        string str = str1 + "." + str2 + "." + str3 + "." + str4;
                        res.push_back(str);
                    }
                }
            }
        }
        return res;
    }
};

// We're tasked with finding all valid IP Addresses given a string of numbers s. 
// We can immediately rule out strings that are less than 4 or greater than 12 in length (000 or 255255255255...)
// Making all possible combinations and then running a validIP algorithm would take too long, it's not optimal and complex at the same time
// Instead, we know that for each dot, we can go up to maximum of 3 spaces from the maximum position
// Thus, we can have a triple nested for loop, each one representing where we place a dot, starting 1 position after it's parent loop
// For example, in the parent loop, we start with the first dot at i = 1 (1 digit number),
// then in the next loop we'll check for the second dot at i + 1, (1 digit number), i + 2 (2 digit number), etc.

// In each loop, we take a substring of the number from the previous dot (or string beginnign) to the current dot (or end of string), and we have to check for:
// A leading 0, or a value > 255
// In the last loop, we have to check both the number before the dot and the number after the dot, since no for loop comes after to check that
// For str4, we can just check until the end of the string (since there's no more dots), and skip over anything with size > 3
