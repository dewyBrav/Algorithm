#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <algorithm>

// Редакционное расстояние
// Расстояние Левенштейна
// Алгоритм Вагнера — Фишера

void minEditDistance(const std::string &s1, const std::string &s2)
{
    const int len1 = s1.length();
    const int len2 = s2.length();

    // двумерный массив
    std::vector<std::vector<int>> d(len1 + 1, std::vector<int>(len2 + 1));
    // заполнение i,0 и 0,j от 0 до len
    for (int i = 0; i < len1 + 1; ++i)
        d[i][0] = i;
    for (int j = 0; j < len2 + 1; ++j)
        d[0][j] = j;

    // вывод массива
    for (int i = 0; i < len1 + 1; ++i)
    {
        for (int j = 0; j < len2 + 1; ++j)
        {
            std::cout << d[i][j] << '\t';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    int cost;
    for (int i = 1; i < len1 + 1; ++i)
    {
        for (int j = 1; j < len2 + 1; ++j)
        {
            cost = 1;
            if (d[i - 1] == d[j - 1])
                cost = 0;
            auto replace = d[i - 1][j - 1] + cost;
            auto remove = d[i][j - 1] + 1;
            auto insert = d[i - 1][j] + 1;
            d[i][j] = std::min({replace, remove, insert});
        }
    }
    // return d[len1][len2];
    for (int i = 0; i < len1 + 1; ++i)
    {
        for (int j = 0; j < len2 + 1; ++j)
        {
            std::cout << d[i][j] << '\t';
        }
        std::cout << std::endl;
    }
}

int main()
{
    // std::string s1{"ACGTACGTACGT"};
    // std::string s2{"AGTACCTACCGT"};
    // std::string s1{"GCTAC"};
    // std::string s2{"CTCA"};
    std::string s2{"labrador"};
    std::string s1{"gibraltar"};
    minEditDistance(s1, s2);

    return 0;
}