#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int partition(std::vector<int>& arr, int low, int high) {
    int pivotIndex = low + rand() % (high - low + 1);
    std::swap(arr[pivotIndex], arr[high]);  // Переносим pivot в конец
    int pivot = arr[high];

    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
void printArray(const std::vector<int>& arr) {
    for (int num : arr)
        std::cout << num << " ";
    std::cout << "\n";
}
int main() {
    srand(time(0));
    std::vector<int> arr = {1, 2, 3, 2,12,23,23,2,1,0,-21,4, 5};
    quickSort(arr, 0, arr.size() - 1);
    printArray(arr);
}
