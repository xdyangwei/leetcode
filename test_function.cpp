#include <thread>
#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <cmath>
#include <bitset>
#include <memory>
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

void output(int i)
{
    cout << i << endl;
}

int main()
{

    for (uint8_t i = 0; i < 4; i++)
    {
        thread t(output, i);
        t.detach();
    }

    getchar();
    return 0;
}