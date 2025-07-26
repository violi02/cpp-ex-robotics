/* Description:
Write a C++ program that:

Defines two 2D points: one for the robot and one for the ball
Calculates the angle (in radians) from the robot to the ball relative to the x-axis
Prints the angle to the console
🔎 The angle represents the direction the robot should face to "look at" the ball.*/

#include <iostream>
#include <cmath>


struct Point2D {
    float x;
    float y;
};

float calculateDistance(const Point2D& r, const Point2D& b){
    float dx = r.x - b.x;
    float dy = r.y - b.y;
    return std::atan2(dy,dx);
}

int main(){

    Point2D r = {7,12};
    Point2D b = {0,4};
    
    
    float theta = calculateDistance(r, b);
    std::cout<<"The angle beetween r and b is: " <<theta<<std::endl;

    return 0;
}