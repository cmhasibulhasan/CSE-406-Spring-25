
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of Process :" << endl;
    cin >> n;
    int a[n], b[n], p[n];
    cout << "Enter Arrival Time: " << endl;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        p[i] = i;
    }

    cout << "Enter Burst Time:" << endl;
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<tuple<int,int,int>> v;
    for(int i = 0; i < n; i++) {
        v.push_back({a[i], b[i], p[i]});
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++) {
        a[i] = get<0>(v[i]);
        b[i] = get<1>(v[i]);
        p[i] = get<2>(v[i]);
    }

    int ct[n], tat[n], wt[n], completed[n] = {0};
    int t = 0, done = 0;

    while(done < n) {
        int idx = -1, mn = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(a[i] <= t && !completed[i] && b[i] < mn) {
                mn = b[i];
                idx = i;
            }
        }

        if(idx == -1) {
            t++;
            continue;
        }

        t += b[idx];
        ct[idx] = t;
        tat[idx] = ct[idx] - a[idx];
        wt[idx] = tat[idx] - b[idx];
        completed[idx] = 1;
        done++;
    }

    cout << endl << "Completion Time: ";
    for(int i = 0; i < n; i++) cout << ct[i] << " ";
    cout << endl;

    cout << "Turn Around Time: ";
    for(int i = 0; i < n; i++) cout << tat[i] << " ";
    cout << endl;

    cout << "Waiting Time: ";
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cout << wt[i] << " ";
        sum += wt[i];
    }
    cout << endl;

    cout << "Average Waiting Time: " << (float)sum/n << endl;
}
