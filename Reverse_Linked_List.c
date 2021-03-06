// Reversing a Linked List
#include <stdio.h>
#include <stdlib.h>

// define the type structure for a node
typedef struct node_struct{
        int value;
        struct node_struct* next;
}       NODE;

// define the new_node value which makes a new node based on input
NODE* new_node(int value){
        NODE* node = (NODE*) malloc(sizeof(NODE));
        node -> value = value;
        node -> next = '\0';
        return node;
}

// define the insert method to insert a node into the start of a node
NODE* insert(NODE* list_start, int value){
        // insert new node at the head node
        NODE* new_n = new_node(value);
        new_n->next = list_start;       // new node points to head of the list
        list_start = new_n;     // update value of the head of the linked list
        return list_start;
}

void show(NODE* list_start){
        if (list_start == '\0'){
                printf("empty list\n");
                return;
        }
        while (list_start != '\0'){
                printf("%d ", list_start->value);
                list_start = list_start->next;
        }
        printf("\n");
        return;
}

// recursive heart of the function recursive_show()
// implemented before recursive_show() or a prototype mus tbe declared
// before the implementation of recursive_show()

void recursive_show1(NODE* p){
        if (p == '\0'){return;}
        printf("%d ", p->value);
        recursive_show1(p->next);
        return;
}

// define recursive_show to:
// 1) check if list is empty
// 2) to get recursion goning
// 3) to display the final newline

void recursive_show(NODE* list_start){
        if (list_start == '\0'){
                printf("empty list\n");
                return;
        }
        recursive_show1(list_start);
        printf("\n");
        return;
}

// reverse_show1() is the recursive heart of the function reverse_show()
// must be implemented before reverse_show() or a prototype must be
// declared before the implementation of reverse_show()
void reverse_show1(NODE* p){
        if (p == '\0'){return;} // base case of recursion
        reverse_show1(p->next); // get to end of node and print backwards
        printf("%d ", p->value);
        return;
}

// reverse_show has 3 purposes:
// 1) check if the list is empty
// 2) to get the recursion going
// 3) to display the final newline
void reverse_show(NODE* list_start){
        if (list_start == '\0'){
                printf("empty list\n");
                return;
        }
        reverse_show1(list_start);
        printf("\n");
        return;
}

int main(){
        char buf[500];
        NODE* list_start = '\0';
        int n;

        while(1){
                printf("please enter positive integer or 'quit': ");
                scanf("%s", &buf);
                if (strcmp(buf, "quit") == 0){break;}
                sscanf(buf, "%d", &n);
                // does not check for validity of the entry!!!
                // do not use conditional statement!!!
                list_start = insert(list_start, n);
        }

        // loop is over
        show(list_start);
        recursive_show(list_start);
        reverse_show(list_start);
        return 0;
}
