// udemy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


int check(std::string buffer)
{

    int words = 0;
    std::stringstream s(buffer);
    std::string word;
    while (s >> word)
    {
        std::cout << word << std::endl;
        if ((word[0] >= 'A' && word[0] <= 'Z') && (word.size() > 1))
            words++;
    }
    return words;
}


int main()
{
    std::string path;
    std::cin >> path;
    std::ifstream file(path);

    int n, counts = 0;
    file >> n;
    file.ignore();
    std::string buffer;

    if (file.is_open()) std::cout << "file opened \n";
    else std::cout << "error\n";
    while (std::getline(file, buffer))
    {

        counts += check(buffer);
    }
    std::cout << counts;
    file.close();
    return 0;
}
