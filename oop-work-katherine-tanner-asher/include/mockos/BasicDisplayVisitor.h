/*
 * Defines the BasicDisplayVisitor class which extends AbstractFileVisitor. This class
 * is designed to interact with TextFile and ImageFile objects through the visitation methods.
 */

#pragma once
#include "../../include/mockos/AbstractFileVisitor.h"
#include "../../include/mockos/TextFile.h"
#include "../../include/mockos/ImageFile.h"
#include <vector>

class BasicDisplayVisitor : public AbstractFileVisitor {
    void visit_TextFile(TextFile* file) override;
    void visit_ImageFile(ImageFile* file) override;
};
