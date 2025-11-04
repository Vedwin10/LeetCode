class Solution {
public:
    string validIPAddress(string queryIP) {
        return validIPv4(queryIP) ? "IPv4" : (validIPv6(queryIP) ? "IPv6" : "Neither");
    }

    bool validIPv4(string IP) {
        if (std::count(IP.begin(), IP.end(), '.') != 3) return false;   // check for more than 3 '.'s
        vector<string> parts = split(IP, '.');
        if (parts.size() != 4) return false;    // check for more than 4 numbers
        for (auto part : parts) {
            // check for empty string, string greater than 3 digits, or a leading 0
            if (part.empty() || part.size() > 3 || (part.size() > 1 && part[0] == '0')) return false;
            // check if a part has a character that isn't a number
            for (char c : part) if (!isdigit(c)) return false;
            // check if the number > 255
            if (stoi(part) > 255) return false;
        }
        return true;
    }

    bool validIPv6(string IP) {
        if (std::count(IP.begin(), IP.end(), ':') != 7) return false;   // check for more than 7 ':'s
        vector<string> parts = split(IP, ':');
        if (parts.size() != 8) return false;    // check for more than 8 numbers
        for (auto part : parts) {
            // check for empty string, or string larger than 4 characters
            if (part.empty() || part.size() > 4) return false;
            // check for non-hexadecimal character
            for (char c : part) if (!isdigit(c) && !(c >= 'a' && c <= 'f') && !(c >= 'A' && c <= 'F')) return false;
        }
        return true;
    }

    vector<string> split(string s, char c) {
        vector<string> res;
        string curr = "";
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == c) {
                if (curr.size() != 0) res.push_back(curr);
                curr = "";
            } else {
                curr += s[i];
            }
        }
        if (curr.size() != 0) res.push_back(curr);
        return res;
    }
};

// For IPv4 we must check the following problems:
/*
 * 1. More than 3 dots?
 * 2. More or less than 4 numbers?
 * 3. Are the numbers the right amount of digits (0 < digits < 4)?
 * 4. Are there leading 0s?
 * 5. Does each string have valid digits as characters?
 * 6. Is the number > 255?
*/

// For IPv6 we must check the following problems:
/*
 * 1. More than 7 colons?
 * 2. More or less than 8 numbers?
 * 3. Are the numbers the right amount of digits (0 < digits < 5)?
 * 4. Does each string have valid hexadecimal characters?
*/

// And we can define a custom split() function really quickly to split the string based on a delimeter to help us evaluate queryIP
