#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
using std::string;

class Point{
public:
    Point(std::istream& stream){
        string input;
        getline(stream, input);
        std::istringstream iss(input);
        
        iss >> x >> y;
    }
    int getX() const { return x; }
    int getY() const { return y; }
private:
    int x;
    int y;
};

class PointManager{
public:
    PointManager(Point p1, Point p2) : p1(p1), p2(p2) {}
    double getEuclideanDistance(){
        return std::sqrt(std::pow(p2.getX() - p1.getX(), 2) + std::pow(p2.getY() - p1.getY() ,2));
    }
private:
    Point p1;
    Point p2;
};

int main(){
    Point point1(std::cin);
    Point point2(std::cin);

    PointManager pm(point1, point2);
    std::cout << std::fixed << std::setprecision(3);
    std::cout << pm.getEuclideanDistance() << std::endl;
}