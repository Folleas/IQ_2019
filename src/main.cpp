/*
** EPITECH PROJECT, 2020
** 205IQ_2019
** File description:
** main
*/

#include "Iq.hpp"

int main(int ac, char **av)
{
    Iq iq;
    Utils utils;
    std::size_t u;
    std::size_t p;
    std::size_t iq1 = 0;
    std::size_t iq2 = 0;

    if (utils.checkArgs(ac, av) == 84) {
        return (84);
    }
    u = atoi(av[1]);
    p = atoi(av[2]);
    iq.appendResultTab(iq.computeDensity(u, p));
    if (ac == 3) {
        if (iq.printResult() == 84) {
            return (84);
        }
    }
    else if (ac == 4) {
        iq1 = atoi(av[3]);
        iq.computeInferiorIq(u, p, iq1);
    }
    else if (ac == 5) {
        iq1 = atoi(av[3]);
        iq2 = atoi(av[4]);
        iq.computeIqRange(u, p, iq1, iq2);
    }
    return (0);
}