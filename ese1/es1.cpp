/*Esercizio 1: Calcola la distanza tra due punti
Scrivi una funzione che dato un robot 
e una palla (entrambe definite da coordinate x,y) calcola la distanza euclidea tra loro.
Obiettivo:
usare struct,
passaggio per riferimento,
calcolo distanza.*/

#include <iostream>
#include <cmath>    


struct Point {
        float x;
        float y;
};

float calculateDistance(const Point& robot, Point& ball){
    float x = robot.x - ball.x;
    float y = robot.y - ball.y;
    return std::sqrt(x*x + y*y);
}

int main(){
    Point robot = {1,2};
    Point ball = {0,4};


    float distance = calculateDistance(robot, ball);
    std::cout << "the distance between ball and robot is: " <<distance <<std::endl;  
    return 0;

}

