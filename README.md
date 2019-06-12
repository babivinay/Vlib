# Vlib
This library has many built in c functions.
____________________________________________________________________________________________________________________________________________________

     int linearSearch(arrayname,length_of_array,searching_element);

       This function performs linear search of an element in given array it returns index if element found and -1 if element not found

   note: here the array and searching_element has to be in type int.
____________________________________________________________________________________________________________________________________________________

____________________________________________________________________________________________________________________________________________________

     int binarySearch(arrayname,starting_index,ending_index,searching_element);

       This function performs binary search recursively and return index if element found and -1 if element not found

   note: here the array and searching_element has to be in type int.
____________________________________________________________________________________________________________________________________________________

____________________________________________________________________________________________________________________________________________________
    void quickSort(arrayname,startingindex,endingindex);

        This function performs quicksort operation for the given array

____________________________________________________________________________________________________________________________________________________

____________________________________________________________________________________________________________________________________________________
   void selectionSort(arrayname,lengthofarray);

	This function performs selectionsort operation for the given array

____________________________________________________________________________________________________________________________________________________

____________________________________________________________________________________________________________________________________________________
   void mergeSort(arrayname,startingindex,endingindex);

        This function peroforms mergesort operation for given array

____________________________________________________________________________________________________________________________________________________

____________________________________________________________________________________________________________________________________________________
   Stacks using Linked list

	In this there are different functions to perform different operations on stack.

	struct stack// structure for creating node
	{
       		int data;
       		struct stack *link;
	};
	typedef struct stack *sptr;

	1. sptr pushStack(top_address,variable); -- function to add element into stack and return modified stack address

	2. sptr popStack(top_address,variable_address); -- function copy top element to variable address provided and
							   return stack top

	3. item stackTop(top_address); -- function that returns stack top element of type item(userdefined can be ,odified),
					   it doesn't modify the stack

        4: int stackEmpty(top_address); -- function to check whether stack empty or not return 1 for empty and 0 for not empty.
  --------------------------------------------------------------------------------------------------------------------------------
  |	note: data type for data on the stack can be modified in the user program. default type is int, it can be midified as  |
  |																 |
  |		typedef new_data_type sitem;											 |
  |																 |
  |	new_data_type-- user defined type like char, float .....                                                                 |
____________________________________________________________________________________________________________________________________________________

____________________________________________________________________________________________________________________________________________________
	Single Linked List

		Here we have different functions to perform different operations on linked list.

	struct lnode// structure for node
	{
    		type data;
    		struct lnode *link;
	};
	typedef struct lnode *lptr;

	1. lptr insertEndOfList(list_address,variable); -- function that inserts node at end of linked list and returns list pointer

	2. lptr insertFrontOfList(list_address,variable); -- function that inserts node at front of list and returns list pointer

	3. lptr insertInOrder(list_address,variable); -- function that inserts element in ascending order and returns list pointer

	4. int listEmpty(list_address); -- function that tells whether list empty or not if empty return 1 else return 0.

	5. int countOfList(list_address); -- function that returns the number of nodes in the list

	6. lptr deleteNode(list_address,addressofvariable); -- function that deletes the first node of list copy it to the variable address
							       provided and returns modified list starting address.
  7. lptr reverseList(list_address); -- function that returns reversed list addressofvariable
  8. litem getMiddleOfList(list); --  function that return middle element of list

		ex: let first be list name then we write as        first=deleteNode(first,&x); --- in x the value will be stored.

  ------------------------------------------------------------------------------------------------------------------------------------------
  |		note: data type for data on linked list can be modified in user program as follows. default type int.                     |
  | 																	    |
  |		typedef new_data_type litem;           											    |
  |																	    |
  |		new_data_type= data type in user program like float,char,........  							    |

____________________________________________________________________________________________________________________________________________________

____________________________________________________________________________________________________________________________________________________
	Functions on dates

		Here we have two functions one prints the date words and other check which date is bigger.

	1. void printDate(string); -- string of the format (dd-mm-yyyy) should be given to print in words, year should be >999 and <9999.

	2. void displayDate(int day,int month,int year); -- function which does as above should have parameters in integer format.

	3. int isBiggerDate(date1,date2); -- date should be string format. returns 1 if date1 bigger, 2 if second date is bigger,
					     0 if both dates are equal and -1 if any of the date is invalid.

____________________________________________________________________________________________________________________________________________________
