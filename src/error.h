#pragma once
enum class ErrorType {
    SWW,
    NO_ARGS,
    TOO_MANY_ARGS,
    UNKNOWN_COMMAND
};
void error(const std::string command, ErrorType errorType = ErrorType::SWW);
