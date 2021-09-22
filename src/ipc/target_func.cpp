#pragma once
#include <iostream>
#include "target_func.h"

namespace xm
{
    void TargetFunc::start(char *msg)
    {
        std::cout << "[TargetFunc::start] msg: " << msg << std::endl;
    }
}