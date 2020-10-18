
#include <iostream>
#include <ctype.h>
#include <string.h>
using namespace std;
 class Stack{
typedef struct Node{
    int data;
    Node *next;
}Node;

  Node *top;
 public:
  Stack(){
      top=NULL;
  }
   int isEmpty();

    void push(int x);
    int pop();
    int Top();

};
int Stack::Top(){
    return top->data;
}
int Stack::isEmpty(){
    if (top==NULL){
        return 1;
    }else{
    return 0;
}}
void Stack ::push(int b ){
  Node *newNode;
  newNode = new Node;
  newNode->data=b;
  newNode->next=top;
  top=newNode;

}
int Stack ::pop( ){

     int y;
     Node *temp;
     temp=top;
     top=top->next;
     y=temp->data;

    delete temp;
    return y;

}

int priority(char ch){
 if(ch == '('|| ch==')'){
     return 0;
 }
 if(ch=='+'|| ch=='-'){
     return 1;
 }
 else if(ch=='*'|| ch=='/'){
     return 2;
 }else if(ch=='^'){
     return 3;
 }else{
     return 4;
 }
}
void infixToPostfix(char infix[20] ){
    char x,tok; int i,j=0;
    Stack s;
    char post[20];
    for(i=0;infix[i]!='\0';i++){
        tok=infix[i];

        if(isalnum(tok)){
            post[j++]=tok;
        }
        else{
            if(tok=='('){
                s.push(tok);
            }
            else{
                if(tok==')'){
                while((x=s.pop())!='('){
                    post[j++]=x;
                }
                }
                else{
                while(!s.isEmpty()&& priority(tok)<=priority(s.Top())){
                    post[j++]=s.pop();
                }
                s.push(tok);
            }

        }
    }
    }
        while(!s.isEmpty()){
            post[j++]=s.pop();
        }
        post[j]='\0';
        cout<<"\nPostfix form is:  ";
        cout<<post;

    }

void infixToPrefix(char infix[20] ){
    char x,tok; int i,j=0;
    Stack s;
    char pre[20];
    for(i=strlen(infix)-1;i>=0;i--){
        tok=infix[i];

        if(isalnum(tok)){
            pre[j++]=tok;
        }
        else{
            if(tok==')'){
                s.push(tok);
            }
            else{
                if(tok=='('){
                while((x=s.pop())!=')'){
                    pre[j++]=x;
                }
                }
                else{
                while(!s.isEmpty()&& priority(tok)<priority(s.Top())){
                    pre[j++]=s.pop();
                }
                s.push(tok);
            }

        }
    }
    }
        while(!s.isEmpty()){
            pre[j++]=s.pop();
        }
        pre[j]='\0';
        cout<<"\nPrefix form is:  ";
        for(i=strlen(infix)-1;i>=0;i--){
            cout<<pre[i];
        }
        cout<<'\0';
    }


int main()
{
    char inf[20];
    cout<<"enter infix form "<<endl;
    cin>>inf;
    infixToPostfix(inf);
    infixToPrefix(inf);
return 0;
}


