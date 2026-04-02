////tabela de dispersie = o structura de date omogene, organizata sub forma unui vector
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
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
//};
//
//struct HashTable {
//	int dim;
//	Nod** vector;
//};
//typedef struct HashTable HashTable;
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
//void afisareListaMasini(Nod* cap_lista) {
//	while (cap_lista) {
//		afisareMasina(cap_lista->info);
//		cap_lista = cap_lista->next;
//	}
//}
//
//void adaugaMasinaInLista(Nod** cap, Masina masinaNoua) {
//	Nod* nodNou = (Nod*)malloc(sizeof(Nod));
//	nodNou->info = masinaNoua;
//	nodNou->next = NULL;
//
//	if (*cap) {
//		Nod* aux = *cap;
//		while (aux->next) {
//			aux = aux->next;
//		}
//		aux->next = nodNou;
//	}
//	else {
//		(*cap) = nodNou;
//	}
//
//}
//
//
//
//HashTable initializareHashTable(int dimensiune) {
//	HashTable ht;
//	ht.dim = dimensiune;
//	ht.vector = (Nod**)malloc(sizeof(Nod*) * dimensiune);
//	for (int i = 0;i < dimensiune;i++)
//	{
//		ht.vector[i] = NULL;
//	}
//	return ht;
//}
//
//int calculeazaHash(int id, int dimensiune) {
//	// NICIODATA nu fol random!!!
//	id = id * 23 + 123;
//	return id % dimensiune;
//}
//
//void inserareMasinaInTabela(HashTable hash, Masina masina) {
//	int poz = calculeazaHash(masina.id, hash.dim);
//	if (hash.vector[poz])
//	{
//		//avem coliziune
//		adaugaMasinaInLista(&hash.vector[poz], masina); //punctul are prioritate mai mare decat indexul si & 
//	}
//	else {
//		//nu avem coliziune
//		adaugaMasinaInLista(&hash.vector[poz], masina);
//	}
//}
//
//HashTable citireMasiniDinFisier(const char* numeFisier) {
//
//	FILE* f = fopen(numeFisier, "r");
//	HashTable ht = initializareHashTable(3);
//	if (!f)
//	{
//		return ht;
//	}
//
//	while (!feof(f)) {
//		inserareMasinaInTabela(ht, citireMasinaDinFisier(f));
//	}
//	fclose(f);
//	return ht;
//
//}
//
//void afisareTabelaDeMasini(HashTable ht) {
//	for (int i = 0; i < ht.dim;i++)
//	{
//		if (ht.vector[i] != NULL)
//		{
//			printf("Clusterul %d \n", i + 1);
//			afisareListaMasini(ht.vector[i]);
//			printf("=============================\n");
//		}
//	}
//
//}
//
//void dezalocareTabelaDeMasini(HashTable* ht) {
//	if (ht != NULL && ht->vector != NULL) {
//		for (int i = 0; i < ht->dim; i++) {
//			Nod* aux = ht->vector[i];
//			while (aux != NULL) {
//				if (aux->info.model != NULL) {
//					free(aux->info.model);
//				}
//				if (aux->info.numeSofer != NULL) {
//					free(aux->info.numeSofer);
//				}
//				Nod* deSters = aux;
//				aux = aux->next;
//				free(deSters);
//			}
//		}
//		free(ht->vector);
//		ht->vector = NULL;
//		ht->dim = 0;
//	}
//
//}
//
//float* calculeazaPreturiMediiPerClustere(HashTable ht, int* nrClustere) {
//	//calculeaza pretul mediu al masinilor din fiecare cluster.
//	//trebuie sa returnam un vector cu valorile medii per cluster.
//	//lungimea vectorului este data de numarul de clustere care contin masini
//	*nrClustere = 0;
//	for (int i = 0; i < ht.dim;i++) {
//		if (ht.vector[i] != NULL)
//		{
//			(*nrClustere)++;
//		}
//	}
//	float* vectorPreturi = malloc(sizeof(float) * (*nrClustere));
//	int k = 0;
//	for (int i = 0; i < ht.dim; i++) {
//		if (ht.vector[i] != NULL)
//		{
//			float sum = 0;
//			int nrMasini = 0;
//			Nod* aux = ht.vector[i];
//			while (aux->next) {
//				sum = aux->info.pret;
//				nrMasini++;
//				aux = aux->next;
//			}
//			vectorPreturi[k++] = sum / nrMasini;
//		}
//	}
//
//	return vectorPreturi;
//}
//
//Masina getMasinaDupaID(HashTable ht, int id) {
//	Masina m;
//	m.id = -1;
//	int hash = calculeazaHash(id, ht.dim);
//	if (hash >= 0 && hash < ht.dim) {
//		Nod* aux = ht.vector[hash];
//		while (aux) {
//			if (aux->info.id == id) {
//				m = aux->info;
//				m.model = (char*)malloc(sizeof(char) * (strlen(aux->info.model) + 1));
//				strcpy_s(m.model, strlen(aux->info.model) + 1, aux->info.model);
//				m.numeSofer = (char*)malloc(sizeof(char) * (strlen(aux->info.numeSofer) + 1));
//				strcpy_s(m.numeSofer, strlen(aux->info.numeSofer) + 1, aux->info.numeSofer);
//				break;
//			}
//			aux = aux->next;
//		}
//	}
//	return m;
//}
//
//int main() {
//	HashTable ht = citireMasiniDinFisier("masini.txt");
//	afisareTabelaDeMasini(ht);
//	Masina m = getMasinaDupaID(ht, 8);
//	printf("Masina cu id %d:\n", m.id);
//	afisareMasina(m);
//	int nrClustere;
//	float* vectorPreturi = calculeazaPreturiMediiPerClustere(ht, &nrClustere);
//	for (int i = 0;i < nrClustere;i++) {
//		printf("Pentru clusterul cu indecele %d, media este %.2f:\n", i, vectorPreturi[i]);
//	}
//	return 0;
//}