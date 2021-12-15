#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *createNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp;
    return temp;
}
void display(struct node *userNode)
{
    if (userNode == NULL)
    {
        printf("Empty List ! \n");
        return;
    }
    struct node *temp = userNode;
    do
    {
        printf("%d->", temp->data);
        temp = temp->next;
    } while (temp != userNode);
    printf("\n");
    return;
}

struct node *insertLast(struct node *userNode, int data)
{
    if (userNode == NULL)
    {
        userNode = createNode(data);
        return userNode;
    }
    struct node *ptr = userNode;
    struct node *newNode = createNode(data);
    newNode->next = ptr;
    while (ptr->next != userNode)
        ptr = ptr->next;
    ptr->next = newNode;
    return userNode;
}

struct node *insertFirst(struct node *userNode, int data)
{
    if (userNode == NULL)
    {
        userNode = createNode(data);
        return userNode;
    }
    struct node *ptr = userNode;
    struct node *newNode = createNode(data);
    newNode->next = ptr;
    while (ptr->next != userNode)
        ptr = ptr->next;
    ptr->next = newNode;
    userNode = newNode;
    return userNode;
}

struct node *deleteFirst(struct node *userNode)
{
    if (userNode == NULL)
    {
        printf("Underflow!\n");
        return userNode;
    }
    if (userNode->next == userNode)
    {
        struct node *newNode = userNode;
        userNode = NULL;
        free(newNode);
        return userNode;
    }
    struct node *ptr = userNode;
    struct node *ptr2 = userNode;
    while (ptr->next != userNode)
        ptr = ptr->next;
    ptr->next = userNode->next;
    userNode = userNode->next;
    free(ptr2);
    return userNode;
}

struct node *deleteLast(struct node *userNode)
{
    if (userNode == NULL)
    {
        printf("Underflow!\n");
        return userNode;
    }
    if (userNode->next == userNode)
    {
        userNode = NULL;
        free(userNode);
        return userNode;
    }
    struct node *ptr = userNode->next;
    struct node *pre = userNode;
    while (ptr->next != userNode)
    {
        ptr = ptr->next;
        pre = pre->next;
    }
    pre->next = userNode;
    free(ptr);
    return userNode;
}

int main()
{
    struct node *myNode = createNode(56);
    display(myNode);
    myNode = insertLast(myNode, 67);
    display(myNode);
    myNode = insertFirst(myNode, 69);
    display(myNode);
    myNode = insertFirst(myNode, 60);
    display(myNode);
    myNode = insertLast(myNode, 61);
    display(myNode);
    myNode = deleteFirst(myNode);
    // display(myNode);
    // myNode = deleteFirst(myNode);
    // display(myNode);
    // myNode = deleteFirst(myNode);
    display(myNode);
    myNode = deleteLast(myNode);
    display(myNode);
    myNode = deleteLast(myNode);
    display(myNode);
    myNode = deleteLast(myNode);
    display(myNode);
    myNode = deleteFirst(myNode);
    display(myNode);
    //printf("%d", myNode->data);
}
