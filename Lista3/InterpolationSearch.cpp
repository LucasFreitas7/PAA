#include <iostream>
#include <vector>

using namespace std;

int interpolationSearch(vector<int> arr, int x) {
    int n = arr.size();
    int low = 0, high = n - 1;
    while (low <= high && x >= arr[low] && x <= arr[high]) {
        int pos = low + ((x - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[pos] == x)
            return pos;

        if (arr[pos] < x)
            low = pos + 1;
        else
            high = pos - 1;
    }

    return -1;
}

int main() {
    vector<int> arr = {2, 3, 4, 10, 40};
    int n = arr.size();
    int x = 10;
    int result = interpolationSearch(arr, x);
    if (result == -1)
        cout << "Element not present in array" << endl;
    else
        cout << "Element found at index " << result << endl;
    return 0;
}
