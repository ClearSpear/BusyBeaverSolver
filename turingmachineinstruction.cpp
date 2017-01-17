/* Sicheng Zeng
 * 12/21/2016
 * turingmachineinstruction.cpp
 */

#include "turingmachineinstruction.h"

TuringMachineInstruction::TuringMachineInstruction(int state, char direction, int next)
{
    this->state = state;
    this->direction = direction;
    this->next = next;
}

std::string TuringMachineInstruction::toString()
{
    return std::to_string(this->state) + this->direction + std::to_string(this->next);
}

std::ostream& operator <<(std::ostream& out, const TuringMachineInstruction& instruction)
{
    return out << instruction.state << instruction.direction << instruction.next;
}
