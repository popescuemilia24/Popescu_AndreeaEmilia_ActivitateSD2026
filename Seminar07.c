////stiva = structura liniara, omogena, LIFO
//
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
////STIVA
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
//typedef struct Nod Nod;
//struct Nod {
//	Nod* next;
//	Masina info;
//};
//
//void pushStack(Nod** prim, Masina masina) {
//	Nod* nou = malloc(sizeof(Nod));
//	nou->info = masina;
//	nou->next = (*prim);
//	(*prim) = nou;
//}
//
//Masina popStack(Nod** prim) {
//	if (prim != NULL)
//	{
//		Masina rezultat = (*prim)->info; //sageata are pioritate mai mare decat dereferentierea
//		Nod* aux = (*prim);
//		(*prim) = (*prim)->next;
//		free(aux);
//		return rezultat;
//	}
//	else {
//		Masina nou;
//		nou.id = -1;
//		return nou;
//	}
//
//}
//
//int emptyStack(Nod* prim) {
//	if (prim == NULL) {
//		return 1;
//	}
//	return 0;
//}
//
//Nod* citireStackMasiniDinFisier(const char* numeFisier) {
//	FILE* f = fopen(numeFisier, "r");
//	Nod* stiva;
//	stiva = NULL;
//	while (!feof(f))
//	{
//		pushStack(&stiva, citireMasinaDinFisier(f));
//	}
//	fclose(f);
//	return stiva;
//}
//
//void dezalocareStivaDeMasini(Nod** prim) {
//	while (*prim) {
//		Masina m = popStack(prim);
//		free(m.model);
//		free(m.numeSofer);
//	}
//}
//
//int size(Nod* prim) {
//	int contor = 0;
//	Nod* aux = prim;
//	while (aux) {
//		contor++;
//		aux = aux->next;
//	}
//	return contor;
//}
//
//
//
//
//
////QUEUE
//
//typedef struct NodD NodD;
//struct NodD {
//	Masina info;
//	NodD* prev;
//	NodD* next;
//};
//
//typedef struct ListaDubla ListaDubla;
//struct ListaDubla {
//	NodD* first;
//	NodD* last;
//};
//
////adaugare la inceput
//void enqueue(ListaDubla* lista, Masina masina) {
//	NodD* nou = (NodD*)malloc(sizeof(NodD));
//	nou->info = masina;
//	nou->next = lista->first;
//	nou->prev = NULL;
//	if (lista->first)
//	{
//		lista->first->prev = nou;
//	}
//	else {
//		lista->last = nou;
//	}
//	lista->first = nou;
//}
//
//Masina dequeue(ListaDubla* lista) {
//	Masina noua;
//
//	if (lista->last) {
//		noua = lista->last->info;
//		lista->last = lista->last->prev;
//		if (lista->last)
//		{
//			free(lista->last->next);
//			lista->last->next = NULL;
//		}
//		else {
//			free(lista->first);
//			lista->first = NULL;
//		}
//
//	}
//	else {
//		noua.id = -1;
//	}
//	return noua;
//}
//
//ListaDubla citireCoadaDeMasiniDinFisier(const char* numeFisier) {
//	ListaDubla coada;
//	coada.first = coada.last = NULL;
//	FILE* f = fopen(numeFisier, "r");
//	if (f) {
//		while (!feof(f))
//		{
//			enqueue(&coada, citireMasinaDinFisier(f));
//		}
//		fclose(f);
//	}
//	return coada;
//}
//
//void dezalocareCoadaDeMasini(ListaDubla* lista) {
//	if (lista == NULL) return;
//	while (lista->first != NULL)
//	{
//		Masina m = dequeue(lista);
//		free(m.model);
//		free(m.numeSofer);
//	}
//}
//
//
////metode de procesare
//Masina getMasinaByID(Nod** prim, int id) {
//	Masina aux;
//	Masina rez;
//	Nod* stivaNoua = NULL;
//
//	while ((*prim) && (*prim)->info.id != id) {
//		pushStack(&stivaNoua, popStack(prim));
//	}
//	if (*prim) {
//		aux = popStack(prim);
//
//		rez = aux;
//		rez.model = (char*)malloc(sizeof(char) * (strlen(aux.model) + 1));
//		strcpy(rez.model, aux.model);
//
//		rez.numeSofer = (char*)malloc(sizeof(char) * (strlen(aux.numeSofer) + 1));
//		strcpy(rez.numeSofer, aux.numeSofer);
//
//		pushStack(prim, aux);
//	}
//	else {
//		rez.id = -1;
//
//	}
//
//	while (stivaNoua) {
//		pushStack(prim, popStack(&stivaNoua));
//	}
//	return rez;
//
//}
//
//float calculeazaPretTotal(Nod** stiva) {
//	float total = 0;
//	Nod* stivaNoua = NULL;
//	while (!emptyStack(*stiva)) {
//		Masina m = popStack(stiva);
//		total += m.pret;
//		pushStack(&stivaNoua, m);
//	}
//
//	while (!emptyStack(stivaNoua)) {
//		pushStack(stiva, popStack(&stivaNoua));
//	}
//	return total;
//}
//
//
//int main() {
//
//	Nod* stiva = citireStackMasiniDinFisier("masini.txt");
//	if (emptyStack(stiva)) {
//		printf("Stiva este goala.\n");
//	}
//	else {
//		printf("Stiva nu este goala.\n");
//	}
//	printf("Size stiva: %d.\n", size(stiva));
//
//	printf("Pretul total al masinilor din stiva este: %5.2f.\n", calculeazaPretTotal(&stiva));
//	afisareMasina(getMasinaByID(&stiva, 3));
//
//	afisareMasina(popStack(&stiva));
//	afisareMasina(popStack(&stiva));
//
//	dezalocareStivaDeMasini(&stiva);
//	if (emptyStack(stiva)) {
//		printf("Stiva este goala.\n");
//	}
//	else {
//		printf("Stiva nu este goala.\n");
//	}
//
//
//
//	ListaDubla coada = citireCoadaDeMasiniDinFisier("masini.txt");
//	printf("Coada:\n");
//	afisareMasina(dequeue(&coada));
//	afisareMasina(dequeue(&coada));
//	dezalocareCoadaDeMasini(&coada);
//
//	return 0;
//}