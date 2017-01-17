/* Sicheng Zeng
 * 12/21/2016
 * turingmachine.cpp
 */

#include "turingmachine.h"

TuringMachine::TuringMachine(int paperLength, int instructionsLength)
{
    state = 1;
    index = paperLength/2;
    ones = 0;

    paper = std::vector<int>(paperLength, 0);
    instructions = std::vector<std::vector<TuringMachineInstruction>>(instructionsLength, std::vector<TuringMachineInstruction>(2, TuringMachineInstruction()));
}

TuringMachine::~TuringMachine()
{
}

int TuringMachine::getState()
{
    return state;
}

int TuringMachine::getIndex()
{
    return index;
}

int TuringMachine::getOnes()
{
    return ones;
}

std::string TuringMachine::toStringPaper()
{
    std::string output = "Paper: ";
    std::vector<int>::iterator it;
    for( int i : paper )
    {
        output += std::to_string(i);
    }
    return output;
}

std::string TuringMachine::toStringInstructions()
{
    std::string output = "Instructions: \n";
    for( unsigned int i = 0; i < instructions.size(); i++ )
    {
        for( unsigned int j = 0; j < instructions.front().size(); j++ )
        {
            output += instructions[i][j].toString() + " ";
        }
        output += "\n";
    }
    return output;
}

void TuringMachine::writeInstructions(const std::vector<std::vector<TuringMachineInstruction>>* newInstructions)
{
    instructions = *newInstructions;
}

void TuringMachine::reset()
{
    state = 1;
    index = paper.size()/2;
    ones = 0;
    std::fill(paper.begin(), paper.end(), 0);
}

void TuringMachine::iterate()
{
    if( state == 0 || index >= paper.size() || index <= 0 )
    {
        return;
    }

    TuringMachineInstruction direction = instructions[state-1][paper[index]];
    int newWrite = direction.state;
    char newDirection = direction.direction;
    int newState = (int) direction.next;

    if( paper[index] == 0 && newWrite == 1 )
    {
        ones++;
    }
    else if( paper[index] == 1 && newWrite == 0 )
    {
        ones--;
    }
    paper[index] = newWrite;

    if( newDirection == 'L' )
    {
        index--;
    }
    else
    {
        index++;
    }

    state = newState;
}
