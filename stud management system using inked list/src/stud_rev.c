#include "header.h"
void rev_list(struct st **ptr)
{
        struct st *p=*ptr;
        int c=0;
        while(p)  //counting the nodes 
        {
                c++;
                p=p->next;
        }
        if(c>1)
        {
                struct st **a,*t=*ptr; //a is an 2d array for storing nodes for safe because we modifying the links
                a=malloc(sizeof(struct st*)*c);
                int i;
                for(i=0;i<c;i++,t=t->next) //storing nodes in to 2d array
                        a[i]=t;

                for(i=c-1;i>=0;i--)
                        a[i]->next=a[i-1]; //changing the node next address from end
                a[0]->next=0; //last next should be zero
                *ptr=a[c-1]; //fist node should be connected to head
        }
}

