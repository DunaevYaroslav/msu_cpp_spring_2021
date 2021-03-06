#pragma once

#include <string>
#include <sstream>
#include <iostream>

bool try_digit(std::string str)
{
    for (uint64_t i = 0; i < str.size(); i++)
    {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

class format_exc : std::exception
{
private:
    std::string what_;

public:
    explicit format_exc(std::string what) : what_(std::move(what))
    {
    }

    const char *what() const noexcept override
    {
        return what_.c_str();
    }
};

int get_num(const std::string &s)
{
    int res;
    try
    {
        res = std::stoi(s);
    }
    catch (const std::logic_error &)
    {
        throw format_exc("Incorrect string format");
    }
    return res;
}

std::string res_check(const std::string &s)
{
    for (auto c : s)
    {
        if (c == '{' || c == '}')
        {
            throw format_exc("Not enough arguments");
        }
    }
    return s;
}

template <typename T>
std::string process(const std::string &s, T arg, int n)
{
    int i = 0;
    bool find = false;
    size_t begin = std::string::npos;
    size_t end = std::string::npos;
    std::string cur_str{};
    std::ostringstream res{};
    while (i < s.length())
    {
        begin = s.find_first_of("{", i);
        end = s.find_first_of("}", i);
        if (begin > end)
        {
            throw format_exc("expected { before }");
        }
        if (end == std::string::npos && begin != std::string::npos)
        {
            throw format_exc("expected } after {");
        }
        if (s[i] == '{')
        {
            i++;
            cur_str = "";
            while (i < s.length() && s[i] != '}')
            {
                cur_str += s[i];
                i++;
            }
            if (n == get_num(cur_str))
            {
                res << arg;
                find = true;
            }
            else
            {
                res << ("{" + cur_str + "}");
            }
        }
        else
        {
            res << s[i];
        }
        i++;
    }
    if (try_digit(cur_str) && cur_str != "")
    {
        try
        {
            int number = std::stoi(cur_str);
        }
        catch (const std::out_of_range &err)
        {
            throw format_exc("incorrect input");
        }
    }
    else
    {
        throw format_exc("incorrect input");
    }
    if (!find)
    {
        throw format_exc("Incorrect string format");
    }
    return res.str();
}

int counter(bool f = false)
{
    static int n = -1;
    int cur = n;
    if (f)
    {
        n = -1;
        return cur + 1;
    }
    else
    {
        n++;
        cur = n;
        return cur;
    }
}

template <typename T>
std::string format(const std::string &s, T arg)
{
    return res_check(process(s, arg, counter(true)));
}

template <class... Args>
std::string format(const std::string &s, const Args &...args)
{
    return s;
}
template <typename T, typename... ArgsT>
std::string format(const std::string &s, T arg, ArgsT... args)
{
    std::string res;
    try
    {
        res = process(s, arg, counter());
    }
    catch (const format_exc &)
    {
        counter(true);
    }
    return format(res, std::forward<ArgsT>(args)...);
}