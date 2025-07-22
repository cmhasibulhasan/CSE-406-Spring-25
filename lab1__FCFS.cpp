
#include<bits/stdc++.h>
using namespace std;

void solve()
{

}
int main()
{
//    int n;
//    cin >> n;
//    int a[n],b[n];
//
////    for(int i=0;i<n;i++)cin >> a[i];
////    for(int i=0;i<n;i++)cin >> b[i];

    int n=4;
    int a[n]= {0,1,2,3};
    int b[n]= {3,2,1,4};
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
