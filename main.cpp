#include <iostream>
#include <sqlite3.h>
#include "Employee.h"
#include "Training.h"


int main() {
    sqlite3* db;
    const char* dbPath = "/Users/ellakerrigan/Downloads/SRC_DATABASE.db"; 

    // Open the SQLite database
    int status = sqlite3_open(dbPath, &db);
    if (status != SQLITE_OK) {
        std::cerr << "Error opening database" << std::endl;
        return 1;
    }

    // TESTING retrieve employee names
    const char* sqlQuery = "SELECT Name FROM Employees";
    sqlite3_stmt* statement;
    status = sqlite3_prepare_v2(db, sqlQuery, -1, &statement, nullptr);
    if (status != SQLITE_OK) {
        std::cerr << "Error preparing statement" << std::endl;
        sqlite3_close(db);
        return 1;
    }

    // get employee names and print
    while (sqlite3_step(statement) == SQLITE_ROW) {
        const unsigned char* name = sqlite3_column_text(statement, 0);
        std::cout << "Employee Name: " << name << std::endl;
    }

    //  close database
    sqlite3_finalize(statement);
    sqlite3_close(db);

    return 0;
}
