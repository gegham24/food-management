#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <string>
#include "/usr/include/mysql/mysql.h"
#include <chrono>
#include <thread>
#include <cstdlib>
#include <unistd.h>
using namespace std;

class Admin {
private:
    const string userName;
    const string passWord;

public:
    Admin ( )  ; 
    Admin(const string& username, const string& password)
        : userName(username), passWord(password) {}

    bool login(const string& enteredPassword) {
        return passWord == enteredPassword;
    }
    
    void show () {
       cout << userName << endl << passWord<< endl ;  

    }
   
    void loadingAnimation() ;
    std::pair<MYSQL_RES *, int> Fetch_User(std::string Current_Admin_ID);
    void checkingConnSQL() ;
    void adminLogin() ;  
};

#endif // ADMIN_H