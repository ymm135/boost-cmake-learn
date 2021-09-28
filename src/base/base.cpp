#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "myvector.h"
#include "teacher.h"
#include "base.h"

using namespace std;

namespace xm
{

    BaseOps::BaseOps(/* args */)
    {
    }

    BaseOps::~BaseOps()
    {
    }

    void BaseOps::run()
    {
        vectorExample();
        templateExample();
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
     * 6.front 得到数组头的引用
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
    void printVector(vector<string> *v)
    {
        for (int i = 0; i < v->size(); i++) {
            cout << i << "." << (*v)[i] << ", ";
        }
        cout << "" << endl;
        cout << "" << endl;
    }

    void BaseOps::vectorExample()
    {
        cout << "===========vector===========" << endl;

        vector<string> books;
        books.push_back("平凡的世界");
        books.push_back("pingfandeshijie");
        books.push_back("principle");
        books.push_back("ooooo");
        books.push_back("aaaaaa");
        books.push_back("bbbbbbb");
        books.push_back("ttttttt");
        books.push_back("uuuuuuu");

        printVector(&books);

        cout << ">> pop_back " << endl;
        books.pop_back();
        printVector(&books);

        cout << ">> sort " << endl;
        sort(books.begin(), books.end()); // begin 得到数组头的指针  end 得到数组的最后一个单元+1的指针
        printVector(&books);

        // 删除元素 返回值：指向删除元素(或范围)的下一个元素。 遍历查找的时候删除
        // 迭代器与指针还是有差异的，如果元素被删除，迭代器就失效了，指针不会!
        cout << ">> erase begin " << endl;
        vector<string>::iterator eraseIt = books.erase(books.begin());
        printVector(&books);
        cout << "*eraseIt=" << *eraseIt << endl;

        cout << "----------------------------" << endl;
    }

    void BaseOps::templateExample()
    {
        //测试类模板
        Teacher t1("t1", 31), t2("t2", 32), t3("t3", 33), t4("t4", 34);

        cout << t1 << endl;

        MyVector<Teacher> tArray(4);
        tArray[0] = t1;
        tArray[1] = t2;
        tArray[2] = t3;
        tArray[3] = t4;

        for (int i = 0; i < 4; i++) {
            Teacher tmp = tArray[i];
            tmp.printT();
        }
        cout << tArray;
    }

} // namespace xm
