// C++ program for Quick Sort on Singly Linled List
#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
using namespace std;
 
/* a node of the singly linked list */
struct node
{
    string data;
    int left;
    int entered;
    struct node *next;
};
 
/* A utility function to insert a node at the beginning of linked list */
void push(struct node** head_ref , string new_data,int in, int out )
{
    /* allocate node */
    struct node* new_node = new node;
 
    /* put in the data  */
    new_node->data  = new_data;
    new_node->entered = in;
    new_node->left = out;
    
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* A utility function to print linked list */

void printList(struct node *node)
{
    while (node != NULL)
    {
        cout << node->data<<" " ;
	if (node->entered>=0){cout<<node->entered<<"  ";}
	
        node = node->next;
    }
    cout << endl ;
}
//Pops out the car as it exits and returns true or if car never entered, returns false. 
bool pop(struct node** head_ref, string reg_no)
{	struct node* node=*head_ref;
	bool exists=true;
	struct node *prev=node;
	while((node)->data!=reg_no && exists)
	{	if((node->next)==NULL)
		{
			exists=false;
			break;		
		}
		prev=node;		
		node=(node)->next;
	}
	if(exists)
	{	node->left++;
		return exists;		
	}
	else
	{
		return exists;
	}
}


// Returns the last node of the list
struct node *getTail(struct node *cur)
{
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}
 
// Partitions the list taking the last element as the pivot
struct node *partition(struct node *head, struct node *end,
                       struct node **newHead, struct node **newEnd)
{
    struct node *pivot = end;
    struct node *prev = NULL, *cur = head, *tail = pivot;
 
    // During partition, both the head and end of the list might change
    // which is updated in the newHead and newEnd variables
    int compare_value = 0;
    while (cur != pivot)
    {
        compare_value = cur->data.compare(0, 5,pivot->data, 0, 5);;//strcmp(cur->data,pivot->data);
        if (compare_value < 0 /*cur->data < pivot->data*/)
        {
            // First node that has a value less than the pivot - becomes
            // the new head
            if ((*newHead) == NULL)
                (*newHead) = cur;
 
            prev = cur;  
            cur = cur->next;
        }
        else // If cur node is greater than pivot
        {
            // Move cur node to next of tail, and change tail
            if (prev)
                prev->next = cur->next;
            struct node *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }
 
    // If the pivot data is the smallest element in the current list,
    // pivot becomes the head
    if ((*newHead) == NULL)
        (*newHead) = pivot;
 
    // Update newEnd to the current last node
    (*newEnd) = tail;
 
    // Return the pivot node
    return pivot;
}
 
 
//here the sorting happens exclusive of the end node
struct node *quickSortRecur(struct node *head, struct node *end)
{
    // base condition
    if (!head || head == end)
        return head;
 
    node *newHead = NULL, *newEnd = NULL;
 
    // Partition the list, newHead and newEnd will be updated
    // by the partition function
    struct node *pivot = partition(head, end, &newHead, &newEnd);
 
    // If pivot is the smallest element - no need to recur for
    // the left part.
    if (newHead != pivot)
    {
        // Set the node before the pivot node as NULL
        struct node *tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;
 
        // Recur for the list before pivot
        newHead = quickSortRecur(newHead, tmp);
 
        // Change next of last node of the left half to pivot
        tmp = getTail(newHead);
        tmp->next =  pivot;
    }
 
    // Recur for the list after the pivot element
    pivot->next = quickSortRecur(pivot->next, newEnd);
 
    return newHead;
}
 
// The main function for quick sort. This is a wrapper over recursive
// function quickSortRecur()
void quickSort(struct node **headRef)
{
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
    return;
}
 
// Driver program to test above functions
int main()
{	
    struct node *cars_inside = NULL;//cars currently inside campus
    struct node *cars_left = NULL;//cars entered left campus
    struct node *cars_inconsistent = NULL;//cars with inconsistent entry
    push(&cars_inside,"",-1,-1);
    push(&cars_left,"",-1,-1);
    push(&cars_inconsistent,"",-1,-1);
    fstream input_entry,input_exit;
	string car_number; 
  
    input_entry.open("Entry_Logs.txt",ios::in);
    while(input_entry >> car_number)
    {   struct node* node=cars_inside;
	bool exists=true;
	
	while((node)->data!=car_number && exists)
	{	if((node->next)==NULL)
		{
			exists=false;
			break;		
		}
				
		node=(node)->next;
	}
	if(exists){node->entered++;}    	
	else {push(&cars_inside,car_number,1,0);}
    }
    input_entry.close();

    input_exit.open("Exit_Logs.txt",ios::in);
    while(input_exit >> car_number)
    {
    	//push(&cars_left,car_number);
	if (pop(&cars_inside,car_number))
     {  struct node* node=cars_inside;
	struct node* prev=cars_inside;
	
	while((node)->data!=car_number )
	{	
		prev=node;		
		node=(node)->next;
	}
       if(node->entered==node->left)
		{	push(&cars_left,car_number,node->left,node->left);
			if(node==prev)
			{
				(cars_inside) = (node)->next;
			}
		   	else
			{
				prev->next=(node)->next;
			}
			
			
		}
		
      
     }
       else
     {	struct node* node=cars_inconsistent;
	bool exists=true;
	
	while((node)->data!=car_number && exists)
	{	if((node->next)==NULL)
		{
			exists=false;
			break;		
		}
				
		node=(node)->next;
	}

	 if (!exists){push(&cars_inconsistent,car_number,-1,-1);}
     
	
      }
   }
    input_exit.close();
    
    
/***********************
* Mate bhai ye code tera galat hai kam number milenge.
* Sir specifically said using Linked List. You have used lists to indicate the c list (cars_inconsistent)
* please implement it using linked list and send me the files. Also use generic values for iterating over for loops not constants like 3 5 etc. use sizeOf etc etc
* I am working meanwhile on making the input files.
*************************
*/

/*   for(int i=0; i<3;i++)
   {
    if (pop(&a,exit[i]))
     {
      push(&b,exit[i]);
     }
    else
     {
     push(&c,exit[i]);
     
     }
   }
*/
 
    cout<<"Vehicles left campus"<<endl;
    quickSort(&cars_left);   
    printList(cars_left);
    cout<<"Vehicles entered but not left"<<endl;
    quickSort(&cars_inside);   
    printList(cars_inside);
    cout<<"Vehicles with inconsistent logs"<<endl;
    quickSort(&cars_inconsistent);   
    printList(cars_inconsistent);



    return 0;
}
