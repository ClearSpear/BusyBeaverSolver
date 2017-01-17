/* Sicheng Zeng
 * 12/21/2016
 * turingmachine.h
 */

#ifndef TURINGMACHINE_H
#define TURINGMACHINE_H

#include <vector>
#include "turingmachineinstruction.h"

class TuringMachine
{
public:
    // Public members
    std::vector<int> paper;
    std::vector<std::vector<TuringMachineInstruction>> instructions;

    // Constructor and destsructor
    TuringMachine(int paperLength = 1000, int instructionsLength = 10);
    ~TuringMachine();

    // Public member functions
    int getState();
    int getIndex();
    int getOnes();

    std::string toStringPaper();
    std::string toStringInstructions();

    void writeInstructions(const std::vector<std::vector<TuringMachineInstruction>>* newInstructions);
    void reset();
    void iterate();

private:
    // Private members
    int state; // of instruction
    int index; // placement on paper 
    int ones; // running total of ones written to the paper
};

#endif // TURINGMACHINE_H
