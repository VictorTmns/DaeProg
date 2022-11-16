// applications.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{
    float redvalue{};
    float bluevalue{};
    float greenvalue{};
    float alphavalue{};

    std::cout << "rgba in [0, 255]? ";
    std::cin >> redvalue >> bluevalue >> greenvalue >> alphavalue;

    std::cout << "rgba in [0.0f, 1.0f]: ";

    redvalue /= 255;
    bluevalue /= 255;
    greenvalue /= 255;
    alphavalue /= 255;

    std::cout << redvalue << "\n";
    std::cout << bluevalue << "\n";
    std::cout << greenvalue << "\n";
    std::cout << alphavalue << "\n \n";


    float kilometers{};
    std::cout << "distance in km? ";
    std::cin >> kilometers;

    float meters{};
    float centimeters{};
    meters = kilometers * 1000;
    centimeters = kilometers * 100000;

    std::cout << meters << " meters. " << centimeters << " cm \n \n";


    float degreestoradians{};
    std::cout << "angle in radians? ";
    std::cin >> degreestoradians;

    float radians{};
    radians = degreestoradians * 57.2957795;

    std::cout << radians << " radians \n \n";


    float radianstodegrees{};
    std::cout << "angle in degrees? ";
    std::cin >> radianstodegrees;

    float degrees{};
    degrees = radianstodegrees * 0.0174532925;

    std::cout << degrees << " degrees \n \n";


    float secondsrotation{};
    std::cout << "seconds of one rotation? ";
    std::cin >> secondsrotation;

    float angularvelocity{};
    angularvelocity = 360 /secondsrotation;

    std::cout << angularvelocity << " degrees/second \n \n";


    float speedPerHour{};
    float distancetravelled{};
    std::cout << "speed (km/h)? ";
    std::cin >> speedPerHour;
    float elapsedminutes;
    std::cout << "elapsed time (minutes)? ";
    std::cin >> elapsedminutes;

    distancetravelled = speedPerHour *(elapsedminutes/60)*1000;

    std::cout << distancetravelled << " meters \n \n";


    float fallingdurations{};
    std::cout << "seconds? ";
    std::cin >> fallingdurations;

    float objectvelocity{};
    objectvelocity = fallingdurations * 9.8;

    std::cout << "Velocity" << objectvelocity << " m/sec \n \n";


    float circleRadius{};
    float pi{ 3.1415 };
    std::cout << "Radius of circle? ";
    std::cin >> circleRadius;

    float circumferenceCircle{};
    float areaCircle{};
    circumferenceCircle = circleRadius * 2 * pi;
    areaCircle = circleRadius * circleRadius * pi;

    std::cout << "circumferenceCircle: " << circumferenceCircle << "\n";
    std::cout << "areaCircle: " << areaCircle << "\n \n";

        
    float rectangleBase{};
    float rectangleHeight{};
    std::cout << "Width and height? ";
    std::cin >> rectangleBase;
    std::cin >> rectangleHeight;

    float circumferenceRectangle;
    float areaRectangle;
    circumferenceRectangle = rectangleBase*2+ rectangleHeight*2;
    areaRectangle = rectangleBase*rectangleHeight;

    std::cout << "circumference: " << circumferenceRectangle << "\n";
    std::cout << "area: " << areaRectangle << "\n \n";

        
    float triangleBase{};
    float triangleHeight{};
    std::cout << "Width and height? ";
    std::cin >> triangleBase;
    std::cin >> triangleHeight;

    float areaTriangle{};
    areaTriangle = triangleBase * triangleHeight /2;

    std::cout << "area: " << areaTriangle << "\n";
    


}
