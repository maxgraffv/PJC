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

int main()
{
    fmt::println(
            "{}\n{}\n{}\n{}",
            reversedWords("Ala ma kota"),
            reversedWords("Ala"),
            reversedWords(""),
            reversedWords("1 2 3")
    );

    return 0;
}
