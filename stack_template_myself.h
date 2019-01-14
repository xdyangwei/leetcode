#ifndef STACK_MYSELF_1
#define STACK_MYSELF_1
#include "forward_list_myself.cpp"
template <class T>
class STACK_MYSELF
{
  public:
    LIST<T> mystack;
    STACK_MYSELF() : mystack(LIST<T>()) {}
    STACK_MYSELF(STACK_MYSELF<T> &a) : mystack(a.stack) {}
    void push(T d);
    T pop();
    T gettop();
    T getback();
    ~STACK_MYSELF() = default;
};
#endif