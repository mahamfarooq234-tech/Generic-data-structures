#include "CustomList.h"

template <class Type>
bool CustomList<Type>::isPrime(Type n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

template <class Type>
void CustomList<Type>::rotateCW(Type* a, int n) {
    if (n <= 1) return;
    Type temp = a[n - 1];
    for (int i = n - 1; i > 0; i--) {
        a[i] = a[i - 1];
    }
    a[0] = temp;
}

template <class Type>
void CustomList<Type>::rotateACW(Type* a, int n) {
    if (n <= 1) return;
    Type temp = a[0];
    for (int i = 0; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    a[n - 1] = temp;
}

template <class Type>
CustomList<Type>::CustomList(int size) : MyList<Type>(size) {}

template <class Type>
CustomList<Type>::CustomList(const CustomList<Type>& other) : MyList<Type>(other) {}

template <class Type>
CustomList<Type>::~CustomList() {}

template <class Type>
Type CustomList<Type>::sum_ofPrime() {
    Type sum = 0;
    for (int i = 0; i < this->currentSize; i++) {
        if (isPrime(this->arr[i])) {
            sum += this->arr[i];
        }
    }
    return sum;
}

template <class Type>
Type CustomList<Type>::secondMaxEven() {
    Type max1 = -1, max2 = -1;
    for (int i = 0; i < this->currentSize; i++) {
        if (this->arr[i] % 2 == 0) {
            if (this->arr[i] > max1) {
                max2 = max1;
                max1 = this->arr[i];
            }
            else if (this->arr[i] > max2 && this->arr[i] != max1) {
                max2 = this->arr[i];
            }
        }
    }
    return max2;
}

template <class Type>
Type CustomList<Type>::secondMinOdd() {
    Type min1 = 999999, min2 = 999999;
    for (int i = 0; i < this->currentSize; i++) {
        if (this->arr[i] % 2 != 0) {
            if (this->arr[i] < min1) {
                min2 = min1;
                min1 = this->arr[i];
            }
            else if (this->arr[i] < min2 && this->arr[i] != min1) {
                min2 = this->arr[i];
            }
        }
    }
    return min2;
}

template <class Type>
void CustomList<Type>::printDuplicates() {
    bool found = false;
    cout << "Duplicates: ";
    for (int i = 0; i < this->currentSize; i++) {
        for (int j = i + 1; j < this->currentSize; j++) {
            if (this->arr[i] == this->arr[j]) {
                bool alreadyPrinted = false;
                for (int k = 0; k < i; k++) {
                    if (this->arr[k] == this->arr[i]) {
                        alreadyPrinted = true;
                        break;
                    }
                }
                if (!alreadyPrinted) {
                    cout << this->arr[i] << " ";
                    found = true;
                }
                break;
            }
        }
    }
    if (!found) cout << "None";
    cout << endl;
}

template <class Type>
void CustomList<Type>::rotateClockwise(int r) {
    int mid = this->currentSize / 2;
    int firstHalf = mid;
    int secondHalf = this->currentSize - mid;

    for (int i = 0; i < r; i++) {
        rotateCW(this->arr, firstHalf);
        rotateCW(this->arr + mid, secondHalf);
    }
    cout << "List rotated clockwise " << r << " times.\n";
}

template <class Type>
void CustomList<Type>::rotateanitclockwise(int rt) {
    int mid = this->currentSize / 2;
    int firstHalf = mid;
    int secondHalf = this->currentSize - mid;

    for (int i = 0; i < rt; i++) {
        rotateACW(this->arr, firstHalf);
        rotateACW(this->arr + mid, secondHalf);
    }
    cout << "List rotated anti-clockwise " << rt << " times.\n";
}

// ===== EXPLICIT INSTANTIATIONS (Linker error fix) =====
template class List<int>;
template class MyList<int>;
template class CustomList<int>;