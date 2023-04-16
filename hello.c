#include <iostream>
include <cmath>

class Car {
private:
    std::string make; // The make of the car
    std::string model; // The model of the car
    int year; // The year the car was made
    int speed; // The current speed of the car in miles per hour
    int x; // The x-coordinate of the car
    int y; // The y-coordinate of the car
public:
    // Constructor to initialize the attributes of the car
    Car(std::string make, std::string model, int year, int speed, int x, int y) {
        this->make = make;
        this->model = model;
        this->year = year;
        this->speed = speed;
        this->x = x;
        this->y = y;
    }
    
    // Method to increase the speed of the car by a given amount
    void accelerate(int speed_increment) {
        speed += speed_increment;
    }
    
    // Method to decrease the speed of the car by a given amount
    void brake(int speed_decrement) {
        speed -= speed_decrement;
        if (speed < 0) {
            speed = 0;
        }
    }
    
    // Method to update the position of the car based on its current speed
    void move() {
        x += speed;
    }
    
    // Method to detect a collision between two cars
    bool detect_collision(Car car2) {
        // Calculate the distance between the two cars using the distance formula
        double distance = std::sqrt(std::pow(x - car2.x, 2) + std::pow(y - car2.y, 2));
        // If the distance is less than or equal to the sum of the radii of the cars (assumed to be 10 units), then there is a collision
        return distance <= 10;
    }
    
    // Method to calculate the time to collision between two cars
    double time_to_collision(Car car2) {
        // Calculate the relative speed between the two cars
        int relative_speed = speed - car2.speed;
        // If the relative speed is 0, return infinity to avoid division by zero
        if (relative_speed == 0) {
            return INFINITY;
        }
        // Calculate the relative position between the two cars
        int relative_position = car2.x - x;
        // Calculate the time to collision using the formula d = rt
        double time = (double)relative_position / (double)relative_speed;
        return time;
    }
};