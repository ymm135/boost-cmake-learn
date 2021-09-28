//
// Created by zero on 2021/9/27.
//

#ifndef BOOST_LEARN_TEACHER_H
#define BOOST_LEARN_TEACHER_H

#include <cstring>

using namespace std;

namespace xm
{

    class Teacher
    {
        friend ostream &operator<<(ostream &out, const Teacher &obj)
        {
            out << "(name:" << obj.name << ",age:" << obj.age << ") ";
            return out;
        }

    public:
        Teacher()
        {
            age = 33;
            strcpy(name, "");
        }

        Teacher(char *name, int age)
        {
            this->age = age;
            strcpy(this->name, name);
        }

        void printT()
        {
            cout << name << ", " << age << endl;
        }

    private:
        int age;
        char name[32];
    };
}
#endif //BOOST_LEARN_TEACHER_H
