/* Sicheng Zeng
 * 12/21/2016
 * busybeaver.cpp
 */

#include "busybeaver.h"

BusyBeaver::BusyBeaver(int numStates, int targetMin, int targetMax)
{
    this->numStates = numStates;
    this->targetMin = targetMin;
    this->targetMax = targetMax;

    possibleInstructions = generatePossibleInstructions();

    tm = TuringMachine(50, numStates);
}

std::vector<TuringMachineInstruction> BusyBeaver::generatePossibleInstructions()
{
    std::vector<TuringMachineInstruction> possibleInstructions;
    for( int i = 0; i < 2; i++ )
    {
        for( int j = 0; j < 2; j++ )
        {
            for( int k = 0; k <= numStates; k++ )
            {
                char direction;
                if( j == 0 )
                {
                    direction = 'L';
                }
                else
                {
                    direction = 'R';
                }
                TuringMachineInstruction tmi(i, direction, k);
                possibleInstructions.push_back(tmi);
            }
        }
    }
    return possibleInstructions;
}

BusyBeaver::~BusyBeaver(){}

std::string BusyBeaver::solveBeaver()
{
    do
    {
        tm.reset();
        setRandomInstructions();
    }
    while( !testSolution() );

    return tm.toStringInstructions() + "\nOnes: " + std::to_string(tm.getOnes()) + "\n " + tm.toStringPaper();
}

std::string BusyBeaver::toStringPossibleInstructions()
{
    std::string output;
    for( TuringMachineInstruction tmi : possibleInstructions )
    {
        output += tmi.toString() + " ";
    }
    return output;
}

void BusyBeaver::setRandomInstructions()
{
    for( int i = 0; i < numStates*2; i++ )
    {
        int randomIndex = rand()%possibleInstructions.size();

        int row = i / 2;
        int col = i % 2;
        tm.instructions[row][col] = possibleInstructions[randomIndex];
    }
}

bool BusyBeaver::testSolution()
{
    int counter = 0;
    bool timeout = false;
    while( (tm.getState() != 0) && !(tm.getIndex() < 0) && !(tm.getIndex() > tm.paper.size()) )
	{
        tm.iterate();
        counter++;
        if( counter > 200 )
        {
            timeout = true;
            break;
        }
    }

    int ones = tm.getOnes();
    if( ones >= targetMin && ones <= targetMax && !timeout)
	{
		return true; 
	}
	return false; 
}
