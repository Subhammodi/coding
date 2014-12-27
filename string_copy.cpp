/* strncpy example */
#include <stdio.h>
#include<stdlib.h>
#include <string.h>

int main ()
{
    char c1, c2;
    while(1)
    {
        c1 = getchar();
        c2 = getchar();
        if(c1 == '\n')
            break;
        if( c1 == c2)
            printf("dfdsf\n");
        else
            printf("dsgsdgs\n");

    }
    printf("jknjn\n");
    char *test = new char[5];
    scanf("%s", test);
    printf("%s\n", test);
    printf("%d\n", strlen(test));
    char *testt;

  char str1[5]= "cgkf";
  char str2[40] = "";
  char str4[40];

  scanf("%s", str4);
  printf("%s", str4);
  scanf("%s", str4);
  printf("%s", str4);

int i = 0;
  /* copy to sized buffer (overflow safe): */
  //strncpy ( str2, str1, sizeof(str2) );

/*    while(str1[i] != 'f')
    {
        str4[i] = str1[i];
        i++;
    }
    i = 0;
    while(str1[i] != 'f')
    {
        str2[i] = str1[i];
        i++;
    }
  //strncpy ( str3, str2, 5 );
  char *str3 = new char[5];// = "ccgghncfvjhvjv";   /* null character manually added */

  puts (str1);
  puts (str2);
  puts (str4);
  //printf("%d\n",strlen(str3));
  //printf("%c",str3[2]);

  return 0;
}
