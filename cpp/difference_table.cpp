#include "./difference_table.h"
#include "./utils.h"

DifferenceTable::DifferenceTable(std::vector<int> sequence)
    : sequence(sequence), isConvergent(true), verbose(false){};

int DifferenceTable::GetCommonDifference()
{
    if (!finalCommonDifference && isConvergent)
    {
        CalculateCommonDifference();
    }

    if (!isConvergent)
    {
        throw std::runtime_error("Sequence isn't convergent.");
    }

    return finalCommonDifference;
}

int DifferenceTable::GetNextValueInSequence()
{
    if (!nextValueInSequence)
    {
        CalculateNextValueInSequence();
    }

    if (!isConvergent)
    {
        throw std::runtime_error("Sequence isn't convergent.");
    }

    int tmp = nextValueInSequence;

    nextValueInSequence = 0;

    return tmp;
}

void DifferenceTable::CalculateCommonDifference()
{
    while (isConvergent && !finalCommonDifference)
    {
        CalculateDifferencesForCurrentRow();
    }
}

void DifferenceTable::CalculateDifferencesForCurrentRow()
{
    std::vector<int> differences;

    if (currentRowSequence == 0)
    {
        differences = CalculateDifferencesOfVecInt(sequence);
    }
    else
    {
        differences = CalculateDifferencesOfVecInt(
            listOfDifferences.at(currentRowSequence - 1));
    }

    if (differences.size() < 2)
    {
        isConvergent = false;

        return;
    }

    if (elementsInVectorAreEqual(differences))
    {
        finalCommonDifference = differences.at(0);

        return;
    }

    listOfDifferences.push_back(differences);
    currentRowSequence += 1;
}

void DifferenceTable::CalculateNextValueInSequence()
{
    int commonDifference = GetCommonDifference();
    int sum = commonDifference + sequence.at(sequence.size() - 1);

    for (std::vector<int> differences : listOfDifferences)
    {
        sum += differences.at(differences.size() - 1);
    }

    sequence.push_back(sum);

    // We do this to update `listOfDifferences` to be able to
    // get the next value. This will act as some sort of cache.
    if (listOfDifferences.size() > 0)
    {
        for (int i = 0; i < listOfDifferences.size(); ++i)
        {
            std::vector<int> *seq1;
            std::vector<int> *seq2;

            if (i == 0)
            {
                seq1 = &sequence;
                seq2 = &(listOfDifferences.at(i));
            }
            else
            {
                seq1 = &(listOfDifferences.at(i - 1));
                seq2 = &(listOfDifferences.at(i));
            }

            int diff = seq1->at(seq1->size() - 1) - seq1->at(seq1->size() - 2);

            seq2->push_back(diff);
        }
    }

    if (verbose)
    {
        std::cout << "Differences for depth: 0" << std::endl << "\t";

        for (int &num : sequence)
        {
            std::cout << num << " ";
        }

        std::cout << std::endl;

        for (int i = 0; i < listOfDifferences.size(); ++i)
        {
            std::cout << "Differences for depth: " << i + 1 << std::endl
                      << "\t";

            for (int &num : listOfDifferences.at(i))
            {
                std::cout << num << " ";
            }

            std::cout << std::endl;
        }
    }

    nextValueInSequence = sum;
}

std::vector<int>
DifferenceTable::CalculateDifferencesOfVecInt(std::vector<int> &vecInt)
{
    std::vector<int> differences;

    if (vecInt.size() < 3)
    {
        return differences;
    }

    for (int i = 0; i < vecInt.size() - 1; ++i)
    {
        bool IS_END = i == vecInt.size() - 1;

        if (IS_END)
        {
            differences.push_back(vecInt.at(i) - vecInt.at(i - 1));
        }
        else
        {
            differences.push_back(vecInt.at(i + 1) - vecInt.at(i));
        }
    }

    return differences;
}
