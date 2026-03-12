#include "header.h"
void rem_single_line(char *cfile,char *ifile)
{
        FILE *fp=fopen(cfile,"r"); //open main.c file for reading
        if(fp==0)
        {
                printf("file is not present \n");
                return;
        }
        FILE *fr=fopen(ifile,"w"); //open .i file writing 
        char *s=malloc(100); //memory for one string
        while(fgets(s,100,fp))
        {
                char *q=s;
                while(*q)
                {
                        if(*q=='/'&&*(q+1)=='/')//checking the single line comment
                        {                      //if found end the string there only
                                *q='\n';
                                *(q+1)='\0';
                                break;
                        }
                        *q++;
                }
                fputs(s,fr); //writing modified string in to .i file
        }
        free(s);
        fclose(fp);
        fclose(fr);
}

