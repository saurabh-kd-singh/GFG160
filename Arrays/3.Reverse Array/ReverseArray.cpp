#include <vector>
#include <iostream>
using namespace std;

void reverseArray(vector<int>& arr)
{
    int l = 0, r = arr.size() - 1;
    while (l < r)
    {
        swap(arr[l], arr[r]);
        l++;
        r--;
    }
}

int main()
{
    vector<int> arr = {1, 2, 0, 4, 3, 0, 5, 0};
    reverseArray(arr);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}