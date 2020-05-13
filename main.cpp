#include <iostream>
// nix

void showMenue();
void startUI();
int minimum();
void fillArrayRandom(int arr[100], int arraySize);
int maximum();
int median();
void printArray();
void sortArray(int pInt[100], const int arraySize);

int range();

double meanDeviation();

double average();

using namespace std;

const int arraySize = 100;
int seriesOfMeasurements[arraySize];

int main() {
    fillArrayRandom(seriesOfMeasurements, arraySize);
    startUI();
    return 0;
}

void fillArrayRandom(int arr[100], int arraySize) {
    srand((unsigned) time(NULL));
    for (int i = 0; i < arraySize; ++i) {
        arr[i] = rand() % 1000 + 1;
    }
}

void startUI() {
    while (true) {
        showMenue();
        int functionID;
        cin >> functionID;
        switch (functionID) {
            case 0:
                return;
            case 1:
                cout << "Das Minimum ist " << minimum() << endl;
                break;
            case 2:
                cout << "Das Maximum ist " << maximum() << endl;
                break;
            case 3:
                cout << "Das Median ist " << median() << endl;
                break;
            case 4:
                cout << "Die Spannweite ist " << range() << endl;
                break;
            case 5:
                cout << "Die mittlere Abweichung ist " << meanDeviation() << endl;
                break;
            case 6:

        }
        printArray();
    }
}

double meanDeviation() {
    int avrg = average();
    int sum = 0;
    for (int i = 0; i < arraySize; ++i) {
        sum += abs(seriesOfMeasurements[i] - avrg);
    }
    return sum / arraySize;
}

double average() {
    int sum = 0;
    for (int i = 0; i < arraySize; ++i) {
        sum += seriesOfMeasurements[i];
    }
    return sum / arraySize;
}

int range() {
    return maximum() - minimum();
}

int median() {
    sortArray(seriesOfMeasurements, arraySize);
    return seriesOfMeasurements[arraySize / 2];
}

void printArray() {
    for (int i = 0; i < arraySize; ++i) {
        cout << seriesOfMeasurements[i] << " ";
    }
    cout << endl;
}

void sortArray(int arr[100], const int arraySize) {
    for (int i = 0; i < arraySize - 1; ++i) {
        int minIndex = 0;
        for (int j = i; j < arraySize; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int maximum() {
    int max = seriesOfMeasurements[0];
    for (int i = 1; i < arraySize; ++i) {
        if (seriesOfMeasurements[i] > max) {
            max = seriesOfMeasurements[i];
        }
    }
    return max;
}

int minimum() {
    int min = seriesOfMeasurements[0];
    for (int i = 1; i < arraySize; ++i) {
        if (seriesOfMeasurements[i] < min) {
            min = seriesOfMeasurements[i];
        }
    }
    return min;
}

void showMenue() {
    cout << endl;
    cout << "Wählen Sie eines der folgenden Funktionen:" << endl;
    cout << "Minimum (1)" << endl;
    cout << "Maximum (2)" << endl;
    cout << "Median (3)" << endl;
    cout << "Spannweite (4)" << endl;
    cout << "Mittlere Abweichung (5)" << endl;
    cout << "Am haeufigsten auftretenden Werte (6)" << endl;
    cout << "Programm beenden (0)" << endl;
    cout << "Bitte Funktionsnummer eingeben: ";
}
