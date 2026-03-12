#include "header.h"
extern int n;
void stud_add(struct st **p)
{
        struct st *new=malloc(sizeof(struct st));
        printf("enter name and %% \n");
        scanf(" %s%f",new->name,&new->perce);
        struct st *n_check=*p; //n_check is pointer for checking duplicates
        while(n_check)
        {
                if(strcmp(new->name,n_check->name)==0 || new->perce==n_check->perce)
                {
                        printf("data is already existed.. duplicates are not allowed\n");
                        return;
                }
                n_check=n_check->next;
        }
        new->roll=++n; //assining roll num automatically form 1 to and so on
        //adding the data based on roll 
        if(*p==0 || (*p)->roll > new->roll)
        {
                new->next=*p;
                *p=new;
        }
        else
        {
                struct st *pos=*p;
                while(pos->next!=0 && pos->next->roll <new->roll)
                        pos=pos->next;
                new->next=pos->next;
                pos->next=new;
        }
}

