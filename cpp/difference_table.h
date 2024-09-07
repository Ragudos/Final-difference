#ifndef DIFFERENCE_TABLE

#define DIFFERENCE_TABLE

#include <iostream>
#include <vector>

class DifferenceTable
{
  public:
    DifferenceTable(std::vector<int> sequence);
    int GetCommonDifference();

  protected:
    std::vector<int> sequence;
    std::vector<std::vector<int>> listOfDifferences;
    /// 0 for being the surface-level or `sequence`
    /// and 1 is the starting point for `listOfDifferences`
    int currentRowSequence;
    int finalCommonDifference;

    void CalculateDifferencesForCurrentRow();
};

#endif
