#ifndef LISTEXCEPTION_H
#define LISTEXCEPTION_H

#include <string>
#include <exception>

class ListException : public std::exception{
    std::string message;
public:
    ListException(std::string msg) : message(msg){}
    virtual const char* what() const noexcept{
        return message.c_str();
    }
};

#endif // LISTEXCEPTION_H
