/*
string name = "Bob";
Console.WriteLine(int.Parse(name));
*/

string value = "bad";
int result = 0;
if (int.TryParse(value, out result))
{
    Console.WriteLine($"Measurement: {result}");
}
else
{
    Console.WriteLine("Unable to report the measurement.");
}

if (result > 0)
{
    Console.WriteLine($"Measurement (W/offset): {50 + result}");   
}