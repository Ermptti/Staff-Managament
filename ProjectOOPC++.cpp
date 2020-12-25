
#include<iostream>
#include<Windows.h>
#include"Header.h"
using namespace std;
int main() {
    system("color F0");
    cout << endl;
    cout << "\t******************************\n";
    cout << "\t*          Welcome           *\n";
    cout << "\t*            To              *\n";
    cout << "\t*     Staff login System     *\n";
    cout << "\t******************************\n";
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "\tLoading ";
    Sleep(100);
    cout << "<";
    Sleep(100);
    cout << ">";
    Sleep(100);  
    cout << "<";
    Sleep(100); 
    cout << ">";
    Sleep(100);
    cout << "<";
    Sleep(100);
    cout << ">";
    Sleep(100);  
    cout << "<";
    Sleep(100); 
    cout << ">";
    Sleep(100);
    cout << "<";
    Sleep(100); 
    cout << ">";
    Sleep(100);
    cout << "<";
    Sleep(100); 
    cout << ">";
    Sleep(100);
    cout << "<";
    Sleep(100); 
    cout << ">";
    Sleep(100);
    cout << "\n\n\t Successful\n";
    Sleep(2000);
    system("CLS");
    StaffManager staffmanager;
    DisplayOutput display;
    int option = 0;
    do {
        option = display.start();
        switch (option) {
        case 1:
            staffmanager.SaveStaff();
            break;
        case 2:
            display.login();
            break;
        case 3:
            exit(0);
        default:
            cout << "Wrong input\n";
        }
    } while (option != 3);
    return 0;
}























// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
