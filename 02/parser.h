#include <sstream>
class TokenParser {
private:
    std::function<int()> start_func_ = nullptr; //везде тип возвращаемого значения должен быть void
    std::function<void(std::string&)> string_func_ = nullptr; //для теста поставила свои, чтобы сравнивать объекты
    std::function<void(uint64_t&)> digit_func_ = nullptr;
    std::function<std::string()> end_func_ = nullptr;

public:
    void SetStartCallback(const std::function<int()> &start);

    void SetStringTokenCallback(const std::function<void(std::string&)> &string);

    void SetDigitTokenCallback(const std::function<void(uint64_t&)> &digit);

    void SetEndCallback(const std::function<std::string()> &end);

    const std::string Parse(const std::string &text);
};