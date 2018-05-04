#include<stdio.h>
#include<conio.h>
#include"vlib.h"
int main()
{
    char x,str[10]="VINNAY";
    int y;
    sptr top=NULL;
    lptr first=NULL;
    qptr front=NULL;
    tptr root=NULL;
    typedef char sitem;
    typedef char litem;

    int i,arr[]={8,6,4,8,1,4,7,4,2,10},a=10,b=20;

    mergeSort(arr,0,10);
    for(i=0;i<10;i++)
        printf("%d ",arr[i]);



    front=insertQueue(front,500);
    front=insertQueue(front,200);
    front=insertQueue(front,400);
    front=insertQueue(front,300);

    printf("%d \n",front->link->link->link->data);
    while(!queueEmpty(front))
    {
        front=deleteQueue(front,&y);
        printf("\n\n%d ",y);

    }

        root=bstInsert(root,10);
        root=bstInsert(root,5);
        root=bstInsert(root,4);
        root=bstInsert(root,12);
        root=bstInsert(root,8);
        root=bstInsert(root,11);
        root=bstInsert(root,19);

    bstInorder(root);

    printf("%d ",isBinaryTree(root));

    printf("\n\n %d ",spalin("madam"));
    printf("\n%d",npalin(1212));

    return 0;
}
