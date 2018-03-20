//
// Created by user on 20.03.2018.
//

#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <random>
#include "formic.h"

void formic(Graph<PointData, LineData>::iterator start, Graph<PointData, LineData>::iterator finish) {

    int alpha = 2;
    int beta = 2;

    for (int agent = 0; agent < 1; agent++) {

        Graph<PointData, LineData>::iterator it = start;

        while (true) {

            std::cout << it.point->id << " " << it.point->lines.size() << std::endl;

            std::vector<double> p;
            double sum = 0;

            for (int point = 0; point < it.point->lines.size(); point++) {

                Graph<PointData, LineData>::iterator nextPoint = it;
                nextPoint.next(point);

                double pi = pow(nextPoint.point->data.weight, alpha) * pow(it.point->lines[point].data.pheromone, beta);
                p.emplace_back(pi);
                sum += pi;

            }

            for (auto &pi : p)
                pi /= sum;

            std::random_device randomDevice;
            std::mt19937 gen(randomDevice());
            std::uniform_real_distribution<> distribution(0, 1);
            double randomNumber = distribution(gen);

            std::sort(p.begin(), p.end());

            if (it.point->lines.empty())
                break;

            double P = 0;
            for (int i = 0; i < p.size(); i++) {
                P += p[i];
                if (randomNumber <= P) {
                    it.next(i);
                    break;
                }
            }

            std::cout << P << std::endl;

        }

    }

}