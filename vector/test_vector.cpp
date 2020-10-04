/*************************************************************************
> File Name       : vector.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年10月04日  19时31分41秒
************************************************************************/

#include "vector.h"

int main(int argc, char const *argv[])
{
    Vector<int> vec;

    //todo 测试下标越界
    for (int i = 0; i < 10; ++i)
        vec.insert(i);

    vec.insert(10, 11);

    vec.insert(12, 12);
    vec.insert(12, 12);
    vec.insert(12, 12);
    vec.insert(12, 12);
    vec.insert(12, 12);
    vec.insert(12, 12);
    vec.insert(12, 12);
    vec.insert(12, 12);
    vec.insert(12, 12);
    vec.insert(12, 12);
    vec.insert(12, 12);
    vec.insert(55, 12);
    vec.insert(12, 12);
    vec.insert(12, 12);
    vec.insert(12, 12);
    vec.insert(12, 12);

    for (int i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
    std::cout << vec.size() << std::endl;
    std::cout << vec[55] << " ";
    std::cout << std::endl;

    return 0;
}
