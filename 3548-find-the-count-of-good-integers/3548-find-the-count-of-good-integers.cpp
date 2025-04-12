class Solution {
public:
    
    void precomputeFactorials(vector<long long> &fact) {
        fact[0] = 1;
        fact[1] = 1;
        for (int i = 2; i <= 10; ++i)
            fact[i] = fact[i - 1] * i;
    }

    long long countUniquePermutations(string& s , vector<long long> &fact) {
        vector<int> freq(10, 0);
        for (char c : s) freq[c - '0']++;
        int len = s.size();

        long long total = 0;

        for (int first = 1; first <= 9; ++first) {
            if (freq[first] == 0) continue;

            freq[first]--;
            long long perms = fact[len - 1];
            for (int d = 0; d < 10; ++d)
                perms /= fact[freq[d]];
            total += perms;
            freq[first]++;
        }

        return total;
    }

    void findPalindromicNum(int pos, string current, int n, int k, vector<long long>& result) {
        if (pos > (n - 1) / 2) {
            long long val = stoll(current);
            if (val % k == 0)
                result.push_back(val);
            return;
        }

        for (char digit = '0'; digit <= '9'; ++digit) {
            if (pos == 0 && digit == '0') continue;

            if (pos == n - pos - 1) {
                current[pos] = digit;
            } else {
                current[pos] = digit;
                current[n - pos - 1] = digit;
            }

            findPalindromicNum(pos + 1, current, n, k, result);
        }
    }

    long long countGoodIntegers(int n, int k) {
        vector<long long> fact(11);
        precomputeFactorials(fact);
        vector<long long> palindromes;
        string current(n, '0');
        findPalindromicNum(0, current, n, k, palindromes);

        set<string> seen;
        long long total = 0;

        for (long long val : palindromes) {
            string temp = to_string(val);
            sort(temp.begin(), temp.end());
            if (seen.insert(temp).second) {
                total += countUniquePermutations(temp , fact);
            }
        }

        return total;
    }
};
