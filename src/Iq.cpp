/*
** EPITECH PROJECT, 2020
** 205IQ_2019
** File description:
** Iq
*/

#include "Iq.hpp"

void Iq::computeInferiorIq(std::size_t u, std::size_t o, std::size_t iq1)
{
    float n = 0.0;

    checkIqBound(iq1);
    for (float i = 0.0; i < iq1; i += 0.01)
        n += computeResult(u, o, i);
    printf("%.1f%% of people have an IQ inferior to %ld\n", n, iq1);
}

void Iq::computeIqRange(std::size_t u, std::size_t o, std::size_t iq1, std::size_t iq2)
{
    float n = 0.0;

    checkIqBound(iq1);
    checkIqBound(iq2);
    if (iq1 > iq2) {
        printf("Error : IQ1 must be inferior to IQ2\n");
        exit(84);
    }
    for (float i = iq1; i < iq2; i += 0.01)
        n += computeResult(u, o, i);
    printf("%0.1f%% of people have an IQ between %ld and %ld\n", n, iq1, iq2);
}

std::size_t Iq::checkIqBound(std::size_t iq)
{
    if (iq < 0 || iq > 200) {
        printf("Error : IQ must be between 0 and 200\n");
        exit(84);
    }
    return (0);
}

std::size_t Iq::printResult()
{
    for (std::size_t i = 0; i <= 200; i++) {
        if (this->resultTab.at(i) < 0)
            return (84);
        printf("%ld %.5f\n", i, this->resultTab.at(i));
    }
    return (0);
}

std::vector<float> Math::computeDensity(std::size_t u, std::size_t o)
{
    std::vector<float> resultTab;
    float result = 0;

    for (std::size_t i = 0; i <= 200; i++) {
        result = (1 / (o * sqrt(2 * M_PI))) * exp(-0.5 * pow((i - u) / o, 2));
        resultTab.push_back(result);
    }
    return (resultTab);
}

void Iq::appendResultTab(std::vector<float> tab)
{
    this->resultTab.insert(resultTab.end(), tab.begin(), tab.end());
}

float Math::computeResult(std::size_t u, std::size_t o, float i)
{
    return (1 / (o * sqrt(2 * M_PI))) * exp(-0.5 * pow((i - u) / o, 2));
}

std::size_t Utils::checkArgs(int ac, char **av)
{
    if (ac < 3 || ac > 5) {
        if (ac == 2 && av[1] == "-h")
            printf("USAGE\n\t./205IQ µ p [IQ1] [IQ2]\n\nDESCRIPTION\n\tµ\tpredetermined mean\n\tp\tpredetermined standard deviation\n\tIQ1\tminimum IQ\n\tIQ2\tmaximum IQ");
        else
            printf("Check help (./205IQ -h)");
        return (84);
    }
    if (atoi(av[1]) < 0 || atoi(av[2]) <= 0) {
        printf("Error : must be positive\n");
        return (84);
    }
    return (0);
}