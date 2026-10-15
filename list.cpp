#include "List.h"

template <class Type>
List<Type>::List(int size) {
    maxSize = size;
    currentSize = 0;
    arr = new Type[maxSize];
}

template <class Type>
List<Type>::List(const List<Type>& other) {
    maxSize = other.maxSize;
    currentSize = other.currentSize;
    arr = new Type[maxSize];
    for (int i = 0; i < currentSize; i++) {
        arr[i] = other.arr[i];
    }
}

template <class Type>
List<Type>::~List() {
    delete[] arr;
}