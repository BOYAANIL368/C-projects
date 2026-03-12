#include "header.h"
int n=0;
void main(int argc,char **argv)
{
        if(argc!=2)
        {
                printf("USAGE:./a.out file_name\n");
                return;
        }
        struct st *head=0;
        char op;
        char *s=malloc(20); //for storing file name
        s=argv[1];//argv[1] is a file name
        while(1)
        {
        printf("\033[34m***** STUDENT RECORD MENU *****\033[m\n");
        printf("a/A :add new record\nd/D :delate a record\ns/S :show the list\nm/M :Modify a record\n");
        printf("v/V :save and exit\nf/F :read file \ne/E :exit\nt/T :sort the list\nl/L :delate all records\nr/R :reverse the list\n");
        printf("enter your choise\n");
        scanf(" %c",&op);
        switch(op)
        {
                case 'a':
                case 'A':
                        stud_add(&head);break;
                case 'd':
                case 'D':
                        stud_del(&head);break;
                case 's':
                case 'S':
                        stud_show(head);break;
                case 'm':
                case 'M':
                        stud_modif(&head);break;
                case 'v':
                case 'V':
                        stud_save(head,s);
                        exit(0);break;
                case 'f':
                case 'F':
                        read_file(&head,s);
                        break;
                case 'e':
                case 'E':
                        exit(0);
                case 't':
                case 'T':
                        stud_sort(head);break;
                case 'l':
                case 'L':
                        delate_all(&head);break;
                case 'r':
                case 'R':
                        rev_list(&head);break;
                default:printf("unknown choice\n");
        }
        }
}

