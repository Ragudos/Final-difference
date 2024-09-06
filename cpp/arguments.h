#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

/**
 *
 * @param argc The amount of arguments that's in `argv`
 * @param argv The list of arguments
 *
 * @return A map with keys being the flags and its value being the flag's value. If no
 * value is encountered, its value is set to `true`
 *
 * @throws `runtime_error` if an argument/s is not in a key-value format (key/flag first, then value).
 */
map<string, string> processArguments(int argc, char *argv[])
{
    map<string, string> arguments;

    for (int i = 1; i < argc; ++i)
    {
        string argument = argv[i];

        if (argument.substr(0, 2) == "--")
        {
            string key = argument.substr(2);
            string value;

            const bool IS_LAST_ITEM = i + 1 == argc;

            if (!IS_LAST_ITEM && argv[i + 1][0] != '-')
            {
                value = argv[++i];
            }
            else
            {
                value = "true";
            }

            arguments[key] = value;
        }
        else
        {
            throw runtime_error("invalid-argument");
        }
    }

    return arguments;
}
