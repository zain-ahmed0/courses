/*
string? readResult;
bool validNumber;

Console.WriteLine("Enter a number between 5 and 10: ");

do
{
    readResult = Console.ReadLine();
    int number = 0;
    validNumber = int.TryParse(readResult, out number);

    if (validNumber == false)
    {
        Console.WriteLine("Sorry, you entered an invalid number, please try again");
    }
    
    if (number >= 5 && number <= 10)
    {
        Console.WriteLine($"Your input value ({number}) has been accepted.");
    }
    else
    {
        Console.WriteLine($"You entered {number}. Please enter a number between 5 and 10.");
    }

} while (!validNumber);
*/

/*
string? readResult;
bool validEntry = false;
Console.WriteLine("Enter your role name (Administrator, Manager, or User)");

do
{
    readResult = Console.ReadLine();
    string newString = readResult.Trim().ToLower();

    if (newString == "administrator" || newString == "manager" || newString == "user")
    {
        validEntry = true;
        Console.WriteLine("Accepted");
    }
    else
    {
        validEntry = false;
        Console.WriteLine("Incorrect input");
    }

} while (validEntry == false);
*/

string[] myStrings = ["I like pizza. I like roast chicken. I like salad", "I like all three of the menu choices"];
int stringsCount = myStrings.Length;

string myString = "";
int periodLocation = 0;

for (int i = 0; i < stringsCount; i++)
{
    myString = myStrings[i];
    periodLocation = myString.IndexOf(".");

    string mySentence;
    
    while (periodLocation != -1)
    {
        mySentence = myString.Remove(periodLocation);

        myString = myString.Substring(periodLocation + 1);

        myString = myString.TrimStart();

        periodLocation = myString.IndexOf(".");

        Console.WriteLine(mySentence);
    }
    
    mySentence = myString.Trim();
    Console.WriteLine(mySentence);
}
