#include "header.h"
void rem_multi_line(char *ifile)
{
        FILE *fp=fopen(ifile,"r+");  //open file for read and write
        char *s=malloc(100);  //for one string
        int l,flag=0;
        while(fgets(s,100,fp)) //getting string from file
        {
                char *q=s;  //temp pointer
                for(l=0;q[l];l++); //finding length of the line
                q=s;
                while(*(q+1)!='\0')
                {
			if(*q=='"')
			{
				q++;
				while(*q!='"')
					q++;
			}
                        if(*q=='*' && *(q+1)=='/')  //condition for waiting the multi line comment end
                        {
                                *q=' ';
                                *(q+1)=' ';
                                flag=0;   //when ever comments ended flag becomes 0
                        }
                        if(*q=='/' && *(q+1)=='*')  //condition for multi line comment starting 
                                flag=1;  //if found flag becomes 1

                        if(flag==1) //an till flag becomes 0 (means munlti comment gets end)
                         *q=' ';   //replacing characters with space ' '

                        q++;
                }
                *q='\n';  //when line ended '\n' for next file 
                fseek(fp,-l,SEEK_CUR); //moving file pointer to starting pos of line in file
                fputs(s,fp); //putting the modified string in to file
        }
                fclose(fp);
                free(s);
}

