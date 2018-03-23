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

    int p0 = 0;
    int p1 = 0;
    int p2 = 0;
    int p3 = 0;
    int p4 = 0;
    int p5 = 0;

    std::mt19937 gen(static_cast<unsigned int>(time(nullptr)));
    std::uniform_real_distribution<double> distribution(0, 1);

    for (int agent = 0; agent < 1000; agent++) {

        Graph<PointData, LineData>::iterator it = start;

        while (true) {

            switch (it.point->id) {
                case 0:
                    p0++;
                    break;
                case 1:
                    p1++;
                    break;
                case 2:
                    p2++;
                    break;
                case 3:
                    p3++;
                    break;
                case 4:
                    p4++;
                    break;
                case 5:
                    p5++;
                    break;
                default:break;
            }

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
        std::cout << std::endl;
    }

    std::cout << "0: " << p0 << " | "
              << "1: " << p1 << " | "
              << "2: " << p2 << " | "
              << "3: " << p3 << " | "
              << "4: " << p4 << " | "
              << "5: " << p5
              << std::endl;
}