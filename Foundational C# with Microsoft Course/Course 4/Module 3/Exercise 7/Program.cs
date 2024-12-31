string orderStream = "B123,C234,A345,C15,B177,G3003,C235,B179";

string[] orders = orderStream.Split(',');
Array.Sort(orders);

for (int i = 0; i < orders.Length; i++)
{
    if (orders[i].Length == 4)
    {
        Console.WriteLine(orders[i]);
    }
    else
    {
        Console.WriteLine($"{orders[i]} \t- Error");
    }

}




