const string input = "<div><h2>Widgets &trade;</h2><span>5000</span></div>";

string quantity = "";
string output = "";

// Extract the "quantity"
int quantityFirstPosition = input.IndexOf("<span>");
int quantityLastPosition = input.IndexOf("</span>");

quantityFirstPosition += 6;

int quantityLength = quantityLastPosition - quantityFirstPosition;
quantity = input.Substring(quantityFirstPosition, quantityLength);

// Extract the "output"
int outputFirstPosition = input.IndexOf("<div>");
int outputLastPosition = input.IndexOf("</div>");

outputFirstPosition += 5;

int outputLength = outputLastPosition - outputFirstPosition;
output = input.Substring(outputFirstPosition, outputLength);

output = output.Replace("&trade", "&reg");

Console.WriteLine(quantity);
Console.WriteLine(output);

// Model Answer
/*
// Extract the "quantity"
const string openSpan = "<span>";
const string closeSpan = "</span>";
   
int quantityStart = input.IndexOf(openSpan) + openSpan.Length; // + length of <span> so index at end of <span> tag
int quantityEnd= input.IndexOf(closeSpan);
int quantityLength = quantityEnd - quantityStart;
quantity = input.Substring(quantityStart, quantityLength);
quantity = $"Quantity: {quantity}";
   
// Set output to input, replacing the trademark symbol with the registered trademark symbol
const string tradeSymbol = "&trade;";
const string regSymbol = "&reg;";
output = input.Replace(tradeSymbol, regSymbol);
   
// Remove the opening <div> tag
const string openDiv = "<div>";
int divStart = output.IndexOf(openDiv);
output = output.Remove(divStart, openDiv.Length);
   
// Remove the closing </div> tag and add "Output:" to the beginning
const string closeDiv = "</div>";
int divCloseStart = output.IndexOf(closeDiv);
output = "Output: " + output.Remove(divCloseStart, closeDiv.Length);
*/