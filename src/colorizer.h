/* colorizer by mattlozinski
 * https://github.com/mattlozinski/colorizer
 */
#pragma once
namespace style {
    const std::string RESET = "\e[0m";
    std::string bold(const std::string text){ return "\e[1m"+text+RESET; }
    std::string dim(const std::string text){ return "\e[2m"+text+RESET; }
    std::string underline(const std::string text){ return "\e[4m"+text+RESET; }
    std::string reverse(const std::string text){ return "\e[7m"+text+RESET; }
    std::string strike(const std::string text){ return "\e[9m"+text+RESET; }
}
namespace fg {
    const std::string RESET = "\e[0m";
    std::string normal(const std::string text){ return "\e[37m"+text+RESET; }
    std::string black(const std::string text){ return "\e[30m"+text+RESET; }
    std::string red(const std::string text){ return "\e[31m"+text+RESET; }
    std::string green(const std::string text){ return "\e[32m"+text+RESET; }
    std::string yellow(const std::string text){ return "\e[33m"+text+RESET; }
    std::string blue(const std::string text){ return "\e[34m"+text+RESET; }
    std::string magenta(const std::string text){ return "\e[35m"+text+RESET; }
    std::string cyan(const std::string text){ return "\e[36m"+text+RESET; }
    std::string light_gray(const std::string text){ return "\e[37m"+text+RESET; }

    std::string dark_gray(const std::string text){ return "\e[90m"+text+RESET; }
    std::string light_red(const std::string text){ return "\e[91m"+text+RESET; }
    std::string light_green(const std::string text){ return "\e[92m"+text+RESET; }
    std::string light_yellow(const std::string text){ return "\e[93m"+text+RESET; }
    std::string light_blue(const std::string text){ return "\e[94m"+text+RESET; }
    std::string light_magenta(const std::string text){ return "\e[95m"+text+RESET; }
    std::string light_cyan(const std::string text){ return "\e[96m"+text+RESET; }
    std::string white(const std::string text){ return "\e[97m"+text+RESET; }
}
namespace bg {
    const std::string RESET = "\e[0m";
    std::string normal(const std::string text){ return "\e[47m"+text+RESET; }
    std::string black(const std::string text){ return "\e[40m"+text+RESET; }
    std::string red(const std::string text){ return "\e[41m"+text+RESET; }
    std::string green(const std::string text){ return "\e[42m"+text+RESET; }
    std::string yellow(const std::string text){ return "\e[43m"+text+RESET; }
    std::string blue(const std::string text){ return "\e[44m"+text+RESET; }
    std::string magenta(const std::string text){ return "\e[45m"+text+RESET; }
    std::string cyan(const std::string text){ return "\e[46m"+text+RESET; }
    std::string light_gray(const std::string text){ return "\e[47m"+text+RESET; }

    std::string dark_gray(const std::string text){ return "\e[100m"+text+RESET; }
    std::string light_red(const std::string text){ return "\e[101m"+text+RESET; }
    std::string light_green(const std::string text){ return "\e[102m"+text+RESET; }
    std::string light_yellow(const std::string text){ return "\e[103m"+text+RESET; }
    std::string light_blue(const std::string text){ return "\e[104m"+text+RESET; }
    std::string light_magenta(const std::string text){ return "\e[105m"+text+RESET; }
    std::string light_cyan(const std::string text){ return "\e[106m"+text+RESET; }
    std::string white(const std::string text){ return "\e[107m"+text+RESET; }
}
