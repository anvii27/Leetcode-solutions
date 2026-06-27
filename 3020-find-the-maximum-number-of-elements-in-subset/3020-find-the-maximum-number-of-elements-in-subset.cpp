class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;

        for (int x : nums)
            freq[x]++;

        int ans = 1;

        // Handle 1 separately
        if (freq.count(1)) {
            // We can only use an odd number of 1's
            ans = max(ans, (freq[1] % 2 == 0) ? freq[1] - 1 : freq[1]);
        }

        for (auto &[num, cnt] : freq) {
            if (num == 1) continue;

            long long cur = num;
            int len = 0;

            while (true) {
                // If we have at least 2 copies, we can place them symmetrically
                if (freq[cur] >= 2) {
                    len += 2;

                    // Prevent overflow
                    if (cur > 1e9 / cur || !freq.count(cur * cur)) {
                        // No next power exists, so only one copy of current
                        // can be the center
                        len--;
                        break;
                    }

                    cur = cur * cur;
                }
                else if (freq[cur] == 1) {
                    // Single copy can serve as center
                    len++;
                    break;
                }
                else {
                    // Current doesn't exist
                    len -= 2; // remove the invalid pair added previously
                    len++;
                    break;
                }
            }

            ans = max(ans, len);
        }

        return ans;
    }
};