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


//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//struct StructuraCarte {
//	int id;
//	int nrPagini;
//	float pret;
//	char* titlu;
//	char* autor;
//	unsigned char editie;
//};
//typedef struct StructuraCarte Carte;
//
//Carte citireCarteFisier(FILE* file) {
//	Carte c;
//	char buffer[100];
//	if (fgets(buffer, 100, file) == NULL)
//	{
//		c.titlu = NULL;
//		c.autor = NULL;
//		return c;
//	}
//	char var[3] = ",\n";
//	c.id = atoi(strtok(buffer, var));
//	c.nrPagini = atoi(strtok(NULL, var));
//	c.pret = atof(strtok(NULL, var));
//	char* aux = strtok(NULL, var);
//	c.titlu = (char*)malloc(sizeof(char) * (strlen(aux) + 1));
//	strcpy_s(c.titlu, strlen(aux) + 1, aux);
//	aux = strtok(NULL, var);
//	c.autor = (char*)malloc(sizeof(char) * (strlen(aux) + 1));
//	strcpy_s(c.autor, strlen(aux) + 1, aux);
//	c.editie = (strtok(NULL, var))[0];
//	return c;
//
//}
//
//void afisareCarte(Carte carte) {
//	printf("\nID: %d\n", carte.id);
//	printf("Numar pagini: %d\n", carte.nrPagini);
//	printf("Pret: %5.2f\n", carte.pret);
//	printf("Titlu: %s\n", carte.titlu);
//	printf("Autor: %s\n", carte.autor);
//	printf("Editie: %c\n\n", carte.editie);
//}
//
////STACK
//
//typedef struct Nod Nod;
//struct Nod
//{
//	Carte info;
//	Nod* next;
//};
//
//
//void pushStack(Nod** nod, Carte carte) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = carte;
//	nou->next = (*nod);
//	(*nod) = nou;
//}
//
//Carte popStack(Nod** nod) {
//	Carte c;
//	if ((*nod) != NULL) {
//		c = (*nod)->info;
//		Nod* nou = (*nod);
//		(*nod) = (*nod)->next;
//		free(nou);
//	}
//	else {
//		c.id = -1;
//	}
//	return c;
//}
//
//int emptyStack(Nod* nod) {
//	if (nod == NULL)
//	{
//		return 1;
//	}
//	else {
//		return 0;
//	}
//}
//
//Nod* citireStackCartiDinFisier(const char* numeFisier) {
//	FILE* f = fopen(numeFisier, "r");
//	Nod* stiva = NULL;
//	if (f)
//	{
//		while (!feof(f))
//		{
//			pushStack(&stiva, citireCarteFisier(f));
//		}
//		fclose(f);
//	}
//	return stiva;
//}
//
//void dezalocareStivaDeCarti(Nod** nod) {
//	while (*nod)
//	{
//		Carte carte = popStack(nod);
//		free(carte.autor);
//		free(carte.titlu);
//	}
//}
//
//int size(Nod* nod) {
//	int contor = 0;
//	Nod* nou = nod;
//	while (nou)
//	{
//		contor++;
//		nou = nou->next;
//	}
//	return contor;
//}
//
////QUEUE
//typedef struct NOD NOD;
//struct NOD {
//	Carte info;
//	NOD* prev;
//	NOD* next;
//};
//
//typedef struct ListaDubla ListaDubla;
//struct ListaDubla {
//	NOD* first;
//	NOD* last;
//};
//
//void enqueue(ListaDubla* lista, Carte carte) {
//	NOD* nou = (NOD*)malloc(sizeof(NOD));
//	nou->info = carte;
//	nou->prev = NULL;
//	nou->next = lista->first;
//	if (lista->first != NULL)
//	{
//		lista->first->prev = nou;
//	}
//	else {
//		lista->last = nou;
//	}
//	lista->first = nou;
//}
//
//Carte dequeue(ListaDubla* lista) {
//	Carte carte;
//	if (lista->last) {
//		carte = lista->last->info;
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
//
//	}
//	else {
//		carte.id = -1;
//	}
//	return carte;
//}
//
//ListaDubla citireCoadaDeCartiDinFisier(const char* numeFisier) {
//	ListaDubla lista;
//	lista.first = NULL;
//	lista.last = NULL;
//	FILE* f = fopen(numeFisier, "r");
//	if (f)
//	{
//		while (!feof(f)) {
//			enqueue(&lista, citireCarteFisier(f));
//		}
//		fclose(f);
//	}
//	return lista;
//}
//
//void dezalocareCoadaDeCarti(ListaDubla* lista) {
//	if (lista == NULL)return;
//	while (lista->first) {
//		Carte carte = dequeue(lista);
//		free(carte.autor);
//		free(carte.titlu);
//	}
//}
//
//
////metode de procesare
//Carte getCarteByID(ListaDubla* lista, int id) {
//	Carte carte;
//	ListaDubla coada;
//	coada.first = NULL;
//	coada.last = NULL;
//	while (lista->first && lista->last->info.id != id) {
//		enqueue(&coada, dequeue(lista));
//	}
//
//	if (lista->first)
//	{
//		Carte c = dequeue(lista);
//		carte = c;
//		carte.titlu = (char*)malloc(sizeof(char) * (strlen(c.titlu) + 1));
//		strcpy_s(carte.titlu, strlen(c.titlu) + 1, c.titlu);
//		carte.autor = (char*)malloc(sizeof(char) * (strlen(c.autor) + 1));
//		strcpy_s(carte.autor, strlen(c.autor) + 1, c.autor);
//		enqueue(&coada, c);
//	}
//	while (lista->first) {
//		enqueue(&coada, dequeue(lista));
//	}
//	while (coada.first)
//	{
//		enqueue(lista, dequeue(&coada));
//	}
//	return carte;
//}
//
//float calculeazaPretTotal(ListaDubla* lista) {
//	float total = 0;
//	ListaDubla coada;
//	coada.first = NULL;
//	coada.last = NULL;
//
//	while (lista->first != NULL) {
//		Carte carte = dequeue(lista);
//		total += carte.pret;
//		enqueue(&coada, carte);
//	}
//
//	while (coada.first != NULL)
//	{
//		enqueue(lista, dequeue(&coada));
//	}
//	return total;
//}
//
//int main() {
//
//	Nod* stiva = citireStackCartiDinFisier("carti.txt");
//	if (emptyStack(stiva)) {
//		printf("Stiva este goala.\n");
//	}
//	else {
//		printf("Stiva nu este goala.\n");
//	}
//	printf("Size stiva: %d.\n", size(stiva));
//
//	afisareCarte(popStack(&stiva));
//	afisareCarte(popStack(&stiva));
//
//
//
//	dezalocareStivaDeCarti(&stiva);
//	if (emptyStack(stiva)) {
//		printf("Stiva este goala.\n");
//	}
//	else {
//		printf("Stiva nu este goala.\n");
//	}
//
//
//
//
//	ListaDubla coada = citireCoadaDeCartiDinFisier("carti.txt");
//	printf("\n\nCOADA:\n");
//	printf("Pretul total al cartilor din coada este: %.2f.\n", calculeazaPretTotal(&coada));
//	printf("Cartea cu id-ul 6 este: \n");
//	afisareCarte(getCarteByID(&coada, 6));
//	afisareCarte(dequeue(&coada));
//	afisareCarte(dequeue(&coada));
//	dezalocareCoadaDeCarti(&coada);
//
//
//	return 0;
//}