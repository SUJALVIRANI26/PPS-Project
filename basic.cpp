#include<iostream>
#include<cmath>
#include<string>
using namespace std;
void  basic ()
{
  cout<<"For exit write Quit"<<endl;
  double a,b;
  char c;
  while(1)
  {
    cin>>a>>c>>b;
    if(!cin.fail())
    {
    switch (c)
    {
      case  '+': cout<<a+b<<endl;
      break;
      case '-':cout<<a-b<<endl;
      break;
      case '*':cout<<a*b<<endl;
      break;
      case '/':cout<<a/b<<endl;
      break;
      case '^':cout<<pow(a,b)<<endl;
      break;
      default : cout<<" Enter valid opertaor ";
      break;
    }
    }
    else
    {
        cin.clear();
        string s;
        getline(cin,s);
        if(s=="Quit")
        return ;
        else
        cout<<"Please Enter number"<<endl;
    }
  }
}
int main()
{
  basic();
  return 0;
}