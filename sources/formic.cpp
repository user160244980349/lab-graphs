//
// Created by user on 20.03.2018.
//

#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <random>
#include <iomanip>
#include "formic.h"

void formic(Graph<PointData, LineData>::iterator start, Graph<PointData, LineData>::iterator finish) {

    double alpha = 0.8; // влияние расстояния
    double beta = 0.5; // влияние феромона
    double pheromone = 1; // начальное количество феромона на ребрах
    double evaporation = 0.005; // начальное количество феромона на ребрах

    std::mt19937 gen(static_cast<unsigned int>(time(nullptr)));
    std::uniform_real_distribution<double> distribution(0, 1);

    for (int agent = 0; agent < 1000; agent++) {

        Graph<PointData, LineData>::iterator it = start;

        while (true) {

            std::cout << it.point->id;

            if (it.point->lines.empty())
                break;

            std::cout << " -> ";

            std::vector<double> p;
            double sum = 0;

            for (int point = 0; point < it.point->lines.size(); point++) {
                Graph<PointData, LineData>::iterator nextPoint = it;
                nextPoint.next(point);

                double pi = 1 / pow(it.point->lines[point].data.weight, alpha) + pow(it.point->lines[point].data.pheromone, beta);

                p.emplace_back(pi);
                sum += pi;
            }

            for (auto &pi : p)
                pi /= sum;

            double randomNumber = distribution(gen);

            double P = 0;
            for (int i = 0; i < p.size(); i++) {
                P += p[i];
                if (randomNumber < P) {
                    it.point->lines[i].data.pheromone = it.point->lines[i].data.pheromone + pheromone / it.point->lines[i].data.weight;
                    it.next(i);
                    break;
                }
            }
        }

        for (auto &p : *it.points)
            for (auto &l : p.lines)
                l.data.pheromone -= evaporation;

        std::cout << std::endl;
    }


    std::cout << "Best way is: ";
    Graph<PointData, LineData>::iterator it = start;
    int range = 0;
    while (true) {

        std::cout << it.point->id;

        if (it.point->lines.empty() or it == finish)
            break;

        std::cout << " -> ";

        int next = 0;
        for (int point = 0; point < it.point->lines.size(); point++) {

            if (it.point->lines[next].data.pheromone < it.point->lines[point].data.pheromone)
                next = point;

        }
        range += it.point->lines[next].data.weight;
        it.next(next);
    }
    std::cout << " with range " << range << std::endl << std::endl;
}