#include "header.h"
extern int n;
void delate_all(struct st **p)
{
        struct st *del=*p;
        if(*p) //is records precent
        {
                n=0; //if delate all roll num should be starts from 1
        while(*p)
        {
                *p=del->next;
                free(del);
                del=*p;
        }
        printf("\033[33mall records are delated\033[m\n");
        }
        else //if no records are available
                printf("no records available to delate\n");
}
void delate_name(struct st **p)
{
        if(*p==0)
        {
                printf("no records available\n");
                return;
        }
        char *name=malloc(20);
        printf("enter name to delate\n");
        scanf("%s",name);
        struct st *del=*p,*prev;//prev is fallow pointer
        while(del)
        {
                if(strcmp(name,del->name)==0) //compare names if matches delate
                {
                        if(del==*p)
                        *p=del->next;  //if it is first node change header
                        else
                                prev->next=del->next; //else delate the using fallow pointer
                        struct st *temp=del->next; // temp pointer to hold delate next because we are delating del
                        free(del);
                        printf("\033[33mnode deleted\033[m\n");
                        del=temp; //re assigning the temp to del for next
                        continue;
               }
                prev=del;//before travers to next store del pointer in to fallow pointer
                del=del->next;
        }
        n=0;//for re arranging the roll num from 1 to ...
        struct st *t=*p;
        while(t)
        {
                t->roll=++n;
                t=t->next;
        }
}
void delate_roll(struct st **p)
{
        if(*p==0)
        {
                printf("no records available to delate\n");
                return;
        }
        int roll;
        printf("enter roll num to delate\n");
        scanf("%d",&roll);
        struct st *del=*p,*prev;
        while(del)
        {
                if(roll==del->roll) //if roll num matches delate
                {
                        if(del==*p) //if it is first node change head
                        *p=del->next;
                        else
                                prev->next=del->next;
                        free(del);
                        printf("\033[33mnode delated \033[m\n");
                        return;
                }
                prev=del;
                del=del->next;
        }
        n=0;
        //re arranging the roll numbers from 1 to ...
        struct st *t=*p;
       while(t)
        {
                t->roll=++n;
                t=t->next;
        }
}
void stud_del(struct st **p)
{
        printf("******\ndelate menu\n");
        printf("\033[33mr/R :baesd_on_roll\nn/N :based_on_name\033[m\n");
        char op;
        printf("enter your option\n");
        scanf(" %c",&op);
        switch(op)
        {
                case 'r':
                case 'R':
                        delate_roll(p);break;
                case 'n':
                case 'N':
                        delate_name(p);break;
                default:printf("unknown choice\n");
        }
}

