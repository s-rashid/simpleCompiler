#include "runtimeexception.h"

RuntimeException::RuntimeException() : std::exception () {
    msg = "Unexpected Error";
}
