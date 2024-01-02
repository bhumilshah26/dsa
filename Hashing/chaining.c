#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node *next;
}*HT[10];
int hash(int val){
    return val%10;
}
void insert(struct node *HT[], int val){
    int index = 0;
    index = hash(val);
    if (HT[index]==0)
    {
        HT[index] = (struct node *)malloc(sizeof(struct node));
        HT[index]->data = val;
        HT[index]->next = NULL;
    }
    else{
        struct node *trail,*temp,*nn;
        nn = (struct node *)malloc(sizeof(struct node));
        nn->data = val;
        nn->next = NULL;
        temp = HT[index];
        while (temp!=NULL&&temp->data<val)
        {
            trail = temp;
            temp = temp->next;
        }
        if (temp==NULL)
        {
            trail->next = nn;
        }
        else{
            nn->next = temp;
            trail->next = nn;
        }        
    }
}
void display(struct node *HT[]){
    struct node *temp;
    for (int i = 0; i < 10; i++)
    {
        temp = HT[i];
        printf("%d ",i);
        while (temp!= NULL)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main(){
    int index = 0;
    for (int i = 0; i < 10; i++)
    {
        HT[i] = 0;
    }
    insert(HT,12);
    insert(HT,14);
    insert (HT,16);
    insert(HT,32);
    insert(HT,22);
    display(HT);
    return 0;
}
