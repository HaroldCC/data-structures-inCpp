/*************************************************************************
> File Name       : test_vector.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020��10��05��  20ʱ43��04��
************************************************************************/

#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>

int testID = 0;

template <typename T>
void permute(Vector<T> &V)
{                                           //�������������ʹ��Ԫ�صȸ��ʳ����ڸ�λ��
    for (int i = V.size(); i > 0; i--)      //�Ժ���ǰ
        std::swap(V[i - 1], V[rand() % i]); //V[i - 1]��V[0, i)��ĳһ���Ԫ�ؽ���
}

template <typename T>
struct Increase //�������󣺵���һ��T�����
{
    virtual void operator()(T &e) { e++; }
}; //����T��ֱ�ӵ�����������++

template <typename T>
void increase(Vector<T> &V) //ͳһ���������еĸ�Ԫ��
{
    V.traverse(Increase<T>());
} //��Increase<T>()Ϊ�����������б���

/******************************************************************************************
 * ���ԣ����������ģ�˳�򣩲���
 ******************************************************************************************/
template <typename T> //Ԫ������
void TestFind(Vector<T> &V, int n)
{
    for (int i = 0; i < V.size(); i++)
    { //���β���������Ԫ�أ���Ȼ�ɹ�
        T e = V[i];
        std::cout << e << std::endl;
        int r = V.find(e);
        if (r < 0)
            printf(" : not found until rank V[%d] <> %d", r, e);
        else
            printf(" : found at rank V[%d] = %d", r, V[r]);
        printf("\n");
    }
    for (int i = 0; i <= V.size(); i++)
    { //���β���ÿ������Ԫ�صľ�ֵ�����ܳɹ�
        T a = (0 < i) ? V[i - 1] : V[0] - 4;
        T b = (i < V.size()) ? V[i] : V[V.size() - 1] + 4;
        T e = (a + b) / 2;
        std::cout << e << std::endl;
        int r = V.find(e);
        if (r < 0)
            printf(" : not found until rank V[%d] <> %d", r, e);
        else
            printf(" : found at rank V[%d] = %d", r, V[r]);
        printf("\n");
    }
}

/******************************************************************************************
 * ���ԣ����������Ĳ��ң�binSearch��fibSearch��
 ******************************************************************************************/
template <typename T> //Ԫ������
void TestSearch(Vector<T> &V)
{
    for (int i = 0; i < V.size(); i++)
    { //���β���������Ԫ�أ���Ȼ�ɹ�
        T e = V[i];
        std::cout << e << std::endl;
        printf(": by ");
        int r = V.search(e);
        if (V[r] == e)
            printf("found at rank V[%d] = %d", r, V[r]);
        else
            printf("found at rank V[%d] = %d <> %d\a\a", r, V[r], e);
        printf("\n\n");
    }
    for (int i = 0; i <= V.size(); i++)
    { //��������Ԫ�صľ�ֵ�����ܳɹ�
        T a = (0 < i) ? V[i - 1] : V[0] - 4;
        T b = (i < V.size()) ? V[i] : V[V.size() - 1] + 4;
        T e = (a + b) / 2;
        std::cout << e << std::endl;
        printf(": by ");
        int r = V.search(e);
        printf("V[%3d] =", r);
        (r < 0) ? (std::cout << "-INF") : (std::cout << V[r]);
        printf("  ~  ");
        printf("V[%3d] =", r + 1);
        (r + 1 < V.size()) ? (std::cout << V[r + 1]) : (std::cout << "+INF");
        bool ordered = true;
        if ((r >= 0) && (V[r] > e))
            ordered = false;
        if ((r + 1 < V.size()) && (V[r + 1] <= e))
            ordered = false;
        if (!ordered)
            printf("\tincorrect search\a\a");
        printf("\n\n");
    }
}

/******************************************************************************************
 * ���ԣ����������Ĳ���
 ******************************************************************************************/
template <typename T> //Ԫ������
void TestOrderedInsertion(Vector<T> &V, int n)
{
    while (n * 2 > V.size())
    {
        T e = rand() % ((T)n * 2);
        printf("Inserting ");
        std::cout << e << std::endl;
        printf(" by ");
        V.insert(V.search(e) + 1, e);
        std::cout << V << std::endl;
    }
}

/******************************************************************************************
 * ��������
 ******************************************************************************************/
