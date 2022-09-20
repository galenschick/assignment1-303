#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Arrays.h"

using namespace std;

char getInput(); // helps shorten main function while also adding error checking, will always return a valid character
void printArray(int*, int);

int main(int argc, char* argv[])
{
    const int ARR_SIZE = 10;

    // OPEN FILE
    string filename;
    if (argc == 1) {    // text file not given in cmd
        cout << "Enter file name: " << endl;
        cin >> filename;
        cout << endl;
    }
    else
        filename = argv[1]; // text is the first argument

    ifstream fin(filename);

    if (!fin.is_open()) {
        cout << "Failed to open file: " << filename << endl;
        return 1;
    }
    //

    // READ THROUGH FILE
    string line;
    getline(fin, line);
    while (fin.good()) {
        // CREATE ARRAY FOR USE
        int size = ARR_SIZE;

        int* arr = new int[size];
        stringstream ss(line);
        string num;
        for (int i = 0; i < size; i++) {
            ss >> num;
            arr[i] = stoi(num);
        }

        cout << "Array: ";
        printArray(arr, size);
        cout << endl;
        //

        // PERFORM COMMANDS
        char command;
        int value, index;
        do {
            command = getInput();
            switch (command) {
            case 'F': {     // Find value
                cout << "Enter value: ";
                cin >> value;
                cout << "Value found at index: " << find(value, arr, size) << endl;
                cout << endl;
                break;
            }
            case 'R': {     // Replace element
                cout << "Enter index: ";
                cin >> index;
                cout << "Enter new value: ";
                cin >> value;
                try {
                    int oldValue = replace(index, value, arr); // will throw error if index is less than 0
                    cout << "Replaced " << oldValue << " with " << value << endl;
                    cout << "Array: ";
                    printArray(arr, size);
                }
                catch (invalid_argument& e) {
                    cout << e.what() << endl;
                }
                cout << endl;
                break;
            }
            case 'A': {     // Add element
                cout << "Enter value: ";
                cin >> value;
                add(value, arr, size++); // array is going to be one element larger
                cout << "Array: ";
                printArray(arr, size);
                cout << endl;
                break;
            }
            case 'D': {     // Delete element
                cout << "Enter index: ";
                cin >> index;
                try {
                    remove(index, arr, size); // throws error if index is less than 0 or greater than size
                    size--; // array is now one element smaller
                    cout << "Array: ";
                    printArray(arr, size);
                }
                catch (invalid_argument& e) {
                    cout << e.what() << endl;
                }
                cout << endl;
                break;
            }
            }
            cout << endl;
        } while (command != 'N');
        //

        cout << endl << endl;

        getline(fin, line);
        delete[] arr; // deallocate the current array
        arr = nullptr;
    }
    //
}

char getInput() {
    char c;
    do {
        cout << "Enter the letter of your choice:" << endl;
        cout << "[F]ind element" << endl;
        cout << "[R]eplace element" << endl;
        cout << "[A]dd element" << endl;
        cout << "[D]elete element" << endl;
        cout << "[N]ext array" << endl;
        cout << "* ";
        cin >> c;
        c = toupper(c);
    } while (!(c == 'F' || c == 'R' || c == 'A' || c == 'D' || c == 'N'));

    return c;
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}