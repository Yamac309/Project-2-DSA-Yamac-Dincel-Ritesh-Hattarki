#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

struct Flight {
    int flight_id;
    string airline;
    int flight_number;
    string origin_airport;
    string destination_airport;
};

void generateData(vector<Flight>& flights, int size){
    string airlines[4] = {"AA", "DL", "UA", "SW"};
    string airports[6] = {"JFK", "LAX", "ATL", "ORD", "MIA", "DFW"};

    flights.clear();

    for (int i = 0; i < size; i++){
        Flight f;
        f.flight_id = i + 1;
        f.airline = airlines[rand() % 4];
        f.flight_number = rand() % 9000 + 100;
        f.origin_airport = airports[rand() % 6];
        f.destination_airport = airports[rand() % 6];

        flight.push_back(f);
    }
}

