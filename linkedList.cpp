////**************************
////**** BY OMER NAIM ********
////**************************
#include <iostream>
using namespace std;


typedef struct Node       //can be done with Class
{
	int data;
	struct Node * next;
}node;

//class Node               //this Class is similer to the struct
//{
//public:
//	int data;
//	Node * next;
//};

Node *newNode(int new_data);
Node* CreatList();
void Insert_Last(Node ** head, Node* nodeToInsert);
void Insert_First(Node ** head, Node* nodeToInsert);
void sortedInsert(Node** head, Node* new_node);
bool Value_in_list(Node* node, int value);
void Delete_node_by_value(Node ** head, int value);
void Delete_All_Even(Node ** head);
void Reverse_List(Node** head);
int List_Length(Node * head);
void PrintList(Node * node);
bool list_cmp(Node * list1, Node * list2);
void merge(Node *list2, Node *list1); 
Node * Union_List(Node *list2, Node *list1);


void main()
{
	cout << "\n Creating new list" << endl; //CreatList
	Node* list = CreatList();
	PrintList(list);

	cout << "\n\n The list length is: " << List_Length(list);

	cout << "\n\n Inserting value 10 to the END of the list" << endl; //insert node(10) to END list
	Node* node1 = newNode(10);
	Insert_Last(&list, node1);
	PrintList(list);

	cout << "\n\n Inserting value 99 to the First of the list" << endl; //insert node(10) to FIRST list
	Node* node2 = newNode(99);
	Insert_First(&list, node2);
	PrintList(list);

	cout << "\n\n Is the value 3 in the list?  "; // cheaks if value 3 is in the list
	if (Value_in_list(list, 3) == true)
		cout << "YES " << endl;
	else
		cout << "NO " << endl;

	cout << "\n\n Trying to delete the value 3 " << endl; //Trying to delete the value 3 
	Delete_node_by_value(&list, 3);
	PrintList(list);

	cout << "\n\nReversing the list order: " << endl; //Reversing the list order:
	Reverse_List(&list);
	PrintList(list);

	cout << "\n\nDeleting all EVEN elements " << endl; //Deleting all EVEN elements
	Delete_All_Even(&list);
	PrintList(list);


	Node* list2 = CreatList();    //creating new list //need to be sorted for this test
	Node * new_node = new Node();
	new_node->data = 5;
	sortedInsert(&list2, new_node); //insering the new node to the sorted list
	PrintList(list2);


	Node * list1 = CreatList();
	Node * list2 = CreatList();
	cout <<"is the list1 equal to list2?  "<< (list_cmp(list1, list2)?"YES":"NO");

	Node * list1 = CreatList();
	Node * list2 = CreatList();
	merge(list2, list1);
	PrintList(list2);

	Node * list1 = CreatList();
	Node * list2 = CreatList();
	PrintList(Union_List(list2, list1));

	cout << endl;
	system("pause");

}

Node *newNode(int new_data)
{
	Node* new_node = new Node(); /* allocate node */

	new_node->data = new_data; /* put in the data */
	new_node->next = NULL;

	return new_node;
}

Node* CreatList()
{
	int size, new_data;
	cout << "enter size  :";
	cin >> size;

	if (size < 1)
	{
		cout << "ERROR";
		return NULL;
	}
				//entering the head (first Node)
	cout << "enter data: ";
	cin >> new_data;
	Node * n1 = newNode(new_data);
	Node* head =n1; // saving the first node as head list

	for (int i = 0; i < size - 1; i++)
	{
		cout << "enter data: ";
		cin >> new_data;
		Node * n2 = newNode(new_data);

		n1->next = n2; //last node to new node
		n1 = n2;
	}
	n1->next = NULL;
	return head; //returning the head list
}

void Insert_First(Node ** head, Node* nodeToInsert)
{
	nodeToInsert->next = (*head);
	(*head) = nodeToInsert;
}

void Insert_Last(Node ** head, Node* nodeToInsert)
{
	if ((*head) == NULL)
	{
		(*head) = nodeToInsert;
		(*head)->next = NULL;
	}
	else
	{
		Node* temp = *head; // saving the start
		while (temp->next != NULL) //moving unril the last node of the list
			temp = temp->next;
		temp->next = nodeToInsert; //conecting the new node to the last node
		nodeToInsert->next = NULL;
	}
}

