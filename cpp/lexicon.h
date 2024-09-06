#include <iostream>
#include <vector>

/**
 * @file lexicon.h
 * @brief Anything that involves extracting/tokenizing/parsing a string goes here.
 *
 * @example
 *
 * To use the `Tokenizer` yourself using the *iterator* pattern.
 * ```Cpp
 * int main()
 * {
 *      std::vector<std::string> tokens;
 *      Tokenizer str("String to be split", " ");
 *
 *      while (str.NextToken())
 *      {
 *          tokens.push_back(str.GetToken());
 *      }
 *
 *      return 0;
 * }
 * ```
 *
 * Another abstraction layer to have the example above done for you.
 * ```Cpp
 * int main()
 * {
 *      std::string input = "Hi, there!";
 *      std::vector<std::string> = split(input);
 *
 *      // Tokens will be: ["Hi", ",", "there", "!"];
 *
 *      return 0;
 * }
 * ```
 */

/**
 * @class Tokenizer
 * @brief A class for tokenizing strings based on specified delimiters.
 *
 * This class provides functionality to split a string into tokens separated by delimiters. It supports
 * default delimiters as well as user-defined delimiters. The class allows for iteration through tokens
 * and provides methods to reset the tokenizer to its initial state.
 *
 * @note Default delimiters include space, tab, newline, and carriage return (" \t\n\r").
 */
class Tokenizer
{
public:
    /**
     * @brief Default delimiters used for tokenization.
     *
     * This static constant string defines the default set of delimiters: space, tab, newline, and carriage return (" \t\n\r").
     */
    static const std::string DELIMITERS;
    Tokenizer(const std::string &str);
    Tokenizer(const std::string &str, const std::string &delimiters);
    bool NextToken();
    bool NextToken(const std::string &delimiters);
    const std::string GetToken() const;
    void Reset();

protected:
    const std::string m_string;

    size_t m_offset;

    std::string m_token;
    std::string m_delimiters;
};

const std::string Tokenizer::DELIMITERS(" \t\n\r");

Tokenizer::Tokenizer(const std::string &s) : m_string(s),
                                             m_offset(0),
                                             m_delimiters(DELIMITERS) {};

Tokenizer::Tokenizer(const std::string &s, const std::string &delimiters) : m_string(s),
                                                                            m_offset(0),
                                                                            m_delimiters(delimiters) {};

bool Tokenizer::NextToken()
{
    return NextToken(m_delimiters);
};

bool Tokenizer::NextToken(const std::string &delimiters)
{
    // Basically, from the start of the string, we find the first character that is not of `delimiter`.
    size_t i = m_string.find_first_not_of(delimiters, m_offset);

    // If we didn't find it, then we return false (thus, we've reached the end/exhausted the iterator/ no more tokens
    // can be extracted).
    if (std::string::npos == i)
    {
        m_offset = m_string.length();

        return false;
    }

    // After finding the first instance that is not of `delimiter`, we just find the next instance that is
    // the `delimiter` starting from `i` or where the first non-delimiter was.
    size_t j = m_string.find_first_of(delimiters, i);

    // The case where we reached the end of `m_string`.
    if (std::string::npos == j)
    {
        m_token = m_string.substr(i);
        m_offset = m_string.length();

        return true;
    }

    m_token = m_string.substr(i, j - 1);
    m_offset = j;

    return true;
};

const std::string Tokenizer::GetToken() const
{
    return m_token;
};

void Tokenizer::Reset()
{
    m_offset = 0;
    m_token = "";
};

std::vector<std::string> split(const std::string &s)
{
    return split(s, Tokenizer::DELIMITERS);
}

std::vector<std::string> split(const std::string &s, const std::string &delimiters)
{
    std::vector<std::string> vec;
    Tokenizer tokenizer(s, delimiters);

    while (tokenizer.NextToken())
    {
        vec.push_back(tokenizer.GetToken());
    }

    return vec;
}
