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
//	Nod* prev;
//	Nod* next;
//};
//
//typedef struct ListaDubla ListaDubla;
//struct ListaDubla {
//	Nod* first;
//	Nod* last;
//	int nrNoduri;
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
//void afisareListaPacienti(ListaDubla lista) {
//	Nod* aux = lista.first;
//	while (aux) {
//		afisarePacient(aux->info);
//		aux = aux->next;
//	}
//}
//
//void afisareInversaListaPacienti(ListaDubla lista) {
//	Nod* aux = lista.last;
//	while (aux) {
//		afisarePacient(aux->info);
//		aux = aux->prev;
//	}
//}
//
//void adaugaPacientInLista(ListaDubla* lista, Pacient pacientNou) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = pacientNou;
//	nou->next = NULL;
//	nou->prev = lista->last;
//	if (lista->last) {
//		lista->last->next = nou;
//	}
//	else {
//		lista->first = nou;
//	}
//	lista->last = nou;
//	lista->nrNoduri++;
//}
//
//void adaugaLaInceputInLista(ListaDubla* lista, Pacient pacientNou) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = pacientNou;
//	nou->prev = NULL;
//	nou->next = lista->first;
//	if (lista->first) {
//		lista->first->prev = nou;
//	}
//	else {
//		lista->last = nou;
//	}
//	lista->first = nou;
//	lista->nrNoduri++;
//}
//
//ListaDubla citireLDPacientiDinFisier(const char* numeFisier) {
//	FILE* f = fopen(numeFisier, "r");
//	ListaDubla lista;
//	lista.first = NULL;
//	lista.last = NULL;
//	lista.nrNoduri = 0;
//	while (!feof(f)) {
//		adaugaPacientInLista(&lista, citirePacientDinFisier(f));
//	}
//	fclose(f);
//	return lista;
//}
//
//void dezalocareLDPacienti(ListaDubla* lista) {
//	Nod* aux = lista->first;
//	while (aux) {
//		Nod* temp = aux;
//		aux = aux->next;
//		if (temp->info.nume != NULL) {
//			free(temp->info.nume);
//		}
//		if (temp->info.diagnostic != NULL) {
//			free(temp->info.diagnostic);
//		}
//		free(temp);
//		lista->nrNoduri--;
//	}
//	lista->first = NULL;
//	lista->last = NULL;
//	lista->nrNoduri = 0;
//}
//
//float calculeazaVarstaMedie(ListaDubla lista) {
//	if (lista.nrNoduri == 0) {
//		return 0;
//	}
//	else
//	{
//		float sum = 0;
//		while (lista.first) {
//			sum += lista.first->info.varsta;
//			lista.first = lista.first->next;
//		}
//		return sum / lista.nrNoduri;
//	}
//
//}
//
//void stergePacientDupaID(ListaDubla* lista, int id) {
//	Nod* temp = lista->first;
//	if (temp == NULL) {
//		return;
//	}
//	while (temp != NULL && temp->info.id != id)
//	{
//		temp = temp->next;
//	}
//	if (temp->prev == NULL) {
//		lista->first = temp->next;
//		lista->first->prev = NULL;
//	}
//	else {
//		if (temp->next != NULL) {
//			temp->prev->next = temp->next;
//			temp->next->prev = temp->prev;
//		}
//		else {
//			lista->last = temp->prev;
//			lista->last->next = NULL;
//		}
//	}
//	if (temp->info.nume != NULL) {
//		free(temp->info.nume);
//	}
//	if (temp->info.diagnostic != NULL) {
//		free(temp->info.diagnostic);
//	}
//	free(temp);
//	lista->nrNoduri--;
//}
//
//void stergePacientiDupaPrioritate(ListaDubla* lista, char prioritate) {
//	Nod* temp = lista->first;
//	if (temp == NULL) {
//		return;
//	}
//
//	while (temp != NULL) {
//		if (temp->info.prioritate == prioritate) {
//			Nod* aux = temp;
//			temp = temp->next;
//
//			if (aux->prev == NULL) {
//				lista->first = aux->next;
//				if (lista->first != NULL) {
//					lista->first->prev = NULL;
//				}
//				else {
//					lista->last = NULL;
//				}
//			}
//			else if (aux->next == NULL) {
//				lista->last = aux->prev;
//				if (lista->last != NULL) {
//					lista->last->next = NULL;
//				}
//				else {
//					lista->first = NULL;
//				}
//			}
//			else {
//				aux->prev->next = aux->next;
//				aux->next->prev = aux->prev;
//			}
//
//			if (aux->info.nume) free(aux->info.nume);
//			if (aux->info.diagnostic) free(aux->info.diagnostic);
//			free(aux);
//
//			lista->nrNoduri--;
//		}
//		else {
//			temp = temp->next;
//		}
//	}
//}
//
//char* getNumePacientGreutateMare(ListaDubla lista) {
//	if (lista.first) {
//		Nod* max = lista.first;
//		Nod* aux = lista.first;
//		while (aux) {
//			if (aux->info.greutate > max->info.greutate) {
//				max = aux;
//			}
//			aux = aux->next;
//		}
//		char* nume = (char*)malloc(sizeof(char) * (strlen(max->info.nume) + 1));
//		strcpy(nume, max->info.nume);
//		return nume;
//	}
//	return NULL;
//}
//
//int main() {
//	ListaDubla lista = citireLDPacientiDinFisier("pacienti.txt");
//	afisareInversaListaPacienti(lista);
//	printf("Varsta medie a pacientilor din lista este: %5.2f\n\n", calculeazaVarstaMedie(lista));
//	printf("Pacientul cu cea mai mare greutate este: %s\n\n", getNumePacientGreutateMare(lista));
//	stergePacientDupaID(&lista, 3);
//	printf("===========================================\n");
//	afisareListaPacienti(lista);
//	stergePacientiDupaPrioritate(&lista, 'C');
//	printf("===========================================\n");
//	afisareListaPacienti(lista);
//	dezalocareLDPacienti(&lista);
//	printf("Lista dupa dezalocare: \n");
//	afisareListaPacienti(lista);
//	return 0;
//}



