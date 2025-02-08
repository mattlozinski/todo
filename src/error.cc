#include "error.h"
void error(const std::string command, ErrorType errorType){
    cout << "\e[31merror:\e[0m ";
    switch (errorType){
        case ErrorType::SWW:
            cerr << "something went wrong";
            break;
        case ErrorType::NO_ARGS:
            cerr << "no valid arguments provided for '\e[1m" << command << "\e[0m'\n";
            break;
        case ErrorType::TOO_MANY_ARGS:
            cerr << "too many arguments for '\e[1m" << command << "\e[0m'\n";
            break;
        case ErrorType::UNKNOWN_COMMAND:
            cerr << "unknown command '\e[1m" << command << "\e[0m'\n";
            break;
        default:
            cerr << "unhandled error type for command '\e[1m" << command << "\e[0m'\n";
            break;
    }
}
