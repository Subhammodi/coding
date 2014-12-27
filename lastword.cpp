#include<stdio.h>
#include<string>

using namespace std;

int lengthOfLastWord(const char *s) {
    string input(s);
    printf("%d\n", input.size());
    if(input.find_first_not_of(" ") != string::npos)
        input = input.substr(input.find_first_not_of(" "));
    int length = input.find_last_of(" ");
    printf("length = %d\n", length);
    if(input.find_last_of(" ") == string::npos)
        return input.size();
    if((length + 1) == input.size())
    {
        printf("\nsdfgds\n");
        while(input[length] == ' ' && length >=0)
            length --;
        if(length >=0)
        {
            int temp = length;
            while(input[temp] != ' ' && temp >=0)
                temp--;
            if(temp < 0)
                return (input.substr(0, length+1)).size();
            else
                return (input.substr(temp, length-temp)).size();
        }
        else
            return 0;
    }
    string filter = input.substr(length+1);
    return filter.size();
}

int main()
{
    char p[19] = {'t','o','d','a','y',' ','i','s',' ','a',' ','n','i','c','e',' ','d','a','y'};
    const char *pp = p;
    printf("\n%d\n", lengthOfLastWord(pp));
    return 0;
}
