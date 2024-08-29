#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Input the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Initialize the starting point
    dp[0][0] = matrix[0][0];

    // Fill the DP table
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i > 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + matrix[i][j]); // Move down
            }
            if (j > 0) {
                dp[i][j] = max(dp[i][j], dp[i][j - 1] + matrix[i][j]); // Move right
            }
        }
    }

    // Output the maximum path sum
    cout << dp[n - 1][n - 1] << endl;

    return 0;
}