//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//struct StructuraProdus {
//	int id;
//	int stoc;
//	float pret;
//	char* denumire;
//	char* producator;
//	unsigned char categorie;
//}; typedef struct StructuraProdus Produs;
//
//
//struct Nod {
//	Produs info;
//	struct Nod* next;
//	int nrNoduri;
//};typedef struct Nod Nod;
//
//Produs citireProdusDinFisier(FILE* file) {
//	Produs p;
//	char buffer[50];
//	char sep[4] = " ,\n";
//	fgets(buffer, 50, file);
//
//	p.id = atoi(strtok(buffer, sep));
//	p.stoc = atoi(strtok(NULL, sep));
//	p.pret = atof(strtok(NULL, sep));
//	char* aux;
//	aux = strtok(NULL, sep);
//	p.denumire = (char*)malloc(sizeof(char) * (strlen(aux) + 1));
//	strcpy(p.denumire, aux);
//	aux = strtok(NULL, sep);
//	p.producator = (char*)malloc(sizeof(char) * (strlen(aux) + 1));
//	strcpy(p.producator, aux);
//	p.categorie = strtok(NULL, sep)[0];
//	return p;
//
//}
//
//void afisareProdus(Produs produs) {
//	printf("Id: %d\n", produs.id);
//	printf("Stoc: %d\n", produs.stoc);
//	printf("Pret: %.2f\n", produs.pret);
//	printf("Denumire: %s\n", produs.denumire);
//	printf("Producator: %s\n", produs.producator);
//	printf("Categorie: %c\n\n", produs.categorie);
//}
//
//void afisareListaProduse(Nod* cap) {
//	while (cap != NULL) {
//		afisareProdus(cap->info);
//		cap = cap->next;
//	}
//}
//
//void adaugaProdusInLista(Nod** cap, Produs produsNou) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->next = NULL;
//	nou->info = produsNou;
//	if ((*cap) == NULL) {
//		(*cap) = nou;
//	}
//	else {
//		Nod* aux = (*cap);
//		while (aux->next != NULL) {
//			aux = aux->next;
//		}
//		aux->next = nou;
//	}
//}
//
//void adaugaLaInceputInLista(Nod** cap, Produs produsNou) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = produsNou;
//	nou->next = (*cap);
//	(*cap) = nou;
//}
//
//Nod* citireListaProduseDinFisier(const char* numeFisier) {
//	FILE* f = fopen(numeFisier, "r");
//	Nod* lista = NULL;
//	while (!feof(f)) {
//		adaugaProdusInLista(&lista, citireProdusDinFisier(f));
//	}
//	fclose(f);
//	return lista;
//}
//
//void dezalocareListaProduse(Nod** cap) {
//	while (*cap != NULL) {
//		Nod* c = (*cap);
//		if (c->info.denumire != NULL) {
//			free(c->info.denumire);
//		}
//		if (c->info.producator != NULL) {
//			free(c->info.producator);
//		}
//		(*cap) = c->next;
//		free(c);
//	}
//}
//
//float calculeazaPretMediu(Nod* cap) {
//	float sum = 0;
//	int k = 0;
//	while (cap) {
//		sum += cap->info.pret;
//		k++;
//		cap = cap->next;
//	}
//	if (k != 0) {
//		return sum / k;
//	}
//	return 0;
//}
//
//void stergeProduseDinCategoria(Nod** cap, char categorieCautata) {
//	while ((*cap) != NULL && (*cap)->info.categorie == categorieCautata)
//	{
//		Nod* aux = (*cap);
//		(*cap) = aux->next;
//		if (aux->info.denumire) {
//			free(aux->info.denumire);
//		}
//		if (aux->info.producator) {
//			free(aux->info.producator);
//		}
//		free(aux);
//	}
//
//	Nod* aux = (*cap);
//	while (aux) {
//		while (aux->next != NULL && aux->next->info.categorie != categorieCautata) {
//			aux = aux->next;
//		}
//
//		if (aux->next) {
//			Nod* temp = aux->next;
//			aux->next = temp->next;
//			if (temp->info.denumire) {
//				free(temp->info.denumire);
//			}
//			if (temp->info.producator) {
//				free(temp->info.producator);
//			}
//			free(temp);
//		}
//		else {
//			aux = aux->next;
//		}
//	}
//}
//
//float calculeazaPretulProduselorUnuiProducator(Nod* cap, const char* producator) {
//	float total = 0;
//	while (cap) {
//		if (strcmp(cap->info.producator, producator) == 0) {
//			total += cap->info.pret;
//		}
//		cap = cap->next;
//	}
//	return total;
//}
//
//int main() {
//	Nod* cap = NULL;
//	cap = citireListaProduseDinFisier("produse.txt");
//	afisareListaProduse(cap);
//
//
//
//	printf("Pretul mediu este: %5.2f\n\n", calculeazaPretMediu(cap));
//
//	const char* producator = "Albalact";
//	printf("Pretul total al producatorului %s este: %5.2f\n\n", producator, calculeazaPretulProduselorUnuiProducator(cap, producator));
//
//
//	printf("Stergere categoria A\n");
//	stergeProduseDinCategoria(&cap, 'A');
//
//	printf("\nLista dupa stegre categorie A:\n");
//	afisareListaProduse(cap);
//
//	dezalocareListaProduse(&cap);
//	printf("\nLista dupa dezalocare\n");
//	afisareListaProduse(cap);
//
//	return 0;
//}



