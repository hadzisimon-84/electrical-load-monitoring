#include <iostream>
using namespace std;

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
            case 6:
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Feature not implemented yet.\n";
        }
    }

    return 0;
}