/*
** EPITECH PROJECT, 2020
** 205IQ_2019
** File description:
** Iq
*/

#ifndef IQ_HPP_
#define IQ_HPP_

#include <iostream>
#include <vector>
#include <math.h>

class Math {
    public:
        Math() {};
        ~Math() {};

        std::vector<float> computeDensity(std::size_t u, std::size_t o);
        float computeResult(std::size_t u, std::size_t o, float i);
    private:
};

class Iq : public Math {
    public:
        Iq() {};
        ~Iq() {};

        void computeInferiorIq(std::size_t u, std::size_t o, std::size_t iq1);
        void computeIqRange(std::size_t u, std::size_t o, std::size_t iq1, std::size_t iq2);
        std::size_t checkIqBound(std::size_t iq);
        std::size_t printResult();
        void appendResultTab(std::vector<float> tab);
    private:
        std::vector<float> resultTab;
};

class Utils {
    public:
        Utils() {};
        ~Utils() {};

        std::size_t checkArgs(int ac, char **av);
    private:
};

#endif /* !IQ_HPP_ */