template <typename T> //Ԫ������
void testVector(int testSize)
{
    printf("\n  ==== Test %2d. Generate a random vector\n", testID++);
    Vector<T> V;
    for (int i = 0; i < testSize; i++)
        V.insert(rand() % (i + 1), rand() % ((T)testSize * 3)); //��[0, 3n)��ѡ��n�����������������
    std::cout << V;
    permute(V);
    std::cout << V
            printf("\n  ==== Test %2d. Lowpass on\n", testID++);
    std::cout << V;
    int i = V.size();
    while (0 < --i)
    {
        V[i - 1] *= 7;
        V[i - 1] += V[i];
        V[i - 1] >>= 3;
    }
    std::cout << V;
    printf("\n  ==== Test %2d. Increase\n", testID++);
    std::cout << V;
    increase(V);
    std::cout << V;
    printf("\n  ==== Test %2d. FIND in\n", testID++);
    std::cout << V;
    TestFind<T>(V, testSize);
    printf("\n  ==== Test %2d. Sort degenerate intervals each of size 1 in\n", testID++);
    std::cout << V;
    for (int i = 0; i < V.size(); i += V.size() / 5)
    {
        V.sort(i, i);
        std::cout << V;
    } //element by element
    printf("\n  ==== Test %2d. Sort %d intervals each of size <=%d in\n", testID++, 5 + (V.size() % 5 > 0), V.size() / 5);
    std::cout << V;
    for (int i = 0; i < V.size(); i += V.size() / 5)
    {
        V.sort(i, __min(V.size(), i + V.size() / 5));
        std::cout << V;
        printf("[%d , %d)\n", i, __min(V.size(), i + V.size() / 5));
    } //interval by interval
    printf("\n  ==== Test %2d. Sort the entire vector of\n", testID++);
    std::cout << V;
    V.sort();
    std::cout << V;
    printf("\n  ==== Test %2d. FIND in\n", testID++);
    std::cout << V;
    TestFind<T>(V, testSize);
    printf("\n  ==== Test %2d. SEARCH in\n", testID++);
    std::cout << V;
    TestSearch<T>(V);
    printf("\n  ==== Test %2d. Unsort interval [%d, %d) in\n", testID++, V.size() / 4, 3 * V.size() / 4);
    std::cout << V;
    V.unsort(V.size() / 4, 3 * V.size() / 4);
    std::cout << V;
    printf("\n  ==== Test %2d. Unsort interval [%d, %d) in\n", testID++, 0, V.size());
    std::cout << V;
    V.unsort();
    std::cout << V;
    printf("\n  ==== Test %2d. Copy interval [%d, %d) from\n", testID++, V.size() / 4, 3 * V.size() / 4);
    std::cout << V;
    Vector<T> U(V, V.size() / 4, 3 * V.size() / 4);
    std::cout << U;
    printf("\n  ==== Test %2d. Copy from\n", testID++);
    std::cout << V;
    Vector<T> W(V);
    std::cout << (W);
    printf("\n  ==== Test %2d. Clone from\n", testID++);
    std::cout << (U);
    W = U;
    std::cout << (W);
    printf("\n  ==== Test %2d. Remove redundancy in unsorted\n", testID++);
    std::cout << V;
    printf("%d node(s) removed\n", V.deduplicate());
    std::cout << V;
    printf("\n  ==== Test %2d. Sort interval [%d, %d) in\n", testID++, 0, V.size());
    std::cout << V;
    V.sort();
    std::cout << V;
    printf("\n  ==== Test %2d. FIND in\n", testID++);
    std::cout << V;
    TestFind<T>(V, testSize);
    printf("\n  ==== Test %2d. SEARCH & INSERT in\n", testID++);
    std::cout << V;
    TestOrderedInsertion<T>(V, testSize);
    std::cout << V;
    printf("\n  ==== Test %2d. Remove redundancy in sorted\n", testID++);
    std::cout << V;
    printf("%d node(s) removed\n", V.uniquify());
    std::cout << V;
}

/******************************************************************************************
 * ��������
 ******************************************************************************************/
int main(int argc, char *argv[])
{
    if (2 > argc)
    {
        printf("Usage: %s <size of test>\a\a\n", argv[0]);
        return 1;
    }
    srand((unsigned int)time(NULL)); //�����������
    testVector<int>(atoi(argv[1]));  //Ԫ�����Ϳ�������������ѡ��
    return 0;
}