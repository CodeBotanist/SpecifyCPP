#ifndef PROJECT_V1_CONTAINERS_H
#define PROJECT_V1_CONTAINERS_H
#include <bits/stdc++.h>
#include <utility>
using namespace std;
int* ptr1 = (int *) malloc(sizeof(int));
double* ptr2 = (double *) malloc(sizeof(double));
string* ptr3 = (string *) malloc(sizeof(string));
struct visitor
{
    void operator()(int tgt){*ptr1=tgt;}
    void operator()(double tgt){*ptr2=tgt;}
    void operator()(string tgt){*ptr3=std::move(tgt);}
};
/*
 * First edition
int explain(variant<int, double, string> var, int free=0)
{
    // this function is used in explaining variant objects.
    size_t idx = var.index();
    visit(visitor {}, var);
    if(idx==0) return *ptr1;
}
double explain(variant<int, double, string> var, double free=0.0)
{
    // this function is used in explaining variant objects.
    size_t idx = var.index();
    visit(visitor {}, var);
    if(idx==1) return *ptr2;
}
string explain(variant<int, double, string> var, char free='0')
{
    // this function is used in explaining variant objects.
    size_t idx = var.index();
    visit(visitor {}, var);
    if(idx==2) return *ptr3;
}
 */

template <typename T>
auto explain(variant<int, double, string> var, T free) {
    size_t idx = var.index();
    visit(visitor {}, var);
    if constexpr (std::is_same_v<T, int>) {
        if (idx == 0) return *ptr1;
    } else if constexpr (std::is_same_v<T, double>) {
        if (idx == 1) return *ptr2;
    } else if constexpr (std::is_same_v<T, char>) {
        if (idx == 2) return *ptr3;
    }
}



class List
{
public:
    // reference
    vector<variant<int, double, string>> vec;
    List()
    = default;
    explicit List(const vector<int>& c)
    {
        for(auto i:c)
        {
            variant<int, double, string> var = i;
            vec.push_back(var);
        }
    }
    // overload
    explicit List(const vector<double>& c)
    {
        for(auto i:c)
        {
            variant<int, double, string> var = i;
            vec.push_back(var);
        }
    }
    // overload
    explicit List(const vector<string>& c)
    {
        for (auto i: c) {
            variant<int, double, string> var = i;
            vec.push_back(var);
        }
    }

    // overload
    explicit List(const vector<variant<int, double, string>>& c)
    {
        for (const auto& i: c) {
            const variant<int, double, string>& var = i;
            vec.push_back(var);
        }
    }

    // Addition
    void append(int addition)
    {
        variant<int, double, string> var = addition;
        vec.emplace_back(addition);
    }
    void append(double addition)
    {
        variant<int, double, string> var = addition;
        vec.emplace_back(addition);
    }
    void append(string addition)
    {
        variant<int, double, string> var = addition;
        vec.emplace_back(addition);
    }

    // Pop
    int pop()
    {
        vec.erase(vec.end()-1);
        return vec.size()-1;
    }
    int pop(int mark) {
        auto ptr = vec.begin();
        ptr += mark;
        vec.erase(ptr);
        return mark;
    }

    variant<int, double, string>& operator[] (int mark)
    {
        return (variant<int, double, std::string> &) vec[mark];
    }

    [[nodiscard]] vector<variant<int, double, string>> getarray() const
    {
        vector<variant<int, double, string>> copy(vec);
        return copy;
    }
};

/*
Tuple is an unchangeable container which gives everyone a good choice of setting a constant container which contains the object one needs.
*/
class Tuple
{
public:
    vector<variant<int, double, string>> vec;
    Tuple()
    = default;
    explicit Tuple(const vector<int>& c)
    {
        for(auto i:c)
        {
            variant<int, double, string> var = i;
            vec.push_back(var);
        }
    }
    // overload
    explicit Tuple(const vector<double>& c)
    {
        for(auto i:c)
        {
            variant<int, double, string> var = i;
            vec.push_back(var);
        }
    }
    // overload
    explicit Tuple(const vector<string>& c)
    {
        for (auto i: c) {
            variant<int, double, string> var = i;
            vec.push_back(var);
        }
    }

    // overload
    explicit Tuple(const vector<variant<int, double, string>>& c)
    {
        for (const auto& i: c) {
            const variant<int, double, string>& var = i;
            vec.push_back(var);
        }
    }

    variant<int, double, string> operator[] (int mark)
    {
        return vec[mark];
    }

    [[nodiscard]] vector<variant<int, double, string>> getarray() const
    {
        vector<variant<int, double, string>> copy(vec);
        return copy;
    }
};


#endif
