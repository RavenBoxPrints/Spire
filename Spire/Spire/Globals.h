#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>  // include support for randomizing
#include <ctime>   // supports ctime function

// Headings
const int static NORTH = 1;
const int static SOUTH = 2;
const int static EAST = 3;
const int static WEST = 4;

const int static NORTHEAST = 5;
const int static SOUTHEAST = 6;
const int static NORTHWEST = 7;
const int static SOUTHWEST = 8;

// Front or Behind Player
const int static FRONT = 1;
const int static BEHIND = 2;

// Actions
const int static STAND = 0;
const int static WALK = 1;
const int static ATTACK = 2;
const int static DIE = 3;

// Screen Dimensions
const int static SCREEN_WIDTH = 480;
const int static SCREEN_HEIGHT = 270;

// Gamemodes
const int static START = 1;
const int static PLAY = 2;
const int static PAUSE = 3;
const int static OVER = 4;

// Levels
const int static CITADEL = 1;

// Time of day
const int static SUNRISE = 1;
const int static SUNSET = 2;
const int static NIGHT = 3;