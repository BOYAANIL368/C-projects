#include "header.h"
void stud_show(struct st *p)
{
        if(p==0)
        {
                printf("no records avalable\n");
                return;
        }
        printf("\033[33mroll\tname\tpercentage\033[m\n"); //like a index
        while(p)
        {
                printf("%d\t%s\t%.2f\n",p->roll,p->name,p->perce);
                p=p->next;
        }
}

