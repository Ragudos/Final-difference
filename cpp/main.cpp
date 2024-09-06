#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void getDifferences(vector<int> &valuesToSubtract, vector<int> &differences)
{
    if (valuesToSubtract.size() < 2)
    {
        return;
    }

    for (int i = 0; i < valuesToSubtract.size() - 1; ++i)
    {
        int difference;

        if (i == valuesToSubtract.size() - 1)
        {
            difference = valuesToSubtract.at(i) - valuesToSubtract.at(i - 1);
        }
        else
        {
            difference = valuesToSubtract.at(i + 1) - valuesToSubtract.at(i);
        }

        differences.push_back(difference);
    }
}

bool isVectorElementsAllEqual(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        for (int j = 0; j < vec.size(); ++j)
        {
            if (vec.at(i) != vec.at(j))
            {
                return false;
            }
        }
    }

    return true;
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        std::cerr << "Please provide a sequence to process")
        return EXIT_FAILURE;
    }

    string input = argv[1];

    try
    {
        vector<int> sequence = tokenizeBy(input, ',');

        for (int i : sequence)
        {
            cout << i << " ";
        }

        cout << endl;

        vector<vector<int>> listOfDifferences;
        int currentSequence = 0;
        int finalCommonDifference = 0;

        while (true)
        {
            vector<int> differences;

            if (currentSequence == 0)
            {
                getDifferences(sequence, differences);
            }
            else
            {
                getDifferences(listOfDifferences[currentSequence - 1], differences);
            }

            cout << " List of differences for sequence/depth of " << currentSequence + 1 << endl;

            for (int difference : differences)
            {
                cout << difference << " ";
            }

            // If no differences, this means we couldn't subtract
            // anything
            if (differences.size() == 0)
            {
                break;
            }

            cout << endl;

            cout << "Differences Length: " << differences.size() << endl;

            if (isVectorElementsAllEqual(differences) && differences.size() >= 2)
            {
                finalCommonDifference = differences.at(0);

                break;
            }

            listOfDifferences.push_back(differences);
            currentSequence += 1;
        }

        if (finalCommonDifference == 0)
        {
            cout << "There is no convergence." << endl;

            return EXIT_SUCCESS;
        }

        cout << "Final common difference: " << finalCommonDifference << endl;

        int sum;

        for (vector<int> differences : listOfDifferences)
        {
            sum += differences.at(differences.size() - 1);
        }

        sum += finalCommonDifference;
        sum += sequence.at(sequence.size() - 1);

        cout << "The next value is: " << sum << endl;
    }
    catch (const runtime_error &err)
    {
        cout << err.what();
    }

    return EXIT_SUCCESS;
}
