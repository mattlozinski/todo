#include "error.h"
#include "colorizer.h"
void error(const std::string command, ErrorType errorType){
    cout << fg::red(style::bold("error: "));
    switch (errorType){
        case ErrorType::SWW:
            cerr << "something went wrong" << endl;
            break;
        case ErrorType::NO_ARGS:
            cerr << "no valid arguments provided for '" << style::bold(command) << "'\n";
            break;
        case ErrorType::TOO_MANY_ARGS:
            cerr << "too many arguments for '" << style::bold(command) << "'\n";
            break;
        case ErrorType::UNKNOWN_COMMAND:
            cerr << "unknown command '" << style::bold(command) << "'\n";
            break;
        default:
            cerr << "unhandled error type for command '" << style::bold(command) << "'\n";
            break;
    }
}
