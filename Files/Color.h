#ifndef COLOR_H
#define COLOR_H

class Color
{
    private:
        unsigned int n, k, m, r; // Size, Length, Type, Colors.
        int bT1_COLS;            // Number of columns in bT1.
        unsigned int s;          // Number of pseudo progressions.
        int *dfs;
        int *dfs2;
        int alpha_ROWS;

    public:
        // Constructors
        Color ();                              

        // Destructor
        ~Color(); 

        // Mutators
        void setN();
        void setK();
        void setM();
        void setR();
        void setDfs();
        void setDfs2();
        void setS();
        void setAlpha();
        void setPrimes();
        void setFactors();

        // Accessors
        unsigned int getN();
        unsigned int getK();
        unsigned int getM();
        unsigned int getR();
        int getS();

        // Calculators
        int fact(int);
        int choose(int, int);
        int prime(int);

        // Start
        void Start();

        // Binary Table Functions
        int bT1(int, int);
        int bT2(int, int);
        int alpha(int, int);

};

#endif