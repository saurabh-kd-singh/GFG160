#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int> &arr)
{
    int n = arr.size();
    int changeIndex = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            changeIndex = i;
            break;
        }
    }

    if (changeIndex == -1)
    {
        reverse(arr.begin(), arr.end());
    }
    else
    {
        for (int i = n - 1; i > changeIndex; i--)
        {
            if (arr[i] > arr[changeIndex])
            {
                swap(arr[i], arr[changeIndex]);
                break;
            }
        }

        reverse(arr.begin() + changeIndex + 1, arr.end());
    }
}

int main()
{
    vector<int> arr = {2, 1, 5, 4, 3, 0, 0};
    nextPermutation(arr);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}
