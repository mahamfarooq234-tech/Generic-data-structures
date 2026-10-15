
#define LIST_H

#include <iostream>
using namespace std;

template <class Type>
class List {
protected:
    Type* arr;
    int maxSize;
    int currentSize;

public:
    List(int size = 10);
    List(const List<Type>& other);
    virtual ~List();

    virtual void addElementAtFirstIndex(Type) = 0;
    virtual void addElementAtLastIndex(Type) = 0;
    virtual Type removeElementFromEnd() = 0;
    virtual void removeElementFromStart() = 0;
};


