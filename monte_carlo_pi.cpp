#include <random>
#include <cstdio>
#include <cmath>
#include <limits>
#include <iostream>

struct Point
{
    double x;
    double y;
};

double length(Point p)
{
    return sqrt( pow(p.x, 2) + pow(p.y, 2) );
}

const long MAX = 1'000'000;

int main(void)
{
    std::mt19937 mt(1929);
    std::uniform_real_distribution<double> real_dist(0.0, std::nextafter(1.0, std::numeric_limits<double>::max()));
    long circle_count = 0l;
    for (long i = 0; i < MAX; ++i) {
        double x = real_dist(mt);
        double y = real_dist(mt);
        Point p1{x, y};
        if (length(p1) < 1) {
            ++circle_count;
        }
    }
    double approximate_area = static_cast<double>(circle_count) / static_cast<double>(MAX);
    double approximate_pi = 4.0 * approximate_area;
    printf("approximate pi: %.10f", approximate_pi);
    return 0;
}
