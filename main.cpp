#include <iostream>
#include <string>
#include <vector>


void boxPrint(std::vector<std::string> text, char sign = '*')
{
    int width = 0;
    int height = text.size();

    for(int i = 0; i < text.size(); i++)
    {
        if(text[i].length() > width)
            width = text[i].length();
    }

    width += 2;
    
    std::string line = "";
    for(int i = 0; i < width; i++)
        line += sign;

    std::string spaces = "";
    
    std::cout << line << std::endl;
    for(int i = 0; i < height; i++)
    {
        spaces.append((width -2 -text[i].length()), ' ');

        std::cout << sign << text[i] <<  spaces << sign << std::endl;
        spaces = "";
    }
    std::cout << line << std::endl;
}


int main()
{

    boxPrint({"a", "quick", "brown", "fox"});
    boxPrint({"a", "quick", "brown", "fox"}, '*');
    boxPrint({"a", "quick", "brown", "fox"}, '#');
    boxPrint(std::vector<std::string>{"a", "quick", "brown", "fox"}, '#');
    boxPrint({""});
    boxPrint({});
    boxPrint({}, '#');
    boxPrint({"", "hmmmm", ""});
    boxPrint({"", "", ""});

    return 0;
}