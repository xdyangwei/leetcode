#include <iostream>
#include <unordered_map>
#include <cmath>
#include <vector>
using namespace std;
vector<pair<int, int>> sort_map(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
    auto a_length = a.first * a.first + a.second * a.second;
    auto b_length = b.first * b.first + b.second * b.second;
    auto c_length = c.first * c.first + c.second * c.second;
    // cout<<a_length<<" "<<b_length<<" "<<c_length<<"yes"<<endl;
    int max, flag = 0;
    vector<pair<int, int>> m;
    if (a_length >= b_length)
    {
        max = a_length;
        flag = 1;
    }
    else
    {
        max = b_length;
        flag = 2;
    }
    if (max < c_length)
    {
        max = c_length;
        flag = 3;
    }
    if (flag == 1)
    {
        m.push_back(a);
        m.push_back(b);
        m.push_back(c);
    }
    else if (flag == 2)
    {
        m.push_back(b);
        m.push_back(a);
        m.push_back(a);
    }
    else
    {
        // cout<<flag<<endl;
        m.push_back(c);
        m.push_back(a);
        m.push_back(b);
    }
    
    return m;
}

bool is_square(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d)
{
    auto ab = make_pair<int, int>(b.first - a.first, b.second - a.second);
    auto ac = make_pair<int, int>(c.first - a.first, c.second - a.second);
    auto ad = make_pair<int, int>(d.first - a.first, d.second - a.second);

    auto ab_length = ab.first * ab.first + ab.second * ab.second;
    auto ac_length = ac.first * ac.first + ac.second * ac.second;
    auto ad_length = ad.first * ad.first + ad.second * ad.second;
    if (ab_length && ac_length && ad_length)
    {
        auto m = sort_map(ab, ac, ad);
        
        auto diagonal = *(m.begin());
        auto x = ++m.begin();
        auto edge1 = *(x);
        auto edge2 = *(++x);
        auto diagonal_length = diagonal.first * diagonal.first + diagonal.second * diagonal.second;
        auto edge1_length = edge1.first * edge1.first + edge1.second * edge1.second;
        auto edge2_length = edge2.first * edge2.first + edge2.second * edge2.second;
        cout<<edge1.first<<" "<<edge2.first<<" "<<diagonal.first<<endl;
        cout<<edge1.second<<" "<<edge2.second<<" "<<diagonal.second<<endl;
        if ((diagonal.first == edge1.first + edge2.first) && (diagonal.second == edge1.second + edge2.second))
        {
            cout<<"yes"<<endl;
            if (edge1_length == edge2_length && edge1.first * edge2.first + edge1.second * edge2.second == 0){
                
                return true;}
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
//求p1绕p2逆时针旋转90度的坐标
pair<int, int> spin_reverse_90degree(pair<int, int> p1, pair<int, int> p2, int i)
{
    if (i > 1)
    {
        return spin_reverse_90degree(make_pair(p2.first + p2.second - p1.second, p2.second - p2.first + p1.first), p2, --i);
    }
    else if (i == 1)
    {
        return make_pair(p2.first + p2.second - p1.second, p2.second - p2.first + p1.first);
    }
    else
    {
        return p1;
    }
}

//计算一堆杂物从v1坐标绕着v3中的不同点转化成v2坐标所需逆时针旋转90度的步数
int spin_sum(vector<pair<int, int>> v1, vector<pair<int, int>> v2, vector<pair<int, int>> v3)
{
    int sum = 0;
    for (size_t j = 0; j < 4; j++)
    {
        for (size_t i = 0; i < 4; i++)
        {
            if (v2[j] == spin_reverse_90degree(v1[j], v3[j], i))
            {
                sum += i;
                break;
            }
        }
    }

    return sum;
}
int main()
{
    // auto a = make_pair<int, int>(1, 1);
	// auto b = make_pair<int, int>(-1, 1);
	// auto c = make_pair<int, int>(-1, -1);
	// auto d = make_pair<int, int>(1, -1);
	// auto z=sort_map(make_pair(2,0),make_pair(0,-2),make_pair(2,-2));
    // for(auto zz:z)
    // cout<<zz.first<<" "<<zz.second<<endl;
    int n;
    cin >> n;
    int a, b, x, y;
    vector<vector<pair<int, int>>> v1, v2;
    for (size_t i = 0; i < n; i++)
    {
        vector<pair<int, int>> v, v3;
        for (size_t i = 0; i < 4; i++)
        {
            cin >> a >> b >> x >> y;
            v.push_back(make_pair(a, b));
            v3.push_back(make_pair(x, y));
        }
        v1.push_back(v);
        v2.push_back(v3);
    }
    for (size_t i = 0; i < n; i++)
    {
        auto rubbish_i = v1[i];
        auto spin_i = v2[i];
        vector<vector<pair<int, int>>> vi;
        for (size_t i = 0; i < 4; i++)
        {
            vector<pair<int, int>> v4(4, {0, 0});
            v4[0] = spin_reverse_90degree(rubbish_i[0], spin_i[0], i);
            for (size_t i = 0; i < 4; i++)
            {
                v4[1] = spin_reverse_90degree(rubbish_i[1], spin_i[1], i);
                for (size_t i = 0; i < 4; i++)
                {
                    v4[2] = spin_reverse_90degree(rubbish_i[2], spin_i[2], i);
                    for (size_t i = 0; i < 4; i++)
                    {
                        v4[3] = spin_reverse_90degree(rubbish_i[3], spin_i[3], i);
                        vi.push_back(v4);
                    }
                }
            }
        }
        int min = 10000;
        int flag = 0;
        for (auto xx : vi)
        {
            if (is_square(xx[0], xx[1], xx[2], xx[3]))
            {
                flag = 1;
                auto z = spin_sum(v1[i], xx, v2[i]);
                cout << z << endl; 
                if (z < min)
                {
                    min = z;
                }
            }
        }
        if (flag == 0)
        {
            min = -1;
        }
        cout << min << endl;
    }

    return 0;
}