#define _CRT_SECURE_NO_WARNINGS
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
//struct Nod{
//	Pacient info;
//	Nod* next;
//};
//
//struct HashTable {
//	int dim;
//	Nod** table;
//};
//typedef struct HashTable HashTable;
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
//		Nod* aux = (*cap);
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
//	ht.table = (Nod**)malloc(sizeof(Nod*) * dimensiune);
//	for (int i = 0; i < ht.dim;i++) {
//		ht.table[i] = NULL;
//	}
//	return ht;
//}
//
//int calculeazaHash(const char* nume, int dimensiune) {
//	int sum = 0;
//	for (int i = 0;i < strlen(nume);i++) {
//		sum += nume[i];
//	}
//	return sum % dimensiune;
//}
//
//void inserarePacientInTabela(HashTable hash, Pacient pacientNou) {
//	int poz = calculeazaHash(pacientNou.nume, hash.dim);
//	adaugaPacientInLista(&hash.table[poz], pacientNou);
//}
//
//HashTable citirePacientiDinFisier(const char* numeFisier, int dimensiune) {
//	FILE* f = fopen(numeFisier, "r");
//	HashTable ht = initializareHashTable(dimensiune);
//	while (!feof(f)) {
//		inserarePacientInTabela(ht, citirePacientDinFisier(f));
//	}
//	fclose(f);
//	return ht;
//}
//
//void afisareTabelaDePacienti(HashTable ht) {
//	for(int i = 0;i < ht.dim;i++) {
//		if (ht.table[i] != 0) {
//			printf("In clusterul %d se afla urmatorii pacienti: \n", i + 1);
//			afisareListaPacienti(ht.table[i]);
//			printf("=========================================================\n");
//		}
//		else {
//			printf("In clusterul %d nu sunt pacienti: \n", i + 1);
//			printf("=========================================================\n");
//		}
//	}
//}
//
//void dezalocareTabelaDePacienti(HashTable *ht) {
//	if(ht!=NULL)
//	{
//		for (int i = 0;i < (*ht).dim; i++) {
//			if ((*ht).table[i] != NULL) {
//				Nod* aux = (*ht).table[i];
//				while (aux) {
//					Nod* temp = aux;
//					aux = aux->next;
//					if (temp->info.nume != NULL) {
//						free(temp->info.nume);
//					}
//					if (temp->info.diagnostic != NULL) {
//						free(temp->info.diagnostic);
//					}
//					free(temp);
//					
//				}
//			}
//		}
//	}
//	free(ht->table);
//	ht->dim = 0;
//	ht->table = NULL;
//}
//
//float* calculeazaVarsteMediiPerClustere(HashTable ht, int* nrClustere) {
//	if (ht.table == NULL) {
//		return NULL;
//	}
//	else {
//		for (int i = 0;i < ht.dim;i++) {
//			if(ht.table[i]!=NULL) (*nrClustere)++;
//		}
//		float* varsta = (float*)malloc(sizeof(float) * (*nrClustere));
//		int poz = 0;
//		for (int i = 0;i < ht.dim;i++) {
//			if (ht.table[i] != NULL) {
//				float sum = 0;
//				int k = 0;
//				Nod* aux = ht.table[i];
//				while (aux) {
//					sum += aux->info.varsta;
//					aux = aux->next;
//					k++;
//				}
//				varsta[poz++] = sum / k;
//			}
//		}
//		return varsta;
//	}
//}
//
//Pacient getPacientDupaCheie(HashTable ht, const char* nume) {
//	Pacient p;
//	p.id = -1;
//	int poz = calculeazaHash(nume, ht.dim);
//	if (poz >= 0 && poz < ht.dim) {
//		Nod* aux = ht.table[poz];
//		while (aux) {
//			if (strcmp(aux->info.nume, nume) == 0) {
//				p = aux->info;
//				p.nume = (char*)malloc(sizeof(char) * (strlen(aux->info.nume) + 1));
//				strcpy(p.nume, aux->info.nume);
//				p.diagnostic = (char*)malloc(sizeof(char) * (strlen(aux->info.diagnostic) + 1));
//				strcpy(p.diagnostic, aux->info.diagnostic);
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
//	HashTable ht = citirePacientiDinFisier("pacienti.txt", dim);
//	afisareTabelaDePacienti(ht);
//
//	int nrClustere = 0;
//	float* varsta = calculeazaVarsteMediiPerClustere(ht, &nrClustere);
//
//	printf("Varstele medii per clastere sunt:\n");
//	for (int i = 0; i < nrClustere;i++) {
//		printf("-> %5.2f \n", varsta[i]);
//	}
//	printf("\n");
//	char* nume = "Radu Gheorghe";
//	printf("Pacientul %s este:\n", nume);
//	afisarePacient(getPacientDupaCheie(ht, nume));
//
//	dezalocareTabelaDePacienti(&ht);
//	printf("Tabela de pacienti dupa dezalocare: \n");
//	afisareTabelaDePacienti(ht);
//
//	return 0;
//}


