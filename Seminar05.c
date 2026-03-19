#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StructuraMasina {
	int id;
	int nrUsi;
	float pret;
	char* model;
	char* numeSofer;
	unsigned char serie;
};
typedef struct StructuraMasina Masina;

typedef struct Nod Nod;
struct Nod {
	Masina info;
	Nod* next;
	Nod* prev;
};

struct ListaDubla
{
	int nrNoduri;
	Nod* first;
	Nod* last;
}; typedef struct ListaDubla ListaDubla;


Masina citireMasinaDinFisier(FILE* file) {
	char buffer[100];
	char sep[3] = ",\n";
	fgets(buffer, 100, file);
	char* aux;
	Masina m1;
	aux = strtok(buffer, sep);
	m1.id = atoi(aux);
	m1.nrUsi = atoi(strtok(NULL, sep));
	m1.pret = atof(strtok(NULL, sep));
	aux = strtok(NULL, sep);
	m1.model = malloc(strlen(aux) + 1);
	strcpy_s(m1.model, strlen(aux) + 1, aux);

	aux = strtok(NULL, sep);
	m1.numeSofer = malloc(strlen(aux) + 1);
	strcpy_s(m1.numeSofer, strlen(aux) + 1, aux);

	m1.serie = *strtok(NULL, sep);
	return m1;
}

void afisareMasina(Masina masina) {
	printf("Id: %d\n", masina.id);
	printf("Nr. usi : %d\n", masina.nrUsi);
	printf("Pret: %.2f\n", masina.pret);
	printf("Model: %s\n", masina.model);
	printf("Nume sofer: %s\n", masina.numeSofer);
	printf("Serie: %c\n\n", masina.serie);
}

void afisareListaMasini(ListaDubla lista) {
	printf("Lista contine %d noduri\n", lista.nrNoduri);
	Nod* p = lista.first;
	while (p)
	{
		afisareMasina(p->info);
		p = p->next;
	}
}

void afisareInversaListaMasina(ListaDubla lista)
{
	printf("Lista contine %d noduri\n", lista.nrNoduri);
	Nod* p = lista.last;
	while (p)
	{
		afisareMasina(p->info);
		p = p->prev;
	}
}

void adaugaMasinaInLista(ListaDubla* lista, Masina masinaNoua) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = masinaNoua;
	nou->next = NULL;
	nou->prev = lista->last;
	if (lista->last != NULL)
	{
		lista->last->next = nou;
	}
	else {
		lista->first = nou;
	}
	lista->last = nou;
	lista->nrNoduri++;
}

void adaugaLaInceputInLista(ListaDubla* lista, Masina masinaNoua) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = masinaNoua;
	nou->next = lista->first;
	nou->prev = NULL;
	if (lista->first != NULL)
	{
		lista->first->prev = nou;
	}
	else {
		lista->last = nou;
	}
	lista->first = nou;
	lista->nrNoduri++;
}
ListaDubla citireLDMasiniDinFisier(const char* numeFisier) {

	FILE* f = fopen(numeFisier, "r");
	ListaDubla lista;
	lista.first = NULL;
	lista.last = NULL;
	lista.nrNoduri = 0;
	if (!f)
	{
		return lista;
	}

	while (!feof(f))
	{
		adaugaMasinaInLista(&lista, citireMasinaDinFisier(f));
	}
	fclose(f);
	return lista;

}

void dezalocareLDMasini(ListaDubla* lista) {
	Nod* nod = lista->first;
	while (nod)
	{
		Nod* aux = nod;
		nod = nod->next;
		if (aux->info.model)
		{
			free(aux->info.model);
		}
		if (aux->info.numeSofer)
		{
			free(aux->info.numeSofer);
		}
		free(aux);
		lista->nrNoduri--;
	}

	lista->first = NULL;
	lista->last = NULL;


}

float calculeazaPretMediu(ListaDubla lista) {
	float suma = 0;
	if (lista.first == NULL)
	{
		return 0;
	}
	else {
		/*Nod* p = lista.first;
		while (p)
		{
			suma += p->info.pret;
			p = p->next;
		}*/

		for (Nod* p = lista.first; p != NULL; p = p->next)
		{
			suma += p->info.pret;
		}

	}
	return suma / lista.nrNoduri;
}

void stergeMasinaDupaID(ListaDubla* lista, int id) {
	//sterge masina cu id-ul primit.
	//tratati situatia ca masina se afla si pe prima pozitie, si pe ultima pozitie
	if (lista->first != NULL)
	{
		Nod* p = lista->first;
		for (; p != NULL && p->info.id != id; p = p->next); //Asta face parcurgerea si pot sa las initializarea goala pt ca am initializat p mai sus
		if (!p) return;
		else {
			if (p->prev == NULL)
			{
				if (p->next) {
					p->next->prev = NULL;
				}
				else {
					lista->last = NULL;
					lista->nrNoduri = 0;
				}
				lista->first = p->next;
				free(p->info.model);
				free(p->info.numeSofer);
				free(p);

			}
			else
			{
				p->prev->next = p->next;
				if (p->next)
				{
					p->next->prev = p->prev;
				}
				else {
					lista->last = p->prev;
				}
				free(p->info.model);
				free(p->info.numeSofer);
				free(p);
			}
			lista->nrNoduri--;

		}
	}
}

char* getNumeSoferMasinaScumpa(/*lista dublu inlantuita*/) {
	//cauta masina cea mai scumpa si 
	//returneaza numele soferului acestei maasini.
	return NULL;
}

int main() {

	ListaDubla lista = citireLDMasiniDinFisier("masini.txt");
	afisareListaMasini(lista);
	//afisareInversaListaMasina(lista);

	printf("\nPretul mediu este %5.2f", calculeazaPretMediu(lista));
	stergeMasinaDupaID(&lista, 5);
	afisareListaMasini(lista);
	afisareListaMasini(lista);
	dezalocareLDMasini(&lista);
	printf("\nLista a fost dezalocata\n");
	afisareListaMasini(lista);
	return 0;
}