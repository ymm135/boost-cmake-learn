#pragma once
#include "base.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace xm
{
    Base::Base(/* args */)
    {
    }

    Base::~Base()
    {
    }

    void Base::run()
    {
    }

    /**
     * 向量（Vector）是一个封装了动态大小数组的顺序容器（Sequence Container）。
     * 跟任意其它类型容器一样，它能够存放各种类型的对象。
     * 可以简单的认为，向量是一个能够存放任意类型的动态数组。
     * 1.push_back 在数组的最后添加一个数据
     * 2.pop_back 去掉数组的最后一个数据
     * 3.at 得到编号位置的数据
     * 4.begin 得到数组头的指针
     * 5.end 得到数组的最后一个单元+1的指针
     * 6．front 得到数组头的引用
     * 7.back 得到数组的最后一个单元的引用
     * 8.max_size 得到vector最大可以是多大
     * 9.capacity 当前vector分配的大小
     * 10.size 当前使用数据的大小
     * 11.resize 改变当前使用数据的大小，如果它比当前使用的大，者填充默认值
     * 12.reserve 改变当前vecotr所分配空间的大小
     * 13.erase 删除指针指向的数据项
     * 14.clear 清空当前的vector
     * 15.rbegin 将vector反转后的开始指针返回(其实就是原来的end-1)
     * 16.rend 将vector反转构的结束指针返回(其实就是原来的begin-1)
     * 17.empty 判断vector是否为空
     * */

    void Base::vector()
    {
        cout << "===========vector===========" << endl;

    }

} // namespace xm
