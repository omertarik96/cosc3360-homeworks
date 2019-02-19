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
    pid_t pid; // Parent process id

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
            number_of_cars++;
        }
        else if (temp.direction == "S")
        {
            south_queue.push(temp);
            number_of_cars++;
        }
        else if (temp.direction == "W")
        {
            west_queue.push(temp);
            number_of_cars++;
        }
        else if (temp.direction == "N")
        {
            north_queue.push(temp);
            number_of_cars++;
        }
    }

    while (number_of_cars > 0)
    {

        Car temp;
        bool initial = true;
        int j = max_number_cars_allowed_for_direction;

        if (current_direction == "E")
        {
            while (j > 0 && number_of_cars > 0)
            {
                if (east_queue.size() != 0)
                {
                    if (initial)
                    {
                        std::cout << "Current direction: Eastbound\n";
                        initial = false;
                    }

                    temp = east_queue.front();
                    east_queue.pop();
                    std::cout << "Car " << temp.plate << " is using intersection for " << temp.duration << " sec(s)\n";
                    if (!fork())
                    {
                        sleep(std::stoi(temp.duration));
                        return 0;
                    }
                    else
                    {
                        wait(NULL);
                        number_of_cars--;
                        j--;
                    }
                }
                else
                {
                    j = 0;
                }
            }
            current_direction = "S";
        }
        else if (current_direction == "S")
        {
            while (j > 0 && number_of_cars > 0)
            {
                if (south_queue.size() != 0)
                {
                    if (initial)
                    {
                        std::cout << "Current direction: Southbound\n";
                        initial = false;
                    }

                    temp = south_queue.front();
                    south_queue.pop();
                    std::cout << "Car " << temp.plate << " is using intersection for " << temp.duration << " sec(s)\n";
                    if (!fork())
                    {
                        sleep(std::stoi(temp.duration));
                        return 0;
                    }
                    else
                    {
                        wait(NULL);
                        number_of_cars--;
                        j--;
                    }
                }
                else
                {
                    j = 0;
                }
            }
            current_direction = "W";
        }
        else if (current_direction == "W")
        {
            while (j > 0 && number_of_cars > 0)
            {
                if (west_queue.size() != 0)
                {

                    if (initial)
                    {
                        std::cout << "Current direction: Westbound\n";
                        initial = false;
                    }

                    temp = west_queue.front();
                    west_queue.pop();
                    std::cout << "Car " << temp.plate << " is using intersection for " << temp.duration << " sec(s)\n";
                    if (!fork())
                    {
                        sleep(std::stoi(temp.duration));
                        return 0;
                    }
                    else
                    {
                        wait(NULL);
                        number_of_cars--;
                        j--;
                    }
                }
                else
                {
                    j = 0;
                }
            }
            current_direction = "N";
        }
        else if (current_direction == "N")
        {
            while (j > 0 && number_of_cars > 0)
            {
                if (north_queue.size() != 0)
                {

                    if (initial)
                    {
                        std::cout << "Current direction: Northbound\n";
                        initial = false;
                    }

                    temp = north_queue.front();
                    north_queue.pop();
                    std::cout << "Car " << temp.plate << " is using intersection for " << temp.duration << " sec(s)\n";
                    if (!fork())
                    {
                        sleep(std::stoi(temp.duration));
                        return 0;
                    }
                    else
                    {
                        wait(NULL);
                        number_of_cars--;
                        j--;
                    }
                }
                else
                {
                    j = 0;
                }
            }
            current_direction = "E";
        }
    }

    return 0;
}