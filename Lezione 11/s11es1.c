#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    int info;
    struct tree *parent;
    struct tree *right;
    struct tree *left;
} 
    tree;

typedef struct leaves
{
    tree* leaf;
    struct leaves *next;
}
    leaf;


int max(int a, int b)
{
    if(a >= b)
        return a;
    
    return b;
}

//Create list of leaves node
leaf* create_node(tree* node)
{
    leaf* new = NULL;

    new = malloc(sizeof(tree));
    new->leaf = node;
    new->next = NULL;

    return new;
}

//Create list of leaves
void leaves_list(leaf **l, tree *Leaf)
{
    leaf *new = create_node(Leaf);

    if(*l == NULL)
        *l = new;

    else
    {
        leaf *last = *l;

        while(last->next != NULL)
            last = last->next;

        last->next = new;
    }
}

//Reach leaves
void get_leaves(tree *u, leaf **l)
{
    if(u != NULL)
    {
        if(u->left == NULL && u->right == NULL)
            leaves_list(l, u);

        get_leaves(u->left, l);
        get_leaves(u->right, l);
    }
}

//Create bst node
tree* create(int n, tree *parent)
{
    tree* new = NULL;

    new = malloc(sizeof(tree));
    new->info = n;
    new->parent = parent;
    new->left = NULL;
    new->right = NULL;

    return new;
}

//Create bst
void build_tree(tree **u, int n, tree *parent)
{
    if(*u == NULL)
        *u = create(n, parent);

    else if((*u)->info < n)
        build_tree(&(*u)->left, n, *u);
    
    else
        build_tree(&(*u)->right, n, *u);
}

//Find maximum path value
int maxpath(tree *u)
{
    if(u == NULL)
        return 0;

    return max( u->info + maxpath(u->left), u->info + maxpath(u->right));
}

//Check path sum from a leaf thru parent
int path(tree *u)
{
    if(u != NULL)
    {
        if(u->parent == NULL)
            return u->info;
        
        return u->info + path(u->parent);
    }

    return 0;
}

//Find min value in a given path from a leaf
int find_min(tree *leaf)
{
    int min = leaf->info;

    while(leaf != NULL)
    {
        if(leaf->info < min)
            min = leaf->info;

        leaf = leaf->parent;
    }

    return min;
}   

void discard_leaves(leaf **l, int maxsum)
{
    leaf *aux = *l,
         *prev;

    while(aux != NULL)
    {
        if(path(aux->leaf) != maxsum)
        {
            //remove node
            if(aux == *l)
            {
                *l = aux->next;
                free(aux);
                aux = *l;
            }
            else
            {
                prev->next = aux->next;
                free(aux);
                aux = prev->next;
            }
        }
        else
        {
            prev = aux;
            aux = aux->next;
        }
    }
}

int main()
{
    tree *root = NULL;
    leaf *head = NULL;
    int i, n, el, maxsum, min, curr;
    

    scanf("%d", &n);

    for(i=0; i<n; i++)
    {
        scanf("%d", &el);
        build_tree(&root, el, NULL);
    }

    if(root != NULL)
    {
        get_leaves(root, &head);

        maxsum = maxpath(root);

        discard_leaves(&head, maxsum);

        while(head != NULL)
        {
            min = head->leaf->info;

            curr = find_min(head->leaf);

            if(curr < min)
                min = curr;

            head = head->next;
        }

        printf("%d\n", min);
    }
    else
        printf("0\n");
    
    return 0;
}

