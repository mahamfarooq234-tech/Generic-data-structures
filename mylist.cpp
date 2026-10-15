#include "MyList.h"

template <class Type>
MyList<Type>::MyList(int size) : List<Type>(size) {}

template <class Type>
MyList<Type>::MyList(const MyList<Type>& other) : List<Type>(other) {}

template <class Type>
MyList<Type>::~MyList() {}

template <class Type>
void MyList<Type>::addElementAtFirstIndex(Type value) {
    if (this->currentSize == this->maxSize) {
        cout << "List is full!\n";
        return;
    }
    for (int i = this->currentSize; i > 0; i--) {
        this->arr[i] = this->arr[i - 1];
    }
    this->arr[0] = value;
    this->currentSize++;
}

template <class Type>
void MyList<Type>::addElementAtLastIndex(Type value) {
    if (this->currentSize == this->maxSize) {
        cout << "List is full!\n";
        return;
    }
    this->arr[this->currentSize] = value;
    this->currentSize++;
}

template <class Type>
Type MyList<Type>::removeElementFromEnd() {
    if (this->currentSize == 0) {
        cout << "List is empty!\n";
        return Type();
    }
    Type val = this->arr[this->currentSize - 1];
    this->currentSize--;
    return val;
}

template <class Type>
void MyList<Type>::removeElementFromStart() {
    if (this->currentSize == 0) {
        cout << "List is empty!\n";
        return;
    }
    for (int i = 0; i < this->currentSize - 1; i++) {
        this->arr[i] = this->arr[i + 1];
    }
    this->currentSize--;
}

template <class Type>
bool MyList<Type>::empty() {
    return this->currentSize == 0;
}

template <class Type>
bool MyList<Type>::full() {
    return this->currentSize == this->maxSize;
}

template <class Type>
int MyList<Type>::size() {
    return this->currentSize;
}

template <class Type>
bool MyList<Type>::insertAt(int index, Type value) {
    if (index < 0 || index > this->currentSize || this->currentSize == this->maxSize) {
        return false;
    }
    for (int i = this->currentSize; i > index; i--) {
        this->arr[i] = this->arr[i - 1];
    }
    this->arr[index] = value;
    this->currentSize++;
    return true;
}

template <class Type>
Type MyList<Type>::last() {
    if (this->currentSize == 0) {
        cout << "List is empty!\n";
        return Type();
    }
    return this->arr[this->currentSize - 1];
}

template <class Type>
bool MyList<Type>::search(Type value) {
    for (int i = 0; i < this->currentSize; i++) {
        if (this->arr[i] == value) return true;
    }
    return false;
}

template <class Type>
void MyList<Type>::display() {
    cout << "List: ";
    for (int i = 0; i < this->currentSize; i++) {
        cout << this->arr[i] << " ";
    }
    cout << endl;
}