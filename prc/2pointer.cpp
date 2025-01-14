#include <iostream>

using namespace::std;

int main(int argc, char const *argv[])
{
    int a = 228;
    int *pA = &a;
    // * = value at pointer
    // & = adress of variable
    cout << *pA << endl; 
    return 0;
}
