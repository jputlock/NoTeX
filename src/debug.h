//
// Created by jputlock on 7/15/19.
//

#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>

namespace Debug
{
    void debug_print(const std::string& message) {
        std::cout << message;
    }
}

#endif
