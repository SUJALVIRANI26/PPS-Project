/**   Scientific calculator   */
#include<iostream>
#include<string>
#include<cmath>
#include<windows.h>
#include<iomanip>
#include "mathematics.h"
#include<exception>
using namespace std;

class Basic
{
  double a;
  char c;
  double b;
  double ans;
  public :
  double get_a()
  {
    return a;
  }
  double get_b()
  {
    return b;
  }
  char get_c()
  {
    return c;
  }
  void gD()
  {
    cin>>a>>c>>b;
  }
  void gD(double a,double b)
  {
    this->a=a;
    this->b=b;
  }
  double basic_cal_fun()
  {
    switch (c)
    {
      case  '+': cout<<"Ans = "<<a+b<<endl;
      break;
      case '-':cout<<"Ans = "<<a-b<<endl;
      break;
      case '*':cout<<"Ans = "<<a*b<<endl;
      break;
      case '/':cout<<"Ans = "<<a/b<<endl;
      break;
      case '^':cout<<"Ans = "<<pow(a,b)<<endl;
      break;
      default : cout<<"Please  Enter valid operator "<<endl;
      break;
    }
  }
};
class Matrix
{
 int r1;
 int r2;
 int c1;
 int c2;
 int **ptr1;
 int **ptr2;
  public :
  Matrix(){};
  Matrix(int r1,int c1,int r2 ,int c2):r1(r1),r2(r2),c1(c1),c2(c2)
  {
    int i=0;
    ptr1= new int *[r1];
     for(i=0;i<r1;i++)
      ptr1[i]=new int [c1];
    ptr2 =new int * [r2];
    for(int i=0;i<r2;i++)
      ptr2[i]=new int [c2];
  }
  ~Matrix()
  {
   for(int i=0;i<c1;i++)
    delete [] ptr1[i];
   for(int i=0;i<c2;i++)
    delete [] ptr2[i];
    delete []ptr1;
    delete []ptr2;
  }
   bool read();
   void cal();
   void add();
   void subtract();
   void mul();
};
class Log
{
   double var;
   public:
   void log_base_10();
   void log_base_e();
};
class Trigonometry
{
  protected:
  double var;
  int m;
  public :
  bool trig_fun();
  virtual int trigo()=0;
  virtual void trigonometry_function(int n)=0;
  virtual ~Trigonometry(){}
};
class Trigo : public Trigonometry
{
  public :
 virtual int trigo();
 virtual void trigonometry_function(int n);

};
class Inverse_Trigo : public Trigonometry
{
public :
virtual int trigo();
virtual void trigonometry_function(int n);
};
bool Quit() //this function is used to check is user want to Quit or not 
{
  if(cin.fail())
  {
  cin.clear();
  string s;
  getline(cin,s);
  if(s == "wq")
  return true;
  else
  return false;
  }
  fflush(stdin);
}
bool Quit(int n) // this function if user write wq than it will return true  else it show wrong input
{
   string s;
   while(1)
   {
    cout<<"Enter 'wq' for <-back : ";
    cin>>s;
    if(s == "wq")
    return true;
    else
    cout<<"Wrong input "<<endl;
   }
}

void factorial()
{
  system("cls");
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
  cout<<"Enter 'wq' for <- back "<<endl<<endl;
  SetConsoleTextAttribute(hConsole,FOREGROUND_INTENSITY);
  int var;
  while(1)
 {
  cout<<"Enter number for which you want to find factorial : ";
  cin>>var;
  if(cin.fail())
  {
    if(Quit())
    return;
    else
      cout<<"Please enter valid number"<<endl;
  }
  else
    cout<<var<<"! = "<<fact(var)<<endl<<endl;
 }
}

long double exponential( double a)
{
    long double result=0;
    long double m=0;
    for(int i=0;i<20;i++)
    {
        m=1;
        for(int j=0;j<i;j++)
            m*=a;
            result+=m/fact(i);  
    }
    return result;
}

