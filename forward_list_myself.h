#ifndef FORWARD_LIST
#define FORWARD_LIST
template <class T>
class LIST_NODE
{
  public:
    LIST_NODE() : data(0), next(0), prev(0) {}
    LIST_NODE(T n) : data(n), next(0), prev(0) {}
    LIST_NODE(T n, LIST_NODE<T> *l, LIST_NODE<T> *r) : data(n), next(r), prev(l) {}
    T data;
    LIST_NODE<T> *prev;
    LIST_NODE<T> *next;
};

template <class T>
class LIST
{
  public:
    LIST_NODE<T> *head;
    LIST_NODE<T> *tail;
    LIST() : head(0), tail(0) {}
    LIST(LIST_NODE<T> *h, LIST_NODE<T> *t) : head(h), tail(t) {}
    bool isempty();
    ~LIST()
    {
        if (!isempty())
        {
            auto x = head->next;
            delete head;
            head = x;
        }
    }
    void addtohead(LIST_NODE<T> *);
    void addtotail(LIST_NODE<T> *);
    T deletefromhead();
    T deletefromtail();
    void deletenode(T d);
    void clear();
};
#endif