void sortedInsert(Node** head, Node* new_node) //insert new node into sorted List
{
	Node* current;
	if (*head == NULL || (*head)->data >= new_node->data) //empty list or the smallest data is first
	{													//both way need to insert the new_node first
		new_node->next = *head;
		*head = new_node;
	}
	else
	{
		current = *head;
		while (current->next != NULL && current->next->data < new_node->data)
		{                           //moving until the place to insert
			current = current->next;
		}
		new_node->next = current->next; //connecting new_node to the list (right)
		current->next = new_node; //connecting list (left side) to new node
	}
}

void PrintList(Node * node)
{
	while (node != NULL)
	{
		cout << node->data << " -> ";
		node = node->next;
	}
	cout << "NULL " << endl;
}

bool Value_in_list(Node* node, int value)
{
	while (node != NULL)
	{
		if (node->data == value)
			return true;
		node = node->next;
	}
	return false;
}

void Delete_node_by_value(Node ** head, int value)
{
	Node* ToDelete;
	int flag = 0;
	if (Value_in_list(*head, value) == false) //value not is list
	{
		cout << "the value is NOT in the list" << endl;
	}
	else
	{
		Node *help = new Node(); //help will be new node befor the head [help]->[head]
		help->next = *head; //connecting the list to the new furst node (help)

		Node *temp = help; //temp will run over the list

		while ((temp->next != NULL) && (flag == 0))
		{
			if (temp->next->data == value)
			{
				ToDelete = temp->next;    // saving the node for free later
				temp->next = temp->next->next; // fix the ponter over ther node for delete
				free(ToDelete);
				flag = 1;
			}
			else
			{
				temp = temp->next;
			}
		}

		*head = help->next; // deleting the help node
		free(help);

		cout << " the value " << value << " has been deleted" << endl;
	}
}

void Delete_All_Even(Node ** head)
{
	Node * help = new Node(); //DUMMEY 
	help->next = *head;       //connecting the DUMMEY to list        D->list
	Node * temp = help;		//temp will run on the list (cus we need to free the dummey in the end)
	Node * save;			//save will help me free the even element

	while (temp->next != NULL)
	{
		if ((temp->next->data) % 2 == 0)
		{
			save = temp->next;				//saving the node to be deleted
			temp->next = temp->next->next;	//jumping over it (disconnecting in from the list)
			free(save);						//free the node from the memory
		}
		else
		{
			temp = temp->next; //we move the temp only when temp->next->data is odd
		}
	}
	*head = help->next;
	free(help); //free the DUMMEY
}

void Reverse_List(Node** head)
{
	Node* cur = *head;
	Node*save;
	Node*prev = NULL;

	while (cur != NULL)
	{
		save = cur->next;
		cur->next = prev;
		prev = cur;
		cur = save;
	}
	*head = prev;
}

int List_Length(Node * head)
{
	int count = 0;
	Node * temp = head;

	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

bool list_cmp(Node * list1, Node * list2)
{
	while (list1 != NULL && list2 != NULL)
	{
		if (list1->data != list2->data)
			return false;
		else
		{
			list1 = list1->next;
			list2 = list2->next;
		}
	}

	if ((list1 == NULL && list2 != NULL)|| (list1 != NULL && list2 == NULL))
		return false;
	return true;
}

void merge(Node *list2, Node *list1)
{//lists are same size
	Node *list2_curr = list2, *list1_curr = list1;
	Node *list2_next, *list1_next;

	// While there are avialable positions in list2  
	while (list2_curr != NULL && list1_curr != NULL)
	{
		// Save next pointers  
		list2_next = list2_curr->next;
		list1_next = list1_curr->next;

		// Make list1_curr next of list2_curr  
		list2_curr->next = list1_curr; // Change next pointer of list2_curr  
		list1_curr->next = list2_next; // Change next pointer of list1_curr  
		
		// Update current pointers for next iteration  
		list2_curr = list2_next;
		list1_curr = list1_next;
	}
	
}	

Node * Union_List(Node *list2, Node *list1)
{
	Node * temp1 = list1;
	Node * temp2 = list2;
	Node * result = NULL;
	Node * save = result;

	while (temp1 != NULL)			//adding all list1 to the result      
	{
		result->next = temp1;
		result = result->next;
		temp1 = temp1->next;
	}

	PrintList(save->next);

	while (temp2 != NULL)			//adding all list1 to the result      
	{
		if(!Value_in_list(result, temp2->data))
			Insert_First(&result, temp2);
		temp2 = temp2->next;
	}
	return result;
}







