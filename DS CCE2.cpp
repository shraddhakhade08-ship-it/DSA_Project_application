#include <iostream>
#include <string>
using namespace std;

// Node structure for Blood Donor
struct Donor
{
    int donorID;
    string name;
    int age;
    string gender;
    string bloodGroup;
    string contact;
    string city;

    Donor* next;
};

// Class for Blood Donor Management
class BloodDonorManagement
{
private:
    Donor* head;

public:

    // Constructor
    BloodDonorManagement()
    {
        head = NULL;
    }

    // Add a new donor
    void addDonor()
    {
        Donor* newDonor = new Donor;

        cout << "\nEnter Donor ID: ";
        cin >> newDonor->donorID;

        cin.ignore();

        cout << "Enter Donor Name: ";
        getline(cin, newDonor->name);

        cout << "Enter Age: ";
        cin >> newDonor->age;

        cin.ignore();

        cout << "Enter Gender: ";
        getline(cin, newDonor->gender);

        cout << "Enter Blood Group: ";
        getline(cin, newDonor->bloodGroup);

        cout << "Enter Contact Number: ";
        getline(cin, newDonor->contact);

        cout << "Enter City: ";
        getline(cin, newDonor->city);

        newDonor->next = NULL;

        // If list is empty
        if (head == NULL)
        {
            head = newDonor;
        }
        else
        {
            // Move to last node
            Donor* temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newDonor;
        }

        cout << "\nDonor added successfully!\n";
    }

    // Display all donors
    void displayDonors()
    {
        if (head == NULL)
        {
            cout << "\nNo donor records available.\n";
            return;
        }

        Donor* temp = head;

        cout << "\n========== BLOOD DONOR RECORDS ==========\n";

        while (temp != NULL)
        {
            cout << "\nDonor ID     : " << temp->donorID;
            cout << "\nName         : " << temp->name;
            cout << "\nAge          : " << temp->age;
            cout << "\nGender       : " << temp->gender;
            cout << "\nBlood Group  : " << temp->bloodGroup;
            cout << "\nContact      : " << temp->contact;
            cout << "\nCity         : " << temp->city;

            cout << "\n-----------------------------------------";

            temp = temp->next;
        }

        cout << endl;
    }

    // Search donor by ID
    void searchDonor()
    {
        if (head == NULL)
        {
            cout << "\nNo donor records available.\n";
            return;
        }

        int id;

        cout << "\nEnter Donor ID to search: ";
        cin >> id;

        Donor* temp = head;

        while (temp != NULL)
        {
            if (temp->donorID == id)
            {
                cout << "\n========== DONOR FOUND ==========\n";
                cout << "Donor ID     : " << temp->donorID << endl;
                cout << "Name         : " << temp->name << endl;
                cout << "Age          : " << temp->age << endl;
                cout << "Gender       : " << temp->gender << endl;
                cout << "Blood Group  : " << temp->bloodGroup << endl;
                cout << "Contact      : " << temp->contact << endl;
                cout << "City         : " << temp->city << endl;

                return;
            }

            temp = temp->next;
        }

        cout << "\nDonor with ID " << id << " not found.\n";
    }

    // Update donor information
    void updateDonor()
    {
        if (head == NULL)
        {
            cout << "\nNo donor records available.\n";
            return;
        }

        int id;

        cout << "\nEnter Donor ID to update: ";
        cin >> id;

        Donor* temp = head;

        while (temp != NULL)
        {
            if (temp->donorID == id)
            {
                cin.ignore();

                cout << "\nEnter New Donor Name: ";
                getline(cin, temp->name);

                cout << "Enter New Age: ";
                cin >> temp->age;

                cin.ignore();

                cout << "Enter New Gender: ";
                getline(cin, temp->gender);

                cout << "Enter New Blood Group: ";
                getline(cin, temp->bloodGroup);

                cout << "Enter New Contact Number: ";
                getline(cin, temp->contact);

                cout << "Enter New City: ";
                getline(cin, temp->city);

                cout << "\nDonor information updated successfully!\n";

                return;
            }

            temp = temp->next;
        }

        cout << "\nDonor with ID " << id << " not found.\n";
    }

    // Delete donor
    void deleteDonor()
    {
        if (head == NULL)
        {
            cout << "\nNo donor records available.\n";
            return;
        }

        int id;

        cout << "\nEnter Donor ID to delete: ";
        cin >> id;

        Donor* temp = head;
        Donor* previous = NULL;

        // Search for donor
        while (temp != NULL && temp->donorID != id)
        {
            previous = temp;
            temp = temp->next;
        }

        // Donor not found
        if (temp == NULL)
        {
            cout << "\nDonor with ID " << id << " not found.\n";
            return;
        }

        // If first node is deleted
        if (previous == NULL)
        {
            head = temp->next;
        }
        else
        {
            previous->next = temp->next;
        }

        delete temp;

        cout << "\nDonor deleted successfully!\n";
    }

    // Search donors by blood group
    void searchByBloodGroup()
    {
        if (head == NULL)
        {
            cout << "\nNo donor records available.\n";
            return;
        }

        string group;

        cin.ignore();

        cout << "\nEnter Blood Group: ";
        getline(cin, group);

        Donor* temp = head;
        bool found = false;

        cout << "\n====== DONORS WITH BLOOD GROUP "
             << group << " ======\n";

        while (temp != NULL)
        {
            if (temp->bloodGroup == group)
            {
                cout << "\nDonor ID    : " << temp->donorID;
                cout << "\nName        : " << temp->name;
                cout << "\nBlood Group : " << temp->bloodGroup;
                cout << "\nContact     : " << temp->contact;
                cout << "\nCity        : " << temp->city;

                cout << "\n--------------------------------";

                found = true;
            }

            temp = temp->next;
        }

        if (!found)
        {
            cout << "\nNo donor found with blood group "
                 << group << ".\n";
        }
    }
};

// Main function
int main()
{
    BloodDonorManagement system;

    int choice;

    do
    {
        cout << "\n\n========================================";
        cout << "\n      BLOOD DONOR MANAGEMENT SYSTEM";
        cout << "\n========================================";

        cout << "\n1. Add Donor";
        cout << "\n2. Display All Donors";
        cout << "\n3. Search Donor";
        cout << "\n4. Update Donor";
        cout << "\n5. Delete Donor";
        cout << "\n6. Search by Blood Group";
        cout << "\n7. Exit";

        cout << "\n========================================";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                system.addDonor();
                break;

            case 2:
                system.displayDonors();
                break;

            case 3:
                system.searchDonor();
                break;

            case 4:
                system.updateDonor();
                break;

            case 5:
                system.deleteDonor();
                break;

            case 6:
                system.searchByBloodGroup();
                break;

            case 7:
                cout << "\nThank you for using the system!\n";
                break;

            default:
                cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}