void exponential()
{
  system("cls");
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
  cout<<"Enter 'wq' for <- back "<<endl<<endl;
  SetConsoleTextAttribute(hConsole,FOREGROUND_INTENSITY);
  double var;
  while(1)
  {
    cout<<"Enter number for which you wnat to find exponential : ";
    cin>>var;
    if(cin.fail())
    {
      if(Quit())
      return;
      else
      cout<<"Not a number"<<endl;
    }
    else
    cout<<"Ans = "<< exponential(var) <<endl;
  }
}

void Log :: log_base_e()
{
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
  cout<<"Enter 'wq' for <- back "<<endl<<endl;
  SetConsoleTextAttribute(hConsole,FOREGROUND_INTENSITY);
  while(1)
  {
   cout<<"Enter number for which you want to find logerithem : ";
    cin>>var;
    while(cin.fail())
    {
       if(Quit())
        return ;
       else
       {
        cout<<"Please enter valid number "<<endl;
        cin>>var;
       }
    }
    cout<<"ln("<<var<<") = "<<log(var)<<endl;
  } 
}

void Log :: log_base_10()
{
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
  cout<<"Enter 'wq' for <- back "<<endl<<endl;
  SetConsoleTextAttribute(hConsole,FOREGROUND_INTENSITY);
  
  while(1)
  {
   cout<<"Enter number for which you want to find logerithem : ";
    cin>>var;
    while(cin.fail())
    {
       if(Quit())
        return ;
       else
       {
        cout<<"Please enter valid number "<<endl;
        cin>>var;
       }
    }
    cout<<"log("<<var<<")"<<": "<<log10(var)<<endl;
  } 
}

void  logerithem()
{
  while(1)
  {
  system("cls");
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,FOREGROUND_INTENSITY);
 cout<<"1 : log value base 10 "<<endl;
 cout<<"2 : log value base e "<<endl;
 cout<<"3 : back "<<endl;
 int n;
 cout<<"Enter your choice : ";
 cin>>n;
 while(cin.fail() || !(n > 0 && n < 4))
 {
  if(Quit())
  return;
  else
  {
    cout<<"Please enter valid number : ";
    cin>>n;
  }
 }
 system("cls");
 Log l1;
  switch(n)
  {
   case 1  :
    l1.log_base_10();
   break;
   case 2 :
    l1.log_base_e();
   break;
   case 3 : return ;
  }
 } 
}

void Trigo ::trigonometry_function(int n)
  {
    system("cls");
    double x;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
     cout<<"Enter 'wq' for <- back "<<endl<<endl;
     SetConsoleTextAttribute(hConsole,FOREGROUND_INTENSITY);
     while(1)
     {
       cin>>var;
       while(cin.fail())
       {
          if(Quit())
           return  ;
          else
          {
           cout<<"Please enter valid number "<<endl;
           cin>>var;
          }
       }
        if(m == 2)
        {
            x = var;
            var = (var * M_PI) / 180.0;
        }
        else
        x=var;

        switch(n)
         {
             case 1 :cout<<"sin("<<x<<") = "<<sine(var)<<endl;
             break;
             case 2 : cout <<"cos("<<x<<") = "<<cosine(var)<<endl;
             break;
             case 3 :cout<<"tan("<<x<<") = "<<tangent(var)<<endl;
             break;
             case 4 :cout<<"cosec("<<x<<") = "<<(1/sine(var))<<endl;
             break;
             case 5 :cout<<"sec("<<x<<") = "<<(1/cosine(var))<<endl;
             break;
             case 6 :cout<<"cot("<<x<<") = "<<(1/tangent(var))<<endl;
             break;
          }
          cout<<endl;
     }
  }

