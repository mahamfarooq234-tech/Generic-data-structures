
#define MYLIST_H

#include "List.h"

template <class Type>
class MyList : public List<Type> {
public:
    MyList(int size = 10);
    MyList(const MyList<Type>& other);
    ~MyList();

    void addElementAtFirstIndex(Type value);
    void addElementAtLastIndex(Type value);
    Type removeElementFromEnd();
    void removeElementFromStart();

    bool empty();
    bool full();
    int size();
    bool insertAt(int index, Type value);
    Type last();
    bool search(Type value);
    void display();
};


