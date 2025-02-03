class Solution {
public:
    bool isNumber(string s) {
        int dot = 0;
        int expon = 0;
        bool digitSeen = false;
        bool digitAfterExponent = true;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '.') {
                if (dot > 0 || expon > 0) {
                    return false;
                }
                dot++;
            } else if (s[i] == 'e' || s[i] == 'E') {
                if (expon > 0 || !digitSeen) {
                    return false;
                }
                expon++;
                digitAfterExponent = false;
            } else if (s[i] == '+' || s[i] == '-') {
                if (i > 0 && (s[i-1] != 'e' && s[i-1] != 'E')) {
                    return false;
                }
            } else if (s[i] >= '0' && s[i] <= '9') {
                digitSeen = true;
                if (expon > 0) {
                    digitAfterExponent = true;
                }
            } else {
                return false;
            }
        }

        return digitSeen && digitAfterExponent;
    }
};