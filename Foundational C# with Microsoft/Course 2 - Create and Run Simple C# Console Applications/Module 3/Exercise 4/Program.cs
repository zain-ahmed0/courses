Random random = new Random();

int daysUntilExpiration = random.Next(1, 7);
int discountPercentage = 0;

if (daysUntilExpiration == 1)
{
    discountPercentage = 20;
    Console.WriteLine($"Your subscription expires within a day!\nRenew now and save {discountPercentage}%!");
}
else if (daysUntilExpiration <= 5)
{
    discountPercentage = 10;
    Console.WriteLine($"Your subscription expires in {daysUntilExpiration} days. \nRenew now and save {discountPercentage}%!");
}
else if (daysUntilExpiration <= 10)
{
    Console.WriteLine($"Your subscription expires in {daysUntilExpiration} days. Renew now!");
}
else
{
    Console.WriteLine("Your subscription has expired.");
}