#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define Maksimal_Karyawan 100
#define Maksimal_Izin 100

typedef struct {
    char id[10];
    char nama[50];
    char jenis_kelamin[10];
    int sisa_izin;
    int hadir;
    bool absen;
} Karyawan;


typedef struct {
    char id[10];
    char jenis[20];
    char alasan[100];
    int durasi;
    char tanggal_mulai[10];
    char tanggal_selesai[10];
} Izin;

// Prosedur untuk menambahkan data karyawan
void tambahKaryawan(Karyawan *karyawan, int *jumlah_karyawan) {
    Karyawan krywn;

    printf("\t=========================================================================================\n");
    printf("\t|                               -- Tambah Karyawan --                                   |\n");
    printf("\t=========================================================================================\n");

    printf("\tNomor identitas: ");
    scanf("%s", krywn.id);
    printf("\tNama: ");
    scanf("%s", krywn.nama);
    printf("\tJenis kelamin:\n");
    printf("\t1. Pria\n");
    printf("\t2. Wanita\n");
    printf("\tPilihan: ");
    int pilihan_jk;
    scanf("%d", &pilihan_jk);
    if (pilihan_jk == 1) {
        strcpy(krywn.jenis_kelamin, "Pria");
    } else if (pilihan_jk == 2) {
        strcpy(krywn.jenis_kelamin, "Wanita");
    } else {
        printf("\tPilihan jenis kelamin tidak valid.\n");
        return;
    }
    printf("\tIzin Tahunan (Hari): ");
    scanf("%d", &krywn.sisa_izin);
    krywn.hadir = 0;

    karyawan[*jumlah_karyawan] = krywn;
    (*jumlah_karyawan)++;

    printf("\tData karyawan berhasil ditambahkan.\n");
    system("cls");
}

// Prosedur untuk mengajukan Absensi Karyawan
void absensiKaryawan(Karyawan *karyawan, int jumlah_karyawan) {
    printf("\t=========================================================================================\n");
    printf("\t|                              -- Menu Absensi Karyawan --                              |\n");
    printf("\t=========================================================================================\n");

    printf("\tNomor identitas: ");
    char id[10];
    scanf("%s", id);

    int indeks_karyawan = -1;
    for (int i = 0; i < jumlah_karyawan; i++) {
        if (strcmp(karyawan[i].id, id) == 0) {
            indeks_karyawan = i;
            break;
        }
    }

    if (indeks_karyawan == -1) {
        printf("\tNomor identitas tidak ditemukan.\n");
        return;
    }
    karyawan[indeks_karyawan].absen = true; // Setel nilai absen menjadi true
    printf("\tNama: %s\n", karyawan[indeks_karyawan].nama);
    printf("\tJenis kelamin: %s\n", karyawan[indeks_karyawan].jenis_kelamin);
    printf("\tSisa izin: %d\n", karyawan[indeks_karyawan].sisa_izin);

    printf("\tAbsensi berhasil dicatat.\n\n");
    system("cls");
}

