#pragma once
#include "conio.h"
#include <iostream>
#include <chrono>
#include <ctime>  
#include <string>
#include <vector>
#include <list>
using namespace std;

namespace CarProject {
	class Car
	{

	private:


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

		Car(string make, string model, int year, float power, float weight, float acceleration) {
			_make = make;
			_model = model;
			_year = year;
			_power = power;
			_weight = weight;
			_acceleration = acceleration;
		}


		//		#region ListOfCars

		void static ListOfCars(list<Car>& cars);
		//		#endregion

		//		#region ChoseCar
		int static ChoseCar();
		//		#endregion

				//Navigation
		//		#region OnTheStreet 
		void static OnTheStreet(int carNum, list<Car>& cars);
		//		#endregion 

		//		#region StartEngine
		void static StartEngine();
		//		#endregion

		//		#region StopEngine
		void static StopEngine();
		//		#endregion

		//		#region Move
		void static Move();
		//		#endregion

		//		#region Stop
		void static Stop();
		//		#endregion

		//		#region TheFastest
		template<typename T>
		int static TheFastest(const T& Input);
		//		#endregion

		//		#region Log
		void static Log(const char* input);
		//		#endregion

	};

}