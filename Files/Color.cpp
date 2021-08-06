#include "Color.h"
#include <iostream>
#include <cmath>
#include<math.h>
#include <fstream>
#include <cstdlib>
using namespace std;

// Constructor
Color:: Color()
{
    n = 2;
    k = 2;
    m = 2;
    r = 2;
    bT1_COLS = 1;
    dfs = new int[k-1];
    dfs2 = new int[k-1];
    alpha_ROWS = 1;
}

// Destructor
Color::~Color()
{
    delete [] dfs;
    delete [] dfs2;
}

// Mutators
void Color::setN()
{
    cout << "Enter n: ";
    cin >> n;
}
void Color::setK()
{
    cout << "Enter k: ";
    cin >> k;
}
void Color::setM()
{
    cout << "Enter m: ";
    cin >> m;
}
void Color::setR()
{
    cout << "Enter r: ";
    cin >> r;
}
void Color::setDfs()
{
    int c = 0;
    int d = 0;
    int e = 0;
    int f = 0;
    int g = 0;
    int index1 = 1;
    int index2 = 1;
    ofstream out;
    out.open("Files/Values/A.txt");
    int *arr = new int[k];
    int *diffs = new int [k-1];

    for (int i = 0; i < pow(2, n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (bT2(i, j) == 0)
                ++c;
        }
        if (c == n)
        {
            c = 0;
        }
        else
        {
            for (int j = 0; j < n; j++)
            {
                if (bT2(i, j) == 1)
                {
                    arr[d] = j+1;
                    d++;
                }
            }
            for (int p = 0; p < k; p++)
            {
                if (p != 0)
                {
                    diffs[e] = arr[p] - arr[p-1];
                    e++;

                }
            }
            for (int p = 0; p < k-1; p++)
            {
                for (int q = p+1; q < k-1; q++)
                {
                    if (diffs[p] == diffs[q])
                    {
                        ++g;
                        diffs[q] = -g;
                    }
                }
            }
            
            for (int j = 0; j < n; j++)
            {
                if (bT2(i, j) == 1)
                {
                    if (k - 1 - g <= m)
                    {
                        out << j + 1 << " ";
                    }
                }
            }
            if (k - 1 - g <= m)
            {
                out << "\n";
            }
              
            if (g != 0)
            {
                dfs[k-2-g]++;
            }
            else
            {
                dfs[k-2]++;
            }

            c = 0;
            d = 0;
            e = 0;
            f = 0;
            g = 0;
        }
    }

    delete [] arr;
    delete [] diffs;
    out.close();
}
void Color::setDfs2()
{
    for (int i = 0; i < k-1; i++)
    {
        dfs2[i] = dfs[i];
    }
    for (int i = 0; i < k-1; i++)
    {
        if ((i != 0))
        {
            dfs2[i] += dfs2[i-1];
        }
    }
}
void Color::setS()
{
    s = dfs2[m-1];
}
void Color::setAlpha()
{
    alpha_ROWS = pow(r, n);
}
void Color::setPrimes()
{
    int num;
    int ex;
    ofstream B;
    B.open("Files/Values/Primes.txt");
    unsigned long long int p = 1;

    
    for (int i = 0; i < pow(r,n); i++)
    {
        for (int j = 0; j < n; j++)
        {  
            ex = alpha(i, j);
            num = prime(j+1);
            p *= pow(num, ex);
        }
        B << p << endl;
        p = 1;
    }
    B.close();
}

void Color::setFactors()
{
    int num;
    int temp;
    ifstream A;
    ofstream B;
    B.open("Files/Values/Factors.txt");
    unsigned long long int p = 1;

    for (int i = 1; i < r+1; i++)
    {
        A.open("Files/Values/A.txt");
        for (int j = 0; j < s; j++)
        {
            for (int l = 0; l < k; l++)
            {
                A >> num;
                temp = prime(num);
                p *= pow(temp, i);
            }
            B << p << endl;
            p = 1;
        }
        A.close();
    }
    A.close();
    B.close();
}


// Calculators
int Color::fact(int a)  
{                         
    if (a == 0)                               
        return 1;                              
    else                                       
        return a*fact(a-1);                                                      
}                                                  
int Color::choose (int a, int b)
{
    return fact(a) / (fact(b)*fact(a-b));
}
int Color::prime(int j)
{
    bool val = false;
    int p = 2;
    int count = 1;
    int num = 0;
    int primeCount = 0;

    while(!val)
    {
        for (int i = 1; i < p+1; i++)
        {
            if (p % i == 0)
                num++;
        }
        if (num > 2)
            p++;
        else
        {
            primeCount++;
            p++;
        }

        if (primeCount == j)
            val = true;
        else
            val = false;

        num = 0;

        count++;
    }

    return p-1;
}

// Accessors
unsigned int Color::getN()
{
    return n;
}
unsigned int Color::getK()
{
    return k;
} 
unsigned int Color::getM()
{
    return m;
}
unsigned int Color::getR()
{
    return r;
}
int Color::getS()
{
    return s;
}


// Start
void Color::Start()
{
    setDfs();
    setDfs2();
    setS();
    setAlpha();
    setPrimes();
    setFactors();
}

// Binary Table Functions
int Color::bT1(int i, int j)
{
    int p = floor(i/pow(2, j));
    int q = floor(p/2);

    return p - 2*q; 
}
int Color::bT2(int row, int col)
{
    int c = 0;
    int ret = 0;
    for (int j = 0; j < n; j++)
    {
        if (bT1(row, j) == 1)
            ++c;
    }
    if (c == k)
    {
        ret = bT1(row, col);
        return ret;
    }
    else
        return 0;
}
int Color::alpha(int i, int j)
{
    int p = floor(i/pow(r, j));
    int q = floor(p/r);

    return p - r*q+1; 
}


