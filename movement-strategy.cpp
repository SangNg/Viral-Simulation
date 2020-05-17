#include "movement-strategy.h"

//Speed on x and y axis
void RegularMovementStrategy::set_x(double x){
    this->_x = x;
};

void RegularMovementStrategy::set_y(double y){
    this->_y = y;
};
void RegularMovementStrategy::set_dx(double x){
    this->_dx = x;
};
void RegularMovementStrategy::set_dy(double y){
    this->_dy = y;
};

//No speed on x and y axis
void LockDownMovementStrategy::set_x(double x){};
void LockDownMovementStrategy::set_y(double y){};
void LockDownMovementStrategy::set_dx(double x){};
void LockDownMovementStrategy::set_dy(double y){};