void Inverse_Trigo ::trigonometry_function(int n)
  {
    system("cls");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
     cout<<"Enter 'wq' for <- back "<<endl<<endl;
     SetConsoleTextAttribute(hConsole,FOREGROUND_INTENSITY);
     while(1)
     {
       cin>>var;
       while(cin.fail())
       {
          if(Quit())
           return ;
          else
          {
           cout<<"Please enter valid number "<<endl;
           cin>>var;
          }
       }
       if(m == 2)
        {
          switch(n)
          {
           case 1 :cout<<"Inverse of sin "<<var<<" : ";
           cout<<((asin(var)*180.0)/M_PI)<<endl;
           break;
           case 2 :cout<<"Inverse of cos "<<var<<" : ";
           cout <<((acos(var)*180.0)/M_PI)<<endl;
           break;
           case 3 :cout<<"Inverse of tan "<<var<<" : ";
           cout<<((atan(var)*180.0)/M_PI)<<endl;
           break;
           case 4 :cout<<"Inverse of cosec "<<var<<" : ";
           cout<<((asin(1/var)*180.0)/M_PI)<<endl;
           break;
           case 5 :cout<<"Inverse of sec "<<var<<" : ";
           cout<<((acos(1/var)*180.0)/M_PI)<<endl;
           break;
           case 6 :cout<<"Inverse of cot "<<var<<" : ";
           cout<<((atan(1/var)*180.0)/M_PI)<<endl;
           break;
         } 
        }
        else
        {
          switch(n)
          {
           case 1 :cout<<"Inverse of sin "<<var<<" : ";
           cout<<asin(var)<<endl;
           break;
           case 2 : cout<<"Inverse of cos "<<var<<" : ";
           cout <<acos(var)<<endl;
            break;
           case 3 :cout<<"Inverse of tan "<<var<<" : ";
           cout<<atan(var)<<endl;
           break;
           case 4 :cout<<"Inverse of cosec "<<var<<" : ";
           cout<<(asin(1/var))<<endl;
           break;
           case 5 :cout<<"Inverse of sec "<<var<<" : ";
           cout<<(acos(1/var))<<endl;
            break;
            case 6 :cout<<"Inverse of cot "<<var<<" : ";
            cout<<(atan(1/var))<<endl;
            break;
         } 
        }
    }
}

int Inverse_Trigo ::trigo()
{
    system("cls");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,FOREGROUND_INTENSITY);
    int n;
    cout<<"1 : for Inverse of sin"<<endl;
    cout<<"2 : for Inverse of cos"<<endl;
    cout<<"3 : for Inverse of tan"<<endl;
    cout<<"4 : for Inverse of cosec"<<endl;
    cout<<"5 : for Inverse of sec"<<endl;
    cout<<"6 : for Inverse of cot"<<endl;
    cout<<"7 : back"<<endl;
    cout<<"Enter your choice : ";
    cin>>n;
    while(cin.fail() || (n > 7 || n <= 0))
    {
      if(Quit())
      return 7;
      else
      {
        cout<<"Please enter valid number "<<endl;
        cin>>n;
      }
    }
    return n;
  }

int Trigo ::trigo()
{
    int n;
  system("cls");
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,FOREGROUND_INTENSITY);
 
  cout<<"1 : sin0"<<endl;
  cout<<"2 : cos0"<<endl;
  cout<<"3 : tan0"<<endl;
  cout<<"4 : cosec0"<<endl;
  cout<<"5 : sec0"<<endl;
  cout<<"6 : cot0"<<endl;
  cout<<"7 : back"<<endl;
  cout<<"Enter your choice : ";
  cin>>n;
  while(cin.fail() || (n > 7 || n <= 0))
  {
    if(Quit())
    return 7;
    else
    {
      cout<<"Please enter valid number "<<endl;
      cin>>n;
    }
  }
 return n;
}


bool Trigonometry :: trig_fun()
{
    system("cls");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(hConsole,FOREGROUND_INTENSITY);

      cout<<"1 : for angle in radian "<<endl;
      cout<<"2 : for angle in degree "<<endl;
      cout<<"3 : back "<<endl;
      cout<<"Enter your choice : ";
      cin>>m;
    while( cin.fail() || (m > 3 || m <= 0))
    {
        if(Quit())
         return true;
        else
        {
         cout<<"Please enter valid number "<<endl;
         cin>>m;
        }
    }
    if(m == 3)
    return true;
    else
    return false;
}

void trigonometry(bool a)
{
    int k=0;
    Trigonometry * ptr ;
    if(a)
    {
        ptr = new Trigo;
    }
    else
    {
        ptr=new Inverse_Trigo;
    }
     while(!(ptr->trig_fun()))
     {
        while((k=ptr->trigo()) != 7)
        ptr->trigonometry_function(k);
     }
     delete ptr;
}  

