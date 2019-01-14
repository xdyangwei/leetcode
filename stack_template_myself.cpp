#include "stack_template_myself.h"
#include <iostream>
template <class T>
void STACK_MYSELF<T>::push(T d)
{
    mystack.addtotail(new LIST_NODE<T>(d));
}
template <class T>
T STACK_MYSELF<T>::gettop()
{
    return mystack.tail->data;
}
template <class T>
T STACK_MYSELF<T>::getback()
{
    return mystack.head->data;
}
template <class T>
T STACK_MYSELF<T>::pop()
{
    return mystack.deletefromtail();
}
int main()
{
    STACK_MYSELF<int> x;
    //x.push(1);x.push(2);
    std::cout << x.pop() << std::endl;
    std::cout << x.gettop() << std::endl;
}