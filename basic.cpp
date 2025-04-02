/**   Scientific calculator   */
#include<iostream>
#include<string>
#include<cmath>
#include<windows.h>
#include<iomanip>
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
      case '^':cout<<"Ans = "<<(a,b)<<endl;
      break;
      default : cout<<"Please  Enter valid operator "<<endl;
      break;
    }
  }
};
bool Quit(int n) //this function if anyone wrijo mste Quit than it will return else it show wrong input
{
 
    string s;
   while(1)
   {
    cout<<"Enter 'wq' for <-back : ";
    cin>>s;
    if(s=="wq")
    return true;
    else
    cout<<"Wrong input "<<endl;
   }
  
}
bool Quit() //this function is used to check is user want to Quit or not 
{
  if(cin.fail())
  {
  cin.clear();
  string s;
  getline(cin,s);
  if(s=="wq")
  return true;
  else
  return false;
  }
  fflush(stdin);
}
void basic ()
{
  system("cls");//clear console 
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
  cout<<"Enter 'wq' for <- back "<<endl<<endl;
  SetConsoleTextAttribute(hConsole,FOREGROUND_INTENSITY);
  Basic basic_cal;
  while(!cin.fail())
  {
    basic_cal.gD();
    if(!cin.fail())
    {
       basic_cal.basic_cal_fun();
    }
    else
    {
      if(Quit())
      return ;
      else
      cout<<"NOT A NUMBER  "<<endl;
    }
  }
}
bool read(int r1,int c1,int r2,int c2,double *m1,double *m2)
{
  cout<<"Enter first matrix "<<endl;
  for(int i=0;i<r1;i++) //take matrix from user
  {
    for(int j=0;j<c1;j++)
    {
      cin>>*(m1+i*r1+j);
      while(cin.fail())
      {
        if(Quit())
        return false;
        else
        cout<<"Please enter number : "<<endl;
        cin>>*(m1+i*r1+j); 
      }
    }
  } 
  fflush(stdin);
  cout<<endl;
  cout<<"Enter second matrix "<<endl;
  for(int i=0;i<r2;i++) //take input from 
  {
    for(int j=0;j<c2;j++)
    {
      cin>>*(m2+i*r1+j);
      while(cin.fail())
      {
        if(Quit())
        return false;
        else
        cout<<"Please enter number : "<<endl;
        cin>>*(m1+i*r1+j); 
      }
    }
  }
  fflush(stdin);
 return true;
}
void add(int r1,int c1,double  * m1,double * m2,double *m3) //add to matrix and store in third matrix and print it
{
  system("cls");
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
  cout<<"Enter 'wq' for <- back "<<endl<<endl;
  SetConsoleTextAttribute(hConsole,FOREGROUND_INTENSITY);
   for(int i=0;i<r1;i++)
   {
    for(int j=0;j<c1;j++)
    {
      *(m3+i*r1+j) = *(m1+i*r1+j)+*(m2+i*r1+j);
      cout<< *(m3+i*r1+j)<<' ';
    }
    cout<<endl;
   }
  Quit(1);
}
void subtract(int r1,int c1,double *m1,double *m2,double *m3)//subtract matrix and store in third matrix and print it
{
  system("cls");
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
  cout<<"Enter 'wq' for <- back "<<endl<<endl;
  SetConsoleTextAttribute(hConsole,FOREGROUND_INTENSITY);
  for(int i=0;i<r1;i++)
   {
    for(int j=0;j<c1;j++)
    {
      *(m3+i*r1+j) = *(m1+i*r1+j)-*(m2+i*r1+j);
      cout<< *(m3+i*r1+j)<<' ';
    }
    cout<<endl;
   }
   Quit(1);
}
void mul(int r1,int c1,int c2,double *m1,double *m2,double *m3) //mul two matrix and strore in third matrix and print it
{
  system("cls");
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
  cout<<"Enter 'wq' for <- back "<<endl<<endl;
  SetConsoleTextAttribute(hConsole,FOREGROUND_INTENSITY);
  for(int i=0;i<r1;i++)
  {
    for(int j=0;j<c2;j++)
    {
      for(int k=0;k<c1;k++)
      {
        *(m3+i*r1+j)+=(*(m1+i*r1+k))*(*(m2+k*r1+j));
      }
      cout<<*(m3+i*r1+j)<<' ';
    }
    cout<<endl;
  }
  Quit(1);
}

