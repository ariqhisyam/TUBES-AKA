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

// Fungsi rekursif untuk mencari indeks minimum
int findMinIndex(const vector<int>& arr, int start, int end) {
    if (start == end) return start;
    int minIndex = findMinIndex(arr, start + 1, end);
    return (arr[start] < arr[minIndex]) ? start : minIndex;
}

// Selection Sort Rekursif dengan Visualisasi
void selectionSortRecursive(vector<int>& arr, int start, int step) {
    if (start >= arr.size() - 1) return;

    int minIndex = findMinIndex(arr, start, arr.size() - 1);
    swap(arr[start], arr[minIndex]);
    printStep(arr, step, "After Swap");

    selectionSortRecursive(arr, start + 1, step + 1);
}

// Insertion Sort Rekursif dengan Visualisasi
void insertionSortRecursive(vector<int>& arr, int n, int step) {
    if (n <= 1) return;

    insertionSortRecursive(arr, n - 1, step);

    int key = arr[n - 1];
    int j = n - 2;

    while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = key;

    printStep(arr, step, "After Insert");
}

// Fungsi untuk mencetak array awal
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

    cout << "\nVisualisasi Selection Sort (Rekursif):\n";
    selectionSortRecursive(arrayForSelectionSort, 0, 1);

    cout << "\nVisualisasi Insertion Sort (Rekursif):\n";
    insertionSortRecursive(arrayForInsertionSort, arrayForInsertionSort.size(), 1);

    return 0;
}
