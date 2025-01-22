#pragma once

class State
{
private:
    double mX;
    double mY;
    double mTheta;

public:
    // Orthodox Canonical Form
    State();
    State(double x, double y, double theta);
    State(const State& state);
    State& operator=(const State& state);
    ~State();

    // Additional member functions
    void printState();
    double getX();
    double getY();
    double getThetaDeg();
    double setThetaRange(double degree);
    double convertTheta(double degree);
    void updateState(double updated_x, double updated_y);
    void updateState(double updated_theta);                     // Overloading
};