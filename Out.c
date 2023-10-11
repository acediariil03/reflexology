#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

struct pijet
{
	char type[200][200], layanan[200][200];
	int harga[100], waktu[100], hasil;

} pijet;
struct pembelian
{
	char namaCus[200];
	int berapaBanyak, layanan, pilih[100];
	int terjual[100];
	int tanggal, bulan, tahun;

} pem;
struct data_short
{
	int terjual[100];
} jual;

void bubbleSort()
{
	int tampung, tampung1, tampung2;
	char tampungN[200];
	for (int i = 0; i < 15 - 1; i++)
	{
		for (int j = 0; j < 15 - 1; j++)
		{
			if (jual.terjual[j] < jual.terjual[j + 1])
			{
				tampung = jual.terjual[j];
				jual.terjual[j] = jual.terjual[j + 1];
				jual.terjual[j + 1] = tampung;

				tampung1 = pijet.harga[j];
				pijet.harga[j] = pijet.harga[j + 1];
				pijet.harga[j + 1] = tampung1;

				strcpy(tampungN, pijet.layanan[j]);
				strcpy(pijet.layanan[j], pijet.layanan[j + 1]);
				strcpy(pijet.layanan[j + 1], tampungN);
			}
		}
	}
}

void sales()
{
	FILE *p1, *p2;

	p1 = fopen("sales.txt", "a");
	fprintf(p1, "%d/%d/%d,", pem.tanggal, pem.bulan, pem.tahun);
	fprintf(p1, "%s,", pem.namaCus);
	fprintf(p1, "%s,", pijet.type[pem.layanan - 1]);
	for (int i = 0; i < pem.berapaBanyak; i++)
	{
		fprintf(p1, "%s,%d.000,", pijet.layanan[pem.pilih[i] - 1], pijet.harga[pem.pilih[i] - 1]);
		pem.terjual[pem.pilih[i] - 1] = 1;
	}
	for (int i = 0; i < pem.berapaBanyak; i++)
	{
		fprintf(p1, "%d,", pem.terjual[pem.pilih[i] - 1]);
	}
	fprintf(p1, "%d.000\n", pijet.hasil);
	fclose(p1);

	p2 = fopen("data_pem.txt", "a");
	fwrite(&pem, sizeof(struct pembelian), 1, p2);
	fclose(p2);
}

