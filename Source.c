#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
typedef struct {
	int idClient;
	char numeClient[50];
	char prenumeClient[50];
	char adresaClient[50];
	int idComanda;
	char metodaPlata[50];
	char metodaLivrare[50];
	float plataRamburs;
	float plataOnline;
}Client;

void creare(char* comanda)
{
	FILE* f;
	Client x;
	f = fopen(comanda, "wb");
	if (!f)printf("\n Eroare! %s", comanda);
	else {
		printf("idClient: "); scanf("%d", &x.idClient);
		while (!feof(stdin))
		{
			printf("Nume Client "); getchar(); gets(x.numeClient);
			printf("Prenume Client: "); getchar(); gets(x.prenumeClient);
			printf("Adresa Client: "); getchar();  gets(x.adresaClient);
			printf("ID Comanda: "); scanf("%d", &x.idComanda);
			printf("Metoda de plata: "); getchar(); gets(x.metodaPlata);
			printf("Metoda de livrare: "); getchar(); gets(x.metodaLivrare);
			printf("Plata Ramburs: "); scanf("%f", &x.plataRamburs);
			printf("Plata Online: "); scanf("%f", &x.plataOnline);
			fwrite(&x, sizeof(Client), 1, f);
			printf("\n idClient: "); scanf("%d", &x.idClient);
		}
		fclose(f);
	}
}
void adaugare(char* comanda)
{
	FILE* f;
	Client x;
	f = fopen(comanda, "rb+");
	,
	if (!f)printf("\n Eroare %s!", comanda);
	else {
		printf("idClient: "); scanf("%d", &x.idClient);
		while (!feof(stdin))
		{
			printf("Nume Client "); getchar(); gets(x.numeClient);
			printf("Prenume Client: "); getchar(); gets(x.prenumeClient);
			printf("Adresa Client: "); getchar(); gets(x.adresaClient);
			printf("ID Comanda: "); scanf("%d", &x.idComanda);
			printf("Metoda de plata: "); getchar(); gets(x.metodaPlata);
			printf("Metoda de livrare: "); getchar(); gets(x.metodaLivrare);
			printf("Plata Ramburs: "); scanf("%f", &x.plataRamburs);
			printf("Plata Online: "); scanf("%f", &x.plataOnline);
			fwrite(&x, sizeof(Client), 1, f);
			printf("\n idClient: "); scanf("%d", &x.idClient);
		}
		fclose(f);
	}
}

void modificareMetodaDeLivrare(char* comanda)
{
	FILE* f;
	Client x;
	char v[50], z[50];
	int n, i;
	f = fopen(comanda, "rb+");
	if (!f)printf("\n Eroare %s!", comanda);
	else {
		printf("\n Nume Client:");
		gets(v);
		printf("\n Prenume Client: ");
		gets(z);
		while (!feof(stdin)) {
			printf("\n Metoda de livrare: "); scanf("%d", &n);
			rewind(f);
			fread(&x, sizeof(Client), 1, f);
			i = 0;
			while ((!feof(f)) && (!i))
			{
				if ((strcmp(v, z, x.numeClient, x.prenumeClient) == 0) && (n == x.metodaLivrare))
				{
					i = 1;
					printf("\n numeClient: %s prenumeClient: %s adresaClient: %s idComanda: %d, metodaPlata: %s, metodaLivrare: %s\n", x.numeClient, x.prenumeClient, x.adresaClient, x.idComanda, x.metodaPlata, x.metodaLivrare);
					printf("Modificati metoda de livrare: ");
					scanf("%s", x.metodaLivrare);
					fseek(f, ftell(f) - sizeof(Client), 0);
					fwrite(&x, sizeof(Client), 1, f);
				}
				else
					fread(&x, sizeof(Client), 1, f);
			}
			if (!i)printf("\n Comanda nu exista. \n");
			printf("\n Nume Client: "); getchar(); gets(v);
			printf("\n Prenume Client: "); getchar(); gets(z);
		}
		fclose(f);
	}
}

void stergereComanda(char* comanda)
{
	FILE* f, * g;
	Client x;
	int i, n;
	f = fopen(comanda, "rb");
	if (!f)printf("\n Eroare! %s ", comanda);
	else {
		printf("\n Comanda cu id-ul urmeaza sa fie anulata: ");
		scanf("%d", &n);
		while (!feof(stdin))
		{
			rewind(f);
			g = fopen("co.dat", "wb");
			fread(&x, sizeof(Client), 1, f);
			i = 0;
			while (!feof(f))
			{
				if (n == x.idComanda)
				{
					i = 1;
					printf("\n Comanda este anulata: ");
				}
				else if (n != x.idComanda)
				{
					fwrite(&x, sizeof(Client), 1, g);
				}
				fread(&x, sizeof(Client), 1, f);
			}
			if (!i)printf("\n Comanda nu exista! \n");
			printf("\n Introduceti id-ul comenzii de anulat: ");
			scanf("%d", &n);
			fclose(g);
		}
		fclose(f);
	}
	remove(comanda);
	rename("co.dat", comanda);
}

