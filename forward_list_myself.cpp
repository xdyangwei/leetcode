#include "forward_list_myself.h"
#include <exception>
#include<iostream>
template <class T>
bool LIST<T>::isempty()
{
    return head == 0 ? true : false;
}
template <class T>
void LIST<T>::addtohead(LIST_NODE<T> *p)
{
    if (isempty())
        head = tail = p;
    else
    {
        head->prev=p;
        p->next = head;
        p->prev=0;
        head = p;
    }
}
template <class T>
void LIST<T>::addtotail(LIST_NODE<T> *p)
{
    if (isempty())
        head = tail = p;
    else
    {
        tail->next = p;
        p->next = 0;
        p->prev=tail;
        tail = p;
    }
}

template <class T>
T LIST<T>::deletefromhead()
{
    try
    {
        if (isempty())
            throw "It's unvalid to delete a node from an empty list!!";
        else if (head == tail)
        {
            head = tail = 0;
        }
        else
        {
            //std::cout<<"no"<<std::endl;
            auto p = head->next;
            delete head;
            head = p;
            return head->data;
        }
    }
    catch (const char *e)
    {
        std::cerr << e << std::endl;
    }
}

template <class T>
T LIST<T>::deletefromtail()
{
    try
    {
        if (isempty())
            throw "It's unvalid to delete a node from an empty list!!";
        else
        {
            if (head == tail)
            {
                auto x = head->data;
                head = tail = 0;
                return x;
            }
            else
            {
                auto x = tail->data;
                auto p = tail->prev;
                delete tail;
                tail = p;
                return x;
            }
        }
    }
    catch (const char *s)
    {
        std::cerr << s << '\n';
        return -1;
    }
}

template <class T>
void LIST<T>::deletenode(T d)
{
    try
    {
        if (isempty())
        {
            throw "It's unvalid to delete a node from an empty list!!";
        }
        else
        {
            if (tail == head)
            {
                // std::cout<<"yes"<<std::endl;
                if (tail->data == d)
                {
                    tail = head = 0;
                    std::cout << "delete success 1" << std::endl;
                }
                else
                {
                    std::cout << "can't find in this list" << std::endl;
                }
            }
            else
            {
                auto x = head, y = tail;
                if (x->data == d)
                {
                    auto p = x->next;
                    delete x;
                    head = p;
                    std::cout << "delete success 0" << std::endl;
                }
                else
                {
                    for (x = x->next; x != tail; x = x->next)
                    {
                        if (x->data == d)
                        {
                            //std::cout<<x->data<<" "<<x->prev->data<<std::endl;
                            x->prev->next = x->next;
                            x->next->prev = x->prev;
                            auto p = x->next;
                            delete x;
                            //std::cout<<x->data<<" "<<x->prev->data<<std::endl;
                            //x = p;
                            break;
                        }
                    }
                    if (tail->data != d && x == tail)
                    {
                        std::cout << "can't find in this list" << std::endl;
                    }
                    else
                    {
                        if (x == tail)
                        {
                            std::cout << "tail" << std::endl;
                            x->prev->next = x->next;
                            delete x;
                        }
                        std::cout << "delete success 2" << std::endl;
                    }
                }
            }
        }
    }
    catch (const char *e)
    {
        std::cerr << e << std::endl;
    }
}

template<class T>
void LIST<T>::clear(){
    if(isempty())
    std::cout<<"clear success"<<std::endl;
    else{
        auto x=head;
        while(x!=0){
            auto p=x->next;
            //std::cout<<x->data<<std::endl;
            delete x;
            x=p;
        }
        head=tail=0;
        std::cout<<"clear success"<<std::endl;
    }
}

/*int main(int argc, char const *argv[])
{
    auto x = new LIST_NODE<int>();
    auto y = new LIST_NODE<int>();
    auto xxx = new LIST_NODE<int>();
    auto yy = new LIST_NODE<int>();
    auto z=new LIST_NODE<int>();
    auto zz=new LIST_NODE<int>();
    LIST_NODE<int> l(1, y, x);
    LIST_NODE<int> m(2, yy, xxx);
    LIST_NODE<int> mm(3, z, zz);
    // std::cout<<l.next->data<<std::endl;
    LIST<int> xx;
    xx.addtohead(&l);
    xx.addtotail(&m);
    xx.addtohead(&mm);
    xx.deletenode(1);
    xx.deletenode(4);
    // xx.deletefromhead();
    // xx.deletefromtail();
    xx.clear();
    auto xxxx=xx.head;
    while(xxxx!=0){
        std::cout<<xxxx->data<<std::endl;
        xxxx=xxxx->next;
    }
    //std::cout << xx.isempty() << std::endl;
    return 0;
}
*/