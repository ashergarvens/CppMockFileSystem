/*
 * Defines the ESParsingStrategy class that extends the AbstractParsingStrategy interface.
 * This strategy is specifically tailored for parsing entries based on a defined schema.
 * It provides detailed parsing methods that can be used to interpret structured text inputs.
 */

#pragma once
#include "AbstractParsingStrategy.h"
#include <sstream>

class ESParsingStrategy : public AbstractParsingStrategy {
public:
    std::vector<std::string>parse(std::string) override;
    void getInfo() override;
};