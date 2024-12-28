#include <vector>
#include <iostream>
#include <map>
using namespace std;

int maxProduct(vector<int> &arr)
{
    int currMin = arr[0], currMax = arr[0], maxProduct = arr[0], temp;
    for (int i = 1; i < arr.size(); i++)
    {
        temp = max(arr[i], max(currMin * arr[i], currMax * arr[i]));
        currMin = min(arr[i], min(currMin * arr[i], currMax * arr[i]));
        currMax = temp;

        maxProduct = max(maxProduct, currMax);
    }
    return maxProduct;
}

int main()
{
    vector<int> prices = {2, 3, -8, 7, -2, 6, 4};
    int answer = maxProduct(prices);
    cout << answer;
    return 0;
}