void listacomenzi(char* comanda)
{
	{
		FILE* f, * g;
		Client x;
		int n;
		f = fopen(comanda, "rb");
		if (!f)printf("\n Eroare! %s", comanda);
		else {
			printf("\n Fisier rezultat (text): "); gets(comanda);
			g = fopen(comanda, "w");
			fprintf(g, "\n Nr. idComanda numeClient prenumeClient adresaClient metodaPlata metodaLivrare plataRamburs plataOnline \n");
			fread(&x, sizeof(Client), 1, f);
			n = 0;
			while (!feof(f))
			{
				fprintf(g, "\n %-3d %-11d %-40s %-40s %-9d %-8d %-13d %-20d %-12d %-12d %-8d", ++n, x.idComanda, x.numeClient, x.prenumeClient, x.adresaClient, x.metodaPlata, x.metodaLivrare, x.plataRamburs, x.plataOnline);
				fread(&x, sizeof(Client), 1, f);
			}
			fclose(g);
			fclose(f);
		}
	}

}

void listarePlataOnline(char* comanda)
{
	FILE* f, * g;
	Client x;
	int n, i;
	f = fopen(comanda, "rb");
	if (!f)printf("\n Eroare! %s", comanda);
	else {
		printf("\n Lista clienti care au achitat online este mai mica de: ");
		scanf("%d", &n);
		while (!feof(stdin))
		{
			rewind(f);
			getchar();
			printf("In fisierul text: "); gets(comanda);
			g = fopen(comanda, "w");
			fread(&x, sizeof(Client), 1, f);
			i = 0;
			while (!feof(f))
			{

				if (n >x.plataOnline)
				{
					i = 1;
					fprintf(g, " \n idComanda: %-11d numeClient %-11s, prenumeClient %-11s,adresaClient %-11s, metodaLivrare %-11s, plataOnline %-8f,", x.idComanda, x.numeClient, x.prenumeClient, x.adresaClient, x.metodaLivrare, x.plataOnline);
				}
				fread(&x, sizeof(Client), 1, f);
			}
			if (!i) printf("\n Nu exista comenzi cu plata online mai mica de %d!\n", n);
			printf("\n Lista comenzi cu plata online mai mica de: ");
			scanf("%d", &n);
			fclose(g);
		}
		fclose(f);
	}
}
void vizualizarecomenzi(char* comanda)
{
	FILE* f;
	Client x;
	int i, n;
	f = fopen(comanda, "rb");
	if (!f)printf("\n Eroare!%s ", comanda);
	else {
		printf("\n Introduceti ID comanda: ");
		scanf("%d", &n);
		while (!feof(stdin))
		{
			rewind(f);
			fread(&x, sizeof(Client), 1, f);
			i = 0;
			while (!feof(f) && (!i))
			{
				if (n == x.idComanda)
				{
					i = 1;
					printf("\n numeClient: %s, prenumeClient: %s,  adresaClient: %s \n", x.numeClient, x.prenumeClient, x.adresaClient);
				}
				fread(&x, sizeof(Client), 1, f);
			}
			if (!i) printf("\n Comanda nu a fost gasita!\n");
			printf("\n Introduceti un nou ID comanda: ");
			scanf("%d", &n);
		}
		fclose(f);
	}
}

void main()
{
	char comanda[50];
	int k = 14;
	printf("\n Alegeti o optiune:\n");
	{
		printf(" 1. Creare fisier lista comenzi \n");
		printf(" 2. Adaugare o comanda noua \n");
		printf(" 3. Modificare metoda de livrare \n");
		printf(" 4. Anulare comanda existenta \n");
		printf(" 5. Lista cu toate comenzile \n");
		printf(" 6. Lista cu clientii care au achitat online \n");
		printf(" 7. Viualizare detalii comenzi \n");
		printf(" 8. Iesire meniu \n");
		printf("\n \n Numarul optiunii este: ");
		scanf("%d", &k);
		switch (k) {
		case 1:
			printf("\n\n Denumire fisier: "); getchar(); gets(comanda);
			creare(comanda);
			break;
		case 2:
			printf("\n\n Adaugare comanda noua in fisierul: "); getchar(); gets(comanda); adaugare(comanda);
			break;
		case 3:
			printf("\n\n Modificare metoda de livrare: ");  getchar(); gets(comanda); modificareMetodaDeLivrare(comanda);
			break;
		case 4:
			printf("\n\n  Anulare comanda existenta: "); getchar(); gets(comanda); stergereComanda(comanda);
			break;
		case 5:
			printf(" \n\n Generare lista cu toate comenzile: "); getchar(); gets(comanda); listacomenzi(comanda);
			break;
		case 6:
			printf("\n\n Generare lista cu clientii care au achitat online: "); getchar(); gets(comanda); listarePlataOnline(comanda);
			break;
		case 7:
			printf("\n\n Vizualizare detalii comenzi: "); getchar(); gets(comanda); vizualizarecomenzi(comanda);
			break;
		case 8:
			printf("Aplicatie inchisa cu succes! \n");
			break;

		}
	}
}