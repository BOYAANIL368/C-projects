#include "header.h"
void roll_base(struct st *p)
{
        int roll;
        printf("enter roll number to search\n");
        scanf("%d",&roll);
        int f=0;
        while(p)
        {
                if(roll==p->roll) //if roll no found give permission to modification
                {
                        printf("data :%d %s %f\n",p->roll,p->name,p->perce);
                        f=1;//flag for data is precent or not
                        printf("enter new name and percentage\n");
                        scanf(" %s%f",p->name,&p->perce);
                }
                p=p->next;
        }
        if(f==0)
                printf("such a roll num record not available\n");
}
void percen_base(struct st *p)
{
        float percentage;
        printf("enter  percentage to search\n");
        scanf("%f",&percentage);
        int f=0;
        while(p)
        {
                if(percentage==p->perce) //if record found give permission to modification
                {
                        printf("data :%d %s %f\n",p->roll,p->name,p->perce);
                        f=1; //flag for data is percent or not
                        printf("enter new name and percentage\n");
                        scanf(" %s%f",p->name,&p->perce);
                }
                p=p->next;
        }
        if(f==0)
                printf("such a percentage record not available\n");
}
void name_base(struct st *p)
{
        char *name=malloc(20);
        printf("enter name to search\n");
        scanf("%s",name);
        int f=0;
        while(p)
        {
                if(strcmp(name,p->name)==0)//if name is found print it and give permission to modification
                {
                        printf("data :%d %s %f\n",p->roll,p->name,p->perce);
                        f=1;//flag for data is precent or not
                        printf("enter new name and percentage\n");
                        scanf(" %s%f",p->name,&p->perce);
                }
                p=p->next;
        }
        if(f==0)
                printf("such a name record not available\n");
}
void stud_modif(struct st **p)
{
        char op;
        printf("\033[33msearch menu\nr/R :based on roll\n n/N :based on name\n p/P :base on percentage\033[m\n");
        printf("enter your choice\n");
        scanf(" %c",&op);
        switch(op)
        {
                case 'r':
                case 'R':
                        roll_base(*p);break;
                case 'n':
                case 'N':
                        name_base(*p);break;
                case 'p':
                case 'P':
                        percen_base(*p);break;
                default:printf("unknown choice \n");
        }
}

