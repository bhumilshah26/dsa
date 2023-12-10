#include <stdio.h>
#include <stdlib.h>
#define sn struct node
struct node
{
    int data;
    struct node *left, *right;
} *root;

void create(){
    int  i, number, data;
    struct node *nn, *temp, *parent;
    printf("Enter the number of nodes: ");
    scanf("%d", &number);
    for(i = 0; i < number; i++){
        nn = (struct node *)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d",&data);
        nn -> data = data;
        nn -> left = nn -> right = NULL;
        parent = temp = root;
    if(!root)
        root = nn;
    else {
             while(temp){
                parent = temp;
                if(temp -> data > data)
                temp = temp -> left;
                else 
                temp = temp -> right;
            }
            if(parent -> data > data)
            parent -> left = nn;
            else
            parent -> right = nn;
        }
    }
}
void insert()
{
    struct node *nn, *temp, *parent;
    int val;
    nn = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value of the node:\n");
    scanf("%d", &val);
    nn -> data = val;
    nn -> left = NULL;
    nn -> right = NULL;
    if (root == NULL)
    {  
        root = nn;
    }
    else
    {
        temp = root;
        while (temp != NULL)
        {
            parent = temp;
            if (temp -> data <= val)
            {
                temp = temp -> right;
            }
            else
            {
                temp = temp -> left;
            }
        }
        if (parent -> data <= val)
            parent -> right = nn;
        else
            parent -> left = nn; 
    }
}
void delete()
{
    int val;
    struct node *temp, *parent, *ps, *succ;
    printf("Enter the value to be deleted:\n");
    scanf("%d", &val);
    temp = root;
    while (temp != NULL && temp -> data != val)
    {
        parent = temp;
        if (temp -> data <= val)
        {
            temp = temp -> right;
        }
        else
        {
            temp = temp -> left;
        }
    }
    if (temp == NULL)
    {
        printf("Value not Found!");
    }
    // leaf node
    else if (temp -> right == NULL && temp -> left == NULL)
    {
        if (parent -> left == temp)
        {
            parent -> left = NULL;
            free(temp);
        }
        else
        {
            parent -> right = NULL;
            free(temp);
        }
    }
    // single child
    else if (temp -> left != NULL)
    {
        if (parent -> left == temp)
        {
            parent -> left = temp -> left;
            free(temp);
        }
        else
        {
            parent -> right = temp -> left;
            free(temp);
        }
    }
    else if (temp -> right != NULL)
    {
        if (parent -> left == temp)
        {
            parent -> left = temp -> right;
            free(temp);
        }
        else
        {
            parent -> right = temp -> right;
            free(temp);
        }
    }
    else 
        {
            succ = temp -> left;
            ps = temp;
            while (succ -> right != NULL)
            {
                ps = succ;
                succ = succ -> right;
            }
            if (ps == temp)
            {
                temp -> data = succ -> data;
                temp -> left = NULL;
                free(succ);
            }
            else
            {
                temp -> data = succ -> data;
                ps -> right = succ -> left;
                free(succ);
            }
        }
}
void inorder(struct node *temp)
{
    if (temp != NULL)
    {
        inorder(temp -> left);
        printf("%d", temp -> data);
        inorder(temp -> right);
    }
}
void preorder(struct node *temp)
{
    if (temp != NULL)
    {
        printf("%d", temp->data);
        preorder(temp -> left);
        preorder(temp -> right);
    }
}
void postorder(struct node *temp)
{
    if (temp != NULL)
    {
        postorder(temp -> left);
        postorder(temp -> right);
        printf("%d", temp -> data);
    }
}
int height(sn* temp){
    if(!temp)
        return 0;
    else {
      int  l = height(temp -> left);
      int  r = height(temp -> right);
      return (l > r) ? (l + 1): (r + 1);
    }
}

void mirror(sn *temp){
    sn *s;
    if(temp){
        mirror(temp -> left);
        mirror(temp -> right);
        s = temp -> left;
        temp -> left = temp -> right;
        temp -> right = s;
    }
}

int totalnodes(sn *temp){
    if(temp)
        return totalnodes(temp -> left) + totalnodes(temp -> right) + 1;
    else
        return 0;
}

int externalnodes(sn *temp){
    if(!temp)
        return 0;
    else if(temp -> left == NULL && temp -> right == NULL)
        return 1;
    else 
        return externalnodes(temp -> left) + externalnodes(temp -> right);

}

int internalnodes(sn *temp){
    return totalnodes(temp) - externalnodes(temp);
}

int main()
{
    int choice;
    create();
do{
    printf("\n1.Insert \n2.Delete \n3.Display using Inorder\n4.Display using Preorder \n5.Display using Postorder\n6.Height");
    printf("\n7.Mirror\n8.Total Nodes\n9.External Nodes\n10.Internal Nodes\n11.Exit\n");
    scanf("%d", &choice);
        switch (choice)
        {
        case 1:{
            insert();
            break;
            }
        case 2:{
            delete();
            break;
            }
        case 3:
        {
            inorder(root);
            break;
        }
        case 4:
        {
            preorder(root);
            break;
        }
        case 5:
            { 
            postorder(root);
            break;
            }
        case 6:
        {
            int h = height(root);
            printf("%d", h);
            break;
        }
        case 7:
        {
            mirror(root);
            preorder(root);
            break;
        }
        case 8:
        {
            int h = totalnodes(root);
            printf("%d\n", h);
            break;
        }
        case 9:
        {
            int h = externalnodes(root);
            printf("%d\n", h);
            break;
        }
        case 10:
        {
            int h = internalnodes(root);
            printf("%d\n", h);
            break;
        }
        case 11:
        {
            exit(0);
            break;
        }
        default:
            {
            printf("Invalid input!");
            break;
            }
        }

}while(choice != 11);
return 0;
}