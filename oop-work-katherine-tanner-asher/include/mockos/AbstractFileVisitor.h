/* This is the interface for a visitor that can visit Image or Text files. Other file types can be added but they need a visitor also.
 * */

#pragma once
#include "Constants.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
class ImageFile;
class TextFile;

class AbstractFileVisitor{
public:
    virtual void visit_TextFile(TextFile* file) = 0;
    virtual void visit_ImageFile(ImageFile* file) = 0;
};