// Prosedur untuk mengajukan izin/cuti karyawan
void ajukanIzin(Karyawan *karyawan, int jumlah_karyawan, Izin *izin, int *jumlah_izin) {
    Izin i;
    int indeks_karyawan = -1;
    int pilihan;

    printf("\t=========================================================================================\n");
    printf("\t|                                -- Ajukan Izin/Cuti --                                 |\n");
    printf("\t=========================================================================================\n");

    printf("\tNomor identitas: ");
    scanf("%s", i.id);

    for (int j = 0; j < jumlah_karyawan; j++) {
        if (strcmp(karyawan[j].id, i.id) == 0) {
            indeks_karyawan = j;
            break;
        }
    }

    if (indeks_karyawan == -1) {
        printf("\tNomor identitas tidak ditemukan.\n");
        return;
    }

    printf("\tNama: %s\n", karyawan[indeks_karyawan].nama);
    printf("\tJenis kelamin: %s\n", karyawan[indeks_karyawan].jenis_kelamin);
    printf("\tSisa izin: %d\n\n", karyawan[indeks_karyawan].sisa_izin);

    printf("\tJenis Izin/Cuti:\n\n");
    printf("\t1. Cuti Tahunan\n");
    printf("\t2. Cuti Sakit\n");
    printf("\t3. Cuti Melahirkan\n");
    printf("\t4. Izin\n");
    printf("\tPilihan: ");
    scanf("%d", &pilihan);

    switch (pilihan) {
        case 1:
            printf("\tDurasi Cuti (dalam hari): ");
            scanf("%d", &i.durasi);
            printf("\tTanggal Mulai Cuti (dd/mm/yy): ");
            scanf("%s", i.tanggal_mulai);
            printf("\tTanggal Akhir Cuti (dd/mm/yy): ");
            scanf("%s", i.tanggal_selesai);
            strcpy(i.jenis, "Cuti Tahunan");
            break;
        case 2:
            printf("\tDurasi Cuti (dalam hari, 1-14): ");
            scanf("%d", &i.durasi);
            if (i.durasi < 1 || i.durasi > 14) {
                printf("Durasi cuti sakit tidak valid.\n");
                return;
            }
            printf("\tTanggal Mulai Cuti (dd/mm/yy): ");
            scanf("%s", i.tanggal_mulai);
            printf("\tTanggal Akhir Cuti (dd/mm/yy): ");
            scanf("%s", i.tanggal_selesai);
            strcpy(i.jenis, "Cuti Sakit");
            break;
        case 3:
            if (strcmp(karyawan[indeks_karyawan].jenis_kelamin, "Wanita") != 0) {
                printf("\tOpsi cuti melahirkan hanya tersedia untuk karyawan Wanita.\n");
                return;
            }
            printf("\tDurasi Cuti (dalam bulan, maksimal 3 bulan): ");
            scanf("%d", &i.durasi);
            if (i.durasi > 3) {
                printf("\tDurasi cuti melahirkan melebihi batas maksimal.\n");
                return;
            }
            printf("\tTanggal Mulai Cuti (dd/mm/yy): ");
            scanf("%s", i.tanggal_mulai);
            printf("\tTanggal Akhir Cuti (dd/mm/yy): ");
            scanf("%s", i.tanggal_selesai);
            strcpy(i.jenis, "Cuti Melahirkan");
            break;
        case 4:
            printf("\tDurasi Izin (dalam hari): ");
            scanf("%d", &i.durasi);
            printf("\tTanggal Mulai Izin (dd/mm/yy): ");
            scanf("%s", i.tanggal_mulai);
            printf("\tTanggal Akhir Izin (dd/mm/yy)): ");
            scanf("%s", i.tanggal_selesai);
            printf("\tAlasan Izin: ");
            scanf("%s", i.alasan);
            strcpy(i.jenis, "Izin");
        break;
        default:
            printf("\tPilihan tidak valid.\n");
            return;
    }

    if (i.durasi > karyawan[indeks_karyawan].sisa_izin && strcmp(i.jenis, "Cuti Tahunan") == 0) {
        printf("\tSisa izin tidak mencukupi.\n");
        return;
    }

    if (strcmp(i.jenis, "Cuti Tahunan") == 0) {
        karyawan[indeks_karyawan].sisa_izin -= i.durasi;
    }

    izin[*jumlah_izin] = i;
    (*jumlah_izin)++;

    printf("\tIzin/cuti berhasil diajukan.\n");
    system("cls");
}
    // Prosedur Untuk Recap Data Kehadiran
    void recapDataKehadiran(Karyawan *karyawan, int jumlah_karyawan, Izin *izin, int jumlah_izin) {
    printf("\t=========================================================================================\n");
    printf("\t|                    -- Data Karyawan dan Izin/Cuti Terkini --                          |\n");
    printf("\t=========================================================================================\n");
    printf("\tNo  | Nomor ID | Nama                 | Jenis Kelamin | Sisa Izin | Status Absen\n");
    printf("\t-----------------------------------------------------------------------------------------\n");
    for (int j = 0; j < jumlah_karyawan; j++) {
    printf("\t%-3d | %-8s | %-20s | %-13s | %-9d | %s\n", j + 1, karyawan[j].id, karyawan[j].nama, karyawan[j].jenis_kelamin, karyawan[j].sisa_izin, karyawan[j].absen ? "Hadir" : "Tidak Hadir");
    }
    printf("\t-----------------------------------------------------------------------------------------\n");
    printf("\t=========================================================================================\n");
    printf("\t|                            -- Daftar Izin/Cuti: --                                    |\n");
    printf("\t=========================================================================================\n");
    printf("\tNo  | Nomor ID | Jenis Izin           | Tanggal Mulai  | Tanggal Akhir  | Durasi | Alasan\n");
    printf("\t-----------------------------------------------------------------------------------------\n");
    for (int j = 0; j < jumlah_izin; j++) {
        if (strcmp(izin[j].jenis, "Izin") == 0) {
            printf("\t%-3d | %-8s | %-20s | %-14s | %-14s | %-6d | %-s\n", j + 1, izin[j].id, izin[j].jenis, izin[j].tanggal_mulai, izin[j].tanggal_selesai, izin[j].durasi, izin[j].alasan);
        } else {
            printf("\t%-3d | %-8s | %-20s | %-14s | %-14s | %-6d | -\n", j + 1, izin[j].id, izin[j].jenis, izin[j].tanggal_mulai, izin[j].tanggal_selesai, izin[j].durasi);
        }
    }
    printf("\t-----------------------------------------------------------------------------------------\n\n");
}

void main() {
    Karyawan karyawan[Maksimal_Karyawan];
    Izin izin[Maksimal_Izin];
    int jumlah_karyawan = 0;
    int jumlah_izin = 0;
    int pilihan;

    do {
        printf("\t=========================================================================================\n");
        printf("\t|                               Program Absensi Karyawan                                |\n");
        printf("\t|                                       Kelompok 2 :                                    |\n");
        printf("\t|                               -Ibrahim Haykal(1322043)                                |\n");
        printf("\t|                               -Aura Maylicha(1322042)                                 |\n");
        printf("\t|                               -Zahra Anggraini(1322037)                               |\n");
        printf("\t|                               -Gilang Nur Mauladi(1322052)                            |\n");
        printf("\t=========================================================================================\n");
        printf("\t1. Tambah Karyawan\n");
        printf("\t2. Absensi Karyawan\n");
        printf("\t3. Pengajuan Izin/Cuti\n");
        printf("\t4. Recap Data Kehadiran Karyawan\n");
        printf("\t0. Keluar\n");
        printf("\tPilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahKaryawan(karyawan, &jumlah_karyawan);
                break;
            case 2:
                absensiKaryawan(karyawan, jumlah_karyawan);
                break;
            case 3:
                ajukanIzin(karyawan, jumlah_karyawan, izin, &jumlah_izin);
                break;
            case 4:
                recapDataKehadiran(karyawan, jumlah_karyawan, izin, jumlah_izin);
                break;
            case 0:
                printf("\tTerima kasih Telah Menggunakan Program Ini. Sampai jumpa!\n");
                break;
            default:
                printf("\tPilihan tidak valid.\n");
                break;
        }
    } while (pilihan != 0);
}
