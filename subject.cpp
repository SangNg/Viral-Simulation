// Corona Simulation - basic simulation of a human transmissable virus
// Copyright (C) 2020  wbrinksma

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "subject.h"

#include <math.h>
#include <stdio.h>

namespace corsim
{

double Subject::x()
{
    return this->setMoveStrategy->x();
}

double Subject::y()
{
    return this->setMoveStrategy->y();
}

void Subject::set_x(double x)
{
    this->setMoveStrategy->set_x(x);
}

void Subject::set_y(double y)
{
    this->setMoveStrategy->set_y(y);
}

double Subject::dx()
{
    return this->setMoveStrategy->dx();
}

double Subject::dy()
{
    return this->setMoveStrategy->dy();
}

void Subject::set_dx(double dx)
{
    // Limiteer x snelheid tot maxspeed
    double newdx = dx;
    if (newdx < 0.0 && newdx < -_maxSpeed)
    {
        newdx = -_maxSpeed;
    }
    else if (newdx > _maxSpeed)
    {
        newdx = _maxSpeed;
    }

    this->setMoveStrategy->set_dx(newdx);
}

void Subject::set_dy(double dy)
{
    // Limiteer y snelheid tot maxspeed
    double newdy = dy;
    if (newdy < 0.0 && newdy < -_maxSpeed)
    {
        newdy = -_maxSpeed;
    }
    else if (newdy > _maxSpeed)
    {
        newdy = _maxSpeed;
    }

    this->setMoveStrategy->set_dy(newdy);
}

int Subject::radius()
{
    return this->_radius;
}

bool Subject::infected()
{
    return this->_infected;
}

void Subject::infect()
{
    this->_infected = true;
}

double Subject::angle()
{
    return atan2(dy(),dx());
}

double Subject::speed()
{
    return sqrt(dx() * dx() + dy() * dy());
}

}