#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Structure to store Department information
struct Department {
    string departmentCode;
    string departmentName;
};

// Structure to store Laboratory information
struct Laboratory {
    string labCode;
    string labName;
    string departmentCode;
};

// Structure to store Equipment information
struct Equipment {
    string equipmentCode;
    string equipmentBrand;
    string equipmentType;
    string labCode;
};

// Function to add a department
void addDepartment(vector<Department>& departments) {
    Department dept;
    cout << "Enter Department Code: ";
    cin >> dept.departmentCode;
    cout << "Enter Department Name: ";
    cin.ignore();  // to handle the newline left by cin
    getline(cin, dept.departmentName);
    departments.push_back(dept);
    cout << "Department added successfully.\n";
}

// Function to list all departments
void listDepartments(const vector<Department>& departments) {
    cout << "\nDepartments:\n";
    for (const auto& dept : departments) {
        cout << "Code: " << dept.departmentCode << ", Name: " << dept.departmentName << endl;
    }
}

// Function to add a laboratory
void addLaboratory(vector<Laboratory>& laboratories, const vector<Department>& departments) {
    Laboratory lab;
    cout << "Enter Lab Code: ";
    cin >> lab.labCode;
    cout << "Enter Lab Name: ";
    cin.ignore();
    getline(cin, lab.labName);

    cout << "Enter Department Code for this Lab: ";
    cin >> lab.departmentCode;

    bool deptFound = false;
    for (const auto& dept : departments) {
        if (dept.departmentCode == lab.departmentCode) {
            deptFound = true;
            break;
        }
    }

    if (deptFound) {
        laboratories.push_back(lab);
        cout << "Laboratory added successfully.\n";
    } else {
        cout << "Department not found. Laboratory not added.\n";
    }
}

// Function to list all laboratories under a department
void listLaboratories(const vector<Laboratory>& laboratories, const vector<Department>& departments) {
    cout << "\nLaboratories:\n";
    for (const auto& lab : laboratories) {
        string deptName;
        for (const auto& dept : departments) {
            if (dept.departmentCode == lab.departmentCode) {
                deptName = dept.departmentName;
                break;
            }
        }
        cout << "Lab Code: " << lab.labCode << ", Lab Name: " << lab.labName << ", Department: " << deptName << endl;
    }
}

// Function to add equipment to a lab
void addEquipment(vector<Equipment>& equipmentList, const vector<Laboratory>& laboratories) {
    Equipment equip;
    cout << "Enter Equipment Code: ";
    cin >> equip.equipmentCode;
    cout << "Enter Equipment Brand: ";
    cin.ignore();
    getline(cin, equip.equipmentBrand);
    cout << "Enter Equipment Type (e.g., Computer, Printer): ";
    getline(cin, equip.equipmentType);
    
    cout << "Enter Lab Code to associate with this equipment: ";
    cin >> equip.labCode;

    bool labFound = false;
    for (const auto& lab : laboratories) {
        if (lab.labCode == equip.labCode) {
            labFound = true;
            break;
        }
    }

    if (labFound) {
        equipmentList.push_back(equip);
        cout << "Equipment added successfully.\n";
    } else {
        cout << "Lab not found. Equipment not added.\n";
    }
}

// Function to generate and save a report for each laboratory
void generateReports(const vector<Laboratory>& laboratories, const vector<Department>& departments, const vector<Equipment>& equipmentList) {
    for (const auto& lab : laboratories) {
        string deptName;
        for (const auto& dept : departments) {
            if (dept.departmentCode == lab.departmentCode) {
                deptName = dept.departmentName;
                break;
            }
        }

        // Create a file for each lab report
        ofstream reportFile(lab.labCode + "_report.txt");
        reportFile << "Lab Code: " << lab.labCode << "\n";
        reportFile << "Lab Name: " << lab.labName << "\n";
        reportFile << "Department: " << deptName << "\n\n";
        reportFile << "Equipment in this Lab:\n";

        int equipmentCount = 0;
        for (const auto& equip : equipmentList) {
            if (equip.labCode == lab.labCode) {
                reportFile << "Code: " << equip.equipmentCode << ", Brand: " << equip.equipmentBrand
                           << ", Type: " << equip.equipmentType << "\n";
                equipmentCount++;
            }
        }
        reportFile << "\nTotal Equipment: " << equipmentCount << "\n";
        reportFile.close();

        cout << "Report for Lab " << lab.labCode << " generated successfully.\n";
    }
}

int main() {
    vector<Department> departments;
    vector<Laboratory> laboratories;
    vector<Equipment> equipmentList;
    
    int choice;
    do {
        // Main Menu
        cout << "\nLab Management System\n";
        cout << "1. Department Management\n";
        cout << "2. Laboratory Management\n";
        cout << "3. Equipment Management\n";
        cout << "4. Generate Reports\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Department Management
                int deptChoice;
                cout << "\nDepartment Management\n";
                cout << "1. Add Department\n";
                cout << "2. List Departments\n";
                cout << "Enter your choice: ";
                cin >> deptChoice;
                if (deptChoice == 1) addDepartment(departments);
                else if (deptChoice == 2) listDepartments(departments);
                break;
            
            case 2:
                // Laboratory Management
                int labChoice;
                cout << "\nLaboratory Management\n";
                cout << "1. Add Laboratory\n";
                cout << "2. List Laboratories\n";
                cout << "Enter your choice: ";
                cin >> labChoice;
                if (labChoice == 1) addLaboratory(laboratories, departments);
                else if (labChoice == 2) listLaboratories(laboratories, departments);
                break;

            case 3:
                // Equipment Management
                int equipChoice;
                cout << "\nEquipment Management\n";
                cout << "1. Add Equipment\n";
                cout << "Enter your choice: ";
                cin >> equipChoice;
                if (equipChoice == 1) addEquipment(equipmentList, laboratories);
                break;

            case 4:
                // Generate Reports
                generateReports(laboratories, departments, equipmentList);
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
