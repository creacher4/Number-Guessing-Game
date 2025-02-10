#include <iostream>
#include <random>

int chooseDifficulty()
{
    int difficulty;
    while (true)
    {
        std::cout << "1. Easy (10 chances)\n";
        std::cout << "2. Medium (5 chances)\n";
        std::cout << "3. Hard (3 chances)\n";
        std::cout << "4. Impossible (1 chance)\n";
        std::cout << "Please enter the number corresponding to your choice: ";

        std::cin >> difficulty;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input. Please enter a number.\n\n";
            continue;
        }

        switch (difficulty)
        {
        case 1:
            std::cout << "You chose Easy. Congrats! You've chosen the 'participation trophy' mode.\n\n";
            return 10;
        case 2:
            std::cout << "You chose Medium. I respect the cautious optimism.\n\n";
            return 5;
        case 3:
            std::cout << "You chose Hard. Let's see how long that confidence lasts.\n\n";
            return 3;
        case 4:
            std::cout << "You chose Impossible. You must love pain.\n\n";
            return 1;
        default:
            std::cout << "Invalid choice. Please try again.\n\n";
        }
    }
}

void playGame(int secretNumber, int attempts)
{
    int guess;

    while (attempts > 0)
    {
        std::cout << "Guess a number between 1 and 100: ";
        std::cin >> guess;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input. Please enter a number.\n\n";
            continue;
        }

        if (guess < 1 || guess > 100)
        {
            std::cout << "Out of bounds! Pick a number between 1 and 100.\n\n";
            continue;
        }

        if (guess == secretNumber)
        {
            std::cout << "You guessed the number! Congratulations!\n\n";
            return;
        }
        else if (guess > secretNumber)
        {
            std::cout << "Too high. Try again.\n\n";
        }
        else
        {
            std::cout << "Too low. Try again.\n\n";
        }

        attempts--;
        if (attempts > 0)
        {
            std::cout << "You have " << attempts << " attempt(s) remaining.\n\n";
        }
    }

    std::cout << "You've run out of attempts. The correct number was " << secretNumber << ".\n\n";
}

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distr(1, 100);

    bool playAgain = true;
    while (playAgain)
    {
        std::cout << "Welcome to the Number Guessing Game!\n";
        std::cout << "I'm thinking of a number between 1 and 100.\n\n";

        int attempts = chooseDifficulty();
        int secretNumber = distr(gen);

        playGame(secretNumber, attempts);

        char choice;
        while (true)
        {
            std::cout << "Do you want to play again? (y/n): ";
            std::cin >> choice;

            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Invalid input. Please enter 'y' or 'n'.\n";
                continue;
            }

            if (choice == 'y' || choice == 'Y')
            {
                std::cout << "Restarting the game...\n\n";
                break;
            }
            else if (choice == 'n' || choice == 'N')
            {
                std::cout << "Thanks for playing! Goodbye!\n";
                playAgain = false;
                break;
            }
            else
            {
                std::cout << "Invalid input. Please enter 'y' for yes or 'n' for no.\n";
            }
        }
    }
    return 0;
}