#define _CRT_SECURE_NO_WARNINGS
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
//struct HashTable {
//	int dim;
//	Masina* table;
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
//HashTable initializareHashTable(int dimensiune) {
//	HashTable ht;
//	ht.dim = dimensiune;
//	ht.table = (Masina*)malloc(sizeof(Masina) * dimensiune);
//	for (int i = 0;i < ht.dim;i++) {
//		ht.table[i].id = -1;
//		ht.table[i].numeSofer = NULL;
//		ht.table[i].model = NULL;
//	}
//	return ht;
//}
//
//int calculeazaHash(const char* nume, int dimensiune) {
//	int sum = 0;
//	for (int i = 0;i < strlen(nume);i++) {
//		sum += nume[i];
//	}
//	return sum % dimensiune;
//}
//void inserareMasinaInTabela(HashTable* ht, Masina masina);
//
//HashTable Redimensionare(HashTable ht) {
//	int dimNoua = ht.dim + (ht.dim / 2) + 1;
//	HashTable hash = initializareHashTable(dimNoua);
//	for (int i = 0;i < ht.dim;i++) {
//		if (ht.table[i].id != -1) {
//			inserareMasinaInTabela(&hash, ht.table[i]);
//		}
//	}
//	free(ht.table);
//	return hash;
//}
//
//void inserareMasinaInTabela(HashTable* ht, Masina masina) {
//	if (masina.id == -1) return-1;
//	
//	int ocupate = 0;
//	for (int i = 0; i < ht->dim; i++) {
//		if (ht->table[i].id != -1) ocupate++;
//	}
//	if (ocupate >= ht->dim - 1) {
//		*ht = Redimensionare(*ht);
//	}
//
//	int poz = calculeazaHash(masina.numeSofer, ht->dim);
//	int i = 0;
//	while (ht->table[(poz + i) % ht->dim].id != -1) {
//		i++;
//	}
//
//	ht->table[(poz + i) % ht->dim] = masina;
//}
//
//HashTable citireMasiniDinFisier(const char* numeFisier, int dimensiune) {
//	FILE* f = fopen(numeFisier, "r");
//	HashTable ht = initializareHashTable(dimensiune);
//	while (!feof(f)) {
//		inserareMasinaInTabela(&ht, citireMasinaDinFisier(f));
//	}
//	fclose(f);
//	return ht;
//}
//
//void afisareTabelaDeMasini(HashTable ht) {
//	printf("\n Continut tabela de dispersie (dimensiune %d):\n", ht.dim);
//	for (int i = 0;i < ht.dim;i++) {
//		if (ht.table[i].id != -1) {
//			printf("Pozitie %d:\n", i );
//			afisareMasina(ht.table[i]);
//			printf("--------------------------------------------\n");
//		}
//		else {
//			printf("Pe pozitia %d nu exista masina.\n", i);
//			printf("--------------------------------------------\n");
//		}
//	}
//}
//
//void dezalocareTabelaDeMasini(HashTable *ht) {
//	if (ht && ht->table) {
//		for (int i = 0;i < ht->dim;i++) {
//			if (ht->table[i].id != -1) {
//				if (ht->table[i].numeSofer != NULL) {
//					free(ht->table[i].numeSofer);
//				}
//				if (ht->table[i].model != NULL) {
//					free(ht->table[i].model);
//				}
//			}
//		}
//		free(ht->table);
//		ht->table = NULL;
//		ht->dim = 0;
//	}
//}
//
//float* calculeazaPreturiMediiPerClustere(HashTable ht, int* nrClustere) {
//	if (ht.table == NULL || ht.dim < 0) {
//		(*nrClustere) = 0;
//		return NULL;
//	}
//	int count = 0;
//	int i = 0;
//	while (i < ht.dim) {
//		if (ht.table[i].id != -1) {
//			count++;
//			while (i < ht.dim && ht.table[i].id != -1) {
//				i++;
//			}
//		}
//		else {
//			i++;
//		}
//	}
//
//	if (count == 0) {
//		(*nrClustere) = 0;
//		return NULL;
//	}
//
//	(*nrClustere) = count;
//	float* preturi = (float*)malloc(sizeof(float) * (*nrClustere));
//	int poz = 0;
//	i = 0;
//	while (i < ht.dim) {
//		if (ht.table[i].id != -1) {
//			float sum = 0;
//			int k = 0;
//			while (i < ht.dim && ht.table[i].id != -1) {
//				sum += ht.table[i].pret;
//				k++;
//				i++;
//			}
//			preturi[poz++] = sum / k;
//		}
//		else {
//			i++;
//		}
//	}
//
//	return preturi;
//}
//
//Masina getMasinaDupaCheie(HashTable ht, const char* nume) {
//	Masina m;
//	m.id = -1;
//	int poz = calculeazaHash(nume, ht.dim);
//	int i = 0;
//	while (i < ht.dim) {
//		int index = (poz + i) % ht.dim;
//		if (ht.table[index].id == -1) {
//			break;
//		}
//		if (strcmp(ht.table[index].numeSofer, nume) == 0) {
//			m = ht.table[index];
//			m.model = malloc(strlen(ht.table[index].model) + 1);
//			strcpy(m.model, ht.table[index].model);
//
//			m.numeSofer = malloc(strlen(ht.table[index].numeSofer) + 1);
//			strcpy(m.numeSofer, ht.table[index].numeSofer);
//			return m;
//		}
//		i++;
//	}
//	
//	return m;
//}
//
//int main() {
//	int dim = 5;
//	HashTable ht = citireMasiniDinFisier("masini.txt", dim);
//
//	afisareTabelaDeMasini(ht);
//	int nrClustere = 0;
//	float* preturi = calculeazaPreturiMediiPerClustere(ht, &nrClustere);
//	printf("S-au gasit %d clustere.\n", nrClustere);
//	for (int i = 0; i < nrClustere; i++) {
//		printf("Media preturilor clusterului %d: %.2f\n", i + 1, preturi[i]);
//	}
//	free(preturi);
//	char* nume = "Badescu";
//	printf("\nCautare sofer %s:\n", nume);
//	Masina cautata = getMasinaDupaCheie(ht, nume);
//	if (cautata.id != -1) {
//		afisareMasina(cautata);
//		free(cautata.model);
//		free(cautata.numeSofer);
//	}
//	else {
//		printf("Nu s-a gasit masina.\n");
//	}
//	dezalocareTabelaDeMasini(&ht);
//	printf("Tabela dupa dezalocare:\n");
//	afisareTabelaDeMasini(ht);
//
//	return 0;
//}


