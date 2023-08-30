#include "admin.h"
#include "SQL.h"

using namespace std;


int getTerminalWidth()
{
  struct winsize size;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
  return size.ws_col;
}
void centeredText(const string &text)
{

  int terminalWidth = getTerminalWidth();

  int textWidth = text.length();
  int padding = (terminalWidth - textWidth) / 2;

  cout << setw(padding + textWidth) << text  ;
}
void centeredTextEndl(const string &text)
{

  int terminalWidth = getTerminalWidth();

  int textWidth = text.length();
  int padding = (terminalWidth - textWidth) / 2;

  cout << setw(padding + textWidth) << text << endl ;
}
void header()
{
  system("clear");
  centeredTextEndl("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
  centeredTextEndl("FOOD MANAGEMENT ");
}
void Admin::checkingConnSQL()  
{
  Admin obj1;
  SQL obj2;
  header();
  centeredTextEndl("Checking connection whit SQL databasa , please white ..."); 
  sleep(2);

  if (obj2.SQLconnection() == true)
  {
    obj1.loadingAnimation();
    obj1.adminLogin();
  }
}

SQL::SQL() {}

Admin::Admin() {}

void Admin::loadingAnimation()
{
  int totalIterations = 100;

  for (int i = 0; i <= totalIterations; ++i)
  {
    float progress = static_cast<float>(i) / totalIterations;

    header();

    cout << "\t\t\t\t\t\t\tLoading: [ "; 

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

    cout << " ] " << int(progress * 100.0) << "%" << endl;

    this_thread::sleep_for(chrono::milliseconds(50));
  }

  centeredTextEndl("Loading complete!") ; 
}
void Admin::adminLogin()
{

  SQL obj;
  Admin obj2;

  string adminName;
  string adminPass;

  obj.SQLgetAdminPassLogin();
  obj.alignment(adminPass, adminName);
  Admin admin(adminPass, adminName);

  sleep(1);
  header();

  centeredTextEndl("Welcome to the Admin Login Portal");

  string enteredAdminName;
  string enteredAdminPass;
  Admin::enterPassLog(enteredAdminPass, enteredAdminName);
  int attempt = 0;
  if (admin.login(enteredAdminPass , enteredAdminName))
  {
    header();
  centeredTextEndl("Login successful!");
    admin.adminMainPage();
  }
  else
  {
    while (attempt != 3)
    {

      header();
      attempt++;
      centeredText("Incorrect Password Attempt (");
      cout << attempt << " of 3):\n";
      centeredTextEndl("Try again !!"); 

      Admin::enterPassLog(enteredAdminPass, enteredAdminName);
      if (admin.login(enteredAdminPass, enteredAdminName))
      {
        header();
       centeredTextEndl("Login successful!"); 
        admin.adminMainPage();
        break;
      }
      else if (attempt == 3)
      {

        system("clear");
        centeredTextEndl("Too Many Incorrect Password Attempts:") ; 
        sleep(1);
        exit(1);
      }
    }
  }
}
void Admin::enterPassLog(string &enteredPass, string &enteredName)
{

  cout << "Admin Username: ";
  cin >> enteredName;

  cout << "Admin Password: ";
  cin >> enteredPass;
}
void AdminPage()
{
  Admin obj;
  obj.checkingConnSQL();
}
void Admin::date()
{

  string command = "date '+%Y-%m-%d %H:%M:%S'";
  string result = "";

  FILE *pipe = popen(command.c_str(), "r");

  char buffer[128];
  while (fgets(buffer, sizeof(buffer), pipe) != nullptr)
  {
    result += buffer;
  }

  pclose(pipe);

  cout << result << endl;
}
void Admin::adminMainPage()
{

  header();
  centeredTextEndl("Main Page");
}

int main()
{
  AdminPage();
  return 0;
}