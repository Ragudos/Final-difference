#ifndef ARGUMENTS_H

#define ARGUMENTS_H

#include <iostream>
#include <map>
#include <unordered_map>

/**
 * This order is important as std::map() orders
 * keys based on their values
 */
enum ArgumentType
{
    SEQUENCE = 0,
    COUNT = 1,
    HELP = 2,
};

extern std::unordered_map<const char *, const char *> argumentDefinitions;

void initializeArguments();
void displayHelp();
void displaySequenceHelp();
void displayCountHelp();
void displayCommandHelp(ArgumentType type);

const char *toString(ArgumentType type);
ArgumentType fromString(const char *str);

std::map<ArgumentType, const char *> processArguments(int argc, char *argv[]);

#endif
