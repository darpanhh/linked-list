#include<iostream>
using namespace std;
struct node{
    int data;
    int pow;
    node* next;
};

void insertterm(node*& head,int coeff,int pow){
    node* newnode = new node;
    newnode->data = coeff;
    newnode->pow = pow;
    newnode->next = nullptr;
    if(head == nullptr){
        head = newnode;
    }
    else{
        node* temp = head;
        while(temp->next!=nullptr){
            temp = temp->next;
        }
        temp->next = newnode;
    }

}
void displaypolynomial(node* head){
    while(head!=nullptr){
        cout<<head->data<<"x^"<<head->pow;
        if(head->next!=nullptr){
           cout<<"+";
        }
        head = head->next;
        
    }
    cout<<endl;
}
node* addpolynomial(node* p,node* q){
    node* result = nullptr;
    while(p!= nullptr && q!=nullptr){
        if(p->pow > q->pow){
            insertterm(result,p->data,p->pow);
            p = p->next;
        }
        else if(p->pow < q->pow){
            insertterm(result,q->data,q->pow);
            q = q->next;
        }
        else{
            int sum = p->data + q->data;
            insertterm(result,sum,p->pow);
            p = p->next;
            q = q->next;
        }
    }
    while(p != nullptr){
        insertterm(result,p->data,p->pow);
        p = p->next;
    }
    while(q != nullptr){
        insertterm(result,q->data,q->pow);
        q = q->next;
    }
    return result;
}

int main(){
    node* p = nullptr;
    node* q = nullptr;
    insertterm(p,5,3);
    insertterm(p,4,2);
    insertterm(p,2,1);
    insertterm(q,3,3);
    insertterm(q,2,2);
    insertterm(q,4,0);
    cout<<"First polynomial:";
    displaypolynomial(p);
    cout<<"Second polynomial:";
    displaypolynomial(q);
    node* r = addpolynomial(p,q);
    displaypolynomial(r);
    return 0;
}