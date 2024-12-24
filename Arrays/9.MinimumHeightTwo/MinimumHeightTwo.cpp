#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int getMinDiff(vector<int> &arr, int k)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());

    // If we increase all heights by k or decrease all
    // heights by k, the result will be arr[n - 1] - arr[0]
    int res = arr[n - 1] - arr[0];

    //  For all indices i, increment arr[0...i-1] by k and
    // decrement arr[i...n-1] by k
    for (int i = 1; i < arr.size(); i++)
    {

        // Impossible to decrement height of ith tower by k,
        // continue to the next tower
        if (arr[i] - k < 0)
            continue;

        // Minimum height after modification
        int minH = min(arr[0] + k, arr[i] - k);

        // Maximum height after modification
        int maxH = max(arr[i - 1] + k, arr[n - 1] - k);

        // Store the minimum difference as result
        res = min(res, maxH - minH);
    }
    return res;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int result = getMinDiff(prices, 2);
    cout << result;
    return 0;
}