void kasir()
{
	FILE *p1;
	p1 = fopen("data_pijet.txt", "r"); //pointer p1 membaca semua data file yg ada di data_pijet.txt
	printf("\nMasukan Nama Customer : ");
	scanf("\n%[^\n]", pem.namaCus);

	fread(&pijet, sizeof(struct pijet), 1, p1); //membaca semua data yg ada di file data_pijet.txt lalu dimasukkan dlm data struct pijet
	for (int i = 0; i < 15; i++) //fungsi 1 utk ngebaca bnyk perhitungan 
	{
		pem.terjual[i] = 0;
	}

	for (int i = 0; i < 5; i++)
	{
		printf("[%d] %s Treatment\n", i + 1, pijet.type[i]);
	}
	printf("\nMasukan Angka : ");
	scanf("%d", &pem.layanan);
	printf("\n");

	switch (pem.layanan) //operator
	{
	case 1: //operand
		for (int i = 0; i < 3; i++)
		{
			printf("[%d] %s Rp %d.000\n", i + 1, pijet.layanan[i], pijet.harga[i]);
		}

		printf("\nBerapa Banyak Menu Yang Ingin Di Pesan : ");
		scanf("%d", &pem.berapaBanyak);
		printf("\nPilih Menu Sesuai Dengan Angka : ");

		for (int i = 0; i < pem.berapaBanyak; i++)
		{
			scanf("%d", &pem.pilih[i]);
			pijet.hasil += pijet.harga[pem.pilih[i] - 1];
		}
		printf("========================================================\n");
		printf("                   Total Pembayaran\n");
		printf("========================================================\n");
		printf("Tanggal Transaksi : %d - %d - %d\n\n", pem.tanggal, pem.bulan, pem.tahun);
		printf("Nama Customer : %s\n", pem.namaCus);
		printf("\nTipe layanan : %s Treatment \n\n", pijet.type[pem.layanan - 1]);
		for (int i = 0; i < pem.berapaBanyak; i++)
		{
			printf("- %s Rp %d.000\n", pijet.layanan[pem.pilih[i] - 1], pijet.harga[pem.pilih[i] - 1]);
			pem.terjual[pem.pilih[i] - 1] += 1;
		}

		printf("\n========================================================\n");
		printf("Total Pembayaran : Rp %d.000\n", pijet.hasil);
		printf("========================================================\n");
		sales();
		break;
	case 2:
		for (int i = 3; i < 6; i++)
		{
			printf("[%d] %s Rp %d.000\n", i + 1, pijet.layanan[i], pijet.harga[i]);
		}

		printf("\nBerapa Banyak Menu Yang Ingin Di Pesan : ");
		scanf("%d", &pem.berapaBanyak);
		printf("\nPilih Menu Sesuai Dengan Angka : ");

		for (int i = 0; i < pem.berapaBanyak; i++)
		{
			scanf("%d", &pem.pilih[i]);
			pijet.hasil += pijet.harga[pem.pilih[i] - 1];
		}
		printf("========================================================\n");
		printf("                   Total Pembayaran\n");
		printf("========================================================\n");
		printf("Tanggal Transaksi : %d - %d - %d\n\n", pem.tanggal, pem.bulan, pem.tahun);
		printf("Nama Customer : %s\n", pem.namaCus);
		printf("\nTipe layanan : %s Treatment \n\n", pijet.type[pem.layanan - 1]);
		for (int i = 0; i < pem.berapaBanyak; i++)
		{
			printf("- %s Rp %d.000\n", pijet.layanan[pem.pilih[i] - 1], pijet.harga[pem.pilih[i] - 1]);
			pem.terjual[pem.pilih[i] - 1] += 1;
		}

		printf("\n========================================================\n");
		printf("Total Pembayaran : Rp %d.000\n", pijet.hasil);
		printf("========================================================\n");
		sales();
		break;
	case 3:
		for (int i = 6; i < 9; i++)
		{
			printf("[%d] %s Rp %d.000\n", i + 1, pijet.layanan[i], pijet.harga[i]);
		}

		printf("\nBerapa Banyak Menu Yang Ingin Di Pesan : ");
		scanf("%d", &pem.berapaBanyak);
		printf("\nPilih Menu Sesuai Dengan Angka : ");

		for (int i = 0; i < pem.berapaBanyak; i++)
		{
			scanf("%d", &pem.pilih[i]);
			pijet.hasil += pijet.harga[pem.pilih[i] - 1];
		}
		printf("========================================================\n");
		printf("                   Total Pembayaran\n");
		printf("========================================================\n");
		printf("Tanggal Transaksi : %d - %d - %d\n\n", pem.tanggal, pem.bulan, pem.tahun);
		printf("Nama Customer : %s\n", pem.namaCus);
		printf("\nTipe layanan : %s Treatment \n\n", pijet.type[pem.layanan - 1]);
		for (int i = 0; i < pem.berapaBanyak; i++)
		{
			printf("- %s Rp %d.000\n", pijet.layanan[pem.pilih[i] - 1], pijet.harga[pem.pilih[i] - 1]);
			pem.terjual[pem.pilih[i] - 1] += 1;
		}

		printf("\n========================================================\n");
		printf("Total Pembayaran : Rp %d.000\n", pijet.hasil);
		printf("========================================================\n");
		sales();
		break;
	case 4:
		for (int i = 9; i < 12; i++)
		{
			printf("[%d] %s Rp %d.000\n", i + 1, pijet.layanan[i], pijet.harga[i]);
		}

		printf("\nBerapa Banyak Menu Yang Ingin Di Pesan : ");
		scanf("%d", &pem.berapaBanyak);
		printf("\nPilih Menu Sesuai Dengan Angka : ");

		for (int i = 0; i < pem.berapaBanyak; i++)
		{
			scanf("%d", &pem.pilih[i]);
			pijet.hasil += pijet.harga[pem.pilih[i] - 1];
		}
		printf("========================================================\n");
		printf("                   Total Pembayaran\n");
		printf("========================================================\n");
		printf("Tanggal Transaksi : %d - %d - %d\n\n", pem.tanggal, pem.bulan, pem.tahun);
		printf("Nama Customer : %s\n", pem.namaCus);
		printf("\nTipe layanan : %s Treatment \n\n", pijet.type[pem.layanan - 1]);
		for (int i = 0; i < pem.berapaBanyak; i++)
		{
			printf("- %s Rp %d.000\n", pijet.layanan[pem.pilih[i] - 1], pijet.harga[pem.pilih[i] - 1]);
			pem.terjual[pem.pilih[i] - 1] += 1;
		}

		printf("\n========================================================\n");
		printf("Total Pembayaran : Rp %d.000\n", pijet.hasil);
		printf("========================================================\n");
		sales();
		break;
	case 5:
		for (int i = 12; i < 15; i++)
		{
			printf("[%d] %s Rp %d.000\n", i + 1, pijet.layanan[i], pijet.harga[i]);
		}

		printf("\nBerapa Banyak Menu Yang Ingin Di Pesan : ");
		scanf("%d", &pem.berapaBanyak);
		printf("\nPilih Menu Sesuai Dengan Angka : ");

		for (int i = 0; i < pem.berapaBanyak; i++)
		{
			scanf("%d", &pem.pilih[i]);
			pijet.hasil += pijet.harga[pem.pilih[i] - 1];
		}
		printf("========================================================\n");
		printf("                   Total Pembayaran\n");
		printf("========================================================\n");
		printf("Tanggal Transaksi : %d - %d - %d\n\n", pem.tanggal, pem.bulan, pem.tahun);
		printf("Nama Customer : %s\n", pem.namaCus);
		printf("\nTipe layanan : %s Treatment \n\n", pijet.type[pem.layanan - 1]);
		for (int i = 0; i < pem.berapaBanyak; i++)
		{
			printf("- %s Rp %d.000\n", pijet.layanan[pem.pilih[i] - 1], pijet.harga[pem.pilih[i] - 1]);
			pem.terjual[pem.pilih[i] - 1] += 1;
		}

		printf("\n========================================================\n");
		printf("Total Pembayaran : Rp %d.000\n", pijet.hasil);
		printf("========================================================\n");
		sales();
		break;
	}
}

