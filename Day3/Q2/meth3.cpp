class Solution {
public:
    double myPow(double y, int n) {
        double ans=1.0;
            long long int x=n;
            if(x<0) x=-1*x;
            while(x>0)
            {
                if(x%2==1)
                {
                    ans=ans*y;
                    x=x-1;
                }
                else
                {
                    y=y*y;
                    x=x/2;
                }
            }
            if(n<0)
                ans=(double)(1.0)/(double)(ans);
            return ans;
        
    }
};
