/* Sicheng Zeng
 * 12/21/2016
 * busybeaver.h
 */

#ifndef BUSYBEAVER_H
#define BUSYBEAVER_H

#include <random>
#include "turingmachine.h"

class BusyBeaver
{
public:
    TuringMachine tm;

    BusyBeaver(int numStates, int targetMin, int targetMax);
    ~BusyBeaver();

    std::string solveBeaver();

    void setRandomInstructions();
    bool testSolution();

    std::string toStringPossibleInstructions();

private:
    std::vector<TuringMachineInstruction> generatePossibleInstructions();

    int numStates;
    int targetMin;
    int targetMax;

    std::vector<TuringMachineInstruction> possibleInstructions;
    int attempts;
};

#endif // BUSYBEAVER_H
