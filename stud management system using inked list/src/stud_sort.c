#include "header.h"
void sort_perce(struct st *p,int c)
{
        struct st *p1=p;
        struct st *p2,t;
        for(int i=0;i<c-1;i++)
        {
                p2=p1->next;
                for(int j=0;j<c-i-1;j++)
                {
                        if(p1->perce>p2->perce)
                        {
                                struct st *next1 = p1->next;
                                struct st *next2 = p2->next;
                                struct st temp = *p1;
                                *p1 = *p2;
                                *p2 = temp;
                                 p1->next = next1;
                                 p2->next = next2;


                        }
                        p2=p2->next;
                }
                p1=p1->next;
        }
}
void sort_name(struct st *p,int c)
{
        struct st *p1=p;
        struct st *p2,t;
        for(int i=0;i<c-1;i++)
        {
                p2=p1->next;
                for(int j=0;j<c-i-1;j++)
                {
                        if(strcmp(p1->name,p2->name)>0)
                        {
                                struct st *next1 = p1->next; //while swapping address get lost
                                struct st *next2 = p2->next; //so storing address in to temp
                                struct st temp = *p1;
                                *p1 = *p2;
                                *p2 = temp;
                                p1->next = next1;
                                 p2->next = next2;


                        }
                        p2=p2->next;
                }
                p1=p1->next;
        }
}
void sort_roll(struct st *p,int c)
{
        struct st *p1=p;
        struct st *p2,t;
        for(int i=0;i<c-1;i++)
        {
                p2=p1->next;
                for(int j=0;j<c-i-1;j++)
                {
                        if(p1->roll>p2->roll)
                        {
                                struct st *next1 = p1->next; //while swapping address get lost 
                                struct st *next2 = p2->next; //so storing address in to temp
                                struct st temp = *p1;
                                *p1 = *p2;
                                *p2 = temp;
                                 p1->next = next1;
                                 p2->next = next2;
                        }
                        p2=p2->next;
                }
                p1=p1->next;
        }
}
void stud_sort(struct st *p)
{
        if(p==0)
        {
                printf("no records available to sort\n");
                return;
        }
        int c=0;
       struct st *t=p;
        while(t)  //counting the nodes how may nodes are precent
        {
                c++;
                t=t->next;
        }
        char op;
        printf("\033[33mr/R :sort_based on roll\nn/N :sort_based on name\np/P:sort_base on percent\033[m\n");
        printf("enter option\n");
        scanf(" %c",&op);
        switch(op)
        {
                case 'r':
                case 'R':
                        sort_roll(p,c);
                        break;
                case 'n':
                case 'N':
                        sort_name(p,c);
                        break;
                case 'p':
                case 'P':
                        sort_perce(p,c);
                        break;
                default:printf("unknown choice\n");
        }
}

