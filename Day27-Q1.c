/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void appendNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
int getLength(struct Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    int diff = abs(len1 - len2);
    struct Node* longer = (len1 > len2) ? head1 : head2;
    struct Node* shorter = (len1 > len2) ? head2 : head1;
    for (int i = 0; i < diff; i++) {
        longer = longer->next;
    }
    while (longer != NULL && shorter != NULL) {
        if (longer == shorter) {
            return longer;
        }
        longer = longer->next;
        shorter = shorter->next;
    }
    return NULL;
}

int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    int n, m, data;
    
    // Input for first list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        appendNode(&head1, data);
    }
    
    // Input for second list
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &data);
        appendNode(&head2, data);
    }
    
    struct Node* intersection = findIntersection(head1, head2);
    if (intersection != NULL) {
        printf("%d\n", intersection->data);
    } else {
        printf("No Intersection\n");
    }
    
    return 0;
}