/*
 * Defines the RenameParsingStrategy class, extending the AbstractParsingStrategy interface.
 * This parsing strategy is specialized for processing input commands intended for renaming files.
 * It parses a string input to extract necessary parameters for a rename operation, typically the
 * current file name and the new name. This class facilitates the interpretation and execution of
 * rename commands by providing structured data necessary for such operations.
 */

#pragma once
#include "AbstractParsingStrategy.h"

class RenameParsingStrategy : public AbstractParsingStrategy {
public:
    std::vector<std::string>parse(std::string) override;
    void getInfo() override;
};