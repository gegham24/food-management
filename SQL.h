#ifndef SQL_H
#define SQL_H

#include "/usr/include/mysql/mysql.h"
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
class SQL
{
private:
    string  password ; 
    string  adminname ; 
    char server[30] = "sql8.freesqldatabase.com";
    char username[25] = "sql8641083";
    char SQLpassword[25] = "FribjdlGNv";
    char database[25] = "sql8641083";
    MYSQL *conn = mysql_init(NULL);

public:
    SQL();
    bool SQLconnection()
    {
        if (mysql_real_connect(conn, server, username, SQLpassword, database, 0, nullptr, 0) == nullptr)
        {
            cout<< "\t\t\t\t\t\tUnable to connect with MySQL server\n";
            mysql_close(conn);
            return false;
        }

        if (mysql_query(conn, "SELECT * FROM Admin"))
        {
            cout<< "\t\t\t\t\tQuery execution error." << std::endl;
            mysql_close(conn);
            return false;
        }
        MYSQL_RES *result = mysql_store_result(conn);
        if (result == nullptr)
        {
            cout << "\t\t\t\t\tResult fetching error." << std::endl;
            mysql_close(conn);
            return false;
        }
        else
        {
            cout <<("\t\t\t\t\t\t\tYour connection is successful!!!\n");
            return true;
        }
    }
  
 void SQLgetAdminPassLogin()
 
{
    if (mysql_real_connect(conn, server, username, SQLpassword, database, 0, nullptr, 0) == nullptr)
    {
        std::cerr << "Unable to connect with MySQL server\n";
        return;
    }

    if (mysql_query(conn, "SELECT * FROM Admin"))
    {
        std::cerr << "Query execution error." << std::endl;
        mysql_close(conn);
        return;
    }

    MYSQL_RES *result = mysql_store_result(conn);
    if (result == nullptr)
    {
        std::cerr << "Result fetching error." << std::endl;
        mysql_close(conn);
        return;
    }

    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result)))
    {
        for (int i = 0; i < num_fields; ++i)
        {
            if (row[i] != nullptr && i == 0)
            {
                adminname = row[i];
              
            }
            else if (row[i] != nullptr && i == 1)
            {
                password = row[i];
              
            }
        }
        std::cout << std::endl;
    }

    mysql_free_result(result);
    mysql_close(conn);
}

    void show () {
        cout << password <<adminname << endl ; 
    }
    void swap  (string & passWord , string & adminName ) {
          passWord = password ; 
          adminName = adminname ; 
    }
};

#endif // SQL_H