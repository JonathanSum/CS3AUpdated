#include <iostream>
using namespace std;
struct Node {
    int data;
    struct Node *next;
};
struct Node* head = NULL;
void insert(int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
}
void display() {
    struct Node* ptr;
    ptr = head;
    while (ptr != NULL) {
        cout<< ptr->data <<" ";
        ptr = ptr->next;
    }
}
int main() {
    Node *list = new Node();
    Node *current = new Node();
    Node* temp = new Node();
    Node *trail = new Node();
    Node *last = new Node();

    insert(39);
    insert(65);
    insert(28);
    insert(50);
    insert(10);
    insert(86);
    insert(35);
    insert(75);
    insert(0);
    cout<<"The linked list is: ";
//    cout<<head->next->data<<endl;
//    list->next=head;

    list=head;
    current->next=(head->next->next);
    current->data=(head->next->data);
    cout<<current->data<<endl;

    temp->next=(head->next->next->next->next);
    temp->data=(head->next->next->next->data);
    cout<<temp->data<<endl;

    trail->next=(head->next->next->next->next->next->next->next->next);
    trail->data=(head->next->next->next->next->next->next->next->data);
    cout<<trail->data<<endl;

    last->next=(head->next->next->next->next->next->next->next->next->next);
    last->data=(head->next->next->next->next->next->next->next->next->data);
    cout<<last->data<<endl;
    display();
    cout<<endl;

    current = new Node;
    current->data = 72;
    current->next = NULL;
    trail = current;
    current = new Node;
    current->data = 46;
    current->next = trail;
    list = current;
    current = new Node;
    current->data = 52;
    list->next = current;
    current->next = trail;
    trail = current;
    current = new Node;
    current->data = 91;
    current->next = trail->next;
    trail->next = current;
    current = list;
    while (current!= NULL)
    {
        cout << current->data <<"";
        current=current->next;
    }


    return 0;
}