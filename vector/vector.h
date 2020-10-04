/*************************************************************************
  > File Name       : vector.h
  > Author          : Harold
  > Mail            : 2106562095@qq.com
  > Github          : www.github.com/Haroldcc
  > Created Time    : Sun 04 Oct 2020 03:11:41 PM CST
 ************************************************************************/

#ifndef VECTOR_H_
#define VECTOR_H_

#define DEFAULT_CAPACITY 3

template <typename T>
class Vector
{
private:
    int _size;     // 元素的个数
    int _capacity; // 数组的容量
    T *_element;   // 存储元素的数组
protected:
    /**
      * \brief 拷贝数组区间vec[low, high]
      * \param vec 源数组
      * \param low 起始位置
      * \param high 结束位置
      * \return void
      */
    void copy_from(const T *vec, int low, int high);

    /**
      * \brief 空间不足时扩容
      */
    void expand();

    /**
      * \brief 空间过大时缩容
      */
    void shrink();

    /**
       * \brief 扫描交换
      * \param low 起始位置
      * \param high 结束位置
      */
    bool bubble(int low, int high);

    /**
      * \brief 冒泡排序
      */
    void bubble_sort(int low, int high);

    /**
      * \brief 获取区间内最大元素
      */
    int max(int low, int high);

    /**
      * \brief 选择排序算法
      */
    void selection_sort(int low, int high);

    /**
      * \brief 归并算法
      */
    void merge(int low, int mid, int high);

    /**
      * \brief 归并排序算法
      */
    void merge_sort(int low, int high);

    /**
      * \brief 堆排序
      */
    void heap_sort(int low, int high);

    /**
      * \brief 轴点构造算法
      */
    int partition(int low, int high);

    /**
      * \brief 快速排序算法
      */
    void quick_sort(int low, int high);

    /**
      * \brief 希尔排序算法
      */
    void shell_sort(int low, int high);

public:
    // 构造函数
    Vector(int capacity = DEFAULT_CAPACITY, int size = 0, T v = 0)
    {
        _element = new T[_capacity = DEFAULT_CAPACITY];
        for (_size = 0; _size < size; _element[_size++] = v)
            ;
    }
    Vector(const T *vec, int n) { copy_from(vec, 0, n); }
    Vector(const T *vec, int low, int high) { copy_from(vec, low, high); }
    Vector(const Vector<T> &v) { copy_from(v._element, 0, v._size); }
    Vector(const Vector<T> &v, int low, int high) { copy_from(v._element, low, high); }
    // 析构函数
    ~Vector()
    {
        delete[] _element;
        _element = nullptr;
    }

#//只读接口
    /**
      * \brief 元素的规模
      * \return 元素的数量
      */
    unsigned size() const { return static_cast<unsigned>(_size); }
    bool empty() const { return _size == 0; }

    /**
      * \brief 无序向量整体查找
      * \param element 查找的元素
      * \return 成功找到返回元素的索引值，失败返回-1
      */
    int find(const T &element) const { return find(element, 0, _size); }

    /**
      * \brief 无序向量区间查找
      * \param element 待查找元素
      * \param low 开始位置
      * \param high 结束位置
      * \return 成功找到返回元素的索引值，失败返回-1
      */
    int find(const T &element, int low, int high) const;

    /**
     * \brief 有序向量整体查找
     * \param element 待查找的元素
     * \return 成功找到返回元素的索引值, 失败返回-1
     */
    int search(const T &element) const { return (0 >= _size) ? -1 : search(element, 0, _size); }

    /**
     * \brief 有序向量区间查找
     * \param element 带查找的元素
     * \param low 起始位置
     * \param high 结束位置
     * \return 成功找到返回元素的索引值, 失败返回-1
     */
    int search(const T &element, int low, int high) const;

#//可写访问接口

    T &operator[](int index);
    const T &operator[](int index) const;
    Vector<T> &operator=(const Vector<T> &vec);

    /**
     * \brief 区间删除元素
     * \param 起始位置
     * \param 结束位置
     * \return 被删除元素数目
     */
    int remove(int low, int high);

    /**
     * \brief 根据索引删除元素
     * \param index 要删除元素的索引
     * \return 删除的元素
     */
    T remove(int index);

    /**
     * \brief 根据索引插入元素
     * \param index 要插入的位置
     * \param element 要插入的元素
     * \return 插入的位置
     */
    int insert(int index, const T &element);

    /**
     * \brief 末尾插入元素
     * \param element 要插入的元素
     * \return 插入位置
     */
    int insert(const T &element) { return insert(_size, element); }

