#include <stdio.h>
#include <math.h>

// mendefinisikan konstanta PI
#define PI 3.14159265358979323846

// toleransi error untuk konvergensi Newton-Raphson
#define TOLERANCE 1e-6

// batas maksimum iterasi agar program tidak looping terus-menerus
#define MAX_ITER 100

// fungsi f(h) = volume air aktual - volume target (V)
// rumus volume air dalam tangki bola: V = (π * h² * (3R - h)) / 3
// jadi f(h) = volume_terhitung - V_target
double f(double h, double R, double V) {
    return (PI * h * h * (3 * R - h)) / 3.0 - V;
}

// turunan fungsi f(h), yaitu f'(h)
// dari perhitungan turunan, f'(h) = π * h * (4R - 2h) / 3
double df(double h, double R) {
    return (PI * h * (4 * R - 2 * h)) / 3.0;
}

// fungsi Newton-Raphson untuk mencari akar f(h) = 0
// input: tebakan awal, radius tangki R, volume target V
// output: nilai kedalaman air h yang memenuhi f(h) = 0
double newton_raphson(double initial_guess, double R, double V) {
    double h = initial_guess;   // nilai awal h
    int iter;

    printf("Iterasi |     h (m)    |   f(h) (m^3)  \n");
    printf("----------------------------------------\n");

    for (iter = 1; iter <= MAX_ITER; iter++) {
        double f_val = f(h, R, V);      // menghitung f(h)
        double df_val = df(h, R);       // menghitung f'(h)

        // cek jika turunan terlalu kecil, agar tidak terjadi pembagian nol
        if (fabs(df_val) < 1e-12) {
            printf("Peringatan: Turunan mendekati nol pada iterasi %d.\n", iter);
            break;
        }

        // hitung h baru dengan metode Newton-Raphson
        double h_new = h - f_val / df_val;

        // hitung error sebagai selisih mutlak antara iterasi berturut-turut
        double error = fabs(h_new - h);

        // hasil iterasi
        printf("%7d | %12.6f | %14.6f\n", iter, h_new, f_val);

        // jika error sudah lebih kecil dari toleransi, memberhentikan iterasi
        if (error < TOLERANCE) {
            return h_new;
        }

        // mengupdate nilai h untuk iterasi selanjutnya
        h = h_new;
    }

    // jika mencapai iterasi maksimum tanpa konvergen, kembalikan nilai terakhir
    printf("Peringatan: Maksimum iterasi tercapai tanpa konvergensi sempurna.\n");
    return h;
}

int main() {
    // parameter tangki bola dan volume air
    double R = 3.0;        // radius tangki bola (meter)
    double V = 30.0;       // volume air yang diinginkan (meter kubik)
    double initial_guess = 2.0;  // tebakan awal kedalaman air (meter)

    printf("Menghitung kedalaman air dalam tangki bola\n");
    printf("Radius tangki R = %.2f meter\n", R);
    printf("Volume air yang diinginkan V = %.2f m^3\n", V);
    printf("Tebakan awal kedalaman h0 = %.2f meter\n\n", initial_guess);

    // jalankan metode Newton-Raphson untuk cari kedalaman air h
    double h_solution = newton_raphson(initial_guess, R, V);

    // tampilkan hasil akhir kedalaman air dan volume pada kedalaman tersebut
    double volume_check = (PI * h_solution * h_solution * (3 * R - h_solution)) / 3.0;

    printf("\nHasil perhitungan:\n");
    printf("Kedalaman air (h) ≈ %.6f meter\n", h_solution);
    printf("Volume air pada kedalaman ini = %.6f m^3\n", volume_check);

    return 0;
}
