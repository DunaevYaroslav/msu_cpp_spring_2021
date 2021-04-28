#include "parser.h"

    void TokenParser::SetStartCallback(const std::function<int()> &start) {
        start_func_ = start;
    }

    void TokenParser::SetStringTokenCallback(const std::function<void(std::string&)> &string) {
        string_func_ = string;
    }

    void TokenParser::SetDigitTokenCallback(const std::function<void(uint64_t&)> &digit) {
        digit_func_ = digit;
    }

    void TokenParser::SetEndCallback(const std::function<std::string()> &end) {
        end_func_ = end;
    }

const std::string TokenParser::Parse(const std::string &text) {
        if(start_func_ == nullptr){
            return text;
        }
        if (start_func_ != nullptr) {
            start_func_();
            std::istringstream iss = std::istringstream(text);
            std::ostringstream oss;
            std::string token;
            while (!iss.eof()) {
                iss >> token;
                bool isnumber = true;
                for (auto c: token) {
                    if (!isdigit(c)) {
                        isnumber = false;
                        break;
                    }
                }
                if (isnumber) {
                    if (digit_func_ == nullptr) {
                        throw std::runtime_error("Функция для обработки чисел не была инициализирована");
                    }
                    uint64_t t = std::stoi(token);
                    digit_func_(t);
                    oss << t << " ";
                } else {
                    if (string_func_ == nullptr) {
                        throw std::runtime_error("Функция для обработки строк не была инициализирована");
                    }
                    string_func_(token);
                    oss << token << " ";
                }
            }
            if (end_func_ == nullptr) {
                throw std::runtime_error("End-функция не была инициализирована");
            }
            end_func_();
            return oss.str();
        }
        return 0;
    }
