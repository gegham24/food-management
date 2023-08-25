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
    void enterPassLog(string & enteredPass, string &enteredName ) ; 
    void checkingConnSQL() ;
    void adminLogin() ;
    void date () ;  
};

#endif // ADMIN_H