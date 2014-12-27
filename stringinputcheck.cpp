#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s = "";
    char t;
    while(1)
    {
        t = getchar();
        if(t == '\n' || t == ' ')
            break;
        s = s+ s+ t;
    }
    cout << s << endl;

    return 0;
}
