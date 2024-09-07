#ifndef LEXICON_TOKENIZER

#define LEXICON_TOKENIZER

#include <iostream>
#include <vector>

/**
 * @example
 * To use the `Tokenizer` yourself using the *iterator* pattern.
 *
 * @code
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
 * @endcode
 *
 *
 * @example
 *
 * A function to do the iteration for you
 * @code
 * int main()
 * {
 *      std::string input = "Hi, there!";
 *      std::vector<std::string> = split(input);
 *
 *      // Tokens will be: ["Hi", ",", "there", "!"];
 *
 *      return 0;
 * }
 * @endcode
 */

/**
 * @class Tokenizer
 * @brief A class for tokenizing strings based on specified delimiters.
 *
 * This class provides functionality to split a string into tokens separated by
 * delimiters. It supports default delimiters as well as user-defined
 * delimiters. The class allows for iteration through tokens and provides
 * methods to reset the tokenizer to its initial state.
 *
 * @note Default delimiters include space, tab, newline, and carriage return ("
 * \t\n\r").
 */
class Tokenizer
{
  public:
    /**
     * @brief Default delimiters used for tokenization.
     *
     * This static constant string defines the default set of delimiters: space,
     * tab, newline, and carriage return (" \t\n\r").
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

#endif

#ifndef LEXICON_PARSER

#define LEXICON_PARSER

#include <iostream>
#include <vector>

std::vector<std::string> split(const std::string &s);
std::vector<std::string>
split(const std::string &s, const std::string &delimiters);

#endif
