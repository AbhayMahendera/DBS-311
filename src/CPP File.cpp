#include <iostream>
#include <iomanip>
#include <occi.h>
using oracle::occi::Environment;
using oracle::occi::Connection;
using namespace oracle::occi;
using namespace std;

int main(void) {
    /* OCCI Variables */
    Environment* env = nullptr;
    Connection* conn = nullptr;
    /* Used Variables */
    string user = "abc"; // Add your dbs username from Blackboard here
    string pass = "123";        // Add your dbs password from Blackboard here
    string srv = "connection_string";


    try {
        env = Environment::createEnvironment(Environment::DEFAULT);
        conn = env->createConnection(user, pass, srv);

        cout << "Connection is Successful!" << endl;
        cout << "-------------------------" << endl;
        cout << "Name : Abhay Mahendera\n" << endl;
        cout << "-------------------------" << endl;
        Statement* stmt = conn->createStatement();
        string choice;

        while (true) {
            cout << "\nMenu Options:" << endl;
            cout << "1. View complete data from the Mall table" << endl;
            cout << "2. Search for a specific mall" << endl;
            cout << "3. View complete data from maintenance table" << endl;
            cout << "4. Search for a specific maintenance instance" << endl;
            cout << "5. Exit" << endl;
            cout << "Enter your choice (1/2/3/4/5): ";
            cin >> choice;

            if (choice == "1") {
                // Option 1: View complete data from the Mall table
                ResultSet* rsss = stmt->executeQuery("SELECT MALL_ID, MALLNAME, PHONENUM, ADDRESS, CITY FROM MALL");
                cout << "\nComplete data from the Mall table:\n" << endl;
                cout << left << setw(20) << "# Mall ID" << setw(30) << "Mall Name" << setw(20) << "Phone Number" << setw(20) << "Address" << setw(20) << "City" << endl;
                cout << left << setw(20) << "---------" << setw(30) << "---------" << setw(20) << "------------" << setw(20) << "-------" << setw(20) << "----" << endl;

                while (rsss->next()) {
                    int MALL_ID = rsss->getInt(1);
                    string MALLNAME = rsss->getString(2);
                    string PHONENUM = rsss->getString(3);
                    string ADDRESS = rsss->getString(4);
                    string CITY = rsss->getString(5);

                    cout << left << setw(20) << MALL_ID << setw(30) << MALLNAME << setw(20) << PHONENUM << setw(20) << ADDRESS << setw(20) << CITY << endl;
                }
            }
            else if (choice == "2") {
                // Option 2: Search for a specific mall
                string MALL_ID;
                cout << "Enter Mall ID to search: ";
                cin >> MALL_ID;
                ResultSet* rsss = stmt->executeQuery("SELECT MALL_ID, MALLNAME, PHONENUM, ADDRESS, CITY FROM MALL WHERE MALL_ID=" + MALL_ID);
                cout << "\nSearch result for Mall ID " << MALL_ID << ":\n" << endl;
                cout << left << setw(20) << "# Mall ID" << setw(30) << "Mall Name" << setw(20) << "Phone Number" << setw(20) << "Address" << setw(20) << "City" << endl;
                cout << left << setw(20) << "---------" << setw(30) << "---------" << setw(20) << "------------" << setw(20) << "-------" << setw(20) << "----" << endl;

                while (rsss->next()) {
                    int MALL_ID = rsss->getInt(1);
                    string MALLNAME = rsss->getString(2);
                    string PHONENUM = rsss->getString(3);
                    string ADDRESS = rsss->getString(4);
                    string CITY = rsss->getString(5);

                    cout << left << setw(20) << MALL_ID << setw(30) << MALLNAME << setw(20) << PHONENUM << setw(20) << ADDRESS << setw(20) << CITY << endl;
                }
            }
            else if (choice == "3") {
                // Option 3: View complete data from maintenance table
                ResultSet* maintenanceResultSet = stmt->executeQuery("SELECT MAINTENANCE_ID, MALL_ID, CONTRACTORCOMPANY, DUTYDESCRIPTION, SCHEDULEDDATE FROM MAINTENANCE");
                cout << "\nComplete data from the maintenance table:\n" << endl;
                cout << left << setw(20) << "Maintenance ID" << setw(20) << "Mall ID" << setw(23) << "Contractor Company" << setw(25) << "Duty Description" << setw(17) << "Scheduled Date" << endl;
                cout << left << setw(20) << "--------------" << setw(20) << "-------" << setw(23) << "------------------" << setw(25) << "----------------" << setw(17) << "--------------" << endl;

                while (maintenanceResultSet->next()) {
                    int maintenanceID = maintenanceResultSet->getInt(1);
                    int mallID = maintenanceResultSet->getInt(2);
                    string contractorCompany = maintenanceResultSet->getString(3);
                    string dutyDescription = maintenanceResultSet->getString(4);
                    string scheduledDate = maintenanceResultSet->getString(5);

                    cout << left << setw(20) << maintenanceID << setw(20) << mallID << setw(23) << contractorCompany << setw(25) << dutyDescription << setw(17) << scheduledDate << endl;
                }
            }
            else if (choice == "4") {
                // Option 4: Search for a specific maintenance instance
                string maintenance_id;
                cout << "Enter Maintenance ID to search: ";
                cin >> maintenance_id;
                ResultSet* maintenanceInstanceResultSet = stmt->executeQuery("SELECT MAINTENANCE_ID, MALL_ID, CONTRACTORCOMPANY, DUTYDESCRIPTION, SCHEDULEDDATE FROM MAINTENANCE WHERE MAINTENANCE_ID=" + maintenance_id);
                cout << "\nSearch result for Maintenance ID " << maintenance_id << ":\n" << endl;
                cout << left << setw(20) << "Maintenance ID" << setw(20) << "Mall ID" << setw(23) << "Contractor Company" << setw(25) << "Duty Description" << setw(17) << "Scheduled Date" << endl;
                cout << left << setw(20) << "--------------" << setw(20) << "-------" << setw(23) << "------------------" << setw(25) << "----------------" << setw(17) << "--------------" << endl;

                while (maintenanceInstanceResultSet->next()) {
                    int maintenanceID = maintenanceInstanceResultSet->getInt(1);
                    int mallID = maintenanceInstanceResultSet->getInt(2);
                    string contractorCompany = maintenanceInstanceResultSet->getString(3);
                    string dutyDescription = maintenanceInstanceResultSet->getString(4);
                    string scheduledDate = maintenanceInstanceResultSet->getString(5);

                    cout << left << setw(20) << maintenanceID << setw(20) << mallID << setw(23) << contractorCompany << setw(25) << dutyDescription << setw(17) << scheduledDate << endl;

                }
            }
            else if (choice == "5") {
                cout << "\nExiting the program..." << endl;
                break; // Exit the menu loop
            }
            else {
                cout << "\nInvalid choice. Please enter a valid option (1/2/3/4/5)." << endl;
            }
        }

        conn->terminateStatement(stmt);
        env->terminateConnection(conn);
        Environment::terminateEnvironment(env);
    }
    catch (SQLException& sqlExcp) {
        cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
    }

    return 0;
}
