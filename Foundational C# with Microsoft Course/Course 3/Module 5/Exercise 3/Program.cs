int heroHealth = 10;
int monsterHealth = 10;
Random attack = new Random();

while (monsterHealth > 0 && heroHealth > 0)
{
    
    int damage = attack.Next(1, 11);
    Console.WriteLine($"Monster was damaged and lost {damage} health and now has {monsterHealth - damage} health.");
    monsterHealth -= damage;
    
    if (monsterHealth > 0)
    {
        damage = attack.Next(1, 11);
        Console.WriteLine($"Hero was damaged and lost {damage} health and now has {heroHealth - damage} health.");
        heroHealth -= damage;
    }
}

string winner = heroHealth > monsterHealth ? "Hero wins!" : "Monster wins!";
Console.WriteLine(winner);

