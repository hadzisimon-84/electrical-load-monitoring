#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;

struct Appliance {
    string name;
    double watts;
    double hours;
};

vector<Appliance> appliances;
const string FILE_NAME = "appliances.txt";

void registerAppliance() {
    Appliance a;
    cin.ignore();

    cout << "Appliance name: ";
    getline(cin, a.name);

    cout << "Power (watts): ";
    cin >> a.watts;

    cout << "Hours used per day: ";
    cin >> a.hours;

    appliances.push_back(a);

    cout << "Appliance added successfully.\n";
}

void viewAppliances() {
    if (appliances.empty()) {
        cout << "No appliances registered.\n";
        return;
    }

    cout << fixed << setprecision(2);
    cout << "\n#  Name                Watts   Hours   kWh/day\n";
    cout << "------------------------------------------------\n";

    for (int i = 0; i < appliances.size(); i++) {
        double kwh = (appliances[i].watts / 1000) * appliances[i].hours;

        cout << i + 1 << ". "
             << setw(18) << left << appliances[i].name
             << setw(8) << appliances[i].watts
             << setw(8) << appliances[i].hours
             << kwh << endl;
    }
}

void searchAppliance() {
    cin.ignore();
    string search;
    cout << "Enter appliance name to search: ";
    getline(cin, search);

    bool found = false;

    for (int i = 0; i < appliances.size(); i++) {
        if (appliances[i].name.find(search) != string::npos) {
            double kwh = (appliances[i].watts / 1000) * appliances[i].hours;

            cout << appliances[i].name << " | "
                 << appliances[i].watts << "W | "
                 << appliances[i].hours << " hrs | "
                 << kwh << " kWh/day\n";

            found = true;
        }
    }

    if (!found)
        cout << "Appliance not found.\n";
}

void calculateBill() {
    if (appliances.empty()) {
        cout << "No appliances available.\n";
        return;
    }

    double tariff;
    cout << "Enter tariff per kWh: ";
    cin >> tariff;

    double totalKwh = 0;

    for (int i = 0; i < appliances.size(); i++) {
        totalKwh += (appliances[i].watts / 1000) * appliances[i].hours;
    }

    double dailyCost = totalKwh * tariff;
    double monthlyCost = dailyCost * 30;

    cout << fixed << setprecision(2);
    cout << "\nTotal Daily Energy: " << totalKwh << " kWh\n";
    cout << "Daily Cost: " << dailyCost << endl;
    cout << "Estimated Monthly Cost (30 days): " << monthlyCost << endl;
}

void saveToFile() {
    ofstream file(FILE_NAME);

    for (int i = 0; i < appliances.size(); i++) {
        file << appliances[i].name << "|"
             << appliances[i].watts << "|"
             << appliances[i].hours << endl;
    }

    file.close();
    cout << "Appliances saved successfully.\n";
}

void showMenu() {
    cout << "\n===== Electrical Load Monitoring System =====\n";
    cout << "1. Register Appliance\n";
    cout << "2. View Appliances\n";
    cout << "3. Search Appliance\n";
    cout << "4. Calculate Bill\n";
    cout << "5. Save Appliances\n";
    cout << "6. Exit\n";
    cout << "Choose option: ";
}

int main() {
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: registerAppliance(); break;
            case 2: viewAppliances(); break;
            case 3: searchAppliance(); break;
            case 4: calculateBill(); break;
            case 5: saveToFile(); break;
            case 6:
                saveToFile();
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }

    return 0;
}
