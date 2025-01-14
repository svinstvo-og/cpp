#include <stdio.h>     
#include <stdlib.h>
#include <time.h> 
#include <iostream>

using namespace std;

int* generateArray(int *pArr, int *pSize) {
    cout << "Enter array size: ";
    cin >> *pSize;

    pArr = new int[*pSize];

    for (int i = 0; i < *pSize; i++) {
        pArr[i] = rand() % 10 + 1;
    }

    return pArr;
}

void printArray(int *pArr, int *pSize) {
    for (int i = 0; i < *pSize; i++) {
        cout << *(pArr + i) << " ";
    }
    cout << "\n";
}

int arrayMin(int *pArr, int *pSize) {
    int* min = pArr;

    for (int i = 0; i < *pSize; i++) {
        if (*(pArr + i) < *min) {
            min = pArr + i;
        }
    }

    return *min;
}

int main(int argc, char const *argv[])
{
    srand (time(NULL));
    
    int *pArr;
    int *pSize;
    pSize = new int;
    pArr = generateArray(pArr, pSize);
    
    printArray(pArr, pSize);

    cout << arrayMin(pArr, pSize);

    delete[] pArr;
    delete pSize;

    return 0;
}
