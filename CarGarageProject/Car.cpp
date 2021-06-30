#include "Car.h"
#include "DrawTable.h"
#include "conio.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include<list>
using namespace std;
using namespace std::chrono;



namespace CarProject {
	Car cars;
	void Car::ListOfCars(list < Car >& cars) {
		DrawTable::tableWidth = 100;
		DrawTable::PrintLine();
		string rows[] = { "Id","Marka","Model","Rok","Moc (KM)","Masa wlasna (kg)","Przyspieszenie do 100km/h (s)" };
		DrawTable::PrintRow(true, rows, 7);
		DrawTable::PrintLine();
		int count = 1;
		for (Car car : cars) {
			string rows[] = {
			  to_string(count),
			  car._make,
			  car._model,
			  to_string(car._year),
			  to_string(car._power),
			  to_string(car._weight),
			  to_string(car._acceleration)
			};
			DrawTable::PrintRow(true, rows, 7);
			count++;
		}
		string rowss[] = { " ","","","","","","" };
		DrawTable::PrintRow(true, rowss, 7);
		DrawTable::PrintLine();
	}

	int Car::ChoseCar() {
		int carNum = 0;
		wcout << "\n\nWybierz samochod: " << endl;
		while (!(cin >> carNum) || carNum < 1 || carNum > 3) {
			wcout << "Wybierz jeszcze raz (id 1-3)! \n" << endl;
		}
		carNum = carNum - 1;
		return carNum;
	}

	void Car::OnTheStreet(int carNum, list < Car >& cars) {
		vector<Car> result(cars.begin(), cars.end());
		cout << "\nWybrano : " << result[carNum]._make << " " << result[carNum]._model << " z " << result[carNum]._year << endl;
		wcout << "Wybierz opcje za pomoca klawiszy: \n" << "[E] Uruchom silnik\n" << "[Q] Wylacz silnik\n" << "[W] Ruszaj w droge\n" << "[S] Zatrzymaj samochod\n" << "[F] Sprawdz najszybszy samochod\n" << "[ESC] Wyjdz\n" << endl;

		DrawTable::tableWidth = 77;
		DrawTable::PrintLine();
		DrawTable::tableWidth = 15;
		string time[] = {
		  "Czas"
		};
		DrawTable::PrintRow(false, time, 1);
		DrawTable::tableWidth = 60;
		string logs[] = {
		  "(" + result[carNum]._make + ", " + result[carNum]._model + ") Log:"
		};
		DrawTable::PrintRow(true, logs, 1);
		DrawTable::tableWidth = 77;
		DrawTable::PrintLine();

		char info = '\0';
		do {
			info = '\0';
			info = _getch();
			if (info == 'e') {
				Car::StartEngine();
			}
			if (info == 'q') {
				Car::StopEngine();
			}
			if (info == 'w') {
				Car::Move();
			}
			if (info == 's') {
				Car::Stop();
			}
			if (info == 'f') {
				//Car* carFastest = Car[TheFastest(Car)];
				//wcout << ("\n\n- Najszybszy samochód to %s %s z %s z przyspieszeniem %s (s) do 100km/h", carFastest->_make, carFastest->_model, carFastest->_year, carFastest->_acceleration) << endl;
				vector < Car* > Fastest;
				//Fastest.push_back(carFastest);
				//Car::ListOfCars(Fastest);
			}
		} while (info != 27);
	}

	void Car::StartEngine() {
	
		if (!cars.isRunning && !cars.isMoving) {
			cars.isRunning = cars.isRunning ? false : true;
			Log(" - Uruchomiono silnik");
		}
		else {
			Log(" - Silnik zostal juz wczesniej uruchomiony");
		}
	}

	void Car::StopEngine() {
		
		if (cars.isRunning && !cars.isMoving) {
			cars.isRunning = cars.isRunning ? false : true;
			Log(" - Wylaczono silnik");
		}
		else if (cars.isRunning && cars.isMoving) {
			Log(" - Nie wylaczaj silnika gdy samochod jest w ruchu");
		}
		else {
			Log(" - Silnik zostal juz wczesniej wylaczony");
		}
	}

	void Car::Move() {
		
		if (!cars.isMoving && cars.isRunning) {
			cars.isMoving = cars.isMoving ? false : true;
			Log(" - Samochod jest w ruchu");
		}
		else if (cars.isMoving && cars.isRunning) Log(" - Samochod jest w ruchu");
		else if (!cars.isRunning) Log(" - W pierwszej kolejnosci uruchom silnik");
	}

	void Car::Stop() {
	
		if (cars.isMoving) {
			cars.isMoving = cars.isMoving ? false : true;
			Car::Log(" - Samochod zatrzymal sie");
		}
		else {
			Car::Log(" - Samochod zatrzymal sie juz wczesniej i stoi w miejscu");
		}
	}

	void Car::Log(const char* input) {
		time_t current_time;
		struct tm* timeinfo;
		time(&current_time);
		timeinfo = localtime(&current_time);

		char output[10];
		strftime(output, 10, "%H:%M:%S", timeinfo);

		string event[] = { output };

		DrawTable::tableWidth = 15;
		DrawTable::PrintRow(false, event, 1);
		DrawTable::tableWidth = 60;
		string text[] = { input };
		DrawTable::PrintRow(true, text, 1);
		return;
	}
}
