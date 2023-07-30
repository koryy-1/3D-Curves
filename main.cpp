#include <iostream>
#include <vector>
#include<algorithm>
#include <cmath>
#include "Curve.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"

const float M_PI = 3.14159265358979323846;

int getRandomNum(int start, int end)
{
    return start + (std::rand() % (end - start + 1));
}

bool compare_radii(const Circle* first, const Circle* second)
{
    return first->Radius < second->Radius;
}

int main()
{
    srand(time(NULL));

    // create and populate vector of Curves
    std::vector<Curve*> CurvesList;

    int N = getRandomNum(10, 100);

    Curve* curve;
    for (size_t i = 0; i < N; i++)
    {
        int choice = getRandomNum(1, 3);
        switch (choice)
        {
        case 1:
            curve = new Circle(getRandomNum(1, 10));
            break;
        case 2:
            curve = new Ellipse(getRandomNum(1, 10), getRandomNum(1, 10));
            break;
        case 3:
            curve = new Helix(getRandomNum(1, 10), getRandomNum(1, 10));
            break;
        }
        CurvesList.push_back(curve);
    }

    // Print coordinates of points and derivatives 
    // of all curves in the container at t=PI/4.
    float t = M_PI / 4;
    std::cout << "Curve type\t\t Coords in point pi/4\t\t Derivative in point pi/4" << std::endl;;
    for (auto* curve : CurvesList)
    {
        Vector3 point = curve->getPoint(t);
        Vector3 derivatives = curve->getDerivative(t);

        std::cout << typeid(*curve).name() << "\t\t" << point.X << " " << point.Y << " " << point.Z << "\t\t"
            << derivatives.X << " " << derivatives.Y << " " << derivatives.Z << std::endl;
    }
    std::cout << std::endl;

    // Populate a second container 
    // that would contain only circles from the first container, via pointers
    std::vector<Circle*> CirclesList;
    for (auto* curve : CurvesList)
    {
        if (typeid(*curve) == typeid(Circle))
        {
            CirclesList.push_back(reinterpret_cast<Circle*>(curve));
        }
    }
    
    std::cout << "Number of curves: " << CurvesList.size() << std::endl;
    std::cout << "Number of circles: " << CirclesList.size() << std::endl;
    std::cout << std::endl;

    // Sort the second container in the ascending order of circles’ radii.
    std::sort(CirclesList.begin(), CirclesList.end(), compare_radii);

    std::cout << "Radii in second container:" << std::endl;
    for (auto* circle : CirclesList)
    {
        std::cout << circle->Radius << std::endl;
    }
    std::cout << std::endl;

    // Compute the total sum of radii of all curves in the second container.
    float totalSumOfRadii = 0;
    for (auto* circle : CirclesList)
    {
        totalSumOfRadii += circle->Radius;
    }
    std::cout << "Total sum of radii in second container = " << totalSumOfRadii << std::endl;

    // clear memory
    for (auto* curve : CurvesList) {
        delete curve;
    }
    CurvesList.clear();
    CirclesList.clear();
}
