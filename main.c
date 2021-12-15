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
    temp->next = NULL;
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
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
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
    while (ptr->next != NULL)
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
    struct node *newNode = createNode(data);
    newNode->next = userNode;
    userNode = newNode;
    return userNode;
}

struct node *insertPos(struct node *userNode, int data, int pos)
{
    struct node *ptr = userNode;
    int i = 1;
    if (pos == 1)
    {
        return insertFirst(userNode, data);
    }
    while (i < pos - 1 && ptr != NULL)
    {
        ptr = ptr->next;
        i++;
    }
    if (i >= pos)
    {
        printf("Invalid Position\n");
        return userNode;
    }
    else
    {
        struct node *newNode = createNode(data);
        newNode->next = ptr->next;
        ptr->next = newNode;
        return userNode;
    }
}

struct node *insertBefore(struct node *userNode, int data, int ndata)
{
    if (userNode == NULL)
    {
        printf("List is empty so can't insert before any element\n");
        return userNode;
    }
    struct node *ptr = userNode->next;
    struct node *pre = userNode;
    if (pre->data == ndata)
    {
        return insertFirst(userNode, data);
    }
    while (ptr->data != ndata && ptr->next != NULL)
    {
        ptr = ptr->next;
        pre = pre->next;
    }
    if (ptr->data == ndata && ptr->next == NULL)
    {
        struct node *newNode = createNode(data);
        newNode->next = pre->next;
        pre->next = newNode;
        return userNode;
    }
    if (ptr->next == NULL)
    {
        printf("Given node not found !\n");
        return userNode;
    }
    struct node *newNode = createNode(data);
    newNode->next = ptr;
    pre->next = newNode;
    return userNode;
}

struct node *insertAfter(struct node *userNode, int data, int ndata)
{
    if (userNode == NULL)
    {
        printf("List is empty so can't insert after any element\n");
        return userNode;
    }
    struct node *ptr = userNode;
    while (ptr->data != ndata && ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    if (ptr->next == NULL && ptr->data == ndata)
    {
        struct node *newNode = createNode(data);
        ptr->next = newNode;
        return userNode;
    }
    if (ptr->next == NULL)
    {
        printf("Given node not found \n");
        return userNode;
    }
    struct node *newNode = createNode(data);
    newNode->next = ptr->next;
    ptr->next = newNode;
    return userNode;
}

struct node *deleteFirst(struct node *userNode)
{
    if (userNode == NULL)
    {
        printf("Underflow!\n");
        return userNode;
    }
    struct node *ptr = userNode;
    userNode = userNode->next;
    free(ptr);
    return userNode;
}

struct node *deleteLast(struct node *userNode)
{
    if (userNode == NULL)
    {
        printf("Underflow!\n");
        return userNode;
    }
    if (userNode->next == NULL)
    {
        userNode = NULL;
        return userNode;
    }
    struct node *ptr = userNode->next;
    struct node *pre = userNode;

    while (ptr->next != NULL)
    {
        pre = pre->next;
        ptr = ptr->next;
    }
    pre->next = NULL;
    free(ptr);
    return userNode;
}

struct node *deletePos(struct node *userNode, int pos)
{
    if (userNode == NULL)
    {
        printf("Underflow!\n");
        return userNode;
    }
    if (pos == 1)
        return deleteFirst(userNode);
    int i = 1;
    struct node *ptr = userNode;
    while (i < pos - 1 && ptr->next != NULL)
    {
        ptr = ptr->next;
        i++;
    }
    if (ptr->next == NULL)
    {
        printf("Invalid Position\n");
        return userNode;
    }
    struct node *newNode = ptr->next->next;
    free(ptr->next);
    ptr->next = newNode;
    return userNode;
}

struct node *deleteAfter(struct node *userNode, int ndata)
{
    if (userNode == NULL)
    {
        printf("Underflow!\n");
        return userNode;
    }
    struct node *ptr = userNode;
    while (ptr->data != ndata)
    {
        ptr = ptr->next;
    }
    if (ptr->next == NULL)
    {
        printf("There is nothing after selected node\n");
        return userNode;
    }
    struct node *temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
    return userNode;
}

struct node *deleteFirstTime(struct node *userNode, int ndata)
{
    if (userNode == NULL)
    {
        printf("Underflow!\n");
        return userNode;
    }
    struct node *ptr = userNode;
    if (ptr->data == ndata)
    {
        return deleteFirst(userNode);
    }
    struct node *pre = userNode;
    ptr = ptr->next;
    while (ptr->data != ndata && ptr->next != NULL)
    {
        ptr = ptr->next;
        pre = pre->next;
    }
    if (ptr->next == NULL && ptr->data == ndata)
    {
        free(pre->next);
        pre->next = NULL;
        return userNode;
    }
    if (userNode->next == NULL)
    {
        printf("Data Not found ! \n");
        return userNode;
    }
    struct node *newNode = ptr->next;
    free(ptr);
    pre->next = newNode;
    return userNode;
}

struct node *deleteAllTime(struct node *userNode, int ndata)
{
    if (userNode == NULL)
    {
        printf("Underflow!\n");
        return userNode;
    }
    struct node *ptr = userNode;
    int i = 0;
    while (ptr->next != NULL)
    {
        if (ptr->data == ndata)
            i++;
        ptr = ptr->next;
    }
    if (i == 0)
    {
        printf("Data not found\n");
        return userNode;
    }
    while (i >= 0)
    {
        deleteFirstTime(userNode, ndata);
        i--;
    }
}

// Driver Code :-

int main()
{
    struct node *myNode;
    myNode = insertLast(myNode, 45);
    display(myNode);
    myNode = insertLast(myNode, 67);
    myNode = insertFirst(myNode, 6);
    myNode = insertPos(myNode, 5, 3);
    myNode = insertPos(myNode, 5, 5);
    display(myNode);
    myNode = insertBefore(myNode, 2, 67);
    myNode = insertAfter(myNode, 4, 67);
    display(myNode);
    myNode = deletePos(myNode, 8);
    myNode = insertBefore(myNode, 2, 40);
    myNode = deleteAfter(myNode, 45);
    myNode = deleteAfter(myNode, 5);
    display(myNode);
}
