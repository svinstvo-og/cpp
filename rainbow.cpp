#include <iostream>
#include <string>

using namespace std;

#define RESET "\033[0m"

const string colors[] = {
    "\033[31m", // Red
    "\033[33m", // Yellow
    "\033[32m", // Green
    "\033[34m", // Blue
    "\033[35m", // Magenta
    "\033[36m"  // Cyan
};

void rainbow(const string& text){
    int colorIndex = 0;

    for (char ch : text){
        cout << colors[colorIndex % 6] << ch << RESET;

        colorIndex++;
    }

    cout << endl;
}

int main(){
    string input;

    input = cin;
    
    rainbow(input);
    return 0;
}
