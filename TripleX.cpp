#include <iostream>
#include<ctime>

void GameIntro(int Difficulty)
{
    std::cout << "\n\nYou are an anthopologist and you have found a temple deep inside the\n";
    std::cout <<"jungles of Amazon which belonged to an ancient technologically advanced civilization\n";
    std::cout <<"You have to get inside the heart of the temple to discover its secrets. You are standing\n";
    std::cout << "in front of the main gate which requires a code to unlock. There are characters which\n";
    std::cout << "correspond to numbers and you have to enter the numbers corresponding to certain\n";
    std::cout << "math conditions. There are a total of 5 gates and if you answer incorrectly, deadly\n";
    std::cout << "spikes will emerge from the surrounding and kill you instantly...\n\n";
    std::cout << "You are in front of gate: " << Difficulty <<"\n\n";
    
}

bool PlayGame(int Difficulty)
{
   GameIntro(Difficulty);

    // Declare 3 number code
    const int CodeA = rand()%Difficulty + Difficulty;
    const int CodeB = rand()%Difficulty + Difficulty;
    const int CodeC = rand()%Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;

    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print Sum and product to the terminal
    std::cout << std::endl;
    std::cout << "+ There are 3 numbers in the code\n";
    std::cout << "+ The codes add-up to: " << CodeSum <<"\n";
    std::cout << "+ The numbers multiply to give: " << CodeProduct << "\n";

    int GuessA, GuessB, GuessC;
    

    std::cin >> GuessA >> GuessB >> GuessC;
    
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n*** Well done! You have opened this gate! Move onto to next door! ***";
        return true;
    }
    else
    {
        std::cout << "\n*** You answered incorrectly! Deadly Spikes kill you!! Try again! ***";
        return false;
    }
}



int main()
{
    srand(time(NULL)); // create new random sequence based on time of day

    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    while(LevelDifficulty <= MaxDifficulty)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //clears any errors
        std::cin.ignore(); //Discards the buffers
    
        if (bLevelComplete)
        {
            // increase difficulty level
            ++LevelDifficulty;
        }
        else
        {
            LevelDifficulty = 1;
        }
        
    }   
    std::cout << "\n\n*** You are in the heart of the temple which will reveal its secrets! ***\n";
    /*
    std::cout << "\n\nPress ENTER to exit...";
    std::cin.ignore();
    */

    return 0;
}
