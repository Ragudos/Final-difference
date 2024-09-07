#include "./utils.h"
#include <cstdlib>
#include <iostream>
#include <string>

bool elementsInVectorAreEqual(std::vector<int> &vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        for (int j = i + 1; j < vec.size(); ++j)
        {
            if (vec.at(i) != vec.at(j))
            {
                return false;
            }
        }
    }

    return true;
}

int charPointerToInt(const char *c)
{
    char *end;

    int num = std::strtol(c, &end, 10);

    if (*end == '\0')
    {
        return num;
    }

    throw std::runtime_error("Invalid number: " + std::string(c));
}

std::vector<int> vecStrToVecInt(std::vector<std::string> &vecStr)
{
    std::vector<int> vecInt;

    for (const std::string &str : vecStr)
    {
        int num;

        STR2INT_RETURN_VALUES result = strToInt(num, str.c_str());

        switch (result)
        {
        case STR2INT_INCONVERTIBLE:
            throw std::runtime_error("inconvertible");
            break;
        case STR2INT_OVERFLOW: throw std::runtime_error("inconvertible"); break;
        case STR2INT_UNDERFLOW:
            throw std::runtime_error("inconvertible");
            break;
        case STR2INT_SUCCESS: vecInt.push_back(num); break;
        }
    }

    return vecInt;
}

STR2INT_RETURN_VALUES strToInt(int &num, char const *s)
{
    return strToInt(num, s, 0);
}

STR2INT_RETURN_VALUES strToInt(int &num, char const *s, int base)
{
    char *end;
    long l;
    errno = 0;

    l = strtol(s, &end, base);

    if ((errno == ERANGE && l == LONG_MAX) || l > INT_MAX)
    {
        return STR2INT_OVERFLOW;
    }

    if ((errno == ERANGE && l == LONG_MIN) || l < INT_MIN)
    {
        return STR2INT_UNDERFLOW;
    }

    if (*s == '\0' || *end != '\0')
    {
        return STR2INT_INCONVERTIBLE;
    }

    num = l;

    return STR2INT_SUCCESS;
}
