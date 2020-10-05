/*************************************************************************
> File Name       : Fib.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年10月05日  09时55分30秒
************************************************************************/
#ifndef __FIB_H__
#define __FIB_H__

class Fib
{
private:
    int f, g; // f = fib(k -1), g = fib(k)

public:
    Fib(int n) : f(1), g(0)
    {
        while (g < n)
        {
            next();
        }
    }

    int get() { return g; }

    int next()
    {
        g += f;
        f = g - f;
        return g;
    }

    int prev()
    {
        f = g - f;
        g -= f;
        return g;
    }
};

#endif // __FIB_H__