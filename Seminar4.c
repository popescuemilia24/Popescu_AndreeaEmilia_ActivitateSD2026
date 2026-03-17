//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//struct StructuraMasina {
//	int id;
//	int nrUsi;
//	float pret;
//	char* model;
//	char* numeSofer;
//	unsigned char serie;
//};
//typedef struct StructuraMasina Masina;
//typedef struct Nod Nod;
//struct Nod {
//	Masina info;
//	Nod* next;
//};
//
//
//Masina citireMasinaDinFisier(FILE* file) {
//	char buffer[100];
//	char sep[3] = ",\n";
//	fgets(buffer, 100, file);
//	char* aux;
//	Masina m1;
//	aux = strtok(buffer, sep);
//	m1.id = atoi(aux);
//	m1.nrUsi = atoi(strtok(NULL, sep));
//	m1.pret = atof(strtok(NULL, sep));
//	aux = strtok(NULL, sep);
//	m1.model = malloc(strlen(aux) + 1);
//	strcpy_s(m1.model, strlen(aux) + 1, aux);
//
//	aux = strtok(NULL, sep);
//	m1.numeSofer = malloc(strlen(aux) + 1);
//	strcpy_s(m1.numeSofer, strlen(aux) + 1, aux);
//
//	m1.serie = *strtok(NULL, sep);
//	return m1;
//}
//
//void afisareMasina(Masina masina) {
//	printf("Id: %d\n", masina.id);
//	printf("Nr. usi : %d\n", masina.nrUsi);
//	printf("Pret: %.2f\n", masina.pret);
//	printf("Model: %s\n", masina.model);
//	printf("Nume sofer: %s\n", masina.numeSofer);
//	printf("Serie: %c\n\n", masina.serie);
//}
//
//void afisareListaMasini(Nod* cap) {
//	while (cap != NULL) {
//		afisareMasina(cap->info);
//		cap = cap->next;
//	}
//}
//
//void adaugaMasinaInLista(Nod** cap, Masina masinaNoua) {
//	//** pt ca daca lista e vida, trebuie sa modificam adresa lui cap, sa adaugam o prima adresa
//
//	Nod* nodNou = (Nod*)malloc(sizeof(Nod));
//	nodNou->info = masinaNoua;
//	nodNou->next = NULL;
//	if ((*cap) == NULL) {
//		(*cap) = nodNou;
//	}
//
//	else {
//		Nod* aux = (*cap);
//		while (aux->next != NULL) {
//			aux = aux->next;
//		}
//		aux->next = nodNou;
//	}
//}
//
//void adaugaLaInceputInLista(Nod** cap, Masina masinaNoua) {
//	Nod* nodNou = (Nod*)malloc(sizeof(Nod));
//	nodNou->info = masinaNoua;
//	nodNou->next = *cap;
//	*cap = nodNou;
//}
//
//Nod* citireListaMasiniDinFisier(const char* numeFisier) {
//	FILE* file = fopen(numeFisier, "r");
//	if (file) {
//		Nod* cap = NULL;
//		while (!feof(file)) {
//			adaugaMasinaInLista(&cap, citireMasinaDinFisier(file));
//		}
//		fclose(file);
//		return cap;
//	}
//	return NULL;
//
//}
//
//void dezalocareListaMasini(Nod** cap) {
//	while (*cap) {
//		Nod* p = *cap;
//		(*cap) = p->next;
//		if (p->info.numeSofer) {
//			free(p->info.numeSofer);
//		}
//		if (p->info.model) {
//			free(p->info.model);
//		}
//		free(p);
//	}
//
//}
//
//float calculeazaPretMediu(Nod* cap) {
//
//	float suma = 0;
//	int contor = 0;
//
//	while (cap) {
//		contor++;
//		suma = suma + (cap->info.pret);
//		cap = cap->next;
//	}
//	if (contor != 0)
//		return suma / contor;
//
//	return 0;
//}
//
//void stergeMasiniDinSeria(Nod** cap, char serieCautata) {
//
//	while ((*cap) && (*cap)->info.serie == serieCautata) {
//		Nod* temp = *cap;
//		(*cap) = temp->next;
//		if (temp->info.numeSofer)
//			free(temp->info.numeSofer);
//		if (temp->info.model)
//			free(temp->info.model);
//	}
//
//	Nod* p = *cap;
//	while (p) {
//		while (p->next && p->next->info.serie != serieCautata) {
//			p = p->next;
//		}
//
//		if (p->next) {
//			Nod* temp = p->next;
//			p->next = temp->next;
//
//			if (temp->info.model) {
//				free(temp->info.model);
//			}
//			if (temp->info.numeSofer)
//				free(temp->info.numeSofer);
//			free(temp);
//		}
//		else {
//			p = p->next;
//		}
//	}
//}
//
//float calculeazaPretulMasinilorUnuiSofer(/*lista masini*/ const char* numeSofer) {
//	//calculeaza pretul tuturor masinilor unui sofer.
//	return 0;
//}
//
//int main() {
//
//	Nod* cap = NULL;
//	cap = citireListaMasiniDinFisier("masini.txt");
//	afisareListaMasini(cap);
//
//
//
//	printf("Pretul mediu=%5.2f\n", calculeazaPretMediu(cap));
//
//
//	printf("Stergere serie A\n");
//	stergeMasiniDinSeria(&cap, 'A');
//
//	printf("\nLista dupa stegre A\n");
//	afisareListaMasini(cap);
//
//	dezalocareListaMasini(&cap);
//	printf("\nLista dupa dezalocare\n");
//	afisareListaMasini(cap);
//	return 0;
//
//}
//
////lista = structura de date omogena, liniara, in care fiecare elem retine adresa urmatorului element
////void* = pointer generic, adica permite sa fie pointer la orice tip si face conversie implicit catre acel tip



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct StructuraZbor {
	int id;
	int nrPasageri;
	float durata;
	char* aeroportPlecare;
	char* aeroportSosire;
	unsigned char status; // 0=la timp, 1=întârziat, 2=anulat
};
typedef struct StructuraZbor Zbor;

