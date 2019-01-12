#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <cmath>
#include <bitset>
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
    rabbit a(1, 1, 1);
    animal bb(1,1);
    animal aa(2,2);
    animal *b=&(bb);
    *b = aa;
    // b->height=5;
    // b->width=5;
    cout << b->height<< endl;
    cout << b->width << endl;
    return 0;
}