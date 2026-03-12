#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct st
{
        int roll;
        char name[20];
        float perce;
        struct st *next;
};
void stud_add(struct st **);
void stud_show(struct st *);
void delate_all(struct st **);
void stud_del(struct st **);
void stud_save(struct st *,char *);
void read_file(struct st **,char *);
void rev_list(struct st **);
void stud_sort(struct st *);
void stud_modif(struct st **);


