#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class OceanAcidificationSimulator {
private:
    double atmosphericCO2; // ppm
    double oceanPH;

public:
    OceanAcidificationSimulator(double co2, double ph) {
        atmosphericCO2 = co2;
        oceanPH = ph;
    }

    void simulate(int years, double annualCO2Increase) {
        cout << "\n===== Ocean Acidification Simulation =====\n";
        cout << left << setw(10) << "Year"
             << setw(15) << "CO2(ppm)"
             << setw(15) << "Ocean pH" << endl;

        for (int year = 0; year <= years; year++) {
            cout << setw(10) << year
                 << setw(15) << fixed << setprecision(2) << atmosphericCO2
                 << setw(15) << oceanPH << endl;

            atmosphericCO2 += annualCO2Increase;

            // Simplified acidification model
            oceanPH = 8.2 - 0.0017 * (atmosphericCO2 - 280);

            if (oceanPH < 7.5)
                oceanPH = 7.5;
        }
    }

    void showImpact() {
        cout << "\n===== Marine Impact Analysis =====\n";

        if (oceanPH >= 8.0)
            cout << "Marine ecosystem is relatively stable.\n";
        else if (oceanPH >= 7.8)
            cout << "Shell-forming organisms may experience stress.\n";
        else if (oceanPH >= 7.6)
            cout << "Coral reefs are significantly affected.\n";
        else
            cout << "Severe ecosystem damage likely.\n";
    }
};

int main() {
    double initialCO2, initialPH, annualIncrease;
    int years;

    cout << "Ocean Acidification Simulator\n";
    cout << "Enter current atmospheric CO2 (ppm): ";
    cin >> initialCO2;

    cout << "Enter current ocean pH: ";
    cin >> initialPH;

    cout << "Enter annual CO2 increase (ppm/year): ";
    cin >> annualIncrease;

    cout << "Enter number of years to simulate: ";
    cin >> years;

    OceanAcidificationSimulator simulator(initialCO2, initialPH);

    simulator.simulate(years, annualIncrease);
    simulator.showImpact();

    return 0;
}
