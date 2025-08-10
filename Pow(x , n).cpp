#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:

    double pow(double x , int n){
        if(n == 0) return 1.0;
        if(n == 1) return x;

        double half = pow(x , n / 2);

        if (n % 2 == 0)
            return half * half;
        else
            return half * half * x;


    }

    double myPow(double x, int n) {

        long long N = n;

        if(N < 0){
            x = 1 / x;
            N = -N;
        }

        return pow(x , N);

    }
};

int main() {
    
    return 0;
}