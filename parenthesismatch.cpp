#include <iostream>
#include <string>

using namespace std;

struct stack{
    int size;
    int top;
    char *t;
};

void push(stack *s,char p){
    if(s->top==s->size-1){
        cout <<"stack overflow";
    }
    else{
        s->top++;
        s->t[s->top]=p;
    }
}

void pop(stack *s){
    if(s->top==-1){
        cout<<"stack underflow";
    }
    else{
        s->top--;
    }
}

int isempty(stack *s){
    if(s->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int valid(string &a){

    struct stack *sk =new stack;
    sk->size=a.length();
    sk->top=-1;
    sk->t=new char[sk->size];

    if(a.length()==0){
        return 0;
    }
    
    for(int i=0;a[i]!='\0';i++){
        if(a[i]=='('){
            push(sk,a[i]);
        }
        else if(a[i]==')'){
            if(sk->top==-1){
                return 0;
            }
            else{
                pop(sk);
            }
        }
    }
    return isempty(sk)?true:false;
}

int main (){

    string a="((a+b))";
    cout<<valid(a);

}
