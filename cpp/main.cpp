#include <cstring>
#include <iostream>
#include <map>

#include "./arguments.h"
#include "./difference_table.h"
#include "./lexicon.h"
#include "./utils.h"

/**
 * Returns `true` if the program should exit early.
 */
bool extractArguments(
    std::map<ArgumentType, const char *> &arguments,
    ArgumentType &previousArgumentType, const char *&sequence,
    int &amountToPredict)
{
    for (const auto &argument : arguments)
    {
        ArgumentType type = argument.first;
        const char *value = argument.second;

        switch (type)
        {
        case HELP:
        {
            // TODO: Track all the previous commands to HELP to ouptut the
            // appropriate value.
            displayCommandHelp(previousArgumentType);

            return true;
        }
        break;
        case SEQUENCE:
        {
            sequence = value;
        }
        break;
        case COUNT:
        {
            amountToPredict = charPointerToInt(value);
        }
        break;
        }

        previousArgumentType = type;
    }

    return false;
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        std::cerr << "What would you like me to do?" << std::endl;

        displayHelp();

        return EXIT_FAILURE;
    }

    std::map<ArgumentType, const char *> arguments;

    try
    {
        arguments = processArguments(argc, argv);
    }
    catch (const std::invalid_argument &err)
    {
        std::cerr << err.what() << std::endl << std::endl;

        displayHelp();

        return EXIT_FAILURE;
    }

    ArgumentType previousArgumentType;
    const char *sequence;
    int amountToPredict;

    if (extractArguments(
            arguments, previousArgumentType, sequence, amountToPredict))
    {
        return EXIT_SUCCESS;
    }

    std::vector<std::string> tokenizedSequence = split(sequence, ",");
    std::vector<int> parsedSequence;

    try
    {
        parsedSequence = vecStrToVecInt(tokenizedSequence);
    }
    catch (const std::runtime_error &err)
    {
        std::cerr << err.what() << std::endl;

        return EXIT_FAILURE;
    }

    DifferenceTable differenceTable(parsedSequence);

    try
    {
        std::cout << "Common difference: "
                  << differenceTable.GetCommonDifference() << std::endl;

        if (amountToPredict)
        {
            std::cout << "Next values in sequence: " << std::endl << "\t";

            for (int i = 0; i < amountToPredict; ++i)
            {
                std::cout << differenceTable.GetNextValueInSequence() << " ";
            }

            std::cout << std::endl;
        }
    }
    catch (const std::runtime_error &err)
    {
        std::cerr << err.what() << std::endl;

        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
