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
//
//typedef struct Nod Nod;
//struct Nod {
//	Masina info;
//	Nod* next;
//	Nod* prev;
//};
//
//struct ListaDubla
//{
//	int nrNoduri;
//	Nod* first;
//	Nod* last;
//}; typedef struct ListaDubla ListaDubla;
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
//void afisareListaMasini(ListaDubla lista) {
//	printf("Lista contine %d noduri\n", lista.nrNoduri);
//	Nod* p = lista.first;
//	while (p)
//	{
//		afisareMasina(p->info);
//		p = p->next;
//	}
//}
//
//void afisareInversaListaMasina(ListaDubla lista)
//{
//	printf("Lista contine %d noduri\n", lista.nrNoduri);
//	Nod* p = lista.last;
//	while (p)
//	{
//		afisareMasina(p->info);
//		p = p->prev;
//	}
//}
//
//void adaugaMasinaInLista(ListaDubla* lista, Masina masinaNoua) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = masinaNoua;
//	nou->next = NULL;
//	nou->prev = lista->last;
//	if (lista->last != NULL)
//	{
//		lista->last->next = nou;
//	}
//	else {
//		lista->first = nou;
//	}
//	lista->last = nou;
//	lista->nrNoduri++;
//}
//
//void adaugaLaInceputInLista(ListaDubla* lista, Masina masinaNoua) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = masinaNoua;
//	nou->next = lista->first;
//	nou->prev = NULL;
//	if (lista->first != NULL)
//	{
//		lista->first->prev = nou;
//	}
//	else {
//		lista->last = nou;
//	}
//	lista->first = nou;
//	lista->nrNoduri++;
//}
//ListaDubla citireLDMasiniDinFisier(const char* numeFisier) {
//
//	FILE* f = fopen(numeFisier, "r");
//	ListaDubla lista;
//	lista.first = NULL;
//	lista.last = NULL;
//	lista.nrNoduri = 0;
//	if (!f)
//	{
//		return lista;
//	}
//
//	while (!feof(f))
//	{
//		adaugaMasinaInLista(&lista, citireMasinaDinFisier(f));
//	}
//	fclose(f);
//	return lista;
//
//}
//
//void dezalocareLDMasini(ListaDubla* lista) {
//	Nod* nod = lista->first;
//	while (nod)
//	{
//		Nod* aux = nod;
//		nod = nod->next;
//		if (aux->info.model)
//		{
//			free(aux->info.model);
//		}
//		if (aux->info.numeSofer)
//		{
//			free(aux->info.numeSofer);
//		}
//		free(aux);
//		lista->nrNoduri--;
//	}
//
//	lista->first = NULL;
//	lista->last = NULL;
//
//
//}
//
//float calculeazaPretMediu(ListaDubla lista) {
//	float suma = 0;
//	if (lista.first == NULL)
//	{
//		return 0;
//	}
//	else {
//		/*Nod* p = lista.first;
//		while (p)
//		{
//			suma += p->info.pret;
//			p = p->next;
//		}*/
//
//		for (Nod* p = lista.first; p != NULL; p = p->next)
//		{
//			suma += p->info.pret;
//		}
//
//	}
//	return suma / lista.nrNoduri;
//}
//
//void stergeMasinaDupaID(ListaDubla* lista, int id) {
//	//sterge masina cu id-ul primit.
//	//tratati situatia ca masina se afla si pe prima pozitie, si pe ultima pozitie
//	if (lista->first != NULL)
//	{
//		Nod* p = lista->first;
//		for (; p != NULL && p->info.id != id; p = p->next); //Asta face parcurgerea si pot sa las initializarea goala pt ca am initializat p mai sus
//		if (!p) return;
//		else {
//			if (p->prev == NULL)
//			{
//				if (p->next) {
//					p->next->prev = NULL;
//				}
//				else {
//					lista->last = NULL;
//					lista->nrNoduri = 0;
//				}
//				lista->first = p->next;
//				free(p->info.model);
//				free(p->info.numeSofer);
//				free(p);
//
//			}
//			else
//			{
//				p->prev->next = p->next;
//				if (p->next)
//				{
//					p->next->prev = p->prev;
//				}
//				else {
//					lista->last = p->prev;
//				}
//				free(p->info.model);
//				free(p->info.numeSofer);
//				free(p);
//			}
//			lista->nrNoduri--;
//
//		}
//	}
//}
//
//char* getNumeSoferMasinaScumpa(/*lista dublu inlantuita*/) {
//	//cauta masina cea mai scumpa si 
//	//returneaza numele soferului acestei maasini.
//	return NULL;
//}
//
//int main() {
//
//	ListaDubla lista = citireLDMasiniDinFisier("masini.txt");
//	afisareListaMasini(lista);
//	//afisareInversaListaMasina(lista);
//
//	printf("\nPretul mediu este %5.2f", calculeazaPretMediu(lista));
//	stergeMasinaDupaID(&lista, 5);
//	afisareListaMasini(lista);
//	afisareListaMasini(lista);
//	dezalocareLDMasini(&lista);
//	printf("\nLista a fost dezalocata\n");
//	afisareListaMasini(lista);
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//
//
//struct StructuraZbor {
//	int id;
//	int nrPasageri;
//	float durata;
//	char* aeroportPlecare;
//	char* aeroportSosire;
//	unsigned char status; // 0=la timp, 1=întârziat, 2=anulat
//};
//typedef struct StructuraZbor Zbor;
//
//typedef struct Nod Nod;
//struct Nod
//{
//	Zbor info;
//	Nod* next;
//	Nod* prev;
//};
//
//struct ListaDubla
//{
//	Nod* first;
//	Nod* last;
//	int nrNoduri;
//}; typedef struct ListaDubla ListaDubla;
//
//Zbor citireZborFisier(FILE* file) {
//	Zbor z;
//	char buffer[100];
//	char sep[3] = ",\n";
//	fgets(buffer, 100, file);
//	z.id = atoi(strtok(buffer, sep));
//	z.nrPasageri = atoi(strtok(NULL, sep));
//	z.durata = atof(strtok(NULL, sep));
//	char* aux = strtok(NULL, sep);
//	z.aeroportPlecare = (char*)malloc(sizeof(char) * (strlen(aux) + 1));
//	strcpy_s(z.aeroportPlecare, strlen(aux) + 1, aux);
//	aux = strtok(NULL, sep);
//	z.aeroportSosire = (char*)malloc(sizeof(char) * (strlen(aux) + 1));
//	strcpy_s(z.aeroportSosire, strlen(aux) + 1, aux);
//	z.status = (strtok(NULL, sep))[0];
//	return z;
//}
//
//void afisareZbor(Zbor zbor) {
//	printf("ID: %d\n", zbor.id);
//	printf("PASAGERI: %d\n", zbor.nrPasageri);
//	printf("DURATA: %.2f\n", zbor.durata);
//	printf("PLECARE: %s\n", zbor.aeroportPlecare);
//	printf("SOSIRE: %s\n", zbor.aeroportSosire);
//	printf("STATUS: %c\n\n", zbor.status);
//}
//
//void afisareInversaListaZbor(ListaDubla lista) {
//	Nod* c = lista.first;
//	while (c != NULL)
//	{
//		afisareZbor(c->info);
//		c = c->next;
//	}
//}
//
//void afisareListaZbor(ListaDubla lista) {
//	Nod* c = lista.last;
//	while (c != NULL)
//	{
//		afisareZbor(c->info);
//		c = c->prev;
//	}
//}
//
//void adaugaMasinaInLista(ListaDubla* lista, Zbor zborNou) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = zborNou;
//	nou->prev = lista->last;
//	nou->next = NULL;
//	if (lista->last != NULL)
//	{
//		lista->last->next = nou;
//	}
//	else
//	{
//		lista->first = nou;
//	}
//	lista->last = nou;
//	lista->nrNoduri++;
//
//	return lista;
//}
//
//void adaugaLaInceputInLista(ListaDubla* lista, Zbor zborNou) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = zborNou;
//	nou->prev = NULL;
//	nou->next = lista->first;
//
//	if (lista->first != NULL)
//	{
//		lista->first->prev = nou;
//	}
//	else {
//		lista->last = nou;
//	}
//	lista->first = nou;
//	lista->nrNoduri++;
//	return lista;
//}
//
//ListaDubla citireLDZborDinFisier(const char* numeFisier) {
//
//	FILE* f = fopen(numeFisier, "r");
//	ListaDubla lista;
//	lista.first = NULL;
//	lista.last = NULL;
//	lista.nrNoduri = 0;
//
//	if (!f) {
//		return lista;
//	}
//
//	while (!feof(f))
//	{
//		adaugaLaInceputInLista(&lista, citireZborFisier(f));
//	}
//
//	fclose(f);
//	return lista;
//}
//
//void dezalocareLDZbor(ListaDubla* lista) {
//	Nod* c = lista->first;
//	while (c != NULL)
//	{
//		Nod* p = c;
//		c = c->next;
//		if (p->info.aeroportPlecare)
//		{
//			free(p->info.aeroportPlecare);
//		}
//		if (p->info.aeroportSosire)
//		{
//			free(p->info.aeroportSosire);
//		}
//		free(p);
//	}
//	lista->first = NULL;
//	lista->last = NULL;
//	lista->nrNoduri = 0;
//}
//
//float calculeazaDurataMedie(ListaDubla lista) {
//	float sum = 0;
//	if (lista.first == NULL)
//	{
//		return 0;
//	}
//	else {
//		Nod* c = lista.first;
//		while (c)
//		{
//			sum += c->info.durata;
//			c = c->next;
//		}
//	}
//
//	return sum / lista.nrNoduri;
//
//}
//
//void stergeZborDupaID(ListaDubla* lista, int id) {
//	if (lista->first == NULL)
//	{
//		return;
//	}
//	Nod* c = lista->first;
//	while (c != NULL & c->info.id != id)
//	{
//		c = c->next;
//	}
//	if (c == NULL)
//	{
//		return;
//	}
//	if (c->prev == NULL)
//	{
//		lista->first = c->next;
//		if (lista->first)
//		{
//			lista->first->prev = NULL;
//		}
//	}
//	else {
//		c->prev->next = c->next;
//	}
//	if (c->next != NULL) {
//		c->next->prev = c->prev;
//	}
//	else {
//		lista->last = c->prev;
//	}
//	if (c->info.aeroportPlecare)
//	{
//		free(c->info.aeroportPlecare);
//	}
//	if (c->info.aeroportSosire)
//	{
//		free(c->info.aeroportSosire);
//	}
//	free(c);
//	lista->nrNoduri--;
//}
//
//char* getNumeAeroportPlecareMasinaDurataMare(ListaDubla lista) {
//	if (lista.first) {
//		Nod* max = lista.first;
//		Nod* c = lista.first;
//		while (c)
//		{
//			if (c->info.durata > max->info.durata)
//			{
//				max = c;
//			}
//			c = c->next;
//		}
//		char* aeroport = (char*)malloc(strlen(max->info.aeroportPlecare) + 1);
//		strcpy_s(aeroport, strlen(max->info.aeroportPlecare) + 1, max->info.aeroportPlecare);
//		return aeroport;
//	}
//	else {
//		return NULL;
//	}
//
//}
//
//int main() {
//
//	ListaDubla lista = citireLDZborDinFisier("zbor.txt");
//	afisareListaZbor(lista);
//	//afisareInversaListaZbor(lista);
//
//	printf("\nDurata medie este de %5.2f\n", calculeazaDurataMedie(lista));
//	char* aeroport = getNumeAeroportPlecareMasinaDurataMare(lista);
//	printf("Aeroportul este %s\n ", aeroport);
//	if (aeroport)
//	{
//		free(aeroport);
//	}
//	stergeZborDupaID(&lista, 5);
//	afisareListaZbor(lista);
//
//	dezalocareLDZbor(&lista);
//	printf("\nLista a fost dezalocata\n");
//	afisareListaZbor(lista);
//
//	return 0;
//}