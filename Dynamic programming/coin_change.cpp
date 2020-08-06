// [Leetcode] Coin Change

// You are given coins of different denominations and a total amount of money amount.
// Write a function to compute the fewest number of coins that you need to make up that amount.
// If that amount of money cannot be made up by any combination of the coins, return -1.

// Example 1:

// Input: coins = [1, 2, 5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1
// Example 2:

// Input: coins = [2], amount = 3
// Output: -1

class Solution
{
  public:
    int coinChange(vector<int> &coins, int amount)
    {
        int dp[1000000];
        fill_n(dp, 1000000, 1000000);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                if (i >= coins[j])
                {
                    int minimum_amount_to_look_in_dp = i - coins[j];
                    dp[i] = min((dp[minimum_amount_to_look_in_dp] + 1), dp[i]);
                }
            }
        }
        if (dp[amount] != 1000000)
            return dp[amount];
        else
            return -1;
    }
};