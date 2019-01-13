#include "forward_list_myself.h"
#include <iostream>
#include<exception>
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
        p->next = head;
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
        tail = p;
    }
}

template<class T>
T LIST<T>::deletefromhead(){
    try{
    if(isempty())
    throw "It's unvalid to delete a node from an empty list!!";
    else if(head==tail)
    {
        head=tail=0;
    }
    else{
        //std::cout<<"no"<<std::endl;
        auto p=head->next;
        delete head;
        head=p;
        return head->data;
    }
    }catch(const char* e){
        std::cerr<<e<<std::endl;
    }
}

template<class T>
T LIST<T>::deletefromtail(){
    try
    {
        if(isempty())
        throw "It's unvalid to delete a node from an empty list!!";
        else
        {
            if(head==tail){
            auto x=head->data;
            head=tail=0;
            return x;
            }
            else{
                auto x=tail->data;
                auto p=tail->prev;
                delete tail;
                tail=p;
                return x;
            }
        }
    }
    catch(const char* s)
    {
        std::cerr << s << '\n';
        return -1;
    }
    
}

template<class T>
void LIST<T>::deletenode(T d){
    try{
        if(isempty())
        throw "It's unvalid to delete a node from an empty list!!";
        else{
            auto x=head,y=tail;
            for(;x!=tail->next;){
                if(x->data==d){
                    if(x==head){
                        auto p=x->next;
                       // std::cout<<1;
                        deletefromhead();
                        x=p;
                    }else if(x==tail){
                        auto p=x->prev;
                        deletefromtail();
                        x=p;
                    }else{
                    x->prev->next=x->next;
                    x->next->prev=x->prev;
                    auto p=x->next;
                    delete x;
                    x=p;
                    }
                    break;
                }else{
                    x=x->next;
                }
            }
            if(x==tail->next)
            std::cout<<"can't find in this list"<<std::endl;
        }
    }catch(const char* e){
        std::cerr<<e<<std::endl;
    }
}


int main(int argc, char const *argv[])
{
    auto x = new LIST_NODE<int>();
    auto y = new LIST_NODE<int>();
    auto xxx = new LIST_NODE<int>();
    auto yy = new LIST_NODE<int>();
    LIST_NODE<int> l(1, y, x);
    LIST_NODE<int> m(2, yy, xxx);
    // std::cout<<l.next->data<<std::endl;
    LIST<int> xx;
    xx.addtohead(&l);
    xx.addtotail(&m);
    xx.deletenode(1);
    xx.deletenode(2);
    // xx.deletefromhead();
    // xx.deletefromtail();
    std::cout << xx.isempty()<< std::endl;
    return 0;
}
