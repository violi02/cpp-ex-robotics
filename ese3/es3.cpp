/*
Exercise 2: Calculate the angle to the ball
Description:
Write a C++ program that:

Defines two 2D points: one for the robot and one for the ball.
Calculates the angle (in radians) from the robot to the ball relative to the x-axis using atan2.
Prints the angle to the console.
Hint: The angle represents the direction the robot should face to "look at" the ball.

Exercise 3: Robot movement commands based on angle
Description:
Using the angle calculated in Exercise 2, write a C++ function that outputs simple movement commands for the robot to align itself with the ball.
For example, commands like "move forward", "turn left", "turn right" based on the angle value.
*/

#include <iostream>
#include <cmath>

struct Point2D {
    float x;
    float y;
    float theta; // angle in radians
};

float calculateTheta(const Point2D& r, const Point2D& b){
    float dx = r.x - b.x;
    float dy = r.y - b.y;
    // for me: we want to calculate the angle from the robot to the ball relative to the x-axis so in the function atan2(), that takes 2 argument, we put
    // dy as the first argument
    return std::atan2(dy,dx);
}


// Function to move the robot forward in the direction of the ball
// This function takes the robot's current position, the ball's position
// It updates the robot's position based on the angle to the ball
// and prints the new position to the console.
// cos and sin are used to calculate the new position based on the angle
void moveForward(Point2D r, Point2D b){
    r.x +=   std::cos(calculateTheta(r, b));
    r.y +=   std::sin(calculateTheta(r, b));
    std::cout << "Robot moved to position: (" << r.x << ", " << r.y << ")" << std::endl;    
}

void turnLeft(Point2D r, float angle){
    r.theta += angle;
    std::cout << "Robot turned left to face the ball at position: (" << r.x << ", " << r.y << ")" << std::endl;
}
void turnRight(Point2D r,float angle){
    r.theta -= angle;
    std::cout << "Robot turned right to face the ball at position: (" << r.x << ", " << r.y << ")" << std::endl;
}

float calculateDistance(const Point2D& r, const Point2D& b){
    float dx = r.x - b.x;
    float dy = r.y - b.y;
    return std::sqrt(dx*dx + dy*dy);
}



int main(){

    Point2D robot = {12.0,3.0, 0.0};
    Point2D ball = {1.0,7.0,0.0};

    float angle = calculateTheta(robot,ball);
    float angleDiff = angle - robot.theta;

    const float TARGET = 0.1;

    if (std::abs(angleDiff) < TARGET) {
        moveForward(robot, ball);
    } else if (angleDiff > 0) {
        turnLeft(robot, angleDiff);
    } else {
        turnRight(robot, -angleDiff);
    }

    std::cout << "The angle between the robot and the ball is: " << angle << " radians" << std::endl;

}