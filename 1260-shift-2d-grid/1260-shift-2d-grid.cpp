class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
       int m = grid.size();
        int n = grid[0].size();
        int total = m * n;

        k %= total;

        vector<int> arr(total);

        // Flatten
        int idx = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                arr[idx++] = grid[i][j];
            }
        }

        vector<int> shifted(total);

        // Shift
        for (int i = 0; i < total; i++) {
            shifted[(i + k) % total] = arr[i];
        }

        // Convert back to 2D
        vector<vector<int>> ans(m, vector<int>(n));
        idx = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = shifted[idx++];
            }
        }

        return ans; 
    }
};