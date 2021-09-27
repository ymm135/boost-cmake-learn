#pragma once

#include <iostream>

using namespace std;

namespace xm {
    template<typename T>
    class MyVector {

        friend ostream &operator
        <<<T>(
        ostream &out,
        const MyVector &obj
        );

    public:
        MyVector(int size = 0);  //构造函数
        MyVector(const MyVector &obj); // 拷贝构造函数
        ~MyVector(); //析构函数

    public:

        T &operator[](int index);//返回引用
        // a3 = a2 = a1;
        MyVector &operator=(const MyVector &obj);

    public:
        int getLen() {
            return m_len;
        }

    protected:
        T *m_space;
        int m_len;
    };
} // namespace xm
