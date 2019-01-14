#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <cmath>
#include <bitset>
#include<memory>
using namespace std;
bool compare(int a, int b)
{
    return a > b ? true : false;
}
void pointer_plus(int *&(p))
{
    cout << p << endl;
    p++;
    cout << p << endl;
}

class animal
{
  protected:
  public:
    int width;
    int height;
    animal(int w, int h) : height(h), width(w)
    {
    }
    void setwidth(int w)
    {
        width = w;
    }
    void setheight(int h)
    {
        height = h;
    }
    virtual int getheight()
    {
        return height;
    }
    virtual int getwidth()
    {
        return width;
    }
    animal(const animal &a) : height(a.height), width(a.width) {}
    animal &operator=(const animal &a)
    {
        width = a.width;
        height = a.height;
        return *this;
    }
    // animal& operator*(){
    //     return *this;
    // }
    virtual ~animal() = default;
};

class rabbit : public animal
{
  public:
    rabbit(int h, int w, int n) : animal(w, h), name(n) {}
    int name;
    int getheight() override
    {
        return height * 2;
    }
    int getwidth() override
    {
        return width * 3;
    }
};

int main()
{
    // rabbit a(1, 1, 1);
    // animal bb(1, 2);
    // animal aa(2, 2);
    // animal *b = nullptr;
    // *b = a;
    // b->height=5;
    // b->width=5;
    int* p = 0;
    //auto p=make_shared<int>(2);
    // int x=1;
     p=new int(2);
    //cout << b->height<< endl;
    cout << *p << endl;
    //cout<<endl;
    delete p;
    p=nullptr;
    cout << *p << endl;
    return 0;
}