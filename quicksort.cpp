#include <vector>
#include <string>

using namespace std;

struct Flight{
    int flight_id;
    string airline;
    int flight_number;
    string origin_airport;
    string destination_airport;
};

long long quickComparisons = 0;
long long quickSwaps = 0;

int partition(vector<Flight>& arr, int low, int high){
    int pivot = arr[high].flight_number;
    int i = low - 1;

    for (int j = low; j < high; j++){
        quickComparisons++;

        if (arr[j].flight_number < pivot){
            i++;
            Flight temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            quickSwaps++;
        }
    }
    Flight temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    quickSwaps++;
    return i + 1;
}
void quickSort(vector<Flight>& arr, int low, int high){
        if (low < high){
           int pi = partition(arr, low, high);
           quickSort(arr, low, pi - 1);
           quickSort(arr, pi + 1, high);
 }
}
