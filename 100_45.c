#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode(int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int height(struct node* root)
{
    if(root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    if(left > right)
        return left + 1;
    else
        return right + 1;
}

int main()
{
    int n;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter level order traversal (-1 for NULL): ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    if(arr[0] == -1)
    {
        printf("Height of tree: 0");
        return 0;
    }

    struct node* nodes[n];

    for(int i=0;i<n;i++)
    {
        if(arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = newNode(arr[i]);
    }

    for(int i=0;i<n;i++)
    {
        if(nodes[i] != NULL)
        {
            int left = 2*i + 1;
            int right = 2*i + 2;

            if(left < n)
                nodes[i]->left = nodes[left];

            if(right < n)
                nodes[i]->right = nodes[right];
        }
    }

    printf("Height of tree: %d", height(nodes[0]));

    return 0;
}