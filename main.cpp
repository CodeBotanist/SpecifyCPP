#include <bits/stdc++.h>
#include "Containers.h"
using namespace std;

int main()
{
    vector<int> vec = {1,2,3,4,5,6,7,8,9,520,1314};
    List lst(vec);
    lst[2]=100;
    cout<<explain(lst[2],0);
}