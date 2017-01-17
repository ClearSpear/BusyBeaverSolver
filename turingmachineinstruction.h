/* Sicheng Zeng
 * 12/21/2016
 * turingmachineinstruction.h
 */

#ifndef TURINGMACHINEINSTRUCTION_H
#define TURINGMACHINEINSTRUCTION_H

#include <iostream>
#include <string>

struct TuringMachineInstruction
{
public:
    int state;
    char direction;
    int next;

    /*
     * Constructor to initialize a new turing machine instruction with
     * the write state, the direction to go, and the next instruction location.
     * If no values are given, writes the instruction to end the turing machine run
     */
    TuringMachineInstruction(int state = 0, char direction = 'L', int next = 0);

    /*
     * Overloading toString
     */
    std::string toString();
};

/*
 * Overloaded operator to print an instruction to an output stream
 */
std::ostream& operator <<(std::ostream& out, const TuringMachineInstruction& instruction);

#endif // TURINGMACHINEINSTRUCTION_H
