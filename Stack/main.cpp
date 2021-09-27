#include "stack.hpp"

template<typename T>
void pop_test(Stack<T>* stk)
{
    stk->print();
    printf("I poped n = %d\n",stk->pop());
    stk->print();
    printf("###POP HAS BEEN STARTED###\n");
    for(int i = 0; i < 20; ++i)
        printf("data[%d] = %d\n", 30-i, stk->pop());
    printf("###POP HAS BEEN ENDED###\n");
    stk->print();
}

int main(){
    Stack<int> stk(20);
    for (int i = 0; i < 40; ++i)
        stk.push(i);
    //pop_test(&stk);
    Stack<int> stki;
    stki = stk;
    stk.print();
    stki.print();
    if(stki == stk)
        printf("EQUAL\n");
    else
        printf("NOT EQUAL\n");
    return 0;
}