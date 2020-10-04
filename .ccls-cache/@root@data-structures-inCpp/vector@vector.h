/*************************************************************************
  > File Name       : vector.h
  > Author          : Harold
  > Mail            : 2106562095@qq.com
  > Github          : www.github.com/Haroldcc
  > Created Time    : Sun 04 Oct 2020 03:11:41 PM CST
 ************************************************************************/

#ifndef VECTOR_H_
#define VECTOR_H_

template <typename T>
class Vector
{
	private:
		int _size;           // 元素的个数
		int _capacity;       // 数组的容量
		T* _element;         // 存储元素的数组
	protected:
		/**
		 * \brief 拷贝数组区间vec[low, high]
		 * \param vec 源数组
		 * \parma low 起始位置
		 * \parma high 结束位置
		 * \return void
		 */
		void copy_from(const T* vec, int low, int high);

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
		Vector(int capacity = 3, int size = 0, T v = 0)
		{
			_element = new T[_capacity=capacity];
			for(_size = 0; _size < size; _element[_size++] = v)
				;
		}
		Vector(const T* vec, int n){copy_from(vec, 0, n);}
		Vector(const T* vec, int low, int high){copy_from(vec, low, high);}
		Vector(const Vector<T>& v){copy_from(v._element, 0, v._size);}
		Vector(const Vector<T>& v, int low, int high){copy_from(v._element, low, high);}
		// 析构函数
		~Vector(){delete[] _element; _element = nullptr;}

		//只读接口
		/**
		 * \brief 元素的规模
		 * \return 元素的数量
		 */
		unsigned size()const {return static_cast<unsigned>(_size);}
		bool empty()const {return _size == 0;}

		/**
		 * \brief 无序向量整体查找
		 * \parma element 查找的元素
		 * \return 成功找到返回元素的索引值，失败返回-1
		 */
		int find(const T& element)const {return find(element, 0, _size);}

		/**
		 * \brief 无序向量区间查找
		 * \parma element 带查找元素
		 * \parma low 开始位置
		 * \parma high 结束位置
		 * \return 成功找到返回元素的索引值，失败返回-1
		 */


};

#endif