//stiva -> LIFO -> LSI
////coada -> FIFO -> LDI
//
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
////STACK
//
//typedef struct Nod Nod;
//struct Nod {
//	Pacient info;
//	Nod* next;
//};
//
//void pushStack(Nod** cap, Pacient pacient) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = pacient;
//	nou->next = (*cap);
//	(*cap) = nou;
//}
//
//Pacient popStack(Nod** cap) {
//	Pacient p;
//	p.id = -1;
//	if (cap != NULL && (*cap) != NULL) {
//		
//		Nod* aux = (*cap);
//		p = aux->info;
//		(*cap) = aux->next;
//		free(aux);
//		
//	}
//	return p;
//}
//
//int emptyStack(Nod* cap) {
//	if (cap == NULL) {
//		return 1;
//	}
//	else { 
//		return 0;
//	}
//}
//
//Nod* citireStackPacientiDinFisier(const char* numeFisier) {
//	FILE* f = fopen(numeFisier, "r");
//	Nod* lista = NULL;
//	while (!feof(f)) {
//		pushStack(&lista, citirePacientDinFisier(f));
//	}
//	fclose(f);
//	return lista;
//}
//
//void dezalocareStivaDePacienti(Nod** cap) {
//	while (*cap != NULL) {
//		Pacient p = popStack(cap);
//		if(p.nume)  free(p.nume);
//		if(p.diagnostic) free(p.diagnostic);
//	}
//}
//
//int size(Nod* cap) {
//	int k = 0;
//	while (cap) {
//		k++;
//		cap = cap->next;
//	}
//	return k;
//}
//
////QUEUE
//
//typedef struct NOD NOD;
//struct NOD {
//	Pacient info;
//	NOD* next;
//	NOD* prev;
//};
//typedef struct ListaDubla ListaDubla;
//struct ListaDubla {
//	NOD* last;
//	NOD* first;
//};
//
////adaug la inceput
//void enqueue(ListaDubla* lista, Pacient pacient) {
//	NOD* nou = (NOD*)malloc(sizeof(NOD));
//	nou->info = pacient;
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
//Pacient dequeue(ListaDubla* lista) {
//	Pacient p;
//	p.id = -1;
//	if (lista->last != NULL) {
//		p = lista->last->info;
//		lista->last = lista->last->prev;
//		if (lista->last != NULL) {
//			free(lista->last->next);
//			lista->last->next = NULL;
//		}
//		else {
//			free(lista->first);
//			lista->first = NULL;
//		}
//	}
//	return p;
//}
//
//ListaDubla citireCoadaDePacientiDinFisier(const char* numeFisier) {
//	FILE* f = fopen(numeFisier, "r");
//	ListaDubla lista;
//	lista.first = NULL;
//	lista.last = NULL;
//	while (!feof(f)) {
//		enqueue(&lista, citirePacientDinFisier(f));
//	}
//	fclose(f);
//	return lista;
//}
//
//void dezalocareCoadaDePacienti(ListaDubla* lista) {
//	if (lista == NULL)return;
//	while (lista->first != NULL)
//	{
//		Pacient p = dequeue(lista);
//		free(p.nume);
//		free(p.diagnostic);
//	}
//	lista->first = NULL;
//	lista->last = NULL;
//}
//
//
//
//Pacient getPacientByID(Nod** cap, int id) {
//	Pacient pacient;
//	pacient.id = -1;
//	Pacient p;
//	Nod* stiva = NULL;
//	while ((*cap) && (*cap)->info.id != id) {
//		pushStack(&stiva, popStack(cap));
//	}
//	if (*cap != NULL) {
//		p = popStack(cap);
//		pacient = p;
//		pacient.nume = (char*)malloc(sizeof(char) * (strlen(p.nume) + 1));
//		strcpy(pacient.nume, p.nume);
//		pacient.diagnostic = (char*)malloc(sizeof(char) * (strlen(p.diagnostic) + 1));
//		strcpy(pacient.diagnostic, p.diagnostic);
//		pushStack(&stiva, p);
//	}
//	while (stiva != NULL) {
//		pushStack(cap, popStack(&stiva));
//	}
//	return pacient;
//}
//
//float calculeazaGreutateTotala(ListaDubla lista) {
//	if (lista.first == NULL) {
//		return 0;
//	}
//	else {
//		float total = 0;
//		NOD* aux = lista.first;
//		while (aux) {
//			total += aux->info.greutate;
//			aux = aux->next;
//		}
//		return total;
//	}
//}
//
//int main() {
//	Nod* stiva = citireStackPacientiDinFisier("pacienti.txt");
//	if (emptyStack(stiva)) {
//		printf("Stiva este goala.\n");
//	}
//	else {
//		printf("Stiva nu este goala.\n");
//	}
//	printf("Size stiva: %d.\n", size(stiva));
//
//	
//	printf("\nPacientul cu id 3:\n");
//	afisarePacient(getPacientByID(&stiva, 3));
//	printf("------------------------------------------\n");
//
//	afisarePacient(popStack(&stiva));
//	afisarePacient(popStack(&stiva));
//
//	dezalocareStivaDePacienti(&stiva);
//	if (emptyStack(stiva)) {
//		printf("Stiva este goala.\n");
//	}
//	else {
//		printf("Stiva nu este goala.\n");
//	}
//
//
//	printf("=====================================================================\n");
//	ListaDubla coada = citireCoadaDePacientiDinFisier("pacienti.txt");
//	printf("Coada:\n");
//	printf("\nGreutatea totala a pacientilor este: %5.2f\n", calculeazaGreutateTotala(coada));
//	afisarePacient(dequeue(&coada));
//	afisarePacient(dequeue(&coada));
//	
//	dezalocareCoadaDePacienti(&coada);
//	
//
//	return 0;
//}


