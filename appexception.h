#ifndef APPEXCEPTION_H
#define APPEXCEPTION_H
#include <QException>


class AppException
{
public:
    AppException();
    AppException(int code);
    int getCode();

private:
    int code;
};

#endif // APPEXCEPTION_H
