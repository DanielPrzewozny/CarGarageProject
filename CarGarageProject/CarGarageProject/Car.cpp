#include "Car.h"
#include "DrawTable.h"
#include "conio.h"
#include <iostream>
#include <chrono>
#include <ctime>  
#include<list>
using namespace std;
using namespace std::chrono;

namespace CarProject
{
	void Car::ListOfCars(list<Car>& cars)
	{
		DrawTable::tableWidth = 100;
		DrawTable::PrintLine();
		string rows[] = { "Id", "Marka", "Model", "Rok", "Moc (KM)", "Masa w³asna (kg)", "Przyspieszenie do 100km/h (s)" };
		DrawTable::PrintRow(true, rows);
		DrawTable::PrintLine();
		int count = 1;
		for (Car car : cars)
		{
			string rows[] = { to_string(count), car._make, car._model, to_string(car._year), to_string(car._power), to_string(car._weight), to_string(car._acceleration) };
			DrawTable::PrintRow(true, rows);

			count++;
		}
		string rowss[] = { "", "", "", "", "", "", "" };
		DrawTable::PrintRow(true, rowss);
		DrawTable::PrintLine();
	}


	int Car::ChoseCar()
	{
		int carNum = 0;
		wcout << L"\n\nWybierz samochód: " << endl;
		while (!(cin >> carNum) || carNum < 1 || carNum > 3)
		{
			wcout << "Wybierz jeszcze raz (id 1-3)! \n" << endl;
		}
		carNum = carNum - 1;
		return carNum;
	}

	void Car::OnTheStreet(int carNum, list<Car>& cars)
	{
		list<Car>::iterator it = cars.begin();
		std::vector<Car> result;
		for (Car const& c : cars) {
			result.push_back(c);
		}
		cout << "\nWybrano : " << result[carNum]._make << L" " << result[carNum]._model << L" z " << result[carNum]._year << endl;
		wcout << "Wybierz opcjê za pomoc¹ klawiszy: \n" << "[E] Uruchom silnik\n" << "[Q] Wy³¹cz silnik\n" << "[W] Ruszaj w drogê\n" << "[S] Zatrzymaj samochód\n" << "[F] SprawdŸ najszybszy samochód\n" << "[ESC] WyjdŸ\n" << endl;

		//			#region DrawTable
		DrawTable::tableWidth = 77;
		DrawTable::PrintLine();
		DrawTable::tableWidth = 15;
		string time[] = { "Czas" };
		DrawTable::PrintRow(false, time);
		DrawTable::tableWidth = 60;
		string logs[] = { "(" + result[carNum]._make + ", " + result[carNum]._model + ") Log:" };
		DrawTable::PrintRow(true, logs);
		DrawTable::tableWidth = 77;
		DrawTable::PrintLine();
		//			#endregion 

		char info;
		do
		{
			info = _getch();
			if (info == 'e')
			{
				Car::StartEngine();
			}
			if (info == 'q')
			{
				Car::StopEngine();
			}
			if (info == 'w')
			{
				Car::Move();
			}
			if (info == 's')
			{
				Car::Stop();
			}
			if (info == 'f')
			{
				//Car* carFastest = Car[TheFastest(Car)];
				//wcout << ("\n\n- Najszybszy samochód to %s %s z %s z przyspieszeniem %s (s) do 100km/h", carFastest->_make, carFastest->_model, carFastest->_year, carFastest->_acceleration) << endl;
				vector<Car*> Fastest;
				//Fastest.push_back(carFastest);
				//Car::ListOfCars(Fastest);
			}
		} while (std::cin.get() != 27);
	}

	void Car::StartEngine()
	{
		Car cars;
		if (!cars.isRunning && !cars.isMoving)
		{
			cars.isRunning = cars.isRunning ? false : true;
			Log(" - Uruchomiono silnik");
		}
		else
		{
			Log(" - Silnik zosta³ ju¿ wczeœniej uruchomiony");
		}
	}

	void Car::StopEngine()
	{
		Car cars;
		if (cars.isRunning && !cars.isMoving)
		{
			cars.isRunning = cars.isRunning ? false : true;
			Log(" - Wy³¹czono silnik");
		}
		else if (cars.isRunning && cars.isMoving)
		{
			Log(" - Nie wy³¹czaj silnika gdy samochód jest w ruchu");
		}
		else
		{
			Log(" - Silnik zosta³ ju¿ wczeœniej wy³¹czony");
		}
	}

	void Car::Move()
	{
		Car cars;
		if (!cars.isMoving && cars.isRunning)
		{
			cars.isMoving = cars.isMoving ? false : true;
			Log(" - Samochód jest w ruchu");
		}
		else if (cars.isMoving && cars.isRunning)
		{
			Log(" - Samochód jest w ruchu");
		}
	}
	//#region Stop
	void Car::Stop()
	{
		Car cars;
		if (cars.isMoving)
		{
			cars.isMoving = cars.isMoving ? false : true;
			Car::Log(" - Samochód zatrzyma³ siê");
		}
		else { Car::Log(" - Samochód zatrzyma³ siê ju¿ wczeœniej i stoi w miejscu"); }
	}
	//#endregion

	void Car::Log(const char* input)
	{
		system_clock::time_point p = system_clock::now();
		time_t localDate = system_clock::to_time_t(p);

		DrawTable::tableWidth = 15;


		time_point<system_clock> now = system_clock::now();
		std::time_t start_time = system_clock::to_time_t(now);
		char timedisplay[100];
		struct tm buf;
		errno_t err = localtime_s(&buf, &start_time);
		if (strftime(timedisplay, sizeof(timedisplay), "%H:%M:%S", &buf)) {
			cout << timedisplay << '\n';
		}

		// Convert to an ASCII representation.
		string event[] = { timedisplay };
		DrawTable::PrintRow(false, event);
		DrawTable::tableWidth = 60;
		DrawTable::PrintRow(true, event);
		return;
	}
}