#ifndef BOOST_LEARN_MYVECTOR_H
#define BOOST_LEARN_MYVECTOR_H

#include <iostream>

using namespace std;

namespace xm
{

    template<typename T>
    class MyVector
    {

        // 出现异常: no match for ‘operator<<’ (operand types are ‘std::ostream’ {aka ‘std::basic_ostream<char>’} and ‘xm::MyVector<xm::Teacher>’)
        // cout  << 输出使用 , 声明时时T，但是在运行时是: Myvector<xm::Teacher>
        // 这相当于是说：朋友是值得信任的，所以可以对他们公开一些自己的隐私。
        friend ostream &operator<<(ostream &out, const MyVector<T> &obj)
        {
            for (int i = 0; i < obj.m_len; i++) {
                out << obj.m_space[i] << " ";  // 前提是T要实现操作符重载: <<
            }
            out << endl;
            return out;
        }

    public:

        MyVector(int size)  //构造函数
        {
            m_space = new T[size];
            m_len = size;
        }

        MyVector(const MyVector &obj) // 拷贝构造函数
        {
            //根据myv1的大小分配内存
            m_len = obj.m_len;
            m_space = new T[m_len];

            //copy数据
            for (int i = 0; i < m_len; i++) {
                m_space[i] = obj.m_space[i];
            }

        }

        ~MyVector() //析构函数
        {
            if (m_space != NULL) {
                delete[] m_space;
                m_space = NULL;
                m_len = 0;
            }
        }

    public:
        // 数组
        T &operator[](int index)
        {
            return m_space[index];
        }

        // a3 = a2 = a1;
        MyVector<T> &operator=(const MyVector<T> &obj)
        {
            //先把a2的旧的内存释放掉
            if (m_space != NULL) {
                delete[] m_space;
                m_space = NULL;
                m_len = 0;
            }

            //根据a1分配内存
            m_len = obj.m_len;
            m_space = new T[m_len];

            //copy数据
            for (int i = 0; i < m_len; i++) {
                m_space[i] = obj[i];
            }
            return *this;  // a2 = a1; 返回给a2 的自身
        }

    public:
        int getLen()
        {
            return m_len;
        }

    protected:
        T *m_space;
        int m_len;
    };

} // namespace xm

#endif