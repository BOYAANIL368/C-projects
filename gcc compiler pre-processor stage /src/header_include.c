#include "header.h"
void header_file(char *ifile)
{
        char include[20]="#include"; //for finding the include file 
        char pre_define[20]="/usr/include/"; //pre define path
        char file_name[20]; //for storing the included file name
        int i;
        FILE *fp=fopen(ifile,"r"); //open the .i file
        if(fp==0)
        {
                printf("soruce file not precent\n");
                return;
        }
        FILE *tp=fopen("final.c","w");  //one another file strong source file with included files
        char *line=malloc(100); //for storing the line from file
        while(fgets(line,100,fp))
        {
                char *p=line;         //it points to line (string)
                char *inl=include;  //pointer to include(#include) 
                i=0;
                while(*p)
                {
                        if(*p==*inl) //if first character mathces then go for next
                        {
                                while(*inl && *p++==*inl++);   //loop for finding the #include
                                if(*inl=='\0')  //pointer go's to null means all characters are matched
                                {             //#include found
                                        while(*p==' ') //after #include waiting for the " or < then onwards fine name 
                                                p++;
                                        if((*p=='<')||(*p=='"'))  // < or " then only correct syntax other wise syntax error
                                        {
                                                p++;
                                                while(*p!='"' && *p!='>' ) //loop for storing the file name in to char array 
                                                {
                                                        file_name[i]=*p;
                                                        i++;
                                                        p++;
                                                }
                                        }
                                        else
                                        {
                                                printf("syntax error %s\n",line );
                                                return;
                                         }
                                           file_name[i]='\0';//string end with null
                                        //printf("%s\n",file_name);  file name
                                        FILE *inl_p=fopen(file_name,"r");  //open the include file 
                                        if(inl_p==0) //if it is nor precent in usr_def_path  we need to cheack pre_def_path
                                        {
                                                //char *file;//*f=pre_define;
                                                //usr define concat
                                                char *file=malloc(30),*f;
                                                f=file;
                                                for(i=0;pre_define[i];i++)
                                                        *file++=pre_define[i];
                                                for(i=0;file_name[i];i++)
                                                        *file++=file_name[i];
                                                *file='\0';
                                                file=f;
                                                //file=strcat(pre_define,file_name); //string concatating (/usr/include/file_name)
                                                printf("%s\n",file);// afetr con_cat we will get pre_def path 
                                                inl_p=fopen(file,"r");  //open the file its finding the file in pre_def_path
                                                if(inl_p==0)  //then also not found. included file is not precent
                                                {
                                                printf("inclusution file not pracent\n");
                                                return;
                                                }
                                        }
                                        char *s=malloc(100); //for strong the line
                                        while(fgets(s,100,inl_p)) //for strong hole file int to dest file
                                                fputs(s,tp);
                                }
                        }
                        p++;
                }
                fputs(line,tp); //strong the line int to dest file
        }
        fclose(fp);
        free(line);
}

