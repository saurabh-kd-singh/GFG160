#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size(), maxProfit = 0, minimumCost = prices[0];
    for (int i = 0; i < n; i++)
    {
        int profitOnDayi = prices[i] - minimumCost;
        maxProfit = max(maxProfit, profitOnDayi);
        minimumCost = min(minimumCost, prices[i]);
    }
    return maxProfit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int result = maxProfit(prices);
    cout << result;
    return 0;
}