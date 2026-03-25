#include <iostream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Flight {
    int flight_id;
    string airline;
    int flight_number;
    string origin_airport;
    string destination_airport;
};

void generateData(vector<Flight>& flights, int size);
void mergeSort(vector<Flight>& arr, int left, int right);
void quickSort(vector<Flight>& arr, int low, int high);

int main() {
    vector<Flight> flights;
    int choice = 0;

    while(choice != 5) {
        cout << "Sorting Algorithm Analyzer" << endl;
        cout << "1. Load dataset" << endl;
        cout << "2. Run Merge Sort" << endl;
        cout << "3. Run Quick Sort" << endl;
        cout << "4. Compare performance" << endl;
        cout << "5. Exit" << endl;
        cout << endl;
        cout << "Enter choice: " << endl;
        cin >> choice;

        if(choice == 1) {
            generateData(flights, 100000);
            cout << "Dataset loaded." << endl;
            cout << endl;
        }

        else if(choice == 2) {
            if(flights.size() == 0) {
                cout << "Load dataset first." << endl;
            }
            else {
                vector<Flight> temp = flights;
                auto start = high_resolution_clock::now();
                mergeSort(temp, 0, temp.size() - 1);
                auto end = high_resolution_clock::now();

                cout << "Time required to complete merge sort: "
                     << duration_cast<milliseconds>(end - start).count()
                     << " ms" << endl;
                cout << endl;
            }
        }
        else if(choice == 3) {
            if(flights.size() == 0) {
                cout << "Load dataset first." << endl;
            }
            else {
                vector<Flight> temp = flights;
                auto start = high_resolution_clock::now();
                quickSort(temp, 0, temp.size() - 1);
                auto end = high_resolution_clock::now();

                cout << "Time required to complete quick sort: "
                     << duration_cast<milliseconds>(end - start).count()
                     << " ms" << endl;
                cout << endl;
            }
        }
        else if(choice == 4) {
            if(flights.size() == 0) {
                cout << "Load dataset first." << endl;
            }
            else {
                vector<Flight> data1 = flights;
                vector<Flight> data2 = flights;

                auto start1 = high_resolution_clock::now();
                mergeSort(data1, 0, data1.size() - 1);
                auto end1 = high_resolution_clock::now();

                auto start2 = high_resolution_clock::now();
                quickSort(data2, 0, data2.size() - 1);
                auto end2 = high_resolution_clock::now();

                cout << endl;
                cout << "Merge Sort Time: "
                     << duration_cast<milliseconds>(end1 - start1).count()
                     << " ms" << endl;

                cout << "Quick Sort Time: "
                     << duration_cast<milliseconds>(end2 - start2).count()
                     << " ms" << endl;
                cout << endl;
            }
        }
        else if(choice == 5) {
            cout << "Exiting..." << endl;
        }
        else {
            cout << "Invalid choice, try again." << endl;
        }
    }
    return 0;
}