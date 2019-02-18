#include <iostream>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <queue>

struct Car
{
    std::string plate;
    std::string direction;
    std::string duration;
};

int main()
{
    std::string current_direction;
    int max_number_cars_allowed_for_direction;
    int number_of_cars = 0;

    // Create queues for each direction: E,S,N,W
    std::queue<Car> east_queue;
    std::queue<Car> south_queue;
    std::queue<Car> north_queue;
    std::queue<Car> west_queue;

    // Read initial direction and max number of cars per direction
    std::cin >> current_direction;
    std::cin >> max_number_cars_allowed_for_direction;

    // Read cars to the array
    while (std::cin)
    {
        Car temp;
        std::cin >> temp.plate;
        std::cin >> temp.direction;
        std::cin >> temp.duration;

        if (temp.direction == "E")
        {
            east_queue.push(temp);
        }
        else if (temp.direction == "S")
        {
            south_queue.push(temp);
        }
        else if (temp.direction == "W")
        {
            west_queue.push(temp);
        }
        else if (temp.direction == "N")
        {
            north_queue.push(temp);
        }

        number_of_cars++;
    }

    for (int j = number_of_cars; j >= 0; j--)
    {
        Car temp;
        if (current_direction == "E")
        {
            if (east_queue.size() != 0)
            {
                std::cout << "Current direction: Eastbound\n";
                for (int k = 0; k < max_number_cars_allowed_for_direction; k++)
                {
                    temp = east_queue.front();
                    east_queue.pop();
                    std::cout << "Car " << temp.plate << " is using intersection for " << temp.duration << "sec(s)\n";
                }
            }
            current_direction = "S";
        }
        else if (current_direction == "S")
        {
            if (south_queue.size() != 0)
            {
                std::cout << "Current direction: Southbound\n";
                for (int k = 0; k < max_number_cars_allowed_for_direction; k++)
                {
                    temp = south_queue.front();
                    south_queue.pop();
                    std::cout << "Car " << temp.plate << " is using intersection for " << temp.duration << " sec(s)\n";
                }
            }
            current_direction = "W";
        }
        else if (current_direction == "W")
        {
            if (west_queue.size() != 0)
            {
                std::cout << "Current direction: Westbound\n";
                for (int k = 0; k < max_number_cars_allowed_for_direction; k++)
                {
                    temp = west_queue.front();
                    west_queue.pop();
                    std::cout << "Car " << temp.plate << " is using intersection for " << temp.duration << " sec(s)\n";
                }
            }
            current_direction = "N";
        }
        else if (current_direction == "N")
        {
            if (north_queue.size() != 0)
            {
                std::cout << "Current direction: Westbound\n";
                for (int k = 0; k < max_number_cars_allowed_for_direction; k++)
                {
                    temp = north_queue.front();
                    north_queue.pop();
                    std::cout << "Car " << temp.plate << " is using intersection for " << temp.duration << " sec(s)\n";
                }
            }
            current_direction = "E";
        }
    }
    return 0;
}