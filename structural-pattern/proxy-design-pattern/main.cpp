#include <iostream>
#include "employee.cpp"
using namespace std;

int main()
{
    EmployeeDAO dao;
    Employee *employeeDao = new EmployeeDAOProxy(dao);
    employeeDao->CreateEmploye("ADMIN", "Punit Sinha");
    employeeDao->CreateEmploye("MANAGER", "Lakshay");
    employeeDao->DeleteEmployee("ADMIN", "Punit Sinha");
}