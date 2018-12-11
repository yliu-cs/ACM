#include <bits/stdc++.h>

const int maxn = "Edit";
const double pi = acos(-1.0);

struct Complex {
    double X, Y;

    Complex operator + (const Complex &B) const {
        return Complex {X + B.X, Y + B.Y};
    }

    Complex operator - (const Complex &B) const {
        return Complex {X - B.X, Y - B.Y};
    }

    Complex operator * (const Complex &B) const {
        return Complex {X * B.X - Y * B.Y, X * B.Y + Y * B.X};
    }
    
    Complex operator / (const Complex &B) const {
        double Temp = B.X * B.X + B.Y * B.Y;
        return Complex {(X * B.X + Y * B.Y) / Temp, (Y * B.X - X * B.Y) / Temp};
    }
};

int N, M;
int L;
int Limit;
int R[maxn << 2];

void FFT(Complex F[], int Op) {
    for (int i = 0; i < Limit; ++i) {
        if (i < R[i]) {
            std::swap(F[i], F[R[i]]);
        }
    }
    for (int j = 1; j < Limit; j <<= 1) {
        Complex Temp = Complex {cos(pi / j), Op * sin(pi / j)};
        for (int k = 0; k < Limit; k += (j << 1)) {
            Complex Buffer = Complex {1.0, 0.0};
            for (int l = 0; l < j; ++l) {
                Complex Tx = F[k + l], Ty = Buffer * F[k + j + l];
                F[k + l] = Tx + Ty;
                F[k + j + l] = Tx - Ty;
                Buffer = Buffer * Temp;
            }
        }
    }
}

Complex A[maxn], B[maxn];

void Cal() {
    Limit = 1; L = 0;
    while (Limit <= N + M) {
        Limit <<= 1;
        L++;
    }
    for (int i = 0; i < Limit; ++i) {
        R[i] = (R[i >> 1] >> 1) | ((i & 1) << (L - 1));
    }
    FFT(A, 1);
    FFT(B, 1);
    for (int i = 0; i <= Limit; ++i) {
        A[i] = A[i] * B[i];
    }
    FFT(A, -1);
}

