﻿Random random = new Random();

Console.WriteLine("Would you like to play? (Y/N)");

if (ShouldPlay()) 
{
    PlayGame();
}

bool ShouldPlay()
{
    string userInput = Console.ReadLine();
    return userInput == "Y";
}

void PlayGame() 
{
    var play = true;

    while (play) 
    {
        int target;
        int roll;

        target = random.Next(1, 7);
        roll = random.Next(1, 7);

        Console.WriteLine($"Roll a number greater than {target} to win!");
        Console.WriteLine($"You rolled a {roll}");
        Console.WriteLine(WinOrLose(target, roll));
        Console.WriteLine("\nPlay again? (Y/N)");
        
        play = ShouldPlay();
    }
}

string WinOrLose(int target, int roll)
{
    string result = target > roll ? "You win!" : "You lose!";
    return result;
}