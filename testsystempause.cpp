#include <cstdlib>
#include <iostream>

using namespace std;

void f(char * x)
{
  x++;
  *x = 'a';
}
int main()
{
  char * str = "hello";
  //f(str);
  cout << str;
  system("pause");
  return 0;
}
