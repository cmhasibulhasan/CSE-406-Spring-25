
#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cout << "Enter number of Proccess:" << endl;
    cin >> n;
    int a[n],b[n];
    cout << "Enter Arrival Time: " << endl;

    for(int i=0;i<n;i++)cin >> a[i];
    cout << "Enter Burst Time:" << endl;
    for(int i=0;i<n;i++)cin >> b[i];


    int ct[n];
    for(int i=0; i<n; i++)
    {
        ct[i]=0;
    }
    ct[0]=b[0];
    for(int i=1; i<n; i++)
    {
        ct[i]=ct[i-1]+b[i];
    }
    cout << endl;
    cout << "Completion Time: " ;
    for(int i=0; i<n; i++)
    {
        cout << ct [i] << " ";
    }
    cout << endl;

    int tat[n];
    for(int i=0; i<n; i++)
    {
        tat[i]=ct[i]-a[i] ;
    }

    cout << "Turn Around Time: ";

    for(int i=0; i<n; i++)
    {
        cout << tat[i] << " ";
    }
    cout << endl;

    int wt[n];
    for(int i=0; i<n; i++)
    {
        wt[i]=tat[i]-b[i];
    }

    cout << "Waiting Time: "  ;
    int sum=0;

    for(int i=0; i<n; i++)
    {
        cout << wt[i] << " ";
        sum+=wt[i];
    }
    cout << endl;

    cout << "Average Waiting Time:"  << sum/n << endl;


}
