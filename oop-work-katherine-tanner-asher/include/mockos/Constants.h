/*
 * This header defines error codes, file extension types, and various constants used across the application.
 * It includes:
 * - ERROR_CODES: Enum defining various potential error states like file not found, invalid arguments, etc.
 * - EXT_INFO: Constants related to file extensions and their properties.
 * - FILE_INFO: Constants related to file content handling such as text and image markers.
 * - EXPORT_INFO: Constants defining export parameters for files, particularly image files.
 * Additional global constants define initialization and validation states.
 */

#pragma once
#include <string>

enum ERROR_CODES {
    SUCCESS = 0,
    INVALID_ARGS = 1,
    FILE_NOT_FOUND = 2,
    FILE_ALREADY_EXISTS = 3,
    INVALID_IMG = 4,
    IMG_DOES_NOT_SUPPORT_APPEND = 5,
    WRONG_PASSWORD = 6,
    COMMAND_ALREADY_EXISTS = 7,
    INVALID_FILE = 8,
    FILE_IS_OPEN = 9,
    UNABLE_TO_MOVE_FILE = 10,
    QUIT = 11,
};

namespace EXT_INFO {
    const int EXT_LENGTH = 3;
    const std::string IMG_EXT = "img";
    const std::string TXT_EXT = "txt";
    const std::string DOT = ".";
}

namespace FILE_INFO {
    const char X_TOKEN = 'X';
    const char SPACE_TOKEN = ' ';
    const std::string text = "text";
    const std::string img = "image";
    const char ZERO_CHAR = '0';
}

namespace EXPORT_INFO {
    const std::string EXPORTED_FILE_DESTINATION_DIRECTORY = "exported-files";
    const std::string IMAGE_FILE_NAME_TOKEN = "_IMG";
}

const int INIT = 0;
const int OFFSET = 1;
const int VALID = 1;
const int INVALID = 0;