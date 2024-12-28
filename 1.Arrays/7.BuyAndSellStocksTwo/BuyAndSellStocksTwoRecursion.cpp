#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int recurProfit(int index, int buy, vector<int> prices, int n, vector<vector<int>> &dp)
{
    if (index == n)
        return 0;
    if (dp[index][buy] != -1)
        return dp[index][buy];

    int profit = 0;
    if (buy)
    {
        profit = max(-prices[index] + recurProfit(index + 1, 0, prices, n, dp),
                     0 + recurProfit(index + 1, 1, prices, n, dp));
    }
    else
    {
        profit = max(+prices[index] + recurProfit(index + 1, 1, prices, n, dp),
                     0 + recurProfit(index + 1, 0, prices, n, dp));
    }

    return dp[index][buy] = profit;
}

int maximumProfit(vector<int> &prices)
{
    vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
    int result = recurProfit(0, 1, prices, prices.size(), dp);
    return result;
}

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    int result = maximumProfit(prices);
    cout << result;
    return 0;
}