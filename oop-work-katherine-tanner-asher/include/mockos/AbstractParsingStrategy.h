/* This is the interface for abstract parsing strategy.
 * */


#pragma once
#include "Constants.h"
#include <string>
#include <vector>
#include <iostream>

class AbstractParsingStrategy {
public:
    virtual std::vector<std::string>parse(std::string) = 0;
    virtual void getInfo() = 0;
};