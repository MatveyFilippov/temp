#include <iostream>
#include <random>


int getRandomInteger(const int minNum, const int maxNum) {
    if (minNum >= maxNum) {
        return minNum;
    }
    return minNum + std::rand() % maxNum;
}


void fillArrayByRandomNumbers(int array[], const int size, const int minNum, const int maxNum) {
    for (int i = 0; i < size; ++i) {
        array[i] = getRandomInteger(minNum, maxNum);
    }
}


void printArray(int array[], const int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}


template <typename T>
void quickSort(T array[], const int size) {
    int i = 0;
    int j = size - 1;

    const int pivotIndex = getRandomInteger(0, size-1);
    T pivotElement = array[pivotIndex];

    do {
        while (array[i] < pivotElement) {
            i++;
        }
        while (array[j] > pivotElement) {
            j--;
        }

        if (i <= j) {
            T tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0) {
        quickSort(array, j + 1);
    }
    if (i < size) {
        quickSort(&array[i], size - i);
    }
}


template <typename T>
void bubbleSort(T array[], const int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                T temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}


template <typename T>
void selectionSort(T array[], const int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            T temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }
}



int main() {
    std::srand(static_cast<unsigned int>(time(nullptr)));
    
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    int *arr = new int[size];
    
    fillArrayByRandomNumbers(arr, size, 0, 999);
    std::cout << "\n * Quick Sort" << std::endl;
    std::cout << "before: ";
    printArray(arr, size);
    
    quickSort(arr, size);
    
    std::cout << "after: ";
    printArray(arr, size);
    
    
    fillArrayByRandomNumbers(arr, size, 0, 999);
    std::cout << "\n * Bubble Sort" << std::endl;
    std::cout << "before: ";
    printArray(arr, size);
    
    bubbleSort(arr, size);
    
    std::cout << "after: ";
    printArray(arr, size);
    
    
    fillArrayByRandomNumbers(arr, size, 0, 999);
    std::cout << "\n * Selection Sort" << std::endl;
    std::cout << "before: ";
    printArray(arr, size);
    
    selectionSort(arr, size);
    
    std::cout << "after: ";
    printArray(arr, size);

    std::cout << std::endl;
    delete[] arr;

    return 0;
}
