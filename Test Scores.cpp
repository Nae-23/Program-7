#include <fstream>
#include <iostream>

using namespace std;

void sortScores(float scores[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (scores[j] < scores[i]) {
                float temp = scores[i];
                scores[i] = scores[j];
                scores[j] = temp;
            }
        }
    }
}

float calculateAverage(float scores[], int count) {
    float sum = 0.0f;
    for (int i = 1; i < count; i++) {
        sum += scores[i];
    }
    return sum / (count - 1);
}

int main() {
    int numScores;

    cout << "Enter the number of test scores (minimum 2): ";
    while (!(cin >> numScores) || numScores < 2) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter 2 or more: ";
    }

    float* scores = new float[numScores];

    for (int i = 0; i < numScores; i++) {
        float score;
        cout << "Enter score " << (i + 1) << ": ";
        while (!(cin >> score) || score < 0.0f) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Score must be 0 or more. Enter again: ";
        }
        scores[i] = score;
    }

    sortScores(scores, numScores);
    float average = calculateAverage(scores, numScores);

    ofstream out("SortedScores.txt");
    out << "Sorted Test Scores\n";
    out << "------------------\n";
    for (int i = 0; i < numScores; i++) {
        out << scores[i] << "\n";
    }
    out << "\n";
    out << "Lowest score dropped: " << scores[0] << "\n";
    out << "Average after dropping lowest: " << average << "\n";

    delete[] scores;
    cout << "Results written to SortedScores.txt\n";
    return 0;
}
