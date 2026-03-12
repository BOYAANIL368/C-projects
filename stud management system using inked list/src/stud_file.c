#include "header.h"
extern int n;
void stud_save(struct st *p,char *s)
{
        if(p==0)
        {
                printf("no records avalable to save\n");
                return;
        }
        FILE *fp=fopen(s,"w+");
        if(fp==0) //if file not pracet it return NULL
        {
                printf("file no pracent\n");
                return;
        }
        while(p) //storing the data in to file 
        {
                 fprintf(fp,"%d\t%s\t%.2f\n",p->roll,p->name,p->perce);
                 p=p->next;
        }
        fclose(fp); //close the file after storing
}
void read_file(struct st  **ptr,char *s)
{
        FILE *fp=fopen(s,"r");

        if(fp==0)
        {
                printf("file not avalable\n");
                return;
        }
        while(1)
        {
                struct st  *new=malloc(sizeof(struct st));
                if(fscanf(fp,"%d%s%f",&new->roll,new->name,&new->perce)==EOF)//if file data is completed
                        break;                                 //it return EOF(-1) then return from function
                new->next=0;
        //      new->roll=++n; //for roll number(in sequence)
                if(*ptr==0)  //if it is first node change the header
                        *ptr=new;
                else
                {
                        struct st *last=*ptr;
                        while(last->next)//waiting for last node
                        {
                                last=last->next;
                        }
                        last->next=new;
                }
        }
        fclose(fp);
}

