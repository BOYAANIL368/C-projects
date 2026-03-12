#include "header.h"
void replace(char line_arr[][100], int no_line, char **def, int no_macro,char *ifile)
{
       int i,j;
        for(i=0;i<no_macro;i+=2)  //loop for replace macros one by one
        {
                for(j=0;j<no_line;j++)  //loop for finding macros line by line
                {
                        char *line=line_arr[j]; //temp pointe
                        if(*line=='#')
                                continue;
                        char replace[200];  //for modified string
                        char *t_re=replace; // temp pointer
                        while(*line)  //loop fo find and replacing
                        {
				if(*line=='"')
				{
					*t_re++=*line++;
					while(*line!='"')
						*t_re++=*line++;
				}
                                char *tline=line;
                                char *name=def[i]; //macro_name
                                if(*line==*name)
                                {
                                        while(*name && *tline++==*name++);
                                        if(*name=='\0'  && ((*tline == ' ') || (*tline == '\t') || (*tline == '\n') || (*tline == '\0') || (*tline == ';')))
                                        {
                                                char *body=def[i+1]; //macro body
                                                //printf("%s\n",body);
                                                while(*body)
                                                        *t_re++=*body++;
                                                line=tline;
                                                if(*line=='\0')
                                                        break;
                                        }
                                }
                                *t_re++=*line++;
                        }
                        *t_re='\0';
                        str_cpy(line_arr[j],replace); //storing modified string in to 2d array
                }
        }
    printf("\n******** After Macro Replacement ********\n");
    FILE *fp=fopen(ifile,"w");  //open fine writing final content  and printing
    for (i = 0; i < no_line; i++)
    {
        printf("%s", line_arr[i]);
        fputs(line_arr[i],fp);
    }
   fclose(fp);
}
void macro_replace(char *ifile)
{
        char define[10]="#define",mac_name[20],mac_body[30];
        int j=0,macro_line=0,i,no_line=0,k=0;
        FILE *fp=fopen(ifile,"r");
        if(fp==0)
        {
                printf("file not precent\n");
                return;
        }
        char *line=malloc(100); //allocating memory for one line
        while(fgets(line,100,fp))
        {
                if(*line=='#')    //finding the no of #define s
                {
                        char *temp=line;
                        char *mac=define;
                        while(*mac && *temp++==*mac++);
                        if(*mac=='\0')
                        macro_line++;
                }
                no_line++;
        }
        //printf("num of macros %d\n",macro_line);
        macro_line=macro_line*2;   //*2 for store name and body

        char **def=malloc(sizeof(char *)*macro_line);  //2d array for macros
        for(i=0;i<macro_line;i++)
                def[i]=malloc(100);

        char line_arr[no_line][100];   //2d array for file 
        rewind(fp);

        while(fgets(line,100,fp))  //getting line from file
        {
                char *s=line;   //s is a temp pointer for line
                char *d=define; //d for #define
                while(*s=='#')  // if lines start with # then macros
                {
                        while(*d && *d++==*s++); //loop for comparison if all characters maches in #define
                        if(*d=='\0')            //means define found
                        {
                                while(*s==' ') //waiting for macro_name
                                        s++;

                                if((*s>='a'&& *s<='z')|| (*s>='A' && *s<='Z') || *s=='_')  //error cheking (macro names fallows variable declaration)
                                {
                                  i=0;
                                  while(*s!=' ')            //up to space sroting name in to man_name
                                        mac_name[i++]=*s++;
                                  mac_name[i]='\0';    //end with null
                                  while(*s==' ' || *s=='\t')  //wiating for macro_body
                                        s++;
                                  if(*s=='\0' || *s=='\n')
                                  {
                                         printf("syntax error: missing macro body\n");
                                          return;
                                  }
                                  i=0;
                                  while(*s!='\0' && *s!='\n')         //up to end storing into macr0_body
                                        mac_body[i++]=*s++;
                                  mac_body[i]='\0'; //end with null 

                                  printf("%s\n%s\n",mac_name,mac_body); //printing macros

                                  str_cpy(def[j],mac_name); //soring name and body in to def array(2d)  
                                  j++;
                                  str_cpy(def[j],mac_body);
                                  j++;
                                }
                                else
                                {
                                        printf("syntax error\n");
                                        return;
                                }
                        }
                        s++;
                }
                str_cpy(line_arr[k],line);  //storing line by line in to line_arry
                k++;
        }

      replace(line_arr,no_line,def,macro_line,ifile); //function call for replace
      free(def);
      fclose(fp);
}

