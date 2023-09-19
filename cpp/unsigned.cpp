#include <iostream>
#include <string>

using namespace std;

int main()
{
    char ch[14];// = "1999-99-99-13";
    unsigned char uc[2][14];
    char *pchar = "1999-99-99-13";

    memcpy(ch, pchar, sizeof(char)*14);

    printf("%s\n",ch);
    return 0;
}