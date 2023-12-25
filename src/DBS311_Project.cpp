#define _CRT_SECURE_NO_WARNINGS
        
#include <iostream>
#include <occi.h>

        using namespace oracle::occi;
        using namespace std;

        Environment* env = nullptr;
        Connection* conn = nullptr;

        void initializeConnection() {
            env = Environment::createEnvironment(Environment::DEFAULT);
            conn = env->createConnection("id ", "pass", "connection string");
        }

        void terminateConnection() {
            env->terminateConnection(conn);
            Environment::terminateEnvironment(env);
        }
        Date stringToDate(const string& dateString, Environment* env) {
            struct tm timeInfo = {};

            // Parse the string into struct tm
            sscanf(dateString.c_str(), "%d-%d-%d", &timeInfo.tm_year, &timeInfo.tm_mon, &timeInfo.tm_mday);

            // Adjust year and month
            timeInfo.tm_year -= 1900;
            timeInfo.tm_mon -= 1;

            // Create a Date object
            Date dateObject(env, timeInfo.tm_year, timeInfo.tm_mon + 1, timeInfo.tm_mday);

            return dateObject;
        }


        void executeMallInsert() {
            try {
                Statement* stmt = conn->createStatement();

                // Input parameters
                int mall_ID;
                string mallName, phoneNum, address, city;

                cout << "Enter Mall ID: ";
                cin >> mall_ID;
                cout << "Enter Mall Name: ";
                cin >> mallName;
                cout << "Enter Phone Number: ";
                cin >> phoneNum;
                cout << "Enter Address: ";
                cin >> address;
                cout << "Enter City: ";
                cin >> city;

                int err_code;
                stmt->setSQL("BEGIN spMallInsert(:1, :2, :3, :4, :5, :6); END;");
                stmt->setInt(1, mall_ID);
                stmt->setString(2, mallName);
                stmt->setString(3, phoneNum);
                stmt->setString(4, address);
                stmt->setString(5, city);
                stmt->registerOutParam(6, Type::OCCIINT, sizeof(err_code));
                stmt->executeUpdate();

                err_code = stmt->getInt(6);

                if (err_code == 0) {
                    cout << "\n--> Mall inserted successfully.\n" << endl;
                }
                else if (err_code == -1) {
                    cout << "\n--> Error: Record already exists.\n" << endl;
                }
                else {
                    cout << "\n--> Error: Unknown error.\n" << endl;
                }

                conn->terminateStatement(stmt);
            }
            catch (SQLException& ex) {
                cout << "Error: " << ex.what() << endl;
            }
        }

        void executeMallUpdate() {
            try {
                Statement* stmt = conn->createStatement();

                // Input parameters
                int mall_ID;
                string mallName, phoneNum, address, city;

                cout << "Enter Mall ID to update: ";
                cin >> mall_ID;
                cout << "Enter New Mall Name: ";
                cin >> mallName;
                cout << "Enter New Phone Number: ";
                cin >> phoneNum;
                cout << "Enter New Address: ";
                cin >> address;
                cout << "Enter New City: ";
                cin >> city;

                int err_code;
                stmt->setSQL("BEGIN spMallUpdate(:1, :2, :3, :4, :5, :6); END;");
                stmt->setInt(1, mall_ID);
                stmt->setString(2, mallName);
                stmt->setString(3, phoneNum);
                stmt->setString(4, address);
                stmt->setString(5, city);
                stmt->registerOutParam(6, Type::OCCIINT, sizeof(err_code));
                stmt->executeUpdate();

                err_code = stmt->getInt(6);

                if (err_code == 0) {
                    cout << "\n--> Mall updated successfully.\n" << endl;
                }
                else if (err_code == -1) {
                    cout << "\n--> Error: No record found.\n" << endl;
                }
                else {
                    cout << "\n--> Error: Unknown error.\n" << endl;
                }

                conn->terminateStatement(stmt);
            }
            catch (SQLException& ex) {
                cout << "Error: " << ex.what() << endl;
            }
        }

        void executeMallDelete() {
            try {
                Statement* stmt = conn->createStatement();

                // Input parameters
                int mall_ID;

                cout << "Enter Mall ID to delete: ";
                cin >> mall_ID;

                int err_code;
                stmt->setSQL("BEGIN spMallDelete(:1, :2); END;");
                stmt->setInt(1, mall_ID);
                stmt->registerOutParam(2, Type::OCCIINT, sizeof(err_code));
                stmt->executeUpdate();

                err_code = stmt->getInt(2);

                if (err_code == 0) {
                    cout << "\n--> Mall deleted successfully.\n" << endl;
                }
                else if (err_code == -1) {
                    cout << "\n--> Error: No record found for deletion.\n" << endl;
                }
                else {
                    cout << "\n--> Error: SQLCODE " << err_code << endl;
                }

                conn->terminateStatement(stmt);
            }
            catch (SQLException& ex) {
                cout << "\n--> Error: " << ex.what() << endl;
            }
        }

        void executeSelectMall(Connection* conn) {
            int err = 0;
            int mall_id;
            string mallname, phonenum, address, city;

            cout << endl;
           
            cout << "Enter Mall ID: ";
            cin >> mall_id;

            Statement* stmt = conn->createStatement();
            string plsql = "BEGIN readmall(:1, :2, :3, :4, :5, :6); END;";
            stmt->setSQL(plsql);
            stmt->registerOutParam(1, Type::OCCIINT, sizeof(err));
            stmt->setInt(2, mall_id);
            stmt->registerOutParam(3, Type::OCCISTRING, 50);  // Assuming the size of mallname is 50
            stmt->registerOutParam(4, Type::OCCISTRING, 12);  // Assuming the size of phonenum is 12
            stmt->registerOutParam(5, Type::OCCISTRING, 50);  // Assuming the size of address is 50
            stmt->registerOutParam(6, Type::OCCISTRING, 50);  // Assuming the size of city is 50

            stmt->executeUpdate();

            err = stmt->getInt(1);
            mallname = stmt->getString(3);
            phonenum = stmt->getString(4);
            address = stmt->getString(5);
            city = stmt->getString(6);

            if (err >= 0) {
                cout << "Mall ID: " << mall_id << endl;
                cout << "Mall Name: " << mallname << endl;
                cout << "Phone Number: " << phonenum << endl;
                cout << "Address: " << address << endl;
                cout << "City: " << city << endl << endl;
            }
            else {
                cout << "Error: Unable to read mall information.\n" << endl;
            }

            conn->terminateStatement(stmt);
        }
        void executeMaintenanceInsert() {
            try {
                Statement* stmt = conn->createStatement();

                // Input parameters
                int maintenance_ID, mall_ID;
                string contractorCompany, dutyDescription, scheduledDateStr;
                Date scheduledDate;

                cout << "Enter Maintenance ID: ";
                cin >> maintenance_ID;
                cout << "Enter Mall ID: ";
                cin >> mall_ID;
                cout << "Enter Contractor Company: ";
                cin >> contractorCompany;
                cout << "Enter Duty Description: ";
                cin >> dutyDescription;
                cout << "Enter Scheduled Date (YYYY-MM-DD): ";
                cin >> scheduledDateStr;

                scheduledDate = stringToDate(scheduledDateStr,env);

                int err_code;
                stmt->setSQL("BEGIN spMaintenanceInsert(:1, :2, :3, :4, :5, :6); END;");
                stmt->setInt(1, maintenance_ID);
                stmt->setInt(2, mall_ID);
                stmt->setString(3, contractorCompany);
                stmt->setString(4, dutyDescription);
                stmt->setDate(5, scheduledDate);
                stmt->registerOutParam(6, Type::OCCIINT, sizeof(err_code));
                stmt->executeUpdate();

                err_code = stmt->getInt(6);

                if (err_code == 0) {
                    cout << "\n--> Maintenance record inserted successfully." << endl;
                }
                else if (err_code == -1) {
                    cout << "\n--> Error: Record already exists." << endl;
                }
                else {
                    cout << "\n--> Error: SQLCODE " << err_code << endl;
                }

                conn->terminateStatement(stmt);
            }
            catch (SQLException& ex) {
                cout << "\n--> Error: " << ex.what() << endl;
            }
        }

        void executeMaintenanceUpdate() {
            try {
                Statement* stmt = conn->createStatement();

                // Input parameters
                int maintenance_ID, mall_ID;
                string contractorCompany, dutyDescription, scheduledDateStr;
                Date scheduledDate;

                cout << "Enter Maintenance ID to update: ";
                cin >> maintenance_ID;
                cout << "Enter New Mall ID: ";
                cin >> mall_ID;
                cout << "Enter New Contractor Company: ";
                cin >> contractorCompany;
                cout << "Enter New Duty Description: ";
                cin >> dutyDescription;
                cout << "Enter New Scheduled Date (YYYY-MM-DD): ";
                cin >> scheduledDateStr;

                scheduledDate = stringToDate(scheduledDateStr,env);

                int err_code;
                stmt->setSQL("BEGIN spMaintenanceUpdate(:1, :2, :3, :4, :5, :6); END;");
                stmt->setInt(1, maintenance_ID);
                stmt->setInt(2, mall_ID);
                stmt->setString(3, contractorCompany);
                stmt->setString(4, dutyDescription);
                stmt->setDate(5, scheduledDate);
                stmt->registerOutParam(6, Type::OCCIINT, sizeof(err_code));
                stmt->executeUpdate();

                err_code = stmt->getInt(6);

                if (err_code == 0) {
                    cout << "\n--> Maintenance record updated successfully." << endl;
                }
                else if (err_code == -1) {
                    cout << "\n--> Error: No record found." << endl;
                }
                else {
                    cout << "\n--> Error: SQLCODE " << err_code << endl;
                }

                conn->terminateStatement(stmt);
            }
            catch (SQLException& ex) {
                cout << "\n--> Error: " << ex.what() << endl;
            }
        }

        // Maintenance Delete
        void executeMaintenanceDelete() {
            try {
                Statement* stmt = conn->createStatement();

                // Input parameters
                int maintenance_ID;

                cout << "Enter Maintenance ID to delete: ";
                cin >> maintenance_ID;

                int err_code;
                stmt->setSQL("BEGIN spMaintenanceDelete(:1, :2); END;");
                stmt->setInt(1, maintenance_ID);
                stmt->registerOutParam(2, Type::OCCIINT, sizeof(err_code));
                stmt->executeUpdate();

                err_code = stmt->getInt(2);

                if (err_code == 0) {
                    cout << "\n--> Maintenance record deleted successfully." << endl;
                }
                else if (err_code == -1) {
                    cout << "\n--> Error: No record found." << endl;
                }
                else {
                    cout << "\n--> Error: SQLCODE " << err_code << endl;
                }

                conn->terminateStatement(stmt);
            }
            catch (SQLException& ex) {
                cout << "\n--> Error: " << ex.what() << endl;
            }
        }

        // Maintenance Select
        void executeMaintenanceSelect(Connection* conn) {
            int err = 0;
            int maintenance_id;
            int mall_id;
            string contractorcompany, dutydescription;
            Date scheduledDate;

            cout << endl;
            cout << "Enter Maintenance ID: ";
            cin >> maintenance_id;

            Statement* stmt = conn->createStatement();
            string plsql = "BEGIN readmaintenance(:1, :2, :3, :4, :5, :6); END;";
            stmt->setSQL(plsql);
            stmt->registerOutParam(1, Type::OCCIINT, sizeof(err));
            stmt->setInt(2, maintenance_id);
            stmt->registerOutParam(3, Type::OCCIINT, sizeof(int));
            stmt->registerOutParam(4, Type::OCCISTRING, 50);  // Assuming the size of contractorcompany is 50
            stmt->registerOutParam(5, Type::OCCISTRING, 50);  // Assuming the size of dutydescription is 50
            stmt->registerOutParam(6, Type::OCCIDATE, sizeof(Date));

            stmt->executeUpdate();

            err = stmt->getInt(1);
            mall_id = stmt->getInt(3);
            contractorcompany = stmt->getString(4);
            dutydescription = stmt->getString(5);
            scheduledDate = stmt->getDate(6);

            if (err >= 0) {
                cout << "Maintenance ID: " << maintenance_id << endl;
                cout << "Mall ID: " << mall_id << endl;
                cout << "Contractor Company: " << contractorcompany << endl;
                cout << "Duty Description: " << dutydescription << endl;
                cout << "Scheduled Date: " << scheduledDate.toText("YYYY-MM-DD") << endl << endl;
            }
            else {
                cout << "Error: Unable to read maintenance information.\n" << endl;
            }

            conn->terminateStatement(stmt);
        }

        int main() {

            cout << "|-------------------------------------|\n";
            cout << "|Name : Abhay Mahendera               |\n";             
            cout << "|Student ID : 174811216               |\n";
            cout << "|Email : abhay - mahendera@myseneca.ca|\n";
            cout << "|-------------------------------------| \n\n";
            try {
                initializeConnection();

                int choice;

                do {
                    cout << "Choose an option:" << endl;
                    cout << "\n--> Mall <--\n";
                    cout << "------------\n";
                    cout << "1. Insert Mall" << endl;
                    cout << "2. Update Mall" << endl;
                    cout << "3. Delete Mall" << endl;
                    cout << "4. Select Mall" << endl;
                    cout << "\n--> Maintenance <--\n";
                    cout << "-------------------\n";
                    cout << "5. Insert Maintenance" << endl;
                    cout << "6. Update Maintenance" << endl;
                    cout << "7. Delete Maintenance" << endl;
                    cout << "8. Select Maintenance" << endl;
               
                    cout << "0. Exit" << endl;
                    cout << "Enter your choice: ";
                    cin >> choice;

                    switch (choice) {
                    case 1:
                        executeMallInsert();
                        conn->commit();
                        break;
                    case 2:
                        executeMallUpdate();
                        conn->commit();
                        break;
                    case 3:
                        executeMallDelete();
                        conn->commit();
                        break;
                    case 4:
                        executeSelectMall(conn);
                        conn->commit();
                        break;
                   
                    case 5:
                        executeMaintenanceInsert();
                        conn->commit();
                        break;
                    case 6:
                        executeMaintenanceUpdate();
                        conn->commit();
                        break;
                    case 7:
                        executeMaintenanceDelete();
                        conn->commit();
                        break;
                    case 8:
                        executeMaintenanceSelect(conn);
                        conn->commit();
                        break;
                    case 0:
                        break;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                    }
                } while (choice != 0);

                terminateConnection();
            }
            catch (SQLException& ex) {
                cout << "Error: " << ex.what() << endl;
            }

            return 0;
        }

