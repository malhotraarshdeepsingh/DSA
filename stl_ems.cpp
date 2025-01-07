#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <string>

using namespace std;

struct Employee
{
    string name;
    int id;
    double salary;
};

void displayEmployees(const Employee &emp)
{
    cout << "Name: " << emp.name << ", ID: " << emp.id << ", Salary: " << emp.salary << endl;
}

int main()
{
    // Create a vector of employees
    vector<Employee> employees = {
        {"John Doe", 101, 50000.0},
        {"Jane Smith", 102, 60000.0},
        {"Alice Johnson", 103, 70000.0}};

    // Sort employees by salary in descending order using lambda function
    sort(employees.begin(), employees.end(), [](const Employee &a, const Employee &b)
         { return a.salary > b.salary; });

    cout << "Employees sorted by salary in descending order:" << endl;

    // Display sorted employees
    for_each(employees.begin(), employees.end(), displayEmployees);

    // New vector of employees to store high earning employees
    vector<Employee> highEarningEmployees;

    // Copy employees with salary greater than 60000.0 to the new vector
    copy_if(employees.begin(), employees.end(), back_inserter(highEarningEmployees), [](const Employee &emp)
            { return emp.salary > 60000.0; });

    // Display high earning employees
    cout << "\nHigh earning employees:" << endl;
    for_each(highEarningEmployees.begin(), highEarningEmployees.end(), displayEmployees);

    // Calculate the total salary of all employees
    double totalSalary = accumulate(employees.begin(), employees.end(), 0.0, [](double sum, const Employee &emp)
                                    { return sum + emp.salary; });

    // Display the total salary                                
    cout << "\nTotal salary of all employees: $" << totalSalary << endl;

    // Find the average salary
    double averageSalary = totalSalary / employees.size();

    // Display the average salary
    cout << "\nAverage salary: $" << averageSalary << endl;

    // Find the employee with the highest salary
    auto highestSalaryEmployee = max_element(employees.begin(), employees.end(), [](const Employee &a, const Employee &b)
                                              { return a.salary < b.salary; });
                                              
    // Display the employee with the highest salary
    cout << "\nEmployee with the highest salary:" << endl;
    displayEmployees(*highestSalaryEmployee);
    
    // Find the employee with the lowest salary
    auto lowestSalaryEmployee = min_element(employees.begin(), employees.end(), [](const Employee &a, const Employee &b)
                                             { return a.salary < b.salary; });
                                             
    // Display the employee with the lowest salary
    cout << "\nEmployee with the lowest salary:" << endl;
    displayEmployees(*lowestSalaryEmployee);

    // Find the employee with a specific ID
    int searchId;

    cout << "\nEnter employee ID to search: ";
    cin >> searchId;

    auto foundEmployee = find_if(employees.begin(), employees.end(), [searchId](const Employee &emp)
                                                              { return emp.id == searchId; });
                                                              
    // Check if the employee with the specific ID was found
    if (foundEmployee != employees.end())
    {
        cout << "\nEmployee with ID " << searchId << ":" << endl;
        displayEmployees(*foundEmployee);
    }
    else
    {
        cout << "\nEmployee with ID " << searchId << " not found." << endl;
    }

    // Search for employees with a specific salary range
    double minSalary, maxSalary;
    
    cout << "\nEnter minimum salary: ";
    cin >> minSalary;
    cout << "Enter maximum salary: ";
    cin >> maxSalary;
    
    // Display employees within the specified salary range
    cout << "\nEmployees with salary between $" << minSalary << " and $" << maxSalary << ":" << endl;
    for (const auto &emp : employees)
    {
        if (emp.salary >= minSalary && emp.salary <= maxSalary)
        {
            displayEmployees(emp);
        }
    }

    return 0;
}