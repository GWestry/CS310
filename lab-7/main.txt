#include <iostream>
using namespace std;

//recursive binary search function
int binarySearch(int arr[], int left, int right, int target) {
        if (right >= left) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target)
                return mid;
            if (arr[mid] > target)
                return binarySearch(arr, left, mid - 1, target);
            return binarySearch(arr, mid + 1, right, target);
        }
        return -1;
    }

//testing out binary search function with different targets/scenarios
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int length = 5;

    int result = binarySearch(arr, 0, length - 1, 1);
    cout << "Searching for 1: index " << result << endl;

    result = binarySearch(arr, 0, length - 1, 3);
    cout << "Searching for 3: index " << result << endl;

    result = binarySearch(arr, 0, length - 1, 5);
    cout << "Searching for 5: index " << result << endl;

    result = binarySearch(arr, 0, length - 1, 6);
    cout << "Searching for 6: index " << result << endl;

    int singleElement[] = {10};
    result = binarySearch(singleElement, 0, 0, 10);
    cout << "Searching a one-element array: index " << result << endl;

    result = binarySearch(arr, 0, -1, 3);
    cout << "Searching an empty array: index " << result << endl;

    return 0;
}