//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//struct StructuraProdus {
//	int id;
//	int stoc;
//	float pret;
//	char* denumire;
//	char* producator;
//	unsigned char categorie;
//}; typedef struct StructuraProdus Produs;
//
//typedef struct Nod Nod;
//struct Nod {
//	Produs info;
//	Nod* prev;
//	Nod* next;
//};
//
//struct ListaDubla {
//	Nod* first;
//	Nod* last;
//}; typedef struct ListaDubla ListaDubla;
//
//Produs citireProdusDinFisier(FILE* file) {
//	Produs p;
//	char buffer[50];
//	char sep[4] = " ,\n";
//
//	fgets(buffer, 50, file);
//	p.id = atoi(strtok(buffer, sep));
//	p.stoc = atoi(strtok(NULL, sep));
//	p.pret = atof(strtok(NULL, sep));
//	char* aux;
//	aux = strtok(NULL, sep);
//	p.denumire = (char*)malloc(sizeof(char) * (strlen(aux) + 1));
//	strcpy(p.denumire, aux);
//	aux = strtok(NULL, sep);
//	p.producator = (char*)malloc(sizeof(char) * (strlen(aux) + 1));
//	strcpy(p.producator, aux);
//	p.categorie = strtok(NULL, sep)[0];
//	return p;
//
//}
//
//void afisareProdus(Produs masina) {
//	printf("Id: %d\n", masina.id);
//	printf("Stoc : %d\n", masina.stoc);
//	printf("Pret: %.2f\n", masina.pret);
//	printf("Denumire: %s\n", masina.denumire);
//	printf("Producator: %s\n", masina.producator);
//	printf("Categorie: %c\n\n", masina.categorie);
//}
//
//void afisareListaProduse(ListaDubla lista) {
//	Nod* l = lista.first;
//	while (l) {
//		afisareProdus(l->info);
//		l = l->next;
//	}
//}
//
//
//void afisareInversaListaProduse(ListaDubla lista) {
//	Nod* l = lista.last;
//	while (l) {
//		afisareProdus(l->info);
//		l = l->prev;
//	}
//}
//
//
//void adaugaProdusInLista(ListaDubla* lista, Produs produsNou) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = produsNou;
//	nou->prev = lista->last;
//	nou->next = NULL;
//
//	if (lista->last != NULL) {
//		lista->last->next = nou;
//	}
//	else {
//		lista->first = nou;
//	}
//	lista->last = nou;
//}
//
//void adaugaLaInceputInLista(ListaDubla* lista, Produs produsNou) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = produsNou;
//	nou->next = lista->first;
//	nou->prev = NULL;
//	if (lista->first != NULL) {
//		lista->first->prev = nou;
//	}
//	else {
//		lista->last = nou;
//	}
//	lista->first = nou;
//}
//
//ListaDubla citireLDProduseDinFisier(const char* numeFisier) {
//	FILE* f = fopen(numeFisier, "r");
//	ListaDubla lista;
//	lista.first = NULL;
//	lista.last = NULL;
//	while (!feof(f)) {
//		adaugaProdusInLista(&lista, citireProdusDinFisier(f));
//	}
//	fclose(f);
//	return lista;
//}
//
//void dezalocareLDProduse(ListaDubla* lista) {
//	Nod* nod = lista->first;
//	while (nod) {
//		Nod* n = nod;
//		nod = nod->next;
//		if (n->info.denumire != NULL) {
//			free(n->info.denumire);
//		}
//		if (n->info.producator != NULL) {
//			free(n->info.producator);
//		}
//		free(n);
//	}
//
//	lista->first = NULL;
//	lista->last = NULL;
//
//}
//
//float calculeazaPretMediu(ListaDubla lista) {
//	float sum = 0;
//	int k = 0;
//	Nod* n = lista.first;
//	while (n) {
//		sum += n->info.pret;
//		k++;
//		n = n->next;
//	}
//	if (k != 0) {
//		return sum / k;
//	}
//	else return 0;
//}
//
//void stergeProdusDupaID(ListaDubla* lista, int id) {
//	if (lista->first == NULL) {
//		return;
//	}
//	Nod* n;
//	n = lista->first;
//	while (n != NULL && n->info.id != id) {
//		n = n->next;
//	}
//	if (n == NULL) {
//		return;
//	}
//	if (n->prev == NULL) {
//		lista->first = n->next;
//		if (lista->first) {
//			lista->first->prev = NULL;
//		}
//	}
//	else {
//		n->prev->next = n->next;
//	}
//	if (n->prev->next != NULL) {
//		n->next->prev = n->prev;
//	}
//	else {
//		lista->last = n->prev;
//	}
//	if (n->info.denumire != NULL) {
//		free(n->info.denumire);
//	}
//	if (n->info.producator != NULL) {
//		free(n->info.producator);
//	}
//	free(n);
//}
//
//char* getNumeProducatorProdusScump(ListaDubla lista) {
//	if (lista.first == NULL)
//	{
//		return NULL;
//	}
//	else {
//		Nod* max = lista.first;
//		Nod* n = lista.first;
//		while (n) {
//			if (n->info.pret > max->info.pret)
//			{
//				max = n;
//			}
//			n = n->next;
//		}
//		char* producator = (char*)malloc(sizeof(char) * (strlen(max->info.producator) + 1));
//		strcpy(producator, max->info.producator);
//		return producator;
//	}
//}
//
//int main() {
//	ListaDubla lista = citireLDProduseDinFisier("produse.txt");
//	afisareInversaListaProduse(lista);
//	printf("Pretul mediu al produselor din lista este: %5.2f\n\n", calculeazaPretMediu(lista));
//	printf("Producatorul cu cel mai scump produs este: %s\n\n", getNumeProducatorProdusScump(lista));
//	stergeProdusDupaID(&lista, 3);
//	afisareListaProduse(lista);
//	dezalocareLDProduse(&lista);
//	printf("Lista dupa dezalocare: \n");
//	afisareListaProduse(lista);
//	return 0;
//}