void  Matrix :: mul() //mul two matrix and strore in third matrix and print it
{
  system("cls");
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
  cout<<"Enter 'wq' for <- back "<<endl<<endl;
  SetConsoleTextAttribute(hConsole,FOREGROUND_INTENSITY);
  double temp=0;
  for(int i = 0; i < r1 ; i++)
  {
    for(int j = 0 ; j < c2 ; j++)
    {
      for(int k = 0 ; k < c1 ; k++)
        temp+=(ptr1[i][k])*(ptr2[k][j]);
      cout<<temp<<' ';
    }
    cout<<endl;
  }
  Quit(1);
}

void Matrix:: subtract()//subtract matrix and store in third matrix and print it
{
  system("cls");
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
  cout<<"Enter 'wq' for <- back "<<endl<<endl;
  SetConsoleTextAttribute(hConsole,FOREGROUND_INTENSITY);
  for(int i = 0 ; i < r1 ; i++)
   {
    for(int j = 0 ; j < c1 ; j++)
      cout<< ptr1[i][j] - ptr2[i][j] <<' ';
    cout<<endl;
   }
   Quit(1);
}

void Matrix :: add() //add to matrix and store in third matrix and print it
{
  system("cls");
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
  cout<<"Enter 'wq' for <- back "<<endl<<endl;
  SetConsoleTextAttribute(hConsole,FOREGROUND_INTENSITY);
   for(int i = 0 ; i < r1; i++)
   {
    for(int j = 0 ; j < c1 ; j++)
      cout<< ptr1[i][j]+ptr2[i][j]<<' ';
    cout<<endl;
   }
  Quit(1);
}
void Matrix :: cal()
{
  while(1)
  {
   system("cls");
   HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(hConsole,FOREGROUND_INTENSITY);
   int k;
   cout<<"1 : add "<<endl;
   cout<<"2 : subtract"<<endl;
   cout<<"3 : multiplication "<<endl;
   cout<<"4 : back "<<endl;
   cout<<"Enter your choice :";
   while(1)
   {
    cin>>k;
    if(cin.fail() || !(k > 0 && k <= 4))
    {
     if(Quit()) 
       return;
     else
     cout<< "Please enter  number between 1 to 4 : ";
    }
    else
     break;
   }
    switch(k)
    {
     case 1 : 
      if(r1 == r2 && c1 == c2)
       add();
       else
       {
        cout<<"addition is not possible "<<endl;
        getchar();
        cout<<"Enter any key to continue ....."<<endl;
        getchar();
       }
       break;
      case 2 :
      if(r1 == r2 && c1 == c2)
        subtract();
        else
        {
         cout<<"subtraction is not possible"<<endl;
         getchar();
         cout<<"Enter any key to continue ....."<<endl;
         getchar();
        }
      break;
     case 3 :
       if(c1 == r2)
        mul();
        else
        {
         cout<<"multiplication is not possible "<<endl;
         getchar();
         cout<<"Enter any key to continue ....."<<endl;
         getchar();
        }
       break;
      case 4:
       return;
    }
 }
}
bool Matrix :: read()
{
  cout<<"Enter first matrix "<<endl;
  for(int i=0 ; i < r1 ; i++)//take matrix from user
  {
    for(int j=0 ; j < c1 ; j++)
    {
      cin>>ptr1[i][j];
      while(cin.fail())
      {
        if(Quit())
        return false;
        else
        cout<<"Please enter number : "<<endl;
        cin>>ptr1[i][j]; 
      }
    }
  } 
  fflush(stdin);
  cout<<endl;
  cout<<"Enter second matrix "<<endl;
  for(int i=0 ; i < r2 ; i++) //take input from 
  {
    for(int j=0 ; j < c2 ; j++)
    {
      cin>>ptr2[i][j];
      while(cin.fail())
      {
        if(Quit())
        return false;
        else
        cout<<"Please enter number : "<<endl;
        cin>>ptr2[i][j]; 
      }
    }
    cout<<endl;
  }
  fflush(stdin);
 return true;
}
void matrix() // this function is used to take matrix from user  
{
  system("cls");
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
  cout<<"Enter 'wq' for <- back "<<endl<<endl;
  SetConsoleTextAttribute(hConsole,FOREGROUND_INTENSITY);
  int r1,r2,c1,c2;
  cout <<"Enter First matrix's number of rows : ";
  cin>>r1;

  if(cin.fail())  // if user not give integer value then say them to give int value 
  {
    if(Quit())
     return ;
    else
    {
      cout<<"Please Enter number : ";
      cin>>r1;
    }
  }
  cout<<"Enter First matrix's number of colums : ";
  cin>>c1;
  if(cin.fail())
  {
    if(Quit())
     return ;
    else
    {
      cout<<"Please Enter number : ";
      cin>>c1;
    }
  }
  fflush(stdin);
  cout<<endl;
  cout<<"Enter Second matrix's number of rows : ";
  cin>>r2;

  if(cin.fail())
  {
    if(Quit())
     return ;
    else
    {
      cout<<"Please Enter number : ";
      cin>>r2;
    }
  }

  fflush(stdin);
  cout<<"Enter Second matrix's number of colums  :";
  cin>>c2;

  if(cin.fail())
  {
    if(Quit())
     return ;
    else
    {
      cout<<"Please Enter number : ";
      cin>>c2;
    }
  }

  fflush(stdin);
  cout<<endl;
  try
  {
    Matrix  matrix1(r1,c1,r2,c2);
    if(matrix1.read()==true)
    matrix1.cal();
    else
    return;
  }
  catch(exception& e)
  {
    cout << e.what() << '\n';
    cout<<"Enter any key to continue"<<endl;
    getchar();
     matrix();
  }
  catch(...)
  {
    cout<<"Something gone wrong"<<endl;
  }
       
}

