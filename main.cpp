#include <iostream>

using namespace std;


void sort(int arr[], const int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] < arr[j]) {
                // swap
                const int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

/**
 * Fills the passed array with user input and returns the size of the array
 */
int getNumbers(int arr[], const int limit) {
    cout << "Enter size of array: ";
    int size;
    cin >> size;

    if (size > limit) {
        cout << "Size is greater than 10. Try again." << endl;
        return getNumbers(arr, limit);
    }

    for (int i = 0; i < size; i++) {
        cout << "Enter number " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << endl;

    return size;
}

int main() {
    int firstArray[10];
    int secondArray[10];

    cout << "First set of numbers: " << endl;
    const int firstSize = getNumbers(firstArray, 10);

    cout << "Second set of numbers: " << endl;
    const int secondSize = getNumbers(secondArray, 10);

    int mergedArray[firstSize + secondSize + 1];

    // iterate through each arrays, then add the elements to the merged array
    for (int i = 0; i < firstSize; i++) {
        mergedArray[i] = firstArray[i];
    }
    for (int i = 0; i < secondSize; i++) {
        mergedArray[firstSize + i] = secondArray[i];
    }

    cout << "Before sorting: ";
    for (int i = 0; i < firstSize + secondSize; i++) {
        cout << mergedArray[i] << " ";
    }
    cout << endl;

    sort(mergedArray, firstSize + secondSize);

    cout << "After sorting: ";
    for (int i = 0; i < firstSize + secondSize; i++) {
        cout << mergedArray[i] << " ";
    }
    cout << endl;
}
