#include <vector>
#include <string>

using namespace std;

struct Flight {
    int flight_id;
    string airline;
    int flight_number;
    string origin_airport;
    string destination_airport;
};

long long mergeComparisons = 0;
long long mergeSwaps = 0;

void merge(vector<Flight>& arr, int left, int mid, int right) {
    int size1 = mid - left + 1;
    int size2 = right - mid;

    vector<Flight> leftPart(size1);
    vector<Flight> rightPart(size2);

    for(int i = 0; i < size1; i++) {
        leftPart[i] = arr[left + i];
    }

    for(int j = 0; j < size2; j++) {
        rightPart[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while(i < size1 && j < size2) {
        mergeComparisons++;

        if(leftPart[i].flight_number <= rightPart[j].flight_number) {
            arr[k] = leftPart[i];
            i++;
        }
        else {
            arr[k] = rightPart[j];
            j++;
        }

        mergeSwaps++;
        k++;
    }

    while(i < size1) {
        arr[k] = leftPart[i];
        i++;
        k++;
        mergeSwaps++;
    }

    while(j < size2) {
        arr[k] = rightPart[j];
        j++;
        k++;
        mergeSwaps++;
    }
}

void mergeSort(vector<Flight>& arr, int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}