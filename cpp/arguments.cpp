#include "./arguments.h"
#include "./utils.h"

#include <cstring>

std::unordered_map<const char *, const char *> argumentDefinitions;

void initializeArguments()
{
    argumentDefinitions["-h"] = "Displays help information";
    argumentDefinitions["-s"] =
        "Specify that the next argument will be the sequence to be parsed.";
    argumentDefinitions["-c"] =
        "Specify that the next agument will be the count of how many numbers "
        "to predict in the sequence.";
}

void displayHelp()
{
    if (argumentDefinitions.empty())
    {
        initializeArguments();
    }

    std::cout << "Available arguments:" << std::endl;

    for (const auto &argumentDefinition : argumentDefinitions)
    {
        std::cout << "\t" << argumentDefinition.first << " : "
                  << argumentDefinition.second << std::endl;
    }
}

void displaySequenceHelp()
{
    std::cout << "The sequence command, " << toString(SEQUENCE)
              << ", takes in a string of a sequence of "
                 "numbers separated by commas"
              << std::endl;
    std::cout << "\tFor example:" << std::endl;
    std::cout << "\t `./main.exe -s 10,20,30,40,50`" << std::endl;
}

void displayCountHelp()
{
    std::cout << "The count command, " << toString(COUNT)
              << ", takes in a number that indicates "
              << " the amount of predictions this program "
              << " will make for the following numbers of the "
              << " provided sequence. "
              << "Note that this will end early if the sequence provided does "
                 "not converge."
              << std::endl;
    std::cout << "\t For example:" << std::endl;
    std::cout << "\t `./main.exe -s 10,20,30,40,50 -c 5`"
              << " will produce: "
              << "10,20,30,40,50,60,70,80,90,100" << std::endl;
}

/**
 * Assumes that `value` is a string representation of
 * an `ArgumentType`.
 */
void displayCommandHelp(ArgumentType type)
{
    switch (type)
    {
    case HELP: displayHelp(); break;
    case SEQUENCE: displaySequenceHelp(); break;
    case COUNT: displayCountHelp(); break;
    }
}

std::map<ArgumentType, const char *> processArguments(int argc, char *argv[])
{
    std::map<ArgumentType, const char *> arguments;

    for (int i = 1; i < argc; ++i)
    {
        const char *argument = argv[i];

        if (argument[0] == '-')
        {
            const char *value;
            const bool IS_LAST_ITEM = i + 1 == argc;

            if (!IS_LAST_ITEM && argv[i + 1][0] != '-')
            {
                value = argv[++i];
            }
            else
            {
                value = "true";
            }

            ArgumentType type = fromString(argument);

            auto doesExist = arguments.find(type);

            if (doesExist != arguments.end())
            {
                throw std::invalid_argument(
                    "There cannot be duplicates of a flag");
            }

            arguments[type] = value;
        }
        else
        {
            throw std::invalid_argument(
                "Unknown argument: " + std::string(argument));
        }
    }

    return arguments;
}

const char *toString(ArgumentType type)
{
    switch (type)
    {
    case SEQUENCE: return "-s";
    case COUNT: return "-c";
    case HELP: return "-h";
    default: throw std::runtime_error("invalid-type");
    }
}

ArgumentType fromString(const char *str)
{
    if (!std::strcmp(str, "-s")) return SEQUENCE;
    if (!std::strcmp(str, "-c")) return COUNT;
    if (!std::strcmp(str, "-h")) return HELP;

    throw std::invalid_argument("Unknown argument");
}
