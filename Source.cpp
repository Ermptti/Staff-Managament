#include<String>
#include<iostream>
#include<fstream>
#include<Windows.h>
#include"Header.h"
using namespace std;
Staff::Staff() {
    id = 0;
    staffname = "";
    password = "";
    role = "";
}
Staff::Staff(int id, string username, string password,string role) {
    this->id = id;
    this->staffname = username;
    this->password = password;
    this->role = role;
}
int Staff::getid() {
    return id;
}
void Staff::setid(int id) {
    this->id = id;
}
string Staff::getStaffname() {
    return staffname;
}
void Staff::setusername(string username) {
    this->staffname = username;
}
string Staff::getpassword() {
    return password;
}
void Staff::setpassword(string password) {
    this->password = password;
}
string Staff::getrole() {
    return role;
}
void Staff::setrole(string role) {
    this->role = role;
}
void Staff::CreateStaff() {
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Staffname: ";
    cin.ignore();
    cin >> staffname;
    cout << "Enter password: ";
    cin.ignore();
    cin >> password;
    cout << "Enter role: ";
    cin.ignore();
    getline(cin, role);
}
void Staff::Displaystaff() {
    std::cout << "ID: " << id << std::endl;
    std::cout << "Staffname: " << staffname << std::endl;
    std::cout << "Password: " << password << std::endl;
    std::cout << "Role: " << role << std::endl;
}
void StaffManager::SaveStaff() {
    fstream fp;
    fp.open("Staff.txt", ios::out | ios::app);
    Staff* staff = new Staff();
    staff->CreateStaff();
    fp.write((char*)staff, sizeof(*staff));
    fp.close();
    cout << "Staff saved" << endl;
}
void StaffManager::DisplayAllStaffs() {
    cout << "Display all users: " << endl;
    Staff* staff = new Staff();
    fstream fp;
    fp.open("Staff.txt", ios::in);
    while (fp.read((char*)staff, sizeof(Staff))) {
        staff->Displaystaff();
        cout << "-------------------------------\n";
    }
    fp.close();
    cout << "All staffs displayed" << endl;
    cout << "-------------------------------\n";
}
void StaffManager::DisplayAStaff(int id) {
    fstream fp;
    Staff* staff = new Staff();
    bool found = false;
    fp.open("Staff.txt", ios::in);
    while (fp.read((char*)staff, sizeof(Staff))) {
        if (staff->getid() == id) {
            staff->Displaystaff();
            found = true;
            break;
        }
    }
    fp.close();

    if (found == false)
        cout << "ID not found\n";
    else {
        cout << "ID found\n";
        cout << "-------------------------------\n";
    }
}
void StaffManager::UpdateStaff(int id) {
    fstream fp;
    Staff* staff = new Staff();
    bool found = false;
    fp.open("Staff.txt", ios::in | ios::out);
    while (fp.read((char*)staff, sizeof(*staff))) {
        if (staff->getid() == id) {
            staff->Displaystaff();
            cout << "Update Staff detail: \n";
            staff->CreateStaff();
            int pos = -1 * static_cast<int>(sizeof(*staff));
            fp.seekp(pos, ios::cur);
            fp.write((char*)staff, sizeof(*staff));
            found = true;
            break;
        }
    }
    fp.close();
    if (found == false)
        cout << "ID not found\n";
    else {
        cout << "Staff have been updated\n";
        cout << "-------------------------------\n";
    }
}
void StaffManager::DeleteStaff(int id) {
    fstream fp;
    Staff* staff = new Staff();
    fp.open("Staff.txt", ios::in);
    fstream fp2;
    fp2.open("temp.txt", ios::out | ios::app);
    fp.seekg(0, ios::beg);
    while (fp.read((char*)staff, sizeof(*staff))) {
        if (staff->getid() != id) {
            fp2.write((char*)staff, sizeof(*staff));
            break;
        }
    }
    cout << "Staff has been deleted\n";
    cout << "-------------------------------\n";
    fp2.close();
    fp.close();
    remove("Staff.txt");
    rename("temp.txt", "Staff.txt");
}
int DisplayOutput::start() {
    system("CLS");
    int option;
    cout << "Welcome to My Project\n";
    cout << "1. Sign up\n";
    cout << "2. Login\n";
    cout << "3. Exit\n";
    cout << "Please choose an option: ";
    cin >> option;
    return option;
}
void DisplayOutput::login() {
    fstream fp;
    Staff* staff = new Staff();
    string name, pass;
    cout << "Enter your Staff Name: ";
    cin >> name;
    cout << "Enter your password: ";
    cin >> pass;
    if (name == "admin" && pass == "admin") {
        Sleep(200);
        cout << "...";
        Sleep(1000);
        cout << " ...";
        Sleep(1000);
        cout << " Successful Login Welcome";
        Sleep(2000);
        system("CLS");
        adminpage();

    }

    bool found = false;
    fp.open("user.txt", ios::in);
    while (fp.read((char*)staff, sizeof(Staff))) {

        if (staff->getStaffname() == name && staff->getpassword() == pass) {

            cout << "Welcome to this Staff Management System!\n";
            system("pause");
        }
    }
    fp.close();
    cout << "Incorrect username or password\n";
    system("pause");
}
void DisplayOutput::adminpage() {
    StaffManager staffmanager;
    int option = 0;
    do {
        option = adminoption();
        switch (option) {
        case 1:
            staffmanager.DisplayAllStaffs();
            adminpage();
            break;
        case 2:
            staffmanager.DisplayAllStaffs();
            int update;
            cout << "Enter Staff id that you want to update:";
            cin >> update;
            staffmanager.UpdateStaff(update);
            adminpage();
            break;
        case 3:
            staffmanager.DisplayAllStaffs();
            int del;
            cout << "Enter Staff id that you want to delete:";
            cin >> del;
            staffmanager.DeleteStaff(del);
            adminpage();
            break;
        case 4:
            main();
        default:
            cout << "Wrong input\n";
        }
    } while (option != 4);

}
int DisplayOutput::adminoption() {
    int option;
    cout << "Welcome Administrator!\n";
    cout << "1. Display all Staffs\n";
    cout << "2. Update Staff\n";
    cout << "3. Delete Staff\n";
    cout << "4. Logout\n";

    cout << "Please choose an option: ";
    cin >> option;
    system("CLS");
    return option;

    return 0;
}
