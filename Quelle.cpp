using namespace std;
#include <iostream>
#include <fstream>
#include <string>

int main() {
	string dateiPfad = "calibrationvalue.txt";
	ifstream dateiStream(dateiPfad);
	string zeile;
	int summeWerte = 0;
	int ersterInt = 0;
	int letzterInt = 0;
	char aktuellerChar;
	bool ersterIntgesetzt = false;
	int Zeilenwert = 0;

	if (!dateiStream.is_open()) {
		cout << "Die Datei kann nicht geoeffnet werden" << endl;
	}	
	while(getline(dateiStream, zeile)) {
		for (string::iterator it = zeile.begin(); it != zeile.end();it++) {
			aktuellerChar = *it;

			if (isdigit(aktuellerChar)) {
				if (!ersterIntgesetzt) {
					ersterInt = aktuellerChar - '0';
					ersterIntgesetzt = 1;
				}
				else {
					letzterInt = aktuellerChar - '0';
				}
			}
		}
		Zeilenwert = (ersterInt * 10) + letzterInt;
		summeWerte = summeWerte + Zeilenwert;
		ersterIntgesetzt = false;
	}
	cout << "Die Summe der Werte lautet: " << summeWerte << endl;
	dateiStream.close();
	
}