typedef struct Nod Nod;
struct Nod
{
	Zbor info;
	Nod* next;
};



Zbor citireZborFisier(FILE* file) {
	Zbor z;
	char buffer[100];
	char sep[3] = ",\n";
	fgets(buffer, 100, file);
	z.id = atoi(strtok(buffer, sep));
	z.nrPasageri = atoi(strtok(NULL, sep));
	z.durata = atof(strtok(NULL, sep));
	char* aux = strtok(NULL, sep);
	z.aeroportPlecare = (char*)malloc(sizeof(char) * (strlen(aux) + 1));
	strcpy_s(z.aeroportPlecare, strlen(aux) + 1, aux);
	aux = strtok(NULL, sep);
	z.aeroportSosire = (char*)malloc(sizeof(char) * (strlen(aux) + 1));
	strcpy_s(z.aeroportSosire, strlen(aux) + 1, aux);
	z.status = (strtok(NULL, sep))[0];
	return z;
}

void afisareZbor(Zbor zbor) {
	printf("ID: %d\n", zbor.id);
	printf("PASAGERI: %d\n", zbor.nrPasageri);
	printf("DURATA: %.2f\n", zbor.durata);
	printf("PLECARE: %s\n", zbor.aeroportPlecare);
	printf("SOSIRE: %s\n", zbor.aeroportSosire);
	printf("STATUS: %c\n\n", zbor.status);
}

void afisareListaZbor(Nod* cap) {
	while (cap != NULL)
	{
		afisareZbor(cap->info);
		cap = cap->next;
	}
}

void adaugaZborInLista(Nod** cap, Zbor ZborNou) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));

	nou->info = ZborNou;
	nou->next = NULL;

	if (*cap == NULL)
	{
		(*cap) = nou;
	}
	else {
		Nod* c = *cap;
		while (c->next != NULL)
		{
			c = c->next;
		}
		c->next = nou;
	}

}

void adaugaLaInceputInLista(Nod** cap, Zbor ZborNou) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = ZborNou;
	nou->next = *cap;
	*cap = nou;

}

Nod* citireListaZborDinFisier(const char* numeFisier) {
	FILE* f = fopen(numeFisier, "r");

	if (f)
	{
		Nod* cap = NULL;
		while (!feof(f))
		{
			adaugaZborInLista(&cap, citireZborFisier(f));
		}
		fclose(f);
		return cap;
	}
	return NULL;
}

void dezalocareListaZbor(Nod** cap) {
	while (*cap)
	{
		Nod* c = *cap;
		(*cap) = c->next;
		if (c->info.aeroportPlecare)
		{
			free(c->info.aeroportPlecare);
		}
		if (c->info.aeroportSosire)
		{
			free(c->info.aeroportSosire);
		}
		free(c);

	}
}

float calculeazaDurataMedie(Nod* cap) {
	float sum = 0;
	int k = 0;

	while (cap)
	{
		sum += cap->info.durata;
		k++;
		cap = cap->next;
	}
	if (k != 0)
	{
		return sum / k;
	}

	return 0;
}

void stergeZborCuStatus(Nod** cap, char statusCautat) {
	while ((*cap) && (*cap)->info.status == statusCautat) {
		Nod* c = *cap;
		(*cap) = c->next;
		if (c->info.aeroportPlecare)
			free(c->info.aeroportPlecare);
		if (c->info.aeroportSosire)
			free(c->info.aeroportSosire);
	}

	Nod* c = *cap;
	while (c) {
		while (c->next && c->next->info.status != statusCautat) {
			c = c->next;
		}

		if (c->next) {
			Nod* temp = c->next;
			c->next = temp->next;

			if (temp->info.aeroportSosire) {
				free(temp->info.aeroportSosire);
			}
			if (temp->info.aeroportPlecare)
				free(temp->info.aeroportPlecare);
			free(temp);
		}
		else {
			c = c->next;
		}
	}
}

float calculeazaDurataTotalaSpreAeroport(Nod* cap, const char* aeroportSosire) {
	float total = 0;
	while (cap != NULL) {
		if (strcmp(cap->info.aeroportSosire, aeroportSosire) == 0) {
			total += cap->info.durata;
		}
		cap = cap->next;
	}

	return total;
}

int main() {

	Nod* cap = NULL;
	cap = citireListaZborDinFisier("zbor.txt");
	afisareListaZbor(cap);



	printf("Durata medie este: %5.2f\n\n", calculeazaDurataMedie(cap));

	const char* destinatieCautata = "Tokyo";
	printf("Durata totala spre aeroportul %s este: %5.2f\n\n", destinatieCautata, calculeazaDurataTotalaSpreAeroport(cap, destinatieCautata));


	printf("Stergere starea 1\n");
	stergeZborCuStatus(&cap, '1');

	printf("\nLista dupa stegre status 1:\n");
	afisareListaZbor(cap);

	dezalocareListaZbor(&cap);
	printf("\nLista dupa dezalocare\n");
	afisareListaZbor(cap);

	return 0;
}