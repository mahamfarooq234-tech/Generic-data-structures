#include <iostream>
#include "CustomList.h"
using namespace std;

int main() {
    int choice, size, value, index, r;

    cout << "Enter size of list: ";
    cin >> size;

    CustomList<int> list(size);

    do {
        cout << "\n========== MENU ==========\n";
        cout << "1.  Add element at first index\n";
        cout << "2.  Add element at last index\n";
        cout << "3.  Remove element from end\n";
        cout << "4.  Remove element from start\n";
        cout << "5.  Check empty\n";
        cout << "6.  Check full\n";
        cout << "7.  Get size\n";
        cout << "8.  Insert at index\n";
        cout << "9.  Get last element\n";
        cout << "10. Search element\n";
        cout << "11. Sum of prime numbers\n";
        cout << "12. Second maximum even\n";
        cout << "13. Second minimum odd\n";
        cout << "14. Print duplicates\n";
        cout << "15. Rotate clockwise\n";
        cout << "16. Rotate anti-clockwise\n";
        cout << "17. Display list\n";
        cout << "0.  Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.addElementAtFirstIndex(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.addElementAtLastIndex(value);
            break;
        case 3:
            cout << "Removed: " << list.removeElementFromEnd() << endl;
            break;
        case 4:
            list.removeElementFromStart();
            cout << "Removed from start.\n";
            break;
        case 5:
            cout << (list.empty() ? "List is empty" : "List is not empty") << endl;
            break;
        case 6:
            cout << (list.full() ? "List is full" : "List is not full") << endl;
            break;
        case 7:
            cout << "Size: " << list.size() << endl;
            break;
        case 8:
            cout << "Enter index: ";
            cin >> index;
            cout << "Enter value: ";
            cin >> value;
            if (list.insertAt(index, value))
                cout << "Inserted successfully.\n";
            else
                cout << "Insertion failed.\n";
            break;
        case 9:
            cout << "Last element: " << list.last() << endl;
            break;
        case 10:
            cout << "Enter value to search: ";
            cin >> value;
            cout << (list.search(value) ? "Found" : "Not found") << endl;
            break;
        case 11:
            cout << "Sum of primes: " << list.sum_ofPrime() << endl;
            break;
        case 12:
            cout << "Second max even: " << list.secondMaxEven() << endl;
            break;
        case 13:
            cout << "Second min odd: " << list.secondMinOdd() << endl;
            break;
        case 14:
            list.printDuplicates();
            break;
        case 15:
            cout << "Enter r: ";
            cin >> r;
            list.rotateClockwise(r);
            break;
        case 16:
            cout << "Enter rt: ";
            cin >> r;
            list.rotateanitclockwise(r);
            break;
        case 17:
            list.display();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}