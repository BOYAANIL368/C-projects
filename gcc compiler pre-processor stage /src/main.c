#include "header.h"
void main(int argc,char **argv)
{
        if(argc!=2)
        {
                printf("USAGE:./a.out file.c\n");
                return;
        }
        char i_file[15];
        int i;
        str_cpy(i_file,argv[1]);
        for(i=0;i_file[i+1];i++);
        i_file[i]='i';
        //printf("%s\n",i_file); converting .h file .i file

        //for single comment remove
        rem_single_line(argv[1],i_file);

        //for multi line comment remove 
         rem_multi_line(i_file);

         macro_replace(i_file);

        //header file inclusion
        header_file(i_file);
}
int str_cmp(char *s1, char *s2)
{
    while (*s1 && *s2 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

void str_cpy(char *d, char *s)
{
    while (*s)
        *d++ = *s++;
    *d = '\0';
}

