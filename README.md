# Kelompok 17

## Anggota Kelompok

* Audy Natalie Cecilia Rumahorbo (2306266962)
* Dwigina Sittizahwa (2306250724)
* Muhammad Pavel (2306242363)
* Nabiel Harits Utomo (2306267044)

## Perhitungan Kedalaman Air di Tangki Bola dengan Newton-Raphson
## Deskripsi Program

Program yang telah kami buat digunakan untuk menghitung **kedalaman air $h$ dalam sebuah tangki berbentuk bola** dengan radius $R$ tertentu, sehingga volume air yang ada dalam tangki mencapai volume target $V$.

Persamaan volume air dalam tangki bola diberikan oleh rumus:

$$
V = \frac{\pi h^2}{3} (3R - h)
$$

Namun karena persamaan tersebut non-linear terhadap $h$, kami menggunakan **metode numerik Newton-Raphson** untuk mencari akar dari fungsi:

$$
f(h) = \frac{\pi h^2}{3} (3R - h) - V = 0
$$

Program menerima input nilai radius $R$, volume air $V$, dan tebakan awal kedalaman $h_0$ (pada kode ini sudah diset default). Kemudian program melakukan iterasi Newton-Raphson sampai solusi $h$ yang memenuhi $f(h) \approx 0$ ditemukan dengan toleransi error tertentu.


## Penjelasan Program

Fungsi *f(h)* digunakan untuk menghitung selisih antara volume air aktual berdasarkan kedalaman $h$ dengan volume target $V$. Sedangkan fungsi *df(h)* berfungsi untuk menghitung turunan dari fungsi *f(h)* yang diperlukan dalam metode Newton-Raphson guna mempercepat pencarian akar fungsi tersebut. Fungsi *newton\_raphson()* kemudian melakukan iterasi berdasarkan metode Newton-Raphson untuk mencari nilai kedalaman $h$ yang memenuhi persamaan hingga mencapai tingkat konvergensi tertentu atau batas maksimum iterasi yang ditentukan. Program utama (*main*) bertugas mengatur parameter-parameter yang diperlukan, menjalankan metode Newton-Raphson, serta menampilkan hasil berupa kedalaman air yang ditemukan beserta volume air yang dihitung pada kedalaman tersebut. Selain itu, program juga menampilkan detail setiap iterasi, termasuk nilai $h$ dan nilai fungsi $f(h)$, sehingga proses konvergensi dapat dipantau secara langsung.


## Contoh Output Program

![image](https://hackmd.io/_uploads/Hy6LnZvzgx.png)

## Penjelasan Output Program
Output ini menggambarkan proses iterasi, dimulai dari tebakan awal hingga mencapai konvergensi, di mana nilai $h$ semakin mendekati akar fungsi sehingga nilai $f(h)$ mendekati nol. Berdasarkan data iterasi, setelah 17 langkah nilai kedalaman air stabil sekitar 2,026906 meter dengan nilai fungsi $f(h)$ yang sangat kecil, menunjukkan tingkat akurasi solusi yang sangat tinggi. Volume air yang dihitung pada kedalaman tersebut juga sangat mendekati volume target 30 m³, dengan selisih yang hampir tidak signifikan yaitu 30,000005 m³. Hal ini berarti metode Newton-Raphson mampu menyelesaikan masalah ini dengan cepat dan presisi.

## Kesimpulan
Kesimpulannya, program ini berhasil mengimplementasikan metode Newton-Raphson secara efektif untuk menyelesaikan persamaan non-linear dalam aplikasi nyata, khususnya perhitungan kedalaman air dalam tangki bola. Metode ini terbukti memiliki laju konvergensi yang cepat dan akurat dengan jumlah iterasi yang relatif sedikit. Selain itu, program juga dirancang dengan penanganan khusus terhadap kondisi kritis seperti turunan yang mendekati nol, guna mencegah kesalahan perhitungan. Dengan implementasi yang jelas serta output yang informatif, program ini memungkinkan kami untuk memantau proses iterasi secara transparan dan memperdalam pemahaman terhadap metode numerik yang kami gunakan.