#define _CRT_SECURE_NO_WARNINGS
//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
//
//struct StructuraFilm {
//    int id;
//    int durataMinute;
//    float rating;
//    char* titlu;
//    char* regizor;
//    unsigned char gen;
//};typedef struct StructuraFilm Film;
//
//typedef struct Nod Nod;
//struct Nod {
//    Film info;
//    Nod* next;
//};
//
//Film citireFilmDinFisier(FILE* file) {
//    char buffer[100];
//    char sep[3] = ",\n";
//    fgets(buffer, 100, file);
//    Film f;
//    f.id = atoi(strtok(buffer, sep));
//    f.durataMinute = atoi(strtok(NULL, sep));
//    f.rating = atof(strtok(NULL, sep));
//    char* aux;
//    aux = strtok(NULL, sep);
//    f.titlu = (char*)malloc(sizeof(char) * (strlen(aux) + 1));
//    strcpy_s(f.titlu, (strlen(aux) + 1), aux);
//    aux = strtok(NULL, sep);
//    f.regizor = (char*)malloc(sizeof(char) * (strlen(aux) + 1));
//    strcpy_s(f.regizor, (strlen(aux) + 1), aux);
//    f.gen = strtok(NULL, sep)[0];
//    return f;
//}
//
//void afisareFilm(Film f) {
//    printf("ID: %d\n", f.id);
//    printf("Durata (minute): %d\n", f.durataMinute);
//    printf("Rating: %5.2f\n", f.rating);
//    printf("Titlu: %s\n", f.titlu);
//    printf("Regizor: %s\n", f.regizor);
//    printf("Gen: %c\n\n", f.gen);
//}
//
//void afisareListaFilme(Nod* cap) {
//    while (cap) {
//        afisareFilm(cap->info);
//        cap = cap->next;
//    }
//}
//
//void adaugaFilmInLista(Nod** cap, Film f) {
//    Nod* nou = (Nod*)malloc(sizeof(Nod));
//    nou->info = f;
//    nou->next = NULL;
//    if ((*cap) == NULL) {
//        (*cap) = nou;
//    }
//    else {
//        Nod* aux = *cap;
//        while (aux->next != NULL) {
//            aux = aux->next;
//        }
//        aux->next = nou;
//    } 
//}
//
//Nod* citireListaFilmeDinFisier(const char* numeFisier) {
//    FILE* f = fopen(numeFisier, "r");
//    Nod* lista =NULL;
//    while (!feof(f)) {
//        adaugaFilmInLista(&lista, citireFilmDinFisier(f));
//    }
//    fclose(f);
//    return lista;
//}
//
//void dezalocareListaFilme(Nod** cap) {
//    while ((*cap)!=NULL) {
//        Nod* temp = (*cap);
//        (*cap) = (*cap)->next;
//        if (temp->info.titlu != NULL) {
//            free(temp->info.titlu);
//        }
//        if (temp->info.regizor != NULL) {
//            free(temp->info.regizor);
//        }
//        free(temp);
//    }
//}
//
//float calculeazaRatingMediu(Nod* cap) {
//    if (cap == NULL) {
//        return 0;
//    }
//    else {
//        float sum = 0;
//        int k = 0;
//        while (cap) {
//            sum += cap->info.rating;
//            k++;
//            cap = cap->next;
//        }
//        if (k != 0) {
//            return sum / k;
//        }
//        else {
//            return 0;
//        }
//    }
//}
//
//
//float calculeazaDurataMedieDupaGen(Nod* cap, const char gen) {
//    if (cap == NULL) {
//        return 0;
//    }
//    else {
//        float sum = 0;
//        int k = 0;
//        while (cap) {
//            if (cap->info.gen == gen) {
//                sum += cap->info.durataMinute;
//                k++;
//            }
//            cap = cap->next;
//        }
//        if (k != 0) {
//            return sum / k;
//        }
//        else {
//            return 0;
//        }
//    }
//}
//
//void stergeFilmCuID(Nod** cap, int id) {
//    if (*cap == NULL) {
//        return;
//    }
//    else {
//        Nod* temp = *cap;
//        if (temp->info.id == id) {
//            (*cap) = (*cap)->next;
//        }
//        else {
//            Nod* aux = temp;
//            while (temp->next != NULL && temp->info.id != id) {
//                aux = temp;
//                temp = temp->next;
//            }
//            aux->next = temp->next;
//        }
//        if (temp->info.titlu != NULL) {
//            free(temp->info.titlu);
//        }
//        if (temp->info.regizor != NULL) {
//            free(temp->info.regizor);
//        }
//        free(temp);
//    }
//}
//
//int main() {
//
//    Nod* lista = citireListaFilmeDinFisier("filme.txt");
//    afisareListaFilme(lista);
//    printf("===================================================\n");
//    printf("Ratingul mediu este: %5.2f\n", calculeazaRatingMediu(lista));
//    printf("Durata medie a filmelor de actiune este: %5.2f\n", calculeazaDurataMedieDupaGen(lista, 'A'));
//    printf("===================================================\n");
//    printf("Stergere film cu id 4:\n");
//    stergeFilmCuID(&lista, 4);
//    afisareListaFilme(lista);
//    printf("===================================================\n");
//    dezalocareListaFilme(&lista);
//    printf("Lista dupa dezalocare:\n");
//    afisareListaFilme(lista);
//
//    return 0;
//}




