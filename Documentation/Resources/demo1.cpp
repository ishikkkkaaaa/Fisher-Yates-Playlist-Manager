#include <stdlib.h>
#include <iostream>
#include <mysql.h>
using namespace std;
int main(void)
{
  // std::vector<std::string> tables;
  MYSQL_RES *result;
  MYSQL_ROW row;
  MYSQL *connection, mysql;

  int state;

  mysql_init(&mysql);

  connection = mysql_real_connect(&mysql, "127.0.0.1", "root", "t3PX2S@1", "mysql", 0, 0, 0);   //连接数据库  mysql_real_connect(MYSQL *mysql, const char *host, const char *user, const char *passwd, const char *db, unsigned int port, const char *unix_socket, unsigned long clientflag)  

  // cout << connection;
  if (connection == NULL)
  {
    std::cout << mysql_error(&mysql) << std::endl;
    // return tables;
  }
  state = mysql_query(connection, "SHOW TABLES");
  if (state != 0)
  {
    std::cout << mysql_error(connection) << std::endl;
  }

  result = mysql_store_result(connection);

  std::cout << "tables: " << mysql_num_rows(result) << std::endl;
  while ((row = mysql_fetch_row(result)) != NULL)
  {
    cout << row[0] << std::endl;
  }

  mysql_free_result(result);
  mysql_close(connection);
}