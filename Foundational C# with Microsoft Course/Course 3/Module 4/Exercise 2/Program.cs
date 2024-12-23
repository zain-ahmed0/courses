string[] names = ["Alex", "Eddie", "David", "Michael"];

for (int i = 0; i < names.Length; i++)
{
    if (names[i] == "David")
    {
        names[i] = "Sammy";
    }
}

foreach (string name in names)
{
    Console.WriteLine(name);
}



