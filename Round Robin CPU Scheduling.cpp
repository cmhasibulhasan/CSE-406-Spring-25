#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, quantum;


    cout << "Enter the number of process: ";
    cin >> n;
    cout << "Enter the quantum: ";
    cin >> quantum;

    vector<string> p(n);
    vector<int> at(n), bt(n);


    for (int i = 0; i < n; i++) {
        cout << "Enter Process (P1-9 AT BT): ";
        cin >> p[i] >> at[i] >> bt[i];
    }

    vector<int> remaining_time = bt;
    vector<int> ct(n, 0);
    vector<int> tat(n, 0);
    vector<int> wt(n, 0);
    vector<bool> visited(n, false);

    int time = 0;
    string gantt = "|0|";
    vector<int> ready;
    int done = 0;

    while (done < n) {

        for (int i = 0; i < n; i++) {
            if (at[i] <= time && !visited[i]) {
                ready.push_back(i);
                visited[i] = true;
            }
        }

        if (!ready.empty()) {
            int i = ready.front();
            ready.erase(ready.begin());


            if (remaining_time[i] > quantum) {
                time += quantum;
                remaining_time[i] -= quantum;
            } else {
                time += remaining_time[i];
                remaining_time[i] = 0;
                ct[i] = time;
                tat[i] = ct[i] - at[i];
                wt[i] = tat[i] - bt[i];
                done++;
            }

            gantt += p[i] + "|" + to_string(time) + "|";


            for (int j = 0; j < n; j++) {
                if (at[j] <= time && !visited[j]) {
                    ready.push_back(j);
                    visited[j] = true;
                }
            }

            if (remaining_time[i] > 0) {
                ready.push_back(i);
            }
        }
    }

    double avg_tat = 0, avg_wt = 0;
    for (int i = 0; i < n; i++) {
        avg_tat += tat[i];
        avg_wt += wt[i];
    }
    avg_tat /= n;
    avg_wt /= n;

    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << p[i] << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << ct[i] << "\t"
             << tat[i] << "\t"
             << wt[i] << "\n";
    }
    cout << "\nGantt Chart:\n";
    cout << gantt << endl;
    cout << "\nAverage Turnaround Time: " << fixed << setprecision(2) << avg_tat << " ms\n";
    cout << "Average Waiting Time: " << fixed << setprecision(2) << avg_wt << " ms\n";

    return 0;
}