void cal(int r1,int c1,int r2,int c2,double *m1,double *m2 ,double *m3)
{
  while(1)
  {
   system("cls");
   HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
   cout<<"Enter 'wq' for <- back "<<endl<<endl;
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
    if(cin.fail() || !(k>0 && k<=4))
    {
     if(Quit()) 
       return;
     else
     cout<<"Please enter  number between 1 to 4 : ";
    }
    else
     break;
   }
    switch(k)
    {
     case 1 : 
      if(r1==r2 && c1==c2)
       add(r1,c1,m1,m2,m3);
       else
       {
        cout<<"addition is not possible "<<endl;
        getchar();
        cout<<"Enter any key to continue ....."<<endl;
        getchar();
       }
       break;
      case 2 :
      if(r1==r2 && c1==c2)
        subtract(r1,c1,m1,m2,m3);
        else
        {
         cout<<"subtraction is not possible"<<endl;
         getchar();
         cout<<"Enter any key to continue ....."<<endl;
         getchar();
        }
      break;
     case 3 :
       if(c1==r2)
        mul(r1,c1,c2,m1,m2,m3);
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
  double m1[r1][c1],m2[r2][c2],m3[r1][c2];
  if(read(r1,c1,r2,c2,&m1[0][0],&m2[0][0]))
  cal(r1,c1,r2,c2,&m1[0][0],&m2[0][0],&m3[0][0]);
  else
  return ;
}
void trig_fun(int n,int m,bool a)
{
  system("cls");
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
   cout<<"Enter 'wq' for <- back "<<endl<<endl;
   SetConsoleTextAttribute(hConsole,FOREGROUND_INTENSITY);
  double var;
  
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
    if(m==2 && a==false)
      var=(var * M_PI) / 180.0;
      if(a)
      {
        if(m==2)
        {
          switch(n)
          {
           case 1 :
           cout<<((asin(var)*180.0)/M_PI)<<endl;
           break;
           case 2 :
           cout <<((acos(var)*180.0)/M_PI)<<endl;
           break;
           case 3 :
           cout<<((atan(var)*180.0)/M_PI)<<endl;
           break;
           case 4 :
           cout<<((asin(1/var)*180.0)/M_PI)<<endl;
           break;
           case 5 :
           cout<<((acos(1/var)*180.0)/M_PI)<<endl;
           break;
           case 6 :
           cout<<((atan(1/var)*180.0)/M_PI)<<endl;
           break;
         } 
        }
        else
        {
          switch(n)
          {
           case 1 :
           cout<<asin(var)<<endl;
           break;
           case 2 : cout <<acos(var)<<endl;
            break;
            case 3 :cout<<atan(var)<<endl;
           break;
           case 4 :cout<<(asin(1/var))<<endl;
           break;
           case 5 :cout<<(acos(1/var))<<endl;
            break;
            case 6 :cout<<(atan(1/var))<<endl;
            break;
         } 
        }
      }
      else
      {
        switch(n)
         {
           case 1 :cout<<sin(var)<<endl;
           break;
           case 2 : cout <<cos(var)<<endl;
           break;
           case 3 :cout<<tan(var)<<endl;
           break;
           case 4 :cout<<(1/sin(var))<<endl;
           break;
           case 5 :cout<<(1/cos(var))<<endl;
           break;
           case 6 :cout<<(1/tan(var))<<endl;
           break;
         }
        }
  } 
}
void inverse_trigo(int m)
{
  while(1)
  {
  system("cls");
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
  cout<<"Enter 'wq' for <- back "<<endl<<endl;
  SetConsoleTextAttribute(hConsole,FOREGROUND_INTENSITY);
  int n;
  {
  cout<<"1 : for Inverse of sin"<<endl;
  cout<<"2 : for Inverse of cos"<<endl;
  cout<<"3 : for Inverse of tan"<<endl;
  cout<<"4 : for Inverse of cosec"<<endl;
  cout<<"5 : for Inverse of sec"<<endl;
  cout<<"6 : for Inverse of cot"<<endl;
  cout<<"7 : back"<<endl;
  cout<<"Enter your choice : ";
  }
  cin>>n;
  while(cin.fail() || (n>7 || n<=0))
  {
    if(Quit())
    return;
    else
    {
      cout<<"Please enter valid number "<<endl;
      cin>>n;
    }
  }
  switch(n)
  {
    case 7 :return ;
    default : trig_fun(n,m,true);
    break;
  }
 } 
}
void trigo( int m)
{
  while(1)
  {
  system("cls");
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
  cout<<"Enter 'wq' for <- back "<<endl<<endl;
  SetConsoleTextAttribute(hConsole,FOREGROUND_INTENSITY);
  int n;
  cout<<"1 : sin0"<<endl;
  cout<<"2 : cos0"<<endl;
  cout<<"3 : tan0"<<endl;
  cout<<"4 : cosec0"<<endl;
  cout<<"5 : sec0"<<endl;
  cout<<"6 : cot0"<<endl;
  cout<<"7 : back"<<endl;
  cout<<"Enter your choice : ";
  cin>>n;
  while(cin.fail() || (n>7 || n<=0))
  {
    if(Quit())
    return;
    else
    {
      cout<<"Please enter valid number "<<endl;
      cin>>n;
    }
  }
  switch(n)
  {
    case 7 : return;
    default : trig_fun(n,m,false);
    break;
  }
 }
}
void trigonometric_function(bool a=false)
{

  int n;
  while(1)
  {
    system("cls");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
   cout<<"Enter 'wq' for <- back "<<endl<<endl;
   SetConsoleTextAttribute(hConsole,FOREGROUND_INTENSITY);
    if(a)
    {
      cout<<"1 : for angle in radian "<<endl;
      cout<<"2 : for angle in degree "<<endl;
      cout<<"3 : back "<<endl;
      cout<<"Enter your choice : ";
    }
    else
    {
      cout<<"1 : for input in radian "<<endl;
      cout<<"2 : for input in degree "<<endl;
      cout<<"3 : back "<<endl;
      cout<<"Enter your choice : ";
    }
  cin>>n;
  while(cin.fail() || (n>3 || n<=0))
  {
    if(Quit())
    return;
    else
    {
      cout<<"Please enter valid number "<<endl;
      cin>>n;
    }
  }
  switch(n)
  {
    case 3 :
    return ;
    default:
    if(!a)
    trigo(n);
    else
    inverse_trigo(n);
    break;
  }
 }
}
void log_base_10()
{
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
  cout<<"Enter 'wq' for <- back "<<endl<<endl;
  SetConsoleTextAttribute(hConsole,FOREGROUND_INTENSITY);
  double var;
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
    cout<<log10(var)<<endl;
  } 
}
void log_base_e()
{
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
  cout<<"Enter 'wq' for <- back "<<endl<<endl;
  SetConsoleTextAttribute(hConsole,FOREGROUND_INTENSITY);
  double var;
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
    cout<<log(var)<<endl;
  } 
}
void logerithem()
{
  while(1)
  {
  system("cls");
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
  cout<<"Enter 'wq' for <- back "<<endl<<endl;
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
  switch(n)
  {
   case 1  :cout<<"Enter number for which you want to find logerithem : ";
    log_base_10();
   break;
   case 2 :cout<<"Enter number for which you want to find logerithem : ";
   log_base_e();
   break;
   case 3 : return ;
  }
}
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
      cout<<"NOT A NUMBER"<<endl;
    }
    else
    cout<<"Ans = "<<exp(var)<<endl;
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
   
  // cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
 cout<<"Enter any key to continue ........  ";
getchar();

cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;

  while(1)
  {
  system("cls");
  cout<<endl;
  cout<<"1 : basic calculation  "<<endl;
  cout<<"2 : for matrix calculation  "<<endl;
  cout<<"3 : for triginomatric calculation "<<endl;
  cout<<"4 : for inverse trigonomtric calculation"<<endl;
  cout<<"5 : for logerithem "<<endl;
  cout<<"6 : for exponential function base e"<<endl;
  cout<<"7 : Quit from calculator "<<endl;
  cout<<"Enter your choice : ";
  cin >>n;
  if(cin.fail() || !(n>0 && n<=7))
  {
    if(Quit())
    return 0;
    else
    {
      cout<<"Please enter valid number : ";
      cout<<"Enter any key to continue ...";
      getchar();
    }
    
    
  }
  else
  {
    switch(n)
    {
      case 1 :basic();
      break;
      case 2 : matrix();
      break;
      case 3 : trigonometric_function(false);
      break;
      case 4 : trigonometric_function(true);
      break;
      case 5 : logerithem();
      break;
      case 6 : exponential();
      break;
      case 7:return 0;
    }
  }
}
}
