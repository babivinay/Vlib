// author Vinay
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/*
function that reverse the string
*/
void reverse(char *str)
{
    int len,start_index,end_index;
    for(len=0;str[len]!='\0';len++);//to find length of the string
    for(start_index=0,end_index=len-1;start_index<end_index;start_index++,end_index--)
    {
        //swapping characters
        str[start_index]=str[start_index]+str[end_index];
        str[end_index]=str[start_index]-str[end_index];
        str[start_index]=str[start_index]-str[end_index];
    }
}
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/*
swap function
*/
void swap(int *x,int *y)
{
    int t;//temporary variable to perform swapping
    t=*x;
    *x=*y;
    *y=t;
}
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/*
Quick Sort function
*/
void quickSort(int array[],int low,int high)
{
	if(low<high)
	{
		int j;
		j=partition(array,low,high);//to identify pivot element correct position
		quickSort(array,low,j-1);//perform recursively quicksort for array before pivot element
		quickSort(array,j+1,high);//perform recursively quicksort for array after pivot element
	}
}
/*
helper function for quicksort to identify element correct position
*/
int partition(int array[],int low,int high)
{
	int i=low+1,j=high,key=array[low],t;
	do
	{
		while(i<=high && array[i]<=key) i++;// increment i untill key element greater than current element (move from left to right)
		while(j>low && array[j]>key) j--;// decrement j untill key element  less than current element (move from right to left)
		if(i<j)
		{
		    swap(&array[i],&array[j]);

		}
	}while(i<j);
	swap(&array[low],&array[j]);

	return j;
}
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/*
Bubble sort
*/
void bubbleSort(int *arr,int length)
{
    int index1,index2;
    for(index1=0;index1<length;index1++)
    {
        for(index2=0;index2<length-1-index1;index2++)
        {
            if(*(arr+index2)>*(arr+index2+1))
             swap(&arr[index2],&arr[index2+1]);
        }
    }
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/*
Selection Sort
*/
void selectionSort(int arr[],int n)
{
    int i, j, pos;
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        pos = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[pos])
            pos = j;
        // Swap the found minimum element with the first element
        swap(&arr[pos], &arr[i]);
    }
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/*
Merge Sort functions
*/
void merging(int *arr,int low, int mid, int high)
{
	int l1, l2, i,b[high];
	for (l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++)//loop to iterate and copy elements to new array
	{
		if (arr[l1] <= arr[l2])
			b[i] = arr[l1++];
		else
			b[i] = arr[l2++];
	}
	while (l1 <= mid)//if any elements remains in first half of unsorted array copy them to new array
		b[i++] = arr[l1++];

	while (l2 <= high)// if any elements remains in second half of unsorted array copy them to new array
		b[i++] = arr[l2++];

	for (i = low; i <= high; i++)
		arr[i] = b[i];

}
void mergeSort(int *arr,int low, int high)
{
	int mid;

	if (low < high)
	{
		mid = (low + high) / 2;// to find middle of unsorted array
		mergeSort(arr,low, mid);// call mergesort function recursively for sorting
		mergeSort(arr,mid + 1, high);// sort first half of unsorted array
		merging(arr,low, mid, high);// sort second half of unsorted array
	}
	else
	{
		return;
	}
}
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/*
Linear Search
*/
int linearSearch(int *arr,int length,int ele)
{
    int i,flag=0;
    for(i=0;i<length;i++)// loop to iterate entire array
    {
        if(*(arr+i)==ele)// check every array element with the required element
        {
            flag=1;// if found setting flag bit and break the loop
            break;
        }
    }
    if(flag==1)
        return i;// element found return its index
    else
        return -1;// element not found return -1 value
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/*
Binary Search
*/
// A recursive binary search function. It returns location of x in
int binarySearch(int arr[], int low, int high, int x)
{
   if (high>= low)
   {
        int mid = low + (high - low)/2;
        // If the element is present at the middle itself
        if (arr[mid] == x)  return mid;
        // If element is smaller than mid, then it can only be present in left subarray
        if (arr[mid] > x) return binarySearch(arr, low, mid-1, x);
        // Else the element can only be present in right subarray
        return binarySearch(arr, mid+1, high, x);
   }
   // We reach here when element is not present in array
   return -1;
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/*
Stacks using linked list
*/
typedef int sitem;// data type in stack
struct stack// structure for creating node
{
       sitem data;
       struct stack *link;
};
typedef struct stack *sptr;
sptr pushStack(sptr top,sitem x)// function to add element into the stack
{
     sptr p;
     p=(sptr)malloc(sizeof(struct stack));
     p->data=x;
     p->link=top;
     top=p;
     return top;
}
sptr popStack(sptr top,sitem *x)// function to pop element from stack
{
     sptr t;
     if(top==NULL)
     {
                  return NULL;
     }
     t=top;
     *x=top->data;
     top=top->link;
     free(t);
     return top;
}
int stackTop(sptr top) // function to get stacktop element
{
    sitem x;
    if(top==NULL)
    {
                   printf("stack is empty\t");
    }
    x=top->data;
    return x;
}
int stackEmpty(sptr top)// function to check whether stack is empty or not
{
    return (top==NULL)?1:0;

}
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/*
Implementation of Single Linked List
*/
typedef int litem;
struct lnode// structure for node
{
    litem data;
    struct lnode *link;
};
typedef struct lnode *lptr;
lptr insertEndOfList(lptr list,litem x)// function to insert element at end of list
{
    lptr p,t;
    p=(lptr)malloc(sizeof(struct lnode));
    p->data=x;
    p->link=NULL;
    if(list==NULL)
        return p;
    t=list;
    while(t->link!=NULL)
        t=t->link;
    t->link=p;
    return list;
}
lptr insertFrontOfList(lptr list,litem x)// function to insert element at the front of list
{
    lptr p;
    p=(lptr)malloc(sizeof(struct lnode));
    p->data=x;
    p->link=list;
    return p;
}
lptr insertInOrder(lptr list,litem x)// function to insert element in order
{
    lptr p,t1,t2;
    p=(lptr)malloc(sizeof(struct lnode));
    p->data=x;
    p->link=NULL;
    if(list==NULL)
        return p;
    if(x<=list->data)
    {
        p->link=list;
        return p;
    }
    t2=list;
    while(x>t2->data)
    {
        t1=t2;
        t2=t2->link;
    }
    t1->link=p;
    p->link=t2;
    return list;
}
int listEmpty(lptr list) // function to check whether list is empty or not
{
    return (list==NULL)?1:0;
}

litem getMiddleOfList(lptr list){
  lptr p1 = list,p2 = list;
  while(p2 != NULL && p2->link != NULL){
    p1 = p1 ->link;
    p2 = p2 -> link -> link;
  }
  return p1 -> data;
}

lptr reverseList(lptr list) {
  lptr prev = NULL,next = NULL,current = list;
  while(current!=NULL){
    next = current -> link;
    current -> link = prev;
    prev = current;
    current = next;
  }
  list = prev;
  return list;
}

lptr deleteNode(lptr list,litem *x) // function to delete node at the front and returns list address
{
    lptr temp;
    if(list==NULL)
        return NULL;
    *x=list->data;
    temp=list;
    list=list->link;
    free(temp);
    return list;
}
int countOfList(lptr list)
{
    int count=0;
    while(list!=NULL)
    {
        count++;
        list=list->link;
    }
    return count;
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/*
Function to print given date in words
*/
void displayDate(int ,int ,int );
void printDate(char *);


void printDate(char *str)// function that divides date month and year
{
	int i,j,day=0,month=0,year=0;
	for(i=0;str[i]>='0' && str[i]<='9';i++)
			day=(day*10)+str[i]-'0';
	i++;
	for(j=i;str[j]>='0' && str[j]<='9';j++)
		month=(month*10)+str[j]-'0';
	j++;
	for(i=j;str[i]>='0' && str[i]<='9';i++)
		year=(year*10)+str[i]-'0';
	displayDate(day,month,year);

}
void displayDate(int day,int month,int year) // function that maps necessary values and prints the date given.
{
	int t,tmp,temp=0,flag=0;
	char a[10][10]={" ","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
	char b[15][15]={"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Ninteen"};
	char c[10][10]={" ","Ten","Twenty","Thirty","Fourty","Fifty","Sixty","Seventy","Eighty","Ninty"};
	char d[10][10]={" ","First","Second","Third"};
	char e[15][15]={"January","February","March","April","May","June","July","August","September","October","November","December"};
	int	range[12]={31,28,31,30,31,30,31,31,30,31,30,31};

	if(year%4==0)
		range[1]=29;

	if(day<=range[month-1] && year<9999 && year>999 && month<=12)
	{
		if(day>19 && day<=31)
		{
			t=day/10;
			day=day%10;
			printf("%s ",c[t]);
		}
		if(day>9 && day<20)
		{
			t=day%10;
			day=0;
			printf("%sth ",b[t]);
		}
		if(day>3 && day<=9)
			printf("%sth ",a[day]);
		else
			printf("%s ",d[day]);

		printf("%s of ",e[month-1]);

		if(year>1000)
		{
			t=year/100;
			temp=1;
			if((t>10)&&(t<20))
			{
				tmp=t%10;
				year=year%1000;
				printf("%s  ",b[tmp]);
			}
			else
			{
				t=year/1000;
				year=year%1000;
				printf("%s Thousand ",a[t]);
			}
		}
		if(year>100&&temp==0)
		{
			t=year/100;
			year=year%100;
			printf("%s  ",a[t]);
		}
		else
			year=year%100;
		if(year>=10 && year<20)
		{
			t=year%10;
			printf("%s ",b[t]);
		}
		if(year>19 && year<=100)
		{
			t=year/10;
			year=year%10;
			printf("%s ",c[t]);
		}
		if(year<10)
		{
			printf("%s ",a[year]);
		}
	}

	else
		printf("Invalid Date\n");
}


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/*
function that tells which date is bigger
*/

int isBiggerDate(char *str,char *str1)
{
	int i, j, day = 0, month = 0, year = 0, day1 = 0, month1 = 0, year1 = 0,v1,v2;
	for (i = 0; str[i] >= '0' && str[i] <= '9'; i++)
	{
		day = (day * 10) + str[i] - '0';
		day1 = (day1 * 10) + str1[i] - '0';
	}
	i++;
	for (j = i; str[j] >= '0' && str[j] <= '9'; j++)
	{
		month = (month * 10) + str[j] - '0';
		month1 = (month1 * 10) + str1[j] - '0';
	}
	j++;
	for (i = j; str[i] >= '0' && str[i] <= '9'; i++)
	{
		year = (year * 10) + str[i] - '0';
		year1 = (year1 * 10) + str1[i] - '0';
	}
	v1 = validate(day, month, year);
	v2 = validate(day1, month1, year1);
	if (v1 == 0 || v2 == 0)
		return -1;
	else if (year<year1)
		return 1;
	else if (year1 < year)
		return 2;
	else if (month < month1)
		return 1;
	else if (month1 < month)
		return 2;
	else if (day < day1)
		return 1;
	else if (day1 < day)
		return 2;
	else
		return 0;
}
int validate(int day, int month, int year)
{
	int range[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (year % 4 == 0)
		range[1] = 29;
	if ((month > 0 && month <= 12) && (day <= range[month-1]))
		return 1;
	else
		return 0;
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/*
Queues using linked list
*/
typedef int qitem;// data type in queue
struct queue// structure for creating node
{
       qitem data;
       struct queue *link;
};
typedef struct queue *qptr;
qptr insertQueue(qptr front,qitem x)// function to add element into the queue
{
     qptr p,t;
     p=(qptr)malloc(sizeof(struct queue));
     p->data=x;
     p->link=NULL;
     if(front ==NULL)
        return p;
    t=front;
    while(t->link!=NULL)
        t=t->link;
    t->link=p;
    return front;
}
qptr deleteQueue(qptr front,qitem *x) // function to delete node at the front and returns list address
{
    qptr temp;
    if(front==NULL)
        return NULL;
    *x=front->data;
    temp=front;
    front=front->link;
    free(temp);
    return front;
}

int queueEmpty(qptr front)// function to check whether queue is empty or not
{
    return (front==NULL)?1:0;

}
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/*
Implementation of Trees
*/
typedef int titem;// data type in tree
struct bstree// structure for storing tree node details
{
    titem data;
    struct bstree *lchild,*rchild;
};
typedef struct bstree *tptr;// pointer to structure to access structure memebers

tptr bstInsert(tptr root,int x)// function to insert element into the binary search tree
{
	tptr p = (tptr)malloc(sizeof(struct bstree));
	p->data=x;
	p->lchild = p->rchild = NULL;

	if(root==NULL)
	return p;

	tptr t = root;
	tptr parent = root;
	while(t!=NULL)
	{
		parent=t;
		if(x < t->data)
			t=t->lchild;
		else
			t=t->rchild;
	}

	if(x < parent->data)
	parent->lchild=p;
	else
	parent->rchild=p;
	return root;
}
void bstPreorder(tptr root)// function to print preorder of tree
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        bstPreorder(root->lchild);
        bstPreorder(root->rchild);
    }
}
void bstInorder(tptr root) // function to print inorder of tree
{
    if(root!=NULL)
    {
        bstInorder(root->lchild);
        printf("%d ",root->data);
        bstInorder(root->rchild);
    }
}

void bstPostorder(tptr root) // function to print post order of tree
{
    if(root!=NULL)
    {
        bstPostorder(root->lchild);
        bstPostorder(root->rchild);
        printf("%d ",root->data);
    }
}
int isBinaryTree(tptr root) // function to verify tree is binary search tree or not
{
	static tptr last = NULL;
	if(root!=NULL)
	{
		if(!isBinaryTree(root->lchild))
			return 0;
		if(last!=NULL && root->data<last->data)
			return 0;
		last=root;
		return isBinaryTree(root->rchild);
	}
	return 1;
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/*
Functions to check palindrome or not
*/
int spalin(char *str)
{
    int len,i,j;
    for(len=0;str[len]!='\0';len++);
    for(i=0,j=len-1;(i<j)&&(str[i]==str[j]);i++,j--);
    if(i>=j)
        return 1;
    else
        return 0;
}

int npalin(int num)
{
    int no=num,rev=0;
    while(no!=0)
    {
        rev=rev*10+(no%10);
        no/=10;
    }
    return (rev==num)?1:0;
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
