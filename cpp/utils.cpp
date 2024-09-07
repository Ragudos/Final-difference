#include "./utils.h"

bool elementsInVectorAreEqual(std::vector<int> &vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        for (int j = i; j < vec.size() - i - 1; ++j)
        {
            if (vec.at(j) != vec.at(j + 1))
            {
                return false;
            }
        }
    }

    return true;
}
