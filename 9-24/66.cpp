

    #include <iostream>  
    #include <string.h>  
    #include <stdio.h>  
      
    using namespace std;  
    typedef long long LL;  
      
    const long long N = 1ll << 48;  
    const long long P = (75ll << 51) + 1;  
    const long long G = 2;  
    const int NUM = 50;  
      
    LL  wn[NUM];  
    LL  a[400000], b[400000];   
      
    LL quick_mod(LL a, LL b, LL m)  
    {  
        LL ans = 1;  
        a %= m;  
        while(b)  
        {  
            if(b & 1)  
            {  
                ans = ans * a % m;  
                b--;  
            }  
            b >>= 1;  
            a = a * a % m;  
        }  
        return ans;  
    }  
      
    void GetWn()  
    {  
        for(int i=0; i<NUM; i++)  
        {  
	   long long t = 1ll << i;  
            wn[i] = quick_mod(G, (P - 1) / t, P);  
        }  
    }  
      
    void Rader(LL a[], int len)  
    {  
        int j = len >> 1;  
        for(int i=1; i<len-1; i++)  
        {  
            if(i < j) swap(a[i], a[j]);  
            int k = len >> 1;  
            while(j >= k)  
            {  
                j -= k;  
                k >>= 1;  
            }  
            if(j < k) j += k;  
        }  
    }  
      
    void NTT(LL a[], int len, int on)  
    {  
        Rader(a, len);  
        int id = 0;  
        for(int h = 2; h <= len; h <<= 1)  
        {  
            id++;  
            for(int j = 0; j < len; j += h)  
            {  
                LL w = 1;  
                for(int k = j; k < j + h / 2; k++)  
                {  
                    LL u = a[k] % P;  
                    LL t = w * (a[k + h / 2] % P) % P;  
                    a[k] = (u + t) % P;  
                    a[k + h / 2] = ((u - t) % P + P) % P;  
                    w = w * wn[id] % P;  
                }  
            }  
        }  
        if(on == -1)  
        {  
            for(int i = 1; i < len / 2; i++)  
                swap(a[i], a[len - i]);  
            LL Inv = quick_mod(len, P - 2, P);  
            for(int i = 0; i < len; i++)  
                a[i] = a[i] % P * Inv % P;  
        }  
    }  

    int main()  
    {  
        GetWn();  
        int T;
        scanf("%d",&T);
        while(T--)  
        {  
        	int len,n; 
		scanf("%d",&n);  
		len = 1;  
		while(len <= 2 * n || len <= 2 * n) len <<= 1;
		LL ans=0,x;
		for(int i=0; i<n; i++){  
		    scanf("%lld",&x);
		    a[i] = x;
		    ans+=x*x;
		}  
		for(int i=0; i<n; i++){  
		    scanf("%lld",&x);
		    b[n-1-i] = x;
		    ans+=x*x;
		}  
		for(int i=n; i<len; i++)  
		    b[i] = a[i] = 0;
		
		NTT(a, len, 1);  
		NTT(b, len, 1);  
		for(int i = 0; i < len; i++)  
		    a[i] = a[i] * b[i] % P;  
		NTT(a, len, -1);

		LL jian=a[n-1];
		for(int i=0;i<n-1;i++) 
			jian=max(jian,a[i]+a[i+n]);
		cout << ans-jian*2 << endl;   
        }  
        return 0;  
    }  
