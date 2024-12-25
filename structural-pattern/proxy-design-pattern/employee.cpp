#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct EmployeeData
{
    string name;
    bool is_active;
};

class Employee
{
public:
    virtual void CreateEmploye(string client, string name) = 0;
    virtual void DeleteEmployee(string client, string name) = 0;
};

class EmployeeDAO : public Employee
{
    vector<string> employee_data;

public:
    void CreateEmploye(string client, string name) override
    {
        employee_data.push_back(name);
        cout << "Employee created:"
             << "\n";
    }

    void DeleteEmployee(string client, string name) override
    {

        employee_data.erase(std::remove(employee_data.begin(), employee_data.end(), name), employee_data.end());

        cout << "Employee Deleted"
             << "\n";
    }
};

class EmployeeDAOProxy : public Employee
{
public:
    EmployeeDAO employeeImpl;

    EmployeeDAOProxy(EmployeeDAO emp) : employeeImpl(emp) {}
    void CreateEmploye(string client, string name) override
    {
        if (client == "ADMIN")
        {
            this->employeeImpl.CreateEmploye(client, name);
        }
    }

    void DeleteEmployee(string client, string name) override
    {
        if (client == "ADMIN" || client == "USER")
        {
            this->employeeImpl.DeleteEmployee(client, name);
        }
    }
};