void basic ()  // functiokn for basic calculation 
{
  system("cls");
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
  cout<<"Enter 'wq' for <- back "<<endl<<endl;
  SetConsoleTextAttribute(hConsole,FOREGROUND_INTENSITY);

  Basic basic_cal;

  while(!cin.fail())
  {
    basic_cal.gD();
    if(!cin.fail())
       basic_cal.basic_cal_fun();
    else
    {
      if(Quit())
      return ;
      else
      cout<<"Not a number  "<<endl;
    }
  }
}

int main()
{
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,FOREGROUND_INTENSITY);
  int n;
  system("cls");
  cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
 

  cout << R"(
                                           __        __   _                            _ 
                                           \ \      / /__| | ___ ___  _ __ ___   ___  | |
                                            \ \ /\ / / _ \ |/ __/ _ \| '_ ` _ \ / _ \ | |
                                             \ V  V /  __/ | (_| (_) | | | | | |  __/ |_|
                                              \_/\_/ \___|_|\___\___/|_| |_| |_|\___| (_)
                         )" << std::endl;
   
 cout<<"Enter any key to continue ........  ";
getchar();

cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;

  while(1)
  {
  system("cls");
  cout<<endl;

  cout<<"1 : Basic calculation  "<<endl;
  cout<<"2 : For matrix calculation  "<<endl;
  cout<<"3 : For triginomatric calculation "<<endl;
  cout<<"4 : For inverse trigonomtric calculation"<<endl;
  cout<<"5 : For logerithem "<<endl;
  cout<<"6 : For exponential function base e"<<endl;
  cout<<"7 : For factorial of any number"<<endl;
  cout<<"8 : Quit from calculator "<<endl;
  cout<<"Enter your choice : ";

  cin >>n;
  while(cin.fail() || !(n > 0 && n <= 8) )
  {
    if(Quit())
    return 0;
    else
    {
      cout<<"Please enter valid number : ";
       cin>>n;
    }
  }
    switch(n)
    {
      case 1 : basic();
      break;
      case 2 : matrix();
      break;
      case 3 : trigonometry(true);
      break;
      case 4 : trigonometry(false);
      break;
      case 5 : logerithem();
      break;
      case 6 : exponential();
      break;
      case 7 : factorial();
      break;
      case 8 : return 0;
    }
 }
}
