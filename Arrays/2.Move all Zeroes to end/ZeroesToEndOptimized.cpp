#include <vector>
#include <iostream>
using namespace std;

void pushZerosToEnd(vector<int> &arr)
{
    int pos = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[pos], arr[i]);
            pos++;
        }
    }
}

int main()
{
    vector<int> arr = {1, 2, 0, 4, 3, 0, 5, 0};
    pushZerosToEnd(arr);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}