#define _CRT_SECURE_NO_WARNINGS
//#include<stdlib.h>
//#include<stdio.h>
//#include<string.h>
//
//struct StructuraFilm {
//    int id;
//    int durataMinute;
//    float rating;
//    char* titlu;
//    char* regizor;
//    unsigned char gen;
//};
//
//typedef struct StructuraFilm Film;
//
//typedef struct Nod Nod;
//struct Nod
//{
//    Film info;
//    Nod* next;
//    Nod* prev;
//};
//
//typedef struct ListaDubla ListaDubla;
//struct ListaDubla {
//    Nod* first;
//    Nod* last;
//    int nrNoduri;
//};
//
//
//
//Film citireFilmDinFisier(FILE* file) {
//    char buffer[100];
//    char sep[3] = ",\n";
//    fgets(buffer, 100, file);
//    Film f;
//    f.id = atoi(strtok(buffer, sep));
//    f.durataMinute = atoi(strtok(NULL, sep));
//    f.rating = atof(strtok(NULL, sep));
//    char* aux;
//    aux = strtok(NULL, sep);
//    f.titlu = (char*)malloc(sizeof(char) * (strlen(aux) + 1));
//    strcpy_s(f.titlu, (strlen(aux) + 1), aux);
//    aux = strtok(NULL, sep);
//    f.regizor = (char*)malloc(sizeof(char) * (strlen(aux) + 1));
//    strcpy_s(f.regizor, (strlen(aux) + 1), aux);
//    f.gen = strtok(NULL, sep)[0];
//    return f;
//}
//
//
//void afisareFilm(Film f) {
//    printf("ID: %d\n", f.id);
//    printf("Durata (minute): %d\n", f.durataMinute);
//    printf("Rating: %5.2f\n", f.rating);
//    printf("Titlu: %s\n", f.titlu);
//    printf("Regizor: %s\n", f.regizor);
//    printf("Gen: %c\n\n", f.gen);
//}
//
//void afisareLDFilme(ListaDubla lista) {
//    if (lista.first == NULL) {
//        return;
//    }
//    else {
//        Nod* aux = lista.first;
//        while (aux) {
//            afisareFilm(aux->info);
//            aux = aux->next;
//        }
//    }
//}
//
//void adaugaFilmInLista(ListaDubla* lista, Film f) {
//    Nod* nou = (Nod*)malloc(sizeof(Nod));
//    nou->info = f;
//    nou->next = NULL;
//    nou->prev = lista->last;
//    if (lista->last != NULL) {
//        lista->last->next = nou;
//    }
//    else {
//        lista->first = nou;
//    }
//    lista->last = nou;
//    lista->nrNoduri++;
//}
//
//ListaDubla citireLDFilmeDinFisier(const char* numeFisier) {
//    FILE* f = fopen(numeFisier, "r");
//    ListaDubla lista;
//    lista.first = NULL;
//    lista.last = NULL;
//    lista.nrNoduri = 0;
//    while (!feof(f)) {
//        adaugaFilmInLista(&lista, citireFilmDinFisier(f));
//    }
//    fclose(f);
//    return lista;
//}
//
//void dezalocareLDFilme(ListaDubla* lista) {
//    while (lista->first != NULL) {
//        Nod* aux = lista->first;
//        lista->first = lista->first->next;
//        if (aux->info.titlu != NULL) {
//            free(aux->info.titlu);
//        }
//        if (aux->info.regizor != NULL) {
//            free(aux->info.regizor);
//        }
//        free(aux);
//    }
//    lista->first = NULL;
//    lista->last = NULL;
//    lista->nrNoduri = 0;
//}
//
//float calculeazaRatingMediu(ListaDubla lista) {
//    if (lista.first == NULL) {
//        return 0;
//    }
//    else {
//        float sum = 0;
//        int k = 0;
//        while (lista.first != NULL) {
//            sum += lista.first->info.rating;
//            k++;
//            lista.first = lista.first->next;
//        }
//        if (k != 0) {
//            return sum / k;
//        }
//        else {
//            return 0;
//        }
//    }
//}
//
//char* getTitluFilmRatingMare(ListaDubla lista) {
//    if (lista.first == NULL) {
//        return NULL;
//    }
//    else {
//        Nod* aux = lista.first;
//        while (lista.first != NULL) {
//            if (lista.first->info.rating > aux->info.rating) {
//                aux = lista.first;
//            }
//            lista.first = lista.first->next;
//        }
//        char* nume = (char*)malloc(sizeof(char) * (strlen(aux->info.titlu) + 1));
//        strcpy(nume, aux->info.titlu);
//        return nume;
//    }
//}
//
//void stergeFilmRatingMic(ListaDubla* lista) {
//    if (lista->first == NULL) {
//        return;
//    }
//    else {
//        Nod* min = lista->first;
//        if (lista->first != lista->last) {
//            
//            Nod* aux = lista->first;
//            while (aux != NULL) {
//                if (aux->info.rating < min->info.rating) {
//                    min = aux;
//
//                }
//                aux = aux->next;
//            }
//            if (min == lista->first) {
//                lista->first = lista->first->next;
//                lista->first->prev = NULL;
//            }
//            else {
//                if (min->next != NULL) {
//                    aux = lista->first;
//                    while (aux->next != NULL && aux != min) {
//                        aux = aux->next;
//                    }
//                    aux->prev->next = aux->next;
//                    aux->next->prev = aux->prev;
//                }
//                else {
//                    lista->last = lista->last->prev;
//                    lista->last->next = NULL;
//                }
//
//            }
//        }
//        else {
//            lista->first = NULL;
//            lista->last = NULL;
//        }
//        if (min->info.titlu != NULL) {
//            free(min->info.titlu);
//        }
//        if (min->info.regizor != NULL) {
//            free(min->info.regizor);
//        }
//        free(min);
//        lista->nrNoduri--;
//    }
//}
//
//void stergereFilmeDupaGen(ListaDubla* lista, const char gen) {
//    if (lista->first == NULL) {
//        return;
//    }
//    else {
//        if (lista->first == lista->last && lista->first->info.gen ==gen) {
//            lista->first = NULL;
//            lista->last = NULL;
//        }
//        else {
//            Nod* temp = lista->first;
//            while (temp != NULL) {
//                Nod* aux = temp;
//                temp = temp->next;
//                if (aux->info.gen == gen) {
//                    if (aux == lista->first) {
//                        lista->first = lista->first->next;
//                        lista->first->prev == NULL;
//                    }
//                    else {
//                        if (aux == lista->last) {
//                            lista->last = lista->last->prev;
//                            lista->last->next = NULL;
//                        }
//                        else {
//                            aux->prev->next = aux->next;
//                            aux->next->prev = aux->prev;
//                        }
//                    }
//                    
//                    if (aux->info.titlu != NULL) {
//                        free(aux->info.titlu);
//                    }
//                    if (aux->info.regizor != NULL) {
//                        free(aux->info.regizor);
//                    }
//                    free(aux);
//                    lista->nrNoduri--;
//                }
//                
//                
//            }
//            
//        }
//    }
//}
//
//
//
//
//int main() {
//    ListaDubla lista = citireLDFilmeDinFisier("filme.txt");
//    afisareLDFilme(lista);
//    printf("============================================\n");
//    printf("Ratingul mediu este: %5.2f\n", calculeazaRatingMediu(lista));
//    char* nume = getTitluFilmRatingMare(lista);
//    printf("Filmul cu cel mai mare rating este: %s\n", nume);
//    stergeFilmRatingMic(&lista);
//    printf("Lista dupa stergere film cu rating min:\n");
//    afisareLDFilme(lista);
//    printf("============================================\n");
//    stergereFilmeDupaGen(&lista, 'A');
//    printf("Lista dupa stergere filme de actiune:\n");
//    afisareLDFilme(lista);
//    printf("============================================\n");
//    dezalocareLDFilme(&lista);
//    printf("Lista dupa dezalocare:\n");
//    afisareLDFilme(lista);
//
//    return 0;
//}




