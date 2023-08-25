#include "admin.h"
#include "SQL.h"

using namespace std;
void header() {
 system("clear");
  cout << "\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
  cout << "\t\t\t\t\t\t\t FOOD MANAGEMENT \n"  << endl;

}
void Admin::checkingConnSQL()
{
  Admin obj1;
  SQL obj2; 
  header() ; 
  cout << " \t\t\t\t\t Checking connection whit SQL databasa , please white ... \n"
       << endl;
  sleep(2);
  obj1.loadingAnimation();

  if (obj2.SQLconnection() == true ) { ; 
  obj1.adminLogin();
  }
  }

SQL::SQL(){}


Admin::Admin() {}

void Admin::loadingAnimation()
{
  int totalIterations = 100;

  for (int i = 0; i <= totalIterations; ++i)
  {
    float progress = static_cast<float>(i) / totalIterations;

    header() ; 

    std::cout << "\t\t\t\t\tLoading: [";

    int barWidth = 40;
    int progressWidth = static_cast<int>(barWidth * progress);

    for (int j = 0; j < barWidth; ++j)
    {
      if (j <= progressWidth)
      {
        cout << "#";
      }
      else
      {
        cout << ".";
      }
    }

    std::cout << "] " << int(progress * 100.0) << "%" << endl;

    this_thread::sleep_for(chrono::milliseconds(50));
  }

  std::cout << "\t\t\t\t\tLoading complete!" << endl;
}
void Admin::adminLogin()
{
  
  SQL obj ; 
  
  string adminName;
  string adminPass;
  
  obj.SQLgetAdminPassLogin();
  obj.swap(adminPass, adminName) ; 
  Admin admin(adminPass, adminName);

 
  sleep(1);
  header() ; 

  cout << "\t\t\t\t\t\tWelcome to the Admin Login Portal\n";

  string enteredAdminName;
  string enteredAdminPass;

  cout << "Admin Username: ";
  cin >> enteredAdminName;

  cout << "Admin Password: ";
  cin >> enteredAdminPass;

  if (admin.login(enteredAdminPass))
  {
    header() ; 
    cout << "\t\t\t\t\t\t\tLogin successful!\n";
  }
  else
  {
    cout << "\t\t\t\t\t\tLogin failed. Incorrect password or username.\n";
  }
}
void AdminPage()
{
  Admin obj;
  obj.checkingConnSQL();
}
int main()
{
  AdminPage();
  return 0;
}