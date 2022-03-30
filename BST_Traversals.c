// Binary Search Tree Traversals
#include <stdio.h>
#include <stdlib.h>

typedef struct node_struct{
        struct node_struct *left, *right;
        int value;
} NODE;

NODE* new_node(int value){
        // malloc is stdlib
        NODE* n = (NODE*) malloc(sizeof(NODE*));        // allocates a piece of memory
        n->value = value;
        n->left = n->right = '\0';
        return n;
}

// insert1 is the recursive heart of insert()
// must be implemented before insert() or a prototype must be placed before
// the implementation of insert()
void insert1(NODE* p, int value){;
        // if value > p->value, then n > 0
        if (value > p->value){
                if (p->right == '\0'){
                        p->right = new_node(value);
                }
                else{
                        insert1(p->right, value);
                }
        }

        // else if value < p->vlaue, then n < 0
        else if (value < p->value){
                if (p->left == '\0'){
                        p->left = new_node(value);
                }
                else{
                        insert1(p->left, value);
                }
        }

        // else n == 0 (i.e. value == p->value)
        // does nothing and terminates -- the duplicates are not stored
}

// two purposes are to 1) check if tree is empty and 2) get recursion going
// to be inserted at the head of the node?
NODE* insert(NODE* root, int value){
        if (root == '\0'){
                root = new_node(value);
                return root;
        }
        insert1(root, value);
        return root;
}

// InOrder1() is the recursive head of InOrder()
// must be implemented before InOrder() or its prototype must be placed
// before the implementation of InOrder()
void InOrder1(NODE* p){
        if (p->left != '\0')    InOrder1(p->left);
        printf("%d ", p->value);
        if (p->right != '\0')   InOrder1(p->right);
}

// this function has three purposes:
// 1) check if the tree is empty
// 2) to get the recursion going
// 3) display the final newline

void InOrder(NODE* root){
        if (root == '\0'){
                printf("empty tree\n");
                return;
        }
        InOrder1(root);
        printf("\n");
}

void PreOrder1(NODE* p){
        printf("%d ", p->value);
        if (p->left != '\0')    PreOrder1(p->left);
        if (p->right != '\0')   PreOrder1(p->right);
}

void PreOrder(NODE* root){
        if (root == '\0'){
                printf("empty tree\n");
                return;
        }
        PreOrder1(root);
        printf("\n");
}

void PostOrder1(NODE* p){
        if (p->left != '\0')    PostOrder1(p->left);
        if (p->right != '\0')   PostOrder1(p->right);
        printf("%d ", p->value);
}

void PostOrder(NODE* root){
        if (root == '\0'){
                printf("empty tree\n");
                return;
        }
        PostOrder1(root);
        printf("\n");
}

int main(){
        char buf[500];
        int n;
        NODE* root = '\0';

        while(1){
                printf("please enter positive integer or 'quit': ");
                scanf("%s", &buf);
                //strcmp is stdlib
                if (strcmp(buf, "quit") == 0){break;}
                // does not check for validity of user input
                sscanf(buf, "%d", &n);  // stores buf of type int into var n
                root = insert(root, n);
        }
        printf("in-order traversal\n");
        InOrder(root);

        printf("pre-order traversal\n");
        PreOrder(root);

        printf("post-order traversal\n");
        PostOrder(root);
}
