// This file has the interface for any commands added to CommandPrompt.cpp. It is purely virtual.

#pragma once
#include <string>
#include "Constants.h"

class AbstractCommand {
public:
    virtual int execute(std::string) = 0;
    virtual void displayInfo() = 0;
    virtual ~AbstractCommand() = default;
};