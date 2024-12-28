#include <vector>
#include <iostream>
using namespace std;

int getSecondLargest(vector<int> &arr) {
        int largest=arr[0];
        int secondLargest=arr[0];
        for(int i=1; i<arr.size(); i++) {
            if(arr[i]>largest) {
                secondLargest = largest;
                largest = arr[i];
            } 
            else if(largest==secondLargest && arr[i]<largest) {
                secondLargest = arr[i];
            }
            else if(arr[i]<largest && arr[i]>secondLargest) {
                secondLargest = arr[i];
            }
        }
        if(largest==secondLargest) {
            return -1;
        } else {
            return secondLargest;
        }
    }

int main() {
    vector<int> arr = {1, 2 , 3, 4, 5};
    cout << "Enter a number";
    int test;
    cin >> test;
    cout << getSecondLargest(arr);
    return 1;
}