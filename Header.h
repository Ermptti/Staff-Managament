

class Staff {
private:
    int id;
    std::string staffname;
    std::string password;
    std::string role;
public:
    Staff();
    Staff(int id, std::string username, std::string password, std::string role);
    int getid();
    void setid(int id);
    std::string getStaffname();
    void setusername(std::string username);
    std::string getpassword();
    void setpassword(std::string password);
    std::string getrole();
    void setrole(std::string role);
    void CreateStaff();
    void Displaystaff();
};
class StaffManager {
public:
    void SaveStaff();
    void DisplayAllStaffs();
    void DisplayAStaff(int id);
    void UpdateStaff(int id);
    void DeleteStaff(int id);
};
class DisplayOutput {
public:
    int start();
    void login();
    void adminpage();
    int adminoption();
};
int main();