void SortByMost()
{

	FILE *p1, *p2;
	printf("========================================================\n");
	printf("                     Data Shorting\n");
	printf("========================================================\n");
	p1 = fopen("data_pem.txt", "r");
	p2 = fopen("data_pijet.txt", "r");
	fread(&pijet, sizeof(struct pijet), 1, p2);

	for (int i = 0; i < 15; i++)
	{
		jual.terjual[i] = 0;
	}

	while (fread(&pem, sizeof(struct pembelian), 1, p1))
	{
		for (int i = 0; i < 15; i++)
		{
			jual.terjual[i] += pem.terjual[i];
		}
	}

	fread(&pem, sizeof(struct pembelian), 1, p1);
	bubbleSort();
	for (int i = 0; i < 3; i++)
	{
		printf("\n- %s Rp %d.000\n", pijet.layanan[i], pijet.harga[i]);
		printf("  Terjual Sebanyak : %d\n", jual.terjual[i]);
		printf("\n========================================================\n");
	}
	for (int i = 3; i < 6; i++)
	{
		printf("\n- %s Rp %d.000\n", pijet.layanan[i], pijet.harga[i]);
		printf("  Terjual Sebanyak : %d\n", jual.terjual[i]);
		printf("\n========================================================\n");
	}
	for (int i = 6; i < 9; i++)
	{
		printf("\n- %s Rp %d.000\n", pijet.layanan[i], pijet.harga[i]);
		printf("  Terjual Sebanyak : %d\n", jual.terjual[i]);
		printf("\n========================================================\n");
	}
	for (int i = 9; i < 12; i++)
	{
		printf("\n- %s Rp %d.000\n", pijet.layanan[i], pijet.harga[i]);
		printf("  Terjual Sebanyak : %d\n", jual.terjual[i]);
		printf("\n========================================================\n");
	}
	for (int i = 12; i < 15; i++)
	{
		printf("\n- %s Rp %d.000\n", pijet.layanan[i], pijet.harga[i]);
		printf("  Terjual Sebanyak : %d\n", jual.terjual[i]);
		printf("\n========================================================\n");
	}
	printf("Total Pembayaran : Rp %d.000\n");
	printf("========================================================\n");
}

