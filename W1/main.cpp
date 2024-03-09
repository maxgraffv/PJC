#include <iostream>
#include <string>
#include <vector>


void boxPrint(std::vector<std::string> text, char sign = '*')
{
    int width = 0;
    int height = text.size();

    for(int i = 0; i < text.size(); i++)
        width = std::max(width, (int)(text[i].length()));

    width += 2;
    
    std::string line(width, sign);
    
    std::cout << line << std::endl;
    for(int i = 0; i < height; i++)
        std::cout << sign <<
            text[i] <<  std::string((width -2 -text[i].length()), ' ') <<
            sign << std::endl;
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