    /**
     * \brief 区间排序
     * \param low 起始位置
     * \param high 结束位置
     */
    void sort(int low, int high);

    /**
     * \brief 整体排序
     */
    void sort() { sort(0, _size); }

    /**
     * \brief 区间置乱
     * \param low 起始位置
     * \param high 结束位置
     */
    void unsort(int low, int high);

    /**
     * \brief 整体置乱
     */
    void unsort() { unsort(0, _size); }

    /**
     * \brief 无序去重
     * \return 被删除元素总数
     */
    int deduplicate();

    /**
     * \brief 有序去重
     * \return 被删除元素总数
     */
    int uniquify();

#// 遍历

    /**
     * \brief 遍历（使用函数指针，只读或局部性修改）
     */
    void traverse(void (*)(T &));

    /**
     * \brief 遍历（使用函数对象，可全局修改）
     */
    template <typename VST>
    void traverse(VST &);
};

template <typename T>
void Vector<T>::copy_from(const T *vec, int low, int high)
{
    _element = new T[_capacity = 2 * (high - low)];
    _size = 0;
    while (low < high)
    {
        _element[_size++] = vec[low++];
    }
}

template <typename T>
int Vector<T>::find(const T &element, int low, int high) const
{
    // 自后向前，顺序查找·
    while ((low < high--) && (element != _element[high]))
        ;
    return high;
}

template <typename T>
const T &Vector<T>::operator[](int index) const
{
    return _element[index];
}

template <typename T>
T &Vector<T>::operator[](int index)
{
    return _element[index];
}

template <typename T>
void Vector<T>::expand()
{
    if (_size < _capacity) // 容量未满时，不必扩容
        return;

    // 不低于最小容量
    if (_capacity < DEFAULT_CAPACITY)
        _capacity = DEFAULT_CAPACITY;

    T *oldElem = _element;
    _element = new T[_capacity <<= 1]; // 容量增加2倍
    for (int i = 0; i < _size; ++i)
        _element[i] = oldElem[i]; // 复制原来向量中的内容

    delete[] oldElem; // 释放原空间
    oldElem = nullptr;
}

template <typename T>
void Vector<T>::shrink()
{
    // 当容量小于默认容量时不需要缩容
    if (_capacity < DEFAULT_CAPACITY)
        return;

    if (_size << 2 > _capacity) // 以%25为界
        return;

    T *oldElem = _element;
    _element = new T[_capacity >>= 1]; // 容量减半
    for (int i = 0; i < _size; ++i)
        _element[i] = oldElem[i]; // 复制原向量诸元素

    delete[] oldElem;
    oldElem = nullptr;
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &vec)
{
    if (_element)
        delete[] _element;
    copy_from(vec._element, 0, vec._size);
    return *this;
}

template <typename T>
int Vector<T>::remove(int low, int high)
{
    if (low == high)
        return 0;
    while (high < _size)
        _element[low++] + _element[high++]; // [high, _size）顺次前移high-low个单元
    _size = low;                            // 更新元素数量，直接丢弃尾部[low, _size=high）区间

    shrink(); // 有必要进行缩容
    return high - low;
}

template <typename T>
T Vector<T>::remove(int index)
{
    T elem = _element[index]; // 备份删除的元素
    remove(index, index + 1);
    return elem;
}

template <typename T>
int Vector<T>::insert(int index, const T &element)
{
    expand(); // 有必要时进行扩容

    for (int i = _size; i > index; --i)
        _element[i] = _element[i - 1]; // 自后向前，index后面的元素诸一后移
    _element[index] = element;
    ++_size; // 添加新元素，更新元素个数
    return index;
}

template <typename T>
void Vector<T>::unsort(int low, int high)
{
    T *vec = _element + low; // 将子向量_element[low, high]视作另一向量vec[0, high-low]
    for (int i = high - low; i > 0; --i)
        swap(vec[i - 1], vec[rand() % i]); // 自后向前，将vec[i-1]与vec[0, i]中某一元素随即交换
}

template <typename T>
int Vector<T>::deduplicate()
{
    int oldSize = _size;
    int i = 1;
    while (i < _size)
        (find(_element[i], 0, i) < 0) ? i++ : remove(i);
    return oldSize - _size;
}

template <typename T>
void Vector<T>::traverse(void (*visit)(T &))
{
    for (int i = 0; i < _size; ++i)
        visit(_element[i]);
}

template <typename T>
template <typename VST>
void Vector<T>::traverse(VST &visit)
{
    for (int i = 0; i < _size; ++i)
        visit(_element[i]);
}

#endif
