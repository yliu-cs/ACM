#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e6 + 5;
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
int R[maxn];

void FFT(Complex F[], int Op) {
    for (int i = 0; i < Limit; ++i) {
        if (i < R[i]) {
            swap(F[i], F[R[i]]);
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

int main(int argc, char *argv[]) {
    scanf("%d%d", &N, &M);
    for (int i = 0; i <= N; ++i) {
        scanf("%lf", &A[i].X);
    }
    for (int i = 0; i <= M; ++i) {
        scanf("%lf", &B[i].X);
    }
    Cal();
    for (int i = 0; i <= N + M; ++i) {
        printf("%.0lf ", fabs(A[i].X / Limit));
    }
    return 0;
}

