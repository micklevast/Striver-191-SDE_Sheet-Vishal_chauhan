// just added two line for to handle n=inf of INT_MAX and INT_MIN
        // if (n == INT_MAX) return (x == 1) ? 1 : (x == -1) ? -1 : 0;
        // if (n == INT_MIN) return (x == 1 || x == -1) ? 1 : 0;

class Solution {
public:
    double posPower(double x,int n){
        if(n==1)return x;
        if(n==0)return 1;
        if(n%2){
            return x*myPow(x,n/2)*myPow(x,n/2);
        }
        else{
            return myPow(x,n/2)*myPow(x,n/2);
        }
    }
    double negPower(double x,int n){
        if(n==1)return 1.0/x;
        if(n==0)return 1;
        if(n%2){
            return (1.0/x)*myPow(x,n/2)*myPow(x,n/2);
        }
        else{
            return myPow(x,n/2)*myPow(x,n/2);
        }
    }
    double myPow(double x, int n) {
        if (n == INT_MAX) return (x == 1) ? 1 : (x == -1) ? -1 : 0;
        if (n == INT_MIN) return (x == 1 || x == -1) ? 1 : 0;
        if(n>0)
        return posPower(x,n);
        else
        return negPower(x,n);
    }
};