#define _CRT_SECURE_NO_WARNINGS
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
//typedef struct Nod Nod;
//struct Nod {
//	Carte info;
//	Nod* next;
//};
//
//struct HashTable {
//	int dim;
//	Nod** tabel;
//};
//typedef struct HashTable HashTable;
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
//	printf("Numarr pagini: %d\n", carte.nrPagini);
//	printf("Pret: %.2f\n", carte.pret);
//	printf("Titlu: %s\n", carte.titlu);
//	printf("Autor: %s\n", carte.autor);
//	printf("Editie: %c\n\n", carte.editie);
//}
//
//void afisareListCarti(Nod* cap) {
//	while (cap) {
//		afisareCarte(cap->info);
//		cap = cap->next;
//	}
//}
//
//void adaugaCarteInLista(Nod** cap, Carte c) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = c;
//	nou->next = NULL;
//	if (*cap == NULL) {
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
//
//HashTable initializareHashTable(int dimensiune) {
//	HashTable ht;
//	ht.dim = dimensiune;
//	ht.tabel = (Nod**)malloc(sizeof(Nod*) * dimensiune);
//	for (int i = 0;i < dimensiune;i++) {
//		ht.tabel[i] = NULL;
//	}
//	return ht;
//}
//
////int calculeazaHash(const char* titlu, int dimensiune) {
////	int sum = 0;
////	for (int i = 0; i < strlen(titlu);i++) {
////		sum += titlu[i];
////	}
////	return sum % dimensiune;
////}
//
//int calculeazaHash(int id, int dimensiune) {
//	id = id * 23 + 123;
//	return id % dimensiune;
//}
//
//
//void inserareCarteInTabela(HashTable hash, Carte c) {
//	int poz = calculeazaHash(c.id, hash.dim);
//	adaugaCarteInLista(&hash.tabel[poz], c);
//}
//
//HashTable citireCartiDinFisier(const char* numeFisier, int dimensiune) {
//	FILE* f = fopen(numeFisier, "r");
//	HashTable ht = initializareHashTable(dimensiune);
//	while (!feof(f)) {
//		inserareCarteInTabela(ht, citireCarteFisier(f));
//	}
//	feof(f);
//	return ht;
//}
//
//void afisareTabelaDeCarti(HashTable ht) {
//	for (int i = 0; i < ht.dim;i++) {
//		printf("Clusterul %d:\n", i+1);
//		afisareListCarti(ht.tabel[i]);
//		printf("-------------------------------\n");
//	}
//}
//
//void dezalocareListaCarti(Nod** cap) {
//	Nod* aux = *cap;
//	while (aux) {
//		Nod* temp = aux;
//		aux = aux->next;
//		if (temp->info.titlu != NULL) {
//			free(temp->info.titlu);
//		}
//		if (temp->info.autor != NULL) {
//			free(temp->info.autor);
//		}
//		free(temp);
//	}
//}
//
//void dezalocareTabelaDeCarti(HashTable *ht) {
//	for (int i = 0; i < ht->dim;i++) {
//		dezalocareListaCarti(&ht->tabel[i]);
//	}
//	ht->dim = 0;
//	ht->tabel = NULL;
//}
//
//float* calculeazaPreturiMediiPerClustere(HashTable ht, int* nrClustere) {
//	(*nrClustere) = 0;
//	for (int i = 0;i < ht.dim;i++) {
//		if (ht.tabel[i] != NULL) {
//			(*nrClustere)++;
//		}
//	}
//	float* vPreturi = (float*)malloc(sizeof(float) * (*nrClustere));
//	int p = 0;
//	for (int i = 0;i < ht.dim;i++) {
//		float sum = 0;
//		int k = 0;
//		Nod* aux = ht.tabel[i];
//		while (aux != NULL) {
//			sum += aux->info.pret;
//			k++;
//			aux = aux->next;
//		}
//		vPreturi[p++] = sum / k;
//	}
//	return vPreturi;
//}
//
//Carte getCarteDupaCheie(HashTable ht, int id) {
//	Carte m;
//	m.id = -1;
//	int poz = calculeazaHash(id, ht.dim);
//	if (poz >= 0 && poz < ht.dim) {
//		Nod* aux = ht.tabel[poz];
//		while (aux) {
//			if (aux->info.id == id) {
//				m = aux->info;
//				m.titlu = (char*)malloc(sizeof(char) * (strlen(aux->info.titlu) + 1));
//				strcpy(m.titlu, aux->info.titlu);
//				m.autor = (char*)malloc(sizeof(char) * (strlen(aux->info.autor) + 1));
//				strcpy(m.autor, aux->info.autor);
//				break;
//			}
//			aux = aux->next;
//		}
//	}
//	return m;
//}
//
//int main() {
//	int dim = 4;
//	HashTable ht = citireCartiDinFisier("carti.txt", dim);
//	afisareTabelaDeCarti(ht);
//	printf("=============================================\n");
//	int nrClustere;
//	float* preturi = calculeazaPreturiMediiPerClustere(ht, &nrClustere);
//	for (int i = 0;i < nrClustere;i++) {
//		printf("Clusterul %d are pretul mediu de: %5.2f\n", i+1, preturi[i]);
//	}
//	printf("Cartea cu id 3 este:\n");
//	afisareCarte(getCarteDupaCheie(ht, 3));
//	printf("=============================================\n");
//	dezalocareTabelaDeCarti(&ht);
//	printf("Tabela dupa dezalocare:\n");
//	afisareTabelaDeCarti(ht);
//	return 0;
//}