string wordInput = "zain";
string sentenceInput = "there are snakes at the zoo";

Console.WriteLine(wordInput);
Console.WriteLine(ReverseWord(wordInput));
Console.WriteLine("");
Console.WriteLine(sentenceInput);
Console.WriteLine(ReverseSentence(sentenceInput));

string ReverseWord(string word) 
{
    string result = "";
    for (int i = word.Length - 1; i >= 0; i--) 
    {
        result += word[i];
    }
    return result;
}

string ReverseSentence(string sentence) 
{
    string result = "";
    string[] words = sentence.Split(" ");

    foreach(string word in words) 
    {
        result += ReverseWord(word) + " ";
    }

    return result.Trim();
}
