/*
** EPITECH PROJECT, 2020
**  
** File description:
**  
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <exception>
#include <stdexcept>

class ArgError : public std::exception {
    public:
        ArgError(std::string const& e) throw();
    virtual ~ArgError(void) throw() {};

    const char *what(void) const throw() override { return (_message.data()); };

    private:
        std::string _message;
};

class FileError : public std::exception {
    public:
        FileError(std::string const& e) throw();
    virtual ~FileError(void) throw() {};

    const char *what(void) const throw() override { return (_message.data()); };

    private:
        std::string _message;
};

class FileExtensionError : public std::exception {
    public:
        FileExtensionError(std::string const& e) throw();
    virtual ~FileExtensionError(void) throw() {};

    const char *what(void) const throw() override { return (_message.data()); };

    private:
        std::string _message;
};

class InputErrorUser : public std::exception {
    public:
        InputErrorUser(std::string const& e) throw();
    virtual ~InputErrorUser(void) throw() {};

    const char *what(void) const throw() override { return (_message.data()); };

    private:
        std::string _message;
};

class LoopError : public std::exception {
    public:
        LoopError(std::string const& e) throw();
    virtual ~LoopError(void) throw() {};

    const char *what(void) const throw() override { return (_message.data()); };

    private:
        std::string _message;
};

#endif /* !ERROR_HPP_ */
