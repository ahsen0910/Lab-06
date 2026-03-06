#include <iostream>

using namespace std;

class WeatherStats {
public:
    static double calculateAverageTemperature(const double* temps, int size) {
        if (size <= 0 || temps == nullptr) return 0.0;

        double sum = 0.0;
        for (int i = 0; i < size; ++i) {
            sum += temps[i];
        }
        return sum / size;
    }

    static double getTemperatureFluctuation(const double* temps, int size) {
        if (size <= 0 || temps == nullptr) return 0.0;

        double minTemp = temps[0];
        double maxTemp = temps[0];

        for (int i = 1; i < size; ++i) {
            if (temps[i] < minTemp) {
                minTemp = temps[i];
            } else if (temps[i] > maxTemp) {
                maxTemp = temps[i];
            }
        }

        return maxTemp - minTemp;
    }
};

int main() {
    int n;
    cout << "Enter number of readings: ";
    cin >> n;

    if (n <= 0) return 0;


    double* readings = new double[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter temperature " << (i + 1) << ": ";
        cin >> readings[i];
    }

    double avg = WeatherStats::calculateAverageTemperature(readings, n);
    double flux = WeatherStats::getTemperatureFluctuation(readings, n);

    cout << " Weather Stats" << endl;
    cout << "Average:     " << avg << endl;
    cout << "Fluctuation: " << flux << endl;

    delete[] readings;
    return 0;
}