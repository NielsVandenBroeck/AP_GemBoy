//
// Created by niels on 1/01/2023.
//

#ifndef PROJECT_FILEEXCEPTION_H
#define PROJECT_FILEEXCEPTION_H

#include <exception>
#include <string>

/**
 * The FileException class is a child of the std::exception such that exceptions can be handled precisely with custom
 * messages.
 */
class FileException : public std::exception {
public:
    /**
     * explanation: return a custom message of the exception.
     * @return string that explain the exception.
     */
    virtual std::string explanation() { return "Error occurred."; }
};

/**
 * The NoLevelMap is a child of FileException. It is used to throw an exception when the directory 'Levels' is not
 * found.
 */
class NoLevelMap : public FileException {
public:
    /**
     * explanation: return a custom message of the exception.
     * @return string that explain the exception.
     */
    std::string explanation() override {
        return "The directory 'Levels' (where the level configuration files should be) is not found.";
    }
};

/**
 * The Nofilesfound is a child of FileException. It is used to throw an exception when there are no levels found in the
 * directory 'Levels'.
 */
class Nofilesfound : public FileException {
public:
    /**
     * explanation: return a custom message of the exception.
     * @return string that explain the exception.
     */
    std::string explanation() override { return "The directory 'Levels' does not contain any levels."; }
};

/**
 * The IncorrectFile is a child of FileException. It is used to throw an exception when a level-file is configured
 * incorrectly.
 */
class IncorrectFile : public FileException {
public:
    /**
     * explanation: return a custom message of the exception.
     * @return string that explain the exception.
     */
    std::string explanation() override { return "A file was not configured correctly."; }
};

#endif // PROJECT_FILEEXCEPTION_H
