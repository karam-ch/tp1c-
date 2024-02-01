#include "appexception.h"

AppException::AppException() {}

AppException::AppException(int code) {
    this->code = code;
}


int AppException::getCode() {
    return this->code;
}