//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//
//struct StructuraProdus {
//	int id;
//	int stoc;
//	float pret;
//	char* denumire;
//	char* producator;
//	unsigned char categorie;
//}; typedef struct StructuraProdus Produs;
//
//typedef struct Nod Nod;
//struct Nod {
//	Produs info;
//	Nod* next;
//};
//
//struct HashTable {
//	int dim;
//	Nod** tabel;
//};
//typedef struct HashTable HashTable;
//
//
//Produs citireProdusDinFisier(FILE* file) {
//	Produs p;
//	char buffer[50];
//	char sep[4] = " ,\n";
//	fgets(buffer, 50, file);
//	p.id = atoi(strtok(buffer, sep));
//	p.stoc = atoi(strtok(NULL, sep));
//	p.pret = atof(strtok(NULL, sep));
//	char* aux;
//	aux = strtok(NULL, sep);
//	p.denumire = (char*)malloc(sizeof(char) * (strlen(aux) + 1));
//	strcpy(p.denumire, aux);
//	aux = strtok(NULL, sep);
//	p.producator = (char*)malloc(sizeof(char) * (strlen(aux) + 1));
//	strcpy(p.producator, aux);
//	p.categorie = strtok(NULL, sep)[0];
//	return p;
//}
//
//void afisareProdus(Produs produs) {
//	printf("Id: %d\n", produs.id);
//	printf("Stoc: %d\n", produs.stoc);
//	printf("Pret: %.2f\n", produs.pret);
//	printf("Denumire: %s\n", produs.denumire);
//	printf("Producator: %s\n", produs.producator);
//	printf("Categorie: %c\n\n", produs.categorie);
//}
//
//void afisareListaProduse(Nod* cap) {
//	while (cap) {
//		afisareProdus(cap->info);
//		cap = cap->next;
//	}
//}
//
//void adaugaProdusInLista(Nod** cap, Produs produsNou) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = produsNou;
//	nou->next = NULL;
//	if (*cap) {
//		Nod* aux = *cap;
//		while (aux->next) {
//			aux = aux->next;
//		}
//		aux->next = nou;
//	}
//	else {
//		(*cap) = nou;
//	}
//}
//
//
//HashTable initializareHashTable(int dimensiune) {
//	HashTable ht;
//	ht.dim = dimensiune;
//	ht.tabel = (Nod**)malloc(sizeof(Nod*) * dimensiune);
//	for (int i = 0; i < dimensiune;i++) {
//		ht.tabel[i] = NULL;
//	}
//	return ht;
//}
//
////int calculeazaHash(const char* denumire, int dimensiune) {
////	int suma = 0;
////	for (int i = 0;i < strlen(denumire);i++)
////	{
////		suma += denumire[i];
////	}
////	return suma % dimensiune;
////}
//int calculeazaHash(const char* denumire, int dimensiune) {
//	unsigned long hash = 5381;
//	int c;
//	while ((c = *denumire++)) {
//		hash = hash + 33 + c;
//	}
//	return (int)(hash % dimensiune);
//}
//
//void inserareProdusInTabela(HashTable hash, Produs produs) {
//	int poz = calculeazaHash(produs.denumire, hash.dim);
//	adaugaProdusInLista(&hash.tabel[poz], produs);
//}
//
//HashTable citireProduseDinFisier(const char* numeFisier, int dimensiune) {
//	FILE* f = fopen(numeFisier, "r");
//	HashTable ht = initializareHashTable(dimensiune);
//	while (!feof(f)) {
//		inserareProdusInTabela(ht, citireProdusDinFisier(f));
//	}
//	fclose(f);
//	return ht;
//}
//
//void afisareTabelaDeProduse(HashTable ht) {
//	for (int i = 0; i < ht.dim; i++) {
//		if (ht.tabel[i] != NULL) {
//			printf("\nIn clusterul %d sunt urmatoarele produse:\n", i + 1);
//			afisareListaProduse(ht.tabel[i]);
//			printf("====================================================\n");
//		}
//		else {
//			printf("\n----->In clusterul %d nu sunt produse\n", i + 1);
//			printf("====================================================\n");
//		}
//
//	}
//}
//
//void dezalocareTabelaDeProduse(HashTable* ht) {
//	if (ht != NULL && ht->tabel != NULL) {
//		for (int i = 0; i < (*ht).dim; i++) {
//			Nod* temp = ht->tabel[i];
//			while (temp) {
//				Nod* aux = temp;
//				if (aux->info.denumire != NULL) {
//					free(aux->info.denumire);
//				}
//				if (aux->info.producator != NULL) {
//					free(aux->info.producator);
//				}
//				temp = temp->next;
//				free(aux);
//			}
//		}
//		free(ht->tabel);
//		ht->tabel = NULL;
//		ht->dim = 0;
//	}
//
//}
//
//float* calculeazaPreturiMediiPerClustere(HashTable ht, int* nrClustere) {
//	float* vPret = NULL;
//	(*nrClustere) = 0;
//	for (int i = 0;i < ht.dim;i++) {
//		if (ht.tabel[i] != NULL) {
//			(*nrClustere)++;
//		}
//	}
//	vPret = (float*)malloc(sizeof(float) * (*nrClustere));
//	int poz = 0;
//	for (int i = 0;i < ht.dim;i++) {
//		if (ht.tabel[i] != NULL) {
//			float sum = 0;
//			int k = 0;
//			Nod* aux = ht.tabel[i];
//			while (aux) {
//				sum += aux->info.pret;
//				k++;
//				aux = aux->next;
//			}
//			vPret[poz++] = sum / k;
//		}
//	}
//	return vPret;;
//}
//
//Produs getProdusDupaCheie(HashTable ht, const char* denumire) {
//	Produs p;
//	p.id = -1;
//	int poz = calculeazaHash(denumire, ht.dim);
//	if (poz >= 0 && poz < ht.dim) {
//		Nod* aux = ht.tabel[poz];
//		while (aux) {
//			if (strcmp(aux->info.denumire, denumire) == 0) {
//				p = aux->info;
//				p.denumire = (char*)malloc(sizeof(char) * (strlen(aux->info.denumire) + 1));
//				strcpy(p.denumire, aux->info.denumire);
//				p.producator = (char*)malloc(sizeof(char) * (strlen(aux->info.producator) + 1));
//				strcpy(p.producator, aux->info.producator);
//				break;
//			}
//			aux = aux->next;
//		}
//	}
//	return p;
//}
//
//int main() {
//	int dim = 5;
//	HashTable ht = citireProduseDinFisier("produse.txt", dim);
//	afisareTabelaDeProduse(ht);
//
//	int nrClustere = 0;
//	float* vPret = calculeazaPreturiMediiPerClustere(ht, &nrClustere);
//
//	printf("Preturi medii per clastere sunt:\n");
//	for (int i = 0; i < nrClustere;i++) {
//		printf("-> %.2f \n", vPret[i]);
//	}
//	printf("\n");
//	char* denumire = "Paine";
//	printf("Produsul %s este:\n", denumire);
//	afisareProdus(getProdusDupaCheie(ht, denumire));
//
//	dezalocareTabelaDeProduse(&ht);
//	printf("Tabela de produse dupa dezalocare: \n");
//	afisareTabelaDeProduse(ht);
//
//	return 0;
//}





