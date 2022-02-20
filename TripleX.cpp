#include <iostream>
#include <ctime>

#ifndef _DEBUG
#define _DEBUG 0
#endif
#define _NDEBUG !_DEBUG
#define DEBUG 1

void PrintAsciiArt()
{
    std::cout << "         _._._                       _._._\n";
    std::cout << "        _|   |_                     _|   |_\n";
    std::cout << "        | ... |_._._._._._._._._._._| ... |\n";
    std::cout << "        | ||| |  o               o  | ||| |\n";
    std::cout << "        | \"\"\" |  \"\"\"    \"\"\"    \"\"\"  | \"\"\" |\n";
    std::cout << "   ())  |[-|-]| [-|-]  [-|-]  [-|-] |[-|-]|  ())\n";
    std::cout << "  (())) |     |---------------------|     | (()))\n";
    std::cout << " (())())| \"\"\" |  \"\"\"    \"\"\"    \"\"\"  | \"\"\" |(())())\n";
    std::cout << " (()))()|[-|-]|  :::   .-\"-.   :::  |[-|-]|(()))()\n";
    std::cout << " ()))(()|     | |~|~|  |_|_|  |~|~| |     |()))(()\n";
    std::cout << "    ||  |_____|_|_|_|__|_|_|__|_|_|_|_____|  ||\n";
    std::cout << " ~ ~^^ @@@@@@@@@@@@@@/=======\\@@@@@@@@@@@@@@ ^^~ ~\n";
    std::cout << "      ^~^~                                ~^~^\n";
}

void PrintWinAscii()
{
    std::cout << "                              \\\\\\\\\\\\\\\n";
    std::cout << "                            \\\\\\\\\\\\\\\\\\\\\\\\\n";
    std::cout << "                          \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
    std::cout << "  -----------,-|           |C>   // )\\\\\\\\|\n";
    std::cout << "           ,','|          /    || ,'/////|\n";
    std::cout << "---------,','  |         (,    ||   /////\n";
    std::cout << "         ||    |          \\\\  ||||//''''|\n";
    std::cout << "         ||    |           |||||||     _|\n";
    std::cout << "         ||    |______      `````\\____/ \\\n";
    std::cout << "         ||    |     ,|         _/_____/ \\\n";
    std::cout << "         ||  ,'    ,' |        /          |\n";
    std::cout << "         ||,'    ,'   |       |         \\  |\n";
    std::cout << "_________|/    ,'     |      /           | |\n";
    std::cout << "_____________,'      ,',_____|      |    | |\n";
    std::cout << "             |     ,','      |      |    | |\n";
    std::cout << "             |   ,','    ____|_____/    /  |\n";
    std::cout << "             | ,','  __/ |             /   |\n";
    std::cout << "_____________|','   ///_/-------------/   |\n";
    std::cout << "              |===========,'\n";
}

void PrintLoseAscii()
{
    std::cout << "               ...\n";
    std::cout << "             ;::::;\n";
    std::cout << "           ;::::; :;\n";
    std::cout << "         ;:::::'   :;\n";
    std::cout << "        ;:::::;     ;.\n";
    std::cout << "       ,:::::'       ;           OOO\\\n";
    std::cout << "       ::::::;       ;          OOOOO\\\n";
    std::cout << "       ;:::::;       ;         OOOOOOOO\n";
    std::cout << "      ,;::::::;     ;'         / OOOOOOO\n";
    std::cout << "    ;:::::::::`. ,,,;.        /  / DOOOOOO\n";
    std::cout << "  .';:::::::::::::::::;,     /  /     DOOOO\n";
    std::cout << " ,::::::;::::::;;;;::::;,   /  /        DOOO\n";
    std::cout << ";`::::::`'::::::;;;::::: ,#/  /          DOOO\n";
    std::cout << ":`:::::::`;::::::;;::: ;::#  /            DOOO\n";
    std::cout << "::`:::::::`;:::::::: ;::::# /              DOO\n";
    std::cout << "`:`:::::::`;:::::: ;::::::#/               DOO\n";
    std::cout << " :::`:::::::`;; ;:::::::::##                OO\n";
    std::cout << " ::::`:::::::`;::::::::;:::#                OO\n";
    std::cout << " `:::::`::::::::::::;'`:;::#                O\n";
    std::cout << "  `:::::`::::::::;' /  / `:#\n";
    std::cout << "   ::::::`:::::;'  /  /   `#\n";
}

