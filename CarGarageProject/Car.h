#pragma once
#include "conio.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
#include <vector>
#include <list>
using namespace std;

namespace CarProject
{
	class Car
	{
		public:
		bool isRunning;
		bool isMoving;
		string _make;
		string _model;
		int _year = 0;
		float _power = 0;
		float _weight = 0;
		float _acceleration = 0;

		Car() {};
		Car(string make, string model, int year, float power, float weight,
			float acceleration)
		{
			_make = make;
			_model = model;
			_year = year;
			_power = power;
			_weight = weight;
			_acceleration = acceleration;
		}

		void static ListOfCars(list<Car> &cars);
		int static ChoseCar();
		void static OnTheStreet(int carNum, list<Car> &cars);
		void static StartEngine();
		void static StopEngine();
		void static Move();
		void static Stop();
		template < typename T > int static TheFastest(const T &Input);
		void static Log(const char *input);
	};
}