//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//struct StructuraPacient {
//	int id;
//	int varsta;
//	float greutate;
//	char* nume;
//	char* diagnostic;
//	unsigned char prioritate;
//};typedef struct StructuraPacient Pacient;
//
//typedef struct Nod Nod;
//struct Nod {
//	Pacient info;
//	Nod* next;
//};
//
//Pacient citirePacientDinFisier(FILE* file) {
//	Pacient p;
//	char buffer[50];
//	char sep[4] = ",\n";
//	fgets(buffer, 50, file);
//	p.id = atoi(strtok(buffer, sep));
//	p.varsta = atoi(strtok(NULL, sep));
//	p.greutate = atof(strtok(NULL, sep));
//	char* aux;
//	aux = strtok(NULL, sep);
//	p.nume = (char*)malloc(sizeof(char) * (strlen(aux) + 1));
//	strcpy(p.nume, aux);
//	aux = strtok(NULL, sep);
//	p.diagnostic = (char*)malloc(sizeof(char) * (strlen(aux) + 1));
//	strcpy(p.diagnostic, aux);
//	p.prioritate = strtok(NULL, sep)[0];
//	return p;
//}
//
//void afisarePacient(Pacient pacient) {
//	printf("Id: %d\n", pacient.id);
//	printf("Varsta: %d\n", pacient.varsta);
//	printf("Greutate: %.2f\n", pacient.greutate);
//	printf("Nume: %s\n", pacient.nume);
//	printf("Diagnostic: %s\n", pacient.diagnostic);
//	printf("Prioritate: %c\n\n", pacient.prioritate);
//}
//
//void afisareListaPacienti(Nod* cap) {
//	while (cap) {
//		afisarePacient(cap->info);
//		cap = cap->next;
//	}
//}
//
//void adaugaPacientInLista(Nod** cap, Pacient pacientNou) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = pacientNou;
//	nou->next = NULL;
//	if (*cap) {
//		Nod* aux = *cap;
//		while (aux->next) {
//			aux = aux->next;
//		}
//		aux->next = nou;
//	}
//	else {
//		*cap = nou;
//	}
//}
//
//void adaugaLaInceputInLista(Nod** cap, Pacient pacientNou) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = pacientNou;
//	nou->next = (*cap);
//	(*cap) = nou;
//}
//
//Nod* citireListaPacientiDinFisier(const char* numeFisier) {
//	FILE* f = fopen(numeFisier, "r");
//	Nod* lista = NULL;
//	while (!feof(f)) {
//		adaugaPacientInLista(&lista, citirePacientDinFisier(f));
//	}
//	fclose(f);
//	return lista;
//}
//
//void dezalocareListaPacienti(Nod** cap) {
//	while (*cap) {
//		Nod* temp = *cap;
//		(*cap) = temp->next;
//		if (temp->info.nume != NULL) {
//			free(temp->info.nume);
//		}
//		if (temp->info.diagnostic != NULL) {
//			free(temp->info.diagnostic);
//		}
//		free(temp);
//	}
//}
//
//float calculeazaVarstaMedie(Nod* cap) {
//	float sum = 0;
//	int k = 0;
//	while (cap) {
//		sum += cap->info.varsta;
//		k++;
//		cap = cap->next;
//	}
//	if (k != 0) {
//		return sum / k;
//	}
//	else {
//		return 0;
//	}
//}
//
//void stergePacientiCuPrioritatea(Nod** cap, char prioritateCautata) {
//	while ((*cap) != NULL && (*cap)->info.prioritate == prioritateCautata)
//	{
//		Nod* aux = (*cap);
//		(*cap) = aux->next;
//		if (aux->info.nume) {
//			free(aux->info.nume);
//		}
//		if (aux->info.diagnostic) {
//			free(aux->info.diagnostic);
//		}
//		free(aux);
//	}
//	Nod* aux = (*cap);
//	while (aux) {
//		while (aux->next != NULL && aux->next->info.prioritate != prioritateCautata) {
//			aux = aux->next;
//		}
//
//		if (aux->next) {
//			Nod* temp = aux->next;
//			aux->next = temp->next;
//			if (temp->info.nume) {
//				free(temp->info.nume);
//			}
//			if (temp->info.diagnostic) {
//				free(temp->info.diagnostic);
//			}
//			free(temp);
//		}
//		else {
//			aux = aux->next;
//		}
//	}
//}
//
//float calculeazaGreutateaMedieDupaDiagnostic(Nod* cap, const char* diagnostic) {
//	float total = 0;
//	int k = 0;
//	while (cap) {
//		if (strcmp(cap->info.diagnostic, diagnostic) == 0) {
//			total += cap->info.greutate;
//			k++;
//		}
//		cap = cap->next;
//	}
//	if (k != 0) {
//		return total / k;
//	}
//	else {
//		return 0;
//	}
//}
//
//int main() {
//	Nod* lista = citireListaPacientiDinFisier("pacienti.txt");
//	afisareListaPacienti(lista);
//
//	printf("Varsta medie a pacientilor este: %.2f\n", calculeazaVarstaMedie(lista));
//
//	const char* diagnostic = "Astm";
//	printf("Greutatea medie a pacientilor cu %s este: %.2f kg.\n", diagnostic, calculeazaGreutateaMedieDupaDiagnostic(lista, diagnostic));
//
//	printf("Stergere pacienti cu prioritete C:\n");
//	stergePacientiCuPrioritatea(&lista, 'C');
//	afisareListaPacienti(lista);
//
//	dezalocareListaPacienti(&lista);
//	printf("Afisare lista dupa dezalocare:\n");
//	afisareListaPacienti(lista);
//
//	return 0;
//}