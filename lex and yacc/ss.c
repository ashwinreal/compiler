#include <stdio.h>
#include <string.h>
int main()
{
char a[]="a";
char b[]="b";
char p[]="+";
char s[]=" ";
char p1[100];strcpy(p1,p);
char s1[100];strcpy(s1,s);
printf("%s",p1);
//printf("\n%s\n",strcat(strcat(strcat(p,a),p), strcat(b,p)));
return 0;
}
