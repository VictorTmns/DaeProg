// FlowControlBasics - Victor Taeijmans

#include "pch.h"
#include "structs.h"
#include <iostream>

void PrintTruthTable();
void CompareTwoNumbers();
void CalculatePrice();
void ConvertDayNumber();
void CheckLeapYear();
void ConvertSeconds();
void UseActorState();
void UsePoint2f();

int main()
{
    srand(time(NULL));
    std::cout << "-- Basic flow control exercise -- \n \n";

    //PrintTruthTable();
    //CompareTwoNumbers();
    //CalculatePrice();
    //ConvertDayNumber();
    //CheckLeapYear();
    //ConvertSeconds();
    //UseActorState();
    //UsePoint2f();
    

}

void PrintTruthTable() {
    const bool trueBool{ true };
    const bool trueBool2{ true };
    const bool falseBool{ false };
    const bool falseBool2{ false };

    std::cout << "-- Print truth table --";

    std::cout << "Logical binary AND-operator (&&) \n";
    std::cout << "true && true is " << std::boolalpha << (trueBool && trueBool2);
    std::cout << std::endl;
    std::cout << "true && false is " << std::boolalpha << (trueBool && falseBool);
    std::cout << std::endl;
    std::cout << "false && true is " << std::boolalpha << (trueBool && falseBool);
    std::cout << std::endl;
    std::cout << "false && false is " << std::boolalpha << (falseBool && falseBool2);
    std::cout << std::endl;
    std::cout << std::endl;
    
    std::cout << "Logical binary OR-operator(||) \n";
    std::cout << "Logical binary OR-operator(||) \n";
    std::cout << "true || true is " << std::boolalpha << (trueBool || trueBool2);
    std::cout << std::endl;
    std::cout << "true || false is " << std::boolalpha << (trueBool || falseBool);
    std::cout << std::endl;
    std::cout << "false || true is " << std::boolalpha << (trueBool || falseBool);
    std::cout << std::endl;
    std::cout << "false || false is " << std::boolalpha << (falseBool || falseBool2);
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Logical binary AND-operator (&&) \n";
    std::cout << "!true is " << std::boolalpha << (!trueBool);
    std::cout << std::endl;
    std::cout << "!false is " << std::boolalpha << (!falseBool);
    std::cout << std::endl;
    std::cout << std::endl;
}

void CompareTwoNumbers() {
    const int randomNumber1{ rand() % 11 };
    const int randomNumber2{ rand() % 11 };

    std::cout << "-- Compare 2 numbers \n";
    std::cout << "First number is : " << randomNumber1 << "\n";
    std::cout << "Second number is : " << randomNumber2 << "\n";

    if (randomNumber1 < randomNumber2) {
        std::cout << "Second number is larger than the first one\n";
    }
    else if (randomNumber1 > randomNumber2) {
        std::cout << "First number is larger than the second one\n";
    }
    else if (randomNumber1 == randomNumber2) {
        std::cout << "The numbers are equal\n";
    }
    
}

void CalculatePrice() {
    float ballpoints{};
    float totalPrice{};


    std::cout << "-- Calculate price --\n";
    std::cout << "Nr of ballpoints? ";
    std::cin >> ballpoints;

    if (ballpoints < 20) {
        totalPrice = ballpoints * 4.f;
    }
    else if (ballpoints < 50) {
        totalPrice = ballpoints * 3.5f;
    }
    else if (ballpoints < 101) {
        totalPrice = ballpoints * 3.25f;
    }
    else{
        totalPrice = ballpoints * 3.1f;
    }

    std::cout << "Total price is " << totalPrice;

}

void ConvertDayNumber() {
    int dayNumber{};

    std::cout << "-- Convert day number --\n";
    std::cout << "Day number [1, 7]? ";
    std::cin >> dayNumber;

    switch (dayNumber)
    {
    case 1:
        std::cout << "monday, ";
        break;
    case 2:
        std::cout << "tuesday, ";
        break;
    case 3:
        std::cout << "wednesday, ";
        break;
    case 4:
        std::cout << "thursday, ";
        break;
    case 5:
        std::cout << "friday, ";
        break;
    case 6:
        std::cout << "saturday, ";
        break;
    case 7:
        std::cout << "sunday, ";
        break;
    default:
        break;
    }


    if (dayNumber == 1) {
        std::cout << "Start of the week";
    }
    else if (dayNumber == 2 || dayNumber == 3 || dayNumber == 4) {
        std::cout << "middle of the week";
    }
    else if (dayNumber == 5) {
        std::cout << "nearly weekend";
    }
    else if (dayNumber == 6 || dayNumber == 7) {
        std::cout << "weekend";
    }
    else {
        std::cout << "wrong day number";
    }
}

void CheckLeapYear() {
    int year{};

    std::cout << "-- Check leap year --\n";
    std::cout << "year ? ";
    std::cin >> year;

    if ((year % 4 == 0 && !(year % 100 == 0)) || year % 400 == 0) {
        std::cout << "leap year";
    }
    else {
        std::cout << "no leap year";
    }
}

void ConvertSeconds() {
    int seconds{};
    int remainingSeconds{};

    std::cout << "-- Convert seconds --\n";
    std::cout << "seconds ? ";
    std::cin >> seconds;

    remainingSeconds = seconds % 86400;
    std::cout << "days: " << (seconds - remainingSeconds) / 86400;
    seconds = remainingSeconds;

    remainingSeconds = seconds % 3600;
    std::cout << "\nhours: " << (seconds - remainingSeconds) / 3600;
    seconds = remainingSeconds;

    remainingSeconds = seconds % 60;
    std::cout << "\nminutes: " << (seconds - remainingSeconds) / 60;
    seconds = remainingSeconds;

    std::cout << "\nseconds: " << remainingSeconds;
}

void UseActorState() {

    std::cout << "-- Define and use actorstate --\n";
    const int randomNumber{ rand() % 3 };

    enum class ActorState {
        running,
        flying,
        falling
    };

    ActorState action{ ActorState(randomNumber)};


    switch (action)
    {
    case ActorState::running:
        std::cout << "running";
        break;
    case ActorState::flying:
        std::cout << "flying";
        break;
    case ActorState::falling:
        std::cout << "falling";
        break;
    default:
        break;
    }
}

void UsePoint2f() {
    Point2f point1;
    Point2f point2{};
    Point2f point3{26, 25};

    std::cout << "-- Define and use Point2f--\n";

    std::cout << "values after definition\n";
    //std::cout << "p1: [" << point1.x << ", " << point1.y << "]\n";
    std::cout << "p2: [" << point2.x << ", " << point2.y << "]\n";
    std::cout << "p3: [" << point3.x << ", " << point3.y << "]\n";


    point1.x = 20;
    point1.y = 3;

    point2 = { 30, 40};

    ++point3.x;
    --point3.y;

    std::cout << "Values after changing the members\n";
    std::cout << "p1: [" << point1.x << ", " << point1.y << "]\n";
    std::cout << "p2: [" << point2.x << ", " << point2.y << "]\n";
    std::cout << "p3: [" << point3.x << ", " << point3.y << "]\n";
}