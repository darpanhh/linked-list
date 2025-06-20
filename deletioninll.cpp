#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
node* createlist(){
    node *head = nullptr,*newnode,*temp;
    int choice=1;
    while(choice){
        newnode = new node;
        cout<<"Enter data:"<<endl;
        cin>>newnode->data;
        newnode->next = nullptr;
        if(head == nullptr){
            head = temp = newnode;
        }
        else{
            temp->next = newnode;
            temp = newnode;
        }
        cout<<"DO YOU WANT TO CONTINUE(0 or 1)"<<endl;
        cin>>choice;
    }
    return head;
}
void displaylist(node* head){
    node*temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
void deletefrombeginning(node*& head){
    if(head==nullptr){
        cout<<"The linked list is empty"<<endl;
    }
node* temp = head;
head = temp->next;
free(temp);
}
void deletefromend(node*& head){
    if(head==nullptr){
        cout<<"The linked list is empty"<<endl;
    }
node* prevnode,* temp=head;
while(temp ->next!=nullptr){
    prevnode = temp;
    temp = temp->next;
}
if(temp == head){
    head = nullptr;
}
else{
    prevnode->next = nullptr;
}
free(temp);
}
void deletefromposition(node*& head){
    if(head==nullptr){
        cout<<"The linked list is empty"<<endl;
    }
node* nextnode,* temp=head;
int pos,i=1;
cout<<"Enter position:"<<endl;
cin>>pos;
while(i<pos-1){
    temp = temp->next;
    i++;
}
nextnode = temp->next;
temp->next = nextnode->next;
free(nextnode);
}
int main(){
node *head = createlist();
cout<<"The linked list is:"<<endl;
displaylist(head);
deletefrombeginning(head);
displaylist(head);
deletefromend(head);
displaylist(head);
deletefromposition(head);
displaylist(head);
return 0;
}