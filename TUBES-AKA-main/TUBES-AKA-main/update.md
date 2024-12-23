# TUBES-AKA
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
void printStep(const vector<int>& arr, int step, const string& message) {
    cout << setw(10) << message << " (Step " << step << "): ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

void selectionSortWithVisualization(vector<int>& arr) {
    int n = arr.size();
    cout << "\nVisualisasi Selection Sort:\n";
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
        printStep(arr, i + 1, "After Swap");
    }
}

void insertionSortWithVisualization(vector<int>& arr) {
    int n = arr.size();
    cout << "\nVisualisasi Insertion Sort:\n";
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        printStep(arr, i, "After Insert");
    }
}

void printArray(const vector<int>& arr, const string& message) {
    cout << message << ": ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> originalArray = {64, 34, 25, 12, 22, 11, 90};
    vector<int> arrayForSelectionSort = originalArray;
    vector<int> arrayForInsertionSort = originalArray;

    printArray(originalArray, "Array Awal");

    selectionSortWithVisualization(arrayForSelectionSort);

    insertionSortWithVisualization(arrayForInsertionSort);

    return 0;
}
