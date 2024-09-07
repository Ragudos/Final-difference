#ifndef HELPERS

#define HELPERS

#include <string>
#include <vector>

enum STR2INT_RETURN_VALUES
{
    STR2INT_SUCCESS,
    STR2INT_OVERFLOW,
    STR2INT_UNDERFLOW,
    STR2INT_INCONVERTIBLE
};

STR2INT_RETURN_VALUES strToInt(int &num, char const *s);
STR2INT_RETURN_VALUES strToInt(int &num, char const *s, int base);
bool elementsInVectorAreEqual(std::vector<int> &vec);
int charPointerToInt(const char *c);
std::vector<int> vecStrToVecInt(std::vector<std::string> &vecStr);

#endif
