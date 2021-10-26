#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};


struct node *createNode(int data)
{
 struct node *temp;
 temp = (struct node *)malloc(sizeof(struct node));
 temp->data = data;
 temp->next = NULL;
 return temp;
}

void append(struct node *userNode,int data)
{
    if(userNode->next == NULL)
    {
        userNode->next = createNode(data);
    }
    else
        append(userNode->next,data);
}

void display(struct node *userNode)
{
    if(userNode == NULL)
        return;
    else
    {
        printf("%d\n",userNode->data);
        display(userNode->next);
    }
}
int main()
{

struct node *myNode = createNode(5);
append(myNode,4);

display(myNode);

}