void sortByDate()
{
	struct tm *Sys_T;

	time_t Tval;
	Tval = time(NULL);
	Sys_T = localtime(&Tval);
	int total = 0;

	FILE *p1, *p2;
	printf("========================================================\n");
	printf("                   Transaksi Perhari\n");
	printf("========================================================\n");
	p1 = fopen("data_pem.txt", "r");
	p2 = fopen("data_pijet.txt", "r");
	fread(&pijet, sizeof(struct pijet), 1, p2);
	while (fread(&pem, sizeof(struct pembelian), 1, p1))
	{
		printf("Tanggal Transaksi : %d - %d - %d\n\n", pem.tanggal, pem.bulan, pem.tahun);
		printf("--------------------------------------------------------");
		printf("\nNama Customer : %s\n", pem.namaCus);
		printf("\nTipe layanan : %s Treatment \n\n", pijet.type[pem.layanan - 1]);
		for (int i = 0; i < pem.berapaBanyak; i++)
		{
			printf("- %s Rp %d.000\n", pijet.layanan[pem.pilih[i] - 1], pijet.harga[pem.pilih[i] - 1]);
			total += pijet.harga[pem.pilih[i] - 1];
		}
	}
	printf("\n========================================================\n");
	printf("Total Pembayaran : Rp %d.000\n", total);
	printf("========================================================\n");
}
int main()
{
	struct tm *Sys_T;

	time_t Tval;
	Tval = time(NULL);
	Sys_T = localtime(&Tval);

	pem.tanggal = Sys_T->tm_mday;
	pem.bulan = Sys_T->tm_mon + 1;
	pem.tahun = 1900 + Sys_T->tm_year;

	int pilihM, pilihZ;

	pijet.hasil = 0;
	FILE *p1;
back:
system("cls");
	printf("\n=======================================================\n");
	printf("Selamat datang di Reflexology Center Malang\n");
	printf("Silahkan memilih layanan yang tersedia dibawah ini");
	printf("\n=======================================================\n");
	printf("[1] Input Menu Pijat\n");
	printf("[2] Data Harian\n");
	printf("[3] Semua Data\n");
	printf("[4] Exit\n");
	printf("Pilih Menu : ");
	scanf("%d", &pilihM);
	switch (pilihM)
	{
	case 1:
		kasir();
		printf("Yakin Ingin Keluar : \n");
		printf("[1] Yes\n");
		printf("[2] No\n");
		printf("Pilih Menu : ");
		scanf("%d", &pilihZ);
		if (pilihZ == 1)
		{
			goto exit;
		}
		else
		{
			goto back;
		}

		break;
	case 2:
		sortByDate();
		printf("Yakin Ingin Keluar : \n");
		printf("[1] Yes\n");
		printf("[2] No\n");
		printf("Pilih Menu : ");
		scanf("%d", &pilihZ);
		if (pilihZ == 1)
		{
			goto exit;
		}
		else
		{
			goto back;
		}
		break;
	case 3:
		SortByMost();
		printf("Yakin Ingin Keluar : \n");
		printf("[1] Yes\n");
		printf("[2] No\n");
		printf("Pilih Menu : ");
		scanf("%d", &pilihZ);
		if (pilihZ == 1)
		{
			goto exit;
		}
		else
		{
			goto back;
		}
		break;
	case 4:
		printf("Yakin Ingin Keluar : \n");
		printf("[1] Yes\n");
		printf("[2] No\n");
		printf("Pilih Menu : ");
		scanf("%d", &pilihZ);
		if (pilihZ == 1)
		{
			goto exit;
		}
		else
		{
			goto back;
		}
	exit:
		exit(0);
		break;
	default:
		break;
	}
}
