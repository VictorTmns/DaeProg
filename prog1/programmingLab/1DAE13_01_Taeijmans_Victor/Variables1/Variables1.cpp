// Variables1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Taeijmans, Victor - 1DAE13

#include "pch.h"
#include <iostream>

int main()
{
    //std::cout << "Wich score do you think you will end up with?";
    //int scoreOutOf20{};
    //std::cin >> scoreOutOf20;
    //std::cout << "Score assumed: " << scoreOutOf20 <<" / 20.\n";

    //int numberOfTrees;
    //std::cout << numberOfTrees;
    //char nameTree;
    //std::cout << nameTree;
    //bool isTreeReal;
    //std::cout << isTreeReal;
    //float heightOfTree;
    //std::cout << heightOfTree;
    //double liquidPercentageTree;
    //std::cout << liquidPercentageTree;

    
    //int numberOfTrees{};
    //std::cout << "(" << numberOfTrees << ") \n";
    //char nameTree{};
    //std::cout << "(" << nameTree << ") \n";
    //bool isTreeReal{};
    //std::cout << "(" << isTreeReal << ") \n";
    //float heightOfTree{};
    //std::cout << "(" << heightOfTree << ") \n";
    //double liquidPercentageTree{};
    //std::cout << "(" << liquidPercentageTree << ") \n";


    int numberOfTrees{70};
    char firstLetterTree{'o'};
    bool isTreeReal{true};
    float heightOfTree{4.94f};
    double liquidPercentageTree{87.7675867};

    std::cout << "(" << numberOfTrees << ") \n";
    std::cout << "(" << firstLetterTree << ") \n";
    std::cout << "(" << isTreeReal << ") \n";
    std::cout << "(" << heightOfTree << ") \n";
    std::cout << "(" << liquidPercentageTree << ") \n";

    numberOfTrees = 12;
    firstLetterTree = 't';
    isTreeReal = false;
    heightOfTree = 5.0878f;
    liquidPercentageTree = 9378.878;

    std::cout << "(" << numberOfTrees << ") \n";
    std::cout << "(" << firstLetterTree << ") \n";
    std::cout << "(" << isTreeReal << ") \n";
    std::cout << "(" << heightOfTree << ") \n";
    std::cout << "(" << liquidPercentageTree << ") \n";

    std::cout << "How many trees do you think are in the forest? \n";
    std::cin >> numberOfTrees;
    std::cout << "So you think that there are " << numberOfTrees << " trees in this forest \n";

    std::cout << "What do you think the first letter of tree is? \n";
    std::cin >> firstLetterTree;
    std::cout << "So you think that the first letter is a " << firstLetterTree << ".\n";

    std::cout << "Is this tree real a true statement or a false statement? \n";
    std::cin >> isTreeReal;
    std::cout << "your answer to the statement the tree is real is " << isTreeReal << "\n";

    std::cout << "How high do you think this tree is in meters? \n";
    std::cin >> heightOfTree;
    std::cout << "Hmm, this tree could be " << heightOfTree << " meters high or maybe even higher. \n";

    std::cout << "How many percent of this tree is liquid? \n";
    std::cin >> liquidPercentageTree;
    std::cout << "You guessed that the tree is " << liquidPercentageTree << "% liquid \n";

}

