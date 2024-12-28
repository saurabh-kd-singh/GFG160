#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int nextDayNotBuy = 0, nextDayBuy = 0, todayNotBuy, todayBuy, profit = 0, n = prices.size();

    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy)
            {
                todayBuy = max(-prices[i] + nextDayNotBuy, 0 + nextDayBuy);
            }
            else
            {
                todayNotBuy = max(prices[i] + nextDayBuy, 0 + nextDayNotBuy);
            }
        }
        nextDayBuy = todayBuy;
        nextDayNotBuy = todayNotBuy;
    }
    return todayBuy;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int result = maxProfit(prices);
    cout << result;
    return 0;
}