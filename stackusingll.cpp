#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
node* top = NULL;
void push(int data){
    node* newnode = new node;
    newnode->data = data;
    newnode->next = top;
    top = newnode;
}
void display(){
    node *temp = top;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void peek(){
    if(top == NULL){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"The top element of stack is:"<<top->data<<endl;
    }
}
void pop(){
    node *temp = top;
    if(top==NULL){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"The popped element is:"<<top->data<<endl;
        top = temp->next;
        free(temp);
    }
}
int main(){
    push(2);
    push(3);
    push(4);
    display();
    peek();
    pop();
    display();
    return 0;
}