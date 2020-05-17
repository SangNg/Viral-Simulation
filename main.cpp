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

#include "simulation.h"
#include <iostream>
#include <random>
#include <math.h>
#include "html_canvas.h"
#include "ChartJS_handler.h"

//Constants to control the simulation
const int SUBJECT_COUNT = 200;
const int SIM_WIDTH = 800;
const int SIM_HEIGHT = 500;
const int SUBJECT_RADIUS = 2;
const int SUBJECT_GROUP_COUNT = 5;
const double SUBJECT_MAX_SPEED = 1;

int main() {
    corsim::Simulation s(SIM_WIDTH,SIM_HEIGHT,std::make_unique<corsim::HTMLCanvas>(30,150,SIM_WIDTH,SIM_HEIGHT),
        std::make_unique<corsim::ChartJSHandler>());

    //Code to randomly generate certain numbers, which is done by using certain distributions
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist_w(1.0, SIM_WIDTH);
    std::uniform_real_distribution<double> dist_h(1.0, SIM_HEIGHT);
    std::uniform_real_distribution<double> dist_dx(-0.1, 0.1);
    std::uniform_real_distribution<double> dist_dy(-0.1, 0.1);

    // Verdeel alle subjects over groepen
    for (int i = 0; i < (SUBJECT_COUNT / SUBJECT_GROUP_COUNT); ++i)
    {
        double x = dist_w(mt); //Randomly generate x position
        double y = dist_h(mt); //Randomly generate y position
        double dx = dist_dx(mt); // Randomly generate x speed
        double dy = dist_dy(mt); // Randomly generate y speed

        // Maakt groep aan met een grote van SUBJECT_GROUP_COUNT,
        for (int j = 0; j < SUBJECT_GROUP_COUNT; j++)
        {
            // Calculeer positie en als j deelbaar door 2 is pak dan een andere x,
            // zodat we geen lijntje krijgen maar meer een groepje
            x = (j % 2 == 0) ? (x + (SUBJECT_RADIUS * j)) : (x - (SUBJECT_RADIUS * j));
            y = y + (SUBJECT_RADIUS * j);

            corsim::Subject su(x, y, SUBJECT_RADIUS, false, new RegularMovementStrategy(x,y), SUBJECT_MAX_SPEED);//LockDownMovementStrategy(x,y));

            su.set_dx(dx);
            su.set_dy(dy);

            s.add_subject(std::move(su));
        }
        
    }  
    // Maak de geinfecteerde subject aan
    double x = dist_w(mt); //Randomly generate x position
    double y = dist_h(mt); //Randomly generate y position
    corsim::Subject su(x, y, SUBJECT_RADIUS, false, new RegularMovementStrategy(x,y), SUBJECT_MAX_SPEED);//LockDownMovementStrategy(x,y));

    su.set_dx(dist_dx(mt));
    su.set_dy(dist_dy(mt));
    su.infect();

    s.add_subject(std::move(su));

    s.run();
    /* Opdracht A
    for (int i = 0; i<SUBJECT_COUNT; ++i)
    {
        double x = dist_w(mt); //Randomly generate x position
        double y = dist_h(mt); //Randomly generate y position
        
        corsim::Subject su(x,y,SUBJECT_RADIUS,false,new LockDownMovementStrategy(x,y));
    
        if(i % 3 == 0){
            su.setMoveStrategy = new RegularMovementStrategy(x, y);
        }
        su.set_dx(dist_dx(mt));
        su.set_dy(dist_dy(mt));

        if(i == SUBJECT_COUNT-1)
        {
            su.infect();
        }

        s.add_subject(std::move(su));
    }  

    s.run();
    */
}