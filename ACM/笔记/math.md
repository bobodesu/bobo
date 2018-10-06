# 数学

## 数论基本定理

**模运算**  
* ( a + b ) % c = ((a % c) + (b % c)) % c 
* ( a * b ) % c = ((a % c) * (b % c)) % c

**消去律**  
如果 gcd(c,p) = 1  则  
ac ≡ bc % p  => a ≡ b % p 

## 快速幂
```cpp
int Pow(int a,int b) { 
    //快速求a^b ，复杂度 log(b)
    int result = 1;  
    int base = a;  
    while(b) {   
        if( b & 1)result *= base;
        base *= base;
        b >>= 1;  
    }
    return result; 
} 
```

## 快速幂取模
```cpp
int PowMod(int a,int b,int c) {
    //快速求 a^b % c ，要避免计算中间结果溢出
    int result = 1;
    int base = a%c;
    while(b) {
        if( b & 1)result = (result * base)%c;
        base = (base * base) % c;
        b >>= 1;
    }
    return result;
} 
```

## 等比数列二分求和取模
Sn= a+a^2+...+a^n 要求 Sn % p 
```cpp
int PowSumMod(int a,int n,int p){
    // return (a+ a^2 + ... + a^n) Mod p;
    if( n == 1)
        return a%p;
    if( n %2 == 0) 
        return 
            (1+PowMod(a,n/2,p)) *
            PowSumMod(a,n/2,p) %
            p;
    else
        return 
            ((1+PowMod(a,(n-1)/2,p)) *
            PowSumMod(a,(n-1)/2,p) +
            PowMod(a,n,p)) % p; 
} 
```

## 最大公约数/最小公倍数
```cpp
int gcd(int a,int b) {
    if( b == 0) return a;
    return gcd(b,a%b); 
} 
int lcm(int a,int b){
    return a*b/gcd(a,b);
}
```