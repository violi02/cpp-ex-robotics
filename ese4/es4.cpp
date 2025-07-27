/*
Exercise 4: Filtering distant balls
Description:
Write a function that takes the ball’s position relative to the robot and ignores (filters out) any ball that is more than 2 meters away.
*/

#include <iostream>
#include <cmath>

struct Point2D {
    float x;
    float y;
};

float calculateAngle(const Point2D& r, const Point2D& b){
    float dx = b.x - r.x;
    float dy = b.y - r.y;
    return std::atan2(dy, dx);
}

// Function to calculate the distance between two points
float calculateDistance(const Point2D& r, const Point2D& b){
    float dx = b.x - r.x;
    float dy = b.y - r.y;
    return std::sqrt(dx * dx + dy * dy);
}
int main(){
    Point2D robot = {12.0,3.0};
    Point2D ball = {1.0,7.0};

    float distance = calculateDistance(robot, ball);
    if (distance > 2.0) {
        std::cout << "Ball is too far away, ignoring it." << std::endl;
    } else {
        float angle = calculateAngle(robot,ball);
        std::cout << "Ball is within range. Angle to ball: " << angle << " radians." << std::endl;
    }
    

}