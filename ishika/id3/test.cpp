#include "DBLite.h"

int main() {

    
    DBLite sqldb;
    sqldb.createTable();
    sqldb.insertData("1", "Dan");
    sqldb.insertData("2", "Jeff");
    sqldb.insertData("3", "Cara");
    sqldb.showTable();
    sqldb.deleteRow("3");
    sqldb.showTable();
    sqldb.closeDB();
    
    return 0;
}