/******************************************************************************



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int LISBottomUp(vector<int> A)
{
    int n = A.size();
    
    vector<int> D(n);
    int ans = 0;
    
    for (int i = 0; i < n; i++)
    {
        D[i] = 1;
        
        for (int j = 0; j < i; j++)
        {
            if ( (A[j] < A[i]) && (D[j] + 1 > D[i]) && (A[i] % A[j] == 0))
                D[i] = D[j] + 1;
        }
    }
    
   for (int i = 0; i < n; i++)
   {
       ans = max(ans, D[i]);
   }
 
    return ans;  

}


int main()
{
    int n, out;
    cout << "n = ";
    cin >> n;
    out = 0;
    
    vector<int> A(n);
    
    cout << "Vector A" << endl;
    
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    out = LISBottomUp(A);

    cout << "LIS count = " << out;

    return 0;
}
