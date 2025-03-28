#include <iostream>
#include <vector>

// Функция слияния с общим буфером
void merge(std::vector<int>& arr, std::vector<int>& temp, int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;

    // Копируем во временный буфер
    for (int idx = left; idx <= right; idx++)
        temp[idx] = arr[idx];

    // Слияние с использованием буфера
    while (i <= mid && j <= right) {
        if (temp[i] <= temp[j]) {
            arr[k] = temp[i];
            i++;
        } else {
            arr[k] = temp[j];
            j++;
        }
        k++;
    }

    // Дописываем оставшиеся элементы
    while (i <= mid) {
        arr[k] = temp[i];
        i++;
        k++;
    }
}

// Рекурсивная сортировка слиянием с буфером
void mergeSort(std::vector<int>& arr, std::vector<int>& temp, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, temp, left, mid);
        mergeSort(arr, temp, mid + 1, right);
        merge(arr, temp, left, mid, right);
    }
}

// Обёртка для удобного вызова
void mergeSort(std::vector<int>& arr) {
    std::vector<int> temp(arr.size());
    mergeSort(arr, temp, 0, arr.size() - 1);
}

// Вывод массива
void printArray(const std::vector<int>& arr) {
    for (int num : arr)
        std::cout << num << " ";
    std::cout << "\n";
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7,6,3,2,1,2,4,45};
    
    std::cout << "Исходный массив: ";
    printArray(arr);

    mergeSort(arr);

    std::cout << "Отсортированный массив: ";
    printArray(arr);

    return 0;
}
