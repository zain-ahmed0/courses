﻿/*
try
{
    Process1();
}
catch
{
    Console.WriteLine("An exception has occurred");
}

Console.WriteLine("Exit program");

static void Process1()
{
    try
    {
        WriteMessage();
    }
    catch (DivideByZeroException ex)
    {
        Console.WriteLine($"Exception caught in Process1: {ex.Message}");
    }
}

static void WriteMessage()
{
    double float1 = 3000.0;
    double float2 = 0.0;
    int number1 = 3000;
    int number2 = 0;
    byte smallNumber;

    try
    {
        Console.WriteLine(float1 / float2);
        Console.WriteLine(number1 / number2);
    }
    catch (DivideByZeroException ex)
    {
        Console.WriteLine($"Exception caught in WriteMessage: {ex.Message}");
    }

    checked
    {
        try
        {
            smallNumber = (byte)number1;
        }
        catch (OverflowException ex)
        {
            Console.WriteLine($"Exception caught in WriteMessage: {ex.Message}");
        }
    }
}
*/

// inputValues is used to store numeric values entered by a user
string[] inputValues = new string[]{"three", "9999999999", "0", "2" };

foreach (string inputValue in inputValues)
{
    int numValue = 0;
    try
    {
        numValue = int.Parse(inputValue);
    }
    catch (FormatException)
    {
        Console.WriteLine("Invalid readResult. Please enter a valid number.");
    }
    catch (OverflowException)
    {
        Console.WriteLine("The number you entered is too large or too small.");
    }
    catch(Exception ex)
    {
        Console.WriteLine(ex.Message);
    }
}

