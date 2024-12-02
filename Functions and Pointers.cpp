#include <iostream>
#include <string>

#define ARR1_MAX 3
#define ARR2_MAX 2

std::string firstStudentName;
std::string secondStudentName;
int arr1[ARR1_MAX];
int arr2[ARR2_MAX];

void getInput() {
    std::cout << "Enter the name and grades for the first student: ";
    std::cin >> firstStudentName >> firstStudentName;
    for (int i = 0; i < ARR1_MAX; ++i) {
        std::cin >> arr1[i];
    }
    
    std::cout << "Enter the name and grades for the second student: ";
    std::cin >> secondStudentName >> secondStudentName;
    for (int i = 0; i < ARR2_MAX; ++i) {
        std::cin >> arr2[i];
    }
}

bool containsNegative(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] < 0) {
            return true;
        }
    }
    return false;
}

void customSwap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                customSwap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void print() {
    if (!containsNegative(arr1, ARR1_MAX)) {
        sort(arr1, ARR1_MAX);
        std::cout << "Grades for student " << firstStudentName << ": ";
        for (int i = 0; i < ARR1_MAX; ++i) {
            std::cout << arr1[i] << (i < ARR1_MAX - 1 ? ", " : "");
        }
        std::cout << std::endl;
    } else {
        std::cout << "Grades for student " << firstStudentName << " are invalid, negative number detected!" << std::endl;
    }

    if (!containsNegative(arr2, ARR2_MAX)) {
        sort(arr2, ARR2_MAX);
        std::cout << "Grades for student " << secondStudentName << ": ";
        for (int i = 0; i < ARR2_MAX; ++i) {
            std::cout << arr2[i] << (i < ARR2_MAX - 1 ? ", " : "");
        }
        std::cout << std::endl;
    } else {
        std::cout << "Grades for student " << secondStudentName << " are invalid, negative number detected!" << std::endl;
    }
}

int main() {
    getInput();
    print();

    return 0;
}
