/* 

BUS RESERVATION

*/

#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main() {
    int row, col, input;
    char rows = '1';
    char c, book1, seniorResponse;
    bool isSenior = false;
    string arr[3][11] = {{"   ", "Dr2", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "CfR", "[ ]", "[ ]", "|L|"},
                         {"   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "|U|"},
                         {"Dr1", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "|G|"}};
    cout << "\n         1   2   3   4   5   6   7   8   9  10  11" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "Row " << rows << ":  ";
        ++rows;
        for (int j = 0; j < 11; ++j)
            cout << arr[i][j] << " ";
        cout << endl;
    }
again:
    rows = '1';
    for (input = 1; input < 33; input = input) {
        rows = '1';
        cout << endl << "Enter Row & Column: ";
        if (!(cin >> row >> col) || row < 0 || col < 0) {
            cout << " ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if ((row == 1 && (col == 3)) || (row == 3 && (col == 2 || col == 3))) {
            cout << "Are you a senior citizen? (Y/N): ";
            if (!(cin >> seniorResponse) || seniorResponse < 0) {
                cout << " ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            if (seniorResponse == 'Y' || seniorResponse == 'y') {
                isSenior = true;
            } else {
                cout << endl << "The Seat is not available." << endl;
                goto again;
            }
        }
        if (row < 1 || row > 3 || col < 1 || col > 11) {
            cout << endl << "Please Pick A Valid Seat." << endl;
            goto again;
        }
        if ((row == 1 && (col == 1 || col == 8 || col == 2 || col == 11)) ||
            (row == 2 && col <= 11) ||
            (row == 3 && col == 1 || col == 11)) {
            cout << endl << "The Seat is not available." << endl;
            goto again;
        }
        --row;
        --col;
        if (arr[row][col] == "[X]") {
            cout << endl << "The Seat is not available." << endl;
            goto again;
        }
        arr[row][col] = "[X]";
        system("cls");
        cout << endl;
        cout << "         1   2   3   4   5   6   7   8   9  10  11" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "Row " << rows << ":  ";
            ++rows;
            for (int j = 0; j < 11; ++j)
                cout << arr[i][j] << " ";
            cout << endl;
        }
        cout << endl << "Seat Booked!" << endl;
        cout << endl << "Do You Want To Book Another Seat?" << endl;
        cout << "Press [Y] For Yes & [ANY KEYS] For No." << endl;
        cout << " ";
        if (!(cin >> c) || c < 0) {
            cout << " ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (c == 'y' || c == 'Y')
            continue;
        else {
            cout << "Thank you for using our program!" << endl;
            break;
        }
    }
    return 0;
}