void PrintIntroduction(int LevelDifficulty)
{
    // Introduction messages to the terminal so the user understands what's going on
    std::cout << "You are a corporate spy trying to break into a LEVEL " << LevelDifficulty << " secure server room.\n";
    std::cout << "You need to enter the correct sequence of codes to get past the vault door.\n\n";
}

void SeedRNG(unsigned RandomSeed = 0)
{
    if (!DEBUG)
        RandomSeed = (unsigned)time(NULL);

    if (DEBUG)
        std::cout << "### DEBUG: Random Seed: " << RandomSeed << "\n";

    // Seed the RNG with above defined seed
    srand(RandomSeed);
}

/**
    \brief Generate Random Digit
    \param Digit (required) Base Digit, also assigned to additional value.
    \param AdditionalValue (required) Additional value added to the final random range.
    \param Multiplier (optional) Multiplier, defaults to 1. A value of zero is invalid.
    \return Random digit from (Base Digit x Multiplier) to (Base Digit x Multiplier) + Additional Value.
**/
const unsigned GenerateCodeDigit(unsigned Digit, unsigned AdditionalValue, unsigned Multiplier = 1)
{
    return unsigned (rand()%(Digit*(Multiplier?Multiplier:1)))+AdditionalValue;
}

bool PlayGame(int LevelDifficulty)
{
    SeedRNG();
    // Generate the 3 digits used for the input code
    const int CodeA = GenerateCodeDigit(LevelDifficulty, LevelDifficulty);
    const int CodeB = GenerateCodeDigit(LevelDifficulty, LevelDifficulty);
    const int CodeC = GenerateCodeDigit(LevelDifficulty, LevelDifficulty);

    // Calculate sum and product
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    if (DEBUG) std::cout << "### DEBUG: Valid Code: " << CodeA << " " << CodeB << " " << CodeC << ".\n";

    // Call the intruduction function
    PrintIntroduction(LevelDifficulty);

    // Print sum and product to the terminal
    std::cout << "+ There are 3 numbers in the code\n";
    std::cout << "+ The codes add up to: " << CodeSum << "\n";
    std::cout << "+ The codes multiply to give: " << CodeProduct << "\n";

    // Initialize Player's Guess variable
    int GuessA, GuessB, GuessC;

    // Ask the player to guess the code and store in GuessA, GuessB, GuessC for the 3 digit values
    std::cout << "Enter the code (# # #): ";
    std::cin >> GuessA >> GuessB >> GuessC;

    // Calculate guess sum and product
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check to see if the players guess is correct
    if (CodeSum == GuessSum && CodeProduct == GuessProduct)
    {
        std::cout << "You made it through LEVEL " << LevelDifficulty << "\n\n";
        return true;
    }
    
    else
    {
        std::cout << "You failed to break through the door and were caught. YOU DIED!\n\n";
        return false;
    }
}

int main()
{
    bool bLevelComplete = true;
    int LevelDifficulty = 1;
    const int MaxLevels = 25;

    // Lets play!!
    PrintAsciiArt();

    // Start Game
    while (bLevelComplete && LevelDifficulty <= MaxLevels)
    {
        if (DEBUG) std::cout << "### DEBUG: Level " << LevelDifficulty << " of " << MaxLevels << ".\n";

        bLevelComplete = PlayGame(LevelDifficulty);

        // Fix issues with cin
        std::cin.clear(); // clears any errors
        std::cin.ignore(); // discards the buffer

        if (bLevelComplete && LevelDifficulty <= MaxLevels)
        {
            // Increase the level difficulty
            ++LevelDifficulty;
        }
    }

    if (LevelDifficulty == (MaxLevels+1))
    {
        // You won the game
        PrintWinAscii();
        std::cout << "You actually won this dumb game? Congratulations!\n";
    }
    else
    {
        // You lost the game
        PrintLoseAscii();
        std::cout << "As I thought, you died just like me.\n";
    }
    
    // End the game
    return 0;
}
