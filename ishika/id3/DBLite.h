#include <iostream>
#include <string>
#include <sqlite3.h>

using namespace std;

class DBLite {

	private:
		// Pointer to SQLite connection
    	sqlite3 *db;

    	// Save any error messages
    	char *zErrMsg;

    	// Save the result of opening the file
    	int rc;

    	// Saved SQL
    	char* sql;

    	// Compiled SQLite Statement
    	sqlite3_stmt *stmt;

    	// Create a callback function  
		static int callback(void *NotUsed, int argc, char **argv, char **azColName) {

		    // int argc: holds the number of results
		    // (array) azColName: holds each column returned
		    // (array) argv: holds each value

		    for(int i = 0; i < argc; i++) {
		        
		        // Show column name, value, and newline
		        cout << azColName[i] << ": " << argv[i] << endl;
		    
		    }

		    // Insert a newline
		    cout << endl;

		    // Return successful
		    return 0;
		}

		void checkDBErrors() {

			if( rc ){
		        // Show an error message
		        cout << "DB Error: " << sqlite3_errmsg(db) << endl;
		        
		        closeDB();
		        
    		}

		}


	public:

		DBLite() {
			// Save the result of opening the file
    		rc = sqlite3_open("example.db", &db);

    		checkDBErrors();
    
    		
		}

		void createTable() {

		    // Save SQL to create a table
		    sql = "CREATE TABLE PEOPLE (ID INT PRIMARY KEY NOT NULL, NAME TEXT NOT NULL);";
		    
		    // Run the SQL
		    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

		}

		void insertData(char* ID, char* name) {

			char *query = NULL;

			// Build a string using asprintf()
			asprintf(&query, "INSERT INTO PEOPLE ('ID', 'NAME') VALUES  ('%s', '%s');", ID, name);   

			// Prepare the query
		    sqlite3_prepare(db, query, strlen(query), &stmt, NULL);

		    // Test it
			rc = sqlite3_step(stmt);

			// Finialize the usage
			sqlite3_finalize(stmt);

			// Free up the query space
			free(query);     

		}

		void showTable() {

			// Save SQL insert data
    		sql = "SELECT * FROM 'PEOPLE';";
    
   			// Run the SQL
    		rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

		}

		void deleteRow(char* ID) {

			char *query = NULL;

			// Build a string using asprintf()
			asprintf(&query, "DELETE FROM 'PEOPLE' WHERE ID = '%s';", ID);   

			// Prepare the query
		    sqlite3_prepare(db, query, strlen(query), &stmt, NULL);

		    // Test it
			rc = sqlite3_step(stmt);

			// Finialize the usage
			sqlite3_finalize(stmt);

			// Free up the query space
			free(query);     

		}

		void closeDB() {

			// Close the SQL connection
    		sqlite3_close(db);

		}
	


};