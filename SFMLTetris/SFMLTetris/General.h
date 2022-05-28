#pragma once
#include <iostream>
#include <vector>
#include <array>
#include <SFML/Graphics.hpp>
#include <string>
#include <random>
#include <ctime>
#include <thread>
#include <mutex>
using namespace sf;

void getPassedTime(Clock& clock, float& timer);
int getRandomNumber(int min, int max);
