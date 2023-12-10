#include <stdio.h>
#include<stdlib.h>
#define TABLE_SIZE 10

int h[TABLE_SIZE] = {NULL};

void insert() {
 int key, index, i, hkey;
 printf("\nEnter data:\n");
 scanf("%d", &key);
 hkey = key % TABLE_SIZE;
 for(i = 0; i < TABLE_SIZE; i++)
    {

     index = (hkey + i) % TABLE_SIZE;

     if(h[index] == NULL)
     {
        h[index] = key;
         break;
     }

    }

    if(i == TABLE_SIZE)

     printf("\nelement cannot be inserted\n");
}

void search() {
 int key, index, i, hkey;
 printf("\nEnter element to be searched:\n");
 scanf("%d", &key);
 hkey = key % TABLE_SIZE;
 for(i = 0; i< TABLE_SIZE; i++)
 {
    index=(hkey + i) % TABLE_SIZE;
    if(h[index] == key) {
      printf("Value at index %d", index);
      break;
    }
  }
  if(i == TABLE_SIZE)
    printf("\n Value Not Found\n");
}

void display() {
  int i;
  printf("\nElements are \n");
  for(i = 0; i < TABLE_SIZE; i++)
    printf("\nIndex %d value =  %d", i, h[i]);
}

int main()
{
    int opt;
    while(1)
    {
        printf("\nMenu:\n1.Insert\n2.Display\n3.Search\n4.Exit \n");
        scanf("%d", &opt);
        switch(opt)
        {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:exit(0);
            default:
            printf("Invalid");
        }
    }
    return 0;
}