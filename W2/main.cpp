#include <iostream>
#include <vector>
#include <ranges>
#include <fmt/core.h>

std::string reversedWords(std::string text)
{
    std::ranges::reverse(text);
    int words_count = std::count(text.begin(), text.end(), ' ')+1;
    int begin = 0;
    int space_i = text.find_first_of(' ');

    std::string final_str = "";
    std::string word = "";

    for(int i = 0; i < words_count; i++)
    {
        word = text.substr(begin, space_i);
        std::reverse(word.begin(), word.end());
        final_str.append((word)+" ");
        text.erase(begin, space_i+1);
        space_i = text.find_first_of(' ');
    }

    return final_str;
}

void justText(std::string text = "", int line_len = 20, char sign = '#')
{
    std::string line(line_len, sign);
    std::string justLeft = line;
    std::string justRight = line;
    std::string justMiddle = line;


    //just left
    justLeft.replace(0, text.length(), text);
    std::cout << justLeft << std::endl;

    //just right
    justRight.replace(line_len -text.length(), text.length(), text);
    std::cout << justRight << std::endl;

    // just middle
    justMiddle.replace((line_len/2) - (text.length()/2), text.length(), text );
    std::cout << justMiddle << std::endl;

}

int main()
{
    fmt::println(
            "{}\n{}\n{}\n{}",
            reversedWords("Ala ma kota"),
            reversedWords("Ala"),
            reversedWords(""),
            reversedWords("1 2 3")
    );

    justText("Textt", 20,'*');

    return 0;
}
