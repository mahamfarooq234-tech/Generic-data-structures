
#define CUSTOMLIST_H

#include "MyList.h"

template <class Type>
class CustomList : public MyList<Type> {
private:
    bool isPrime(Type n);
    void rotateCW(Type* a, int n);
    void rotateACW(Type* a, int n);

public:
    CustomList(int size = 10);
    CustomList(const CustomList<Type>& other);
    ~CustomList();

    Type sum_ofPrime();
    Type secondMaxEven();
    Type secondMinOdd();
    void printDuplicates();
    void rotateClockwise(int r);
    void rotateanitclockwise(int rt);
};

