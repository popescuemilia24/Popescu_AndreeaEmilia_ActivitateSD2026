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
//struct Nod {
//	Masina info;
//	struct Nod* stanga;
//	struct Nod* dreapta;
//};typedef struct Nod Nod;
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
//	if (masina.id != -1) {
//		printf("Id: %d\n", masina.id);
//		printf("Nr. usi : %d\n", masina.nrUsi);
//		printf("Pret: %.2f\n", masina.pret);
//		printf("Model: %s\n", masina.model);
//		printf("Nume sofer: %s\n", masina.numeSofer);
//		printf("Serie: %c\n\n", masina.serie);
//	}
//	else {
//		printf("Masina nu exista!!!!\n");
//	}
//
//}
//
//
//void adaugaMasinaInArbore(Nod** radacina, Masina masinaNoua) {
//
//	if (*radacina) {
//		if ((*radacina)->info.id < masinaNoua.id) {
//			adaugaMasinaInArbore(&(*radacina)->dreapta, masinaNoua);
//		}
//		if ((*radacina)->info.id > masinaNoua.id) {
//			adaugaMasinaInArbore(&(*radacina)->stanga, masinaNoua);
//		}
//	}
//	else {
//		Nod* nou = (Nod*)malloc(sizeof(Nod));
//		nou->info = masinaNoua;
//		nou->stanga = NULL;
//		nou->dreapta = NULL;
//		*radacina = nou;
//	}
//}
//
//Nod* citireArboreDeMasiniDinFisier(const char* numeFisier) {
//	FILE* f = fopen(numeFisier, "r");
//	Nod* arbore = NULL; // setez cu NULL pt a intra pe else atunci cand apelez pt prima data adauga...
//	while (!feof(f)) {
//		adaugaMasinaInArbore(&arbore, citireMasinaDinFisier(f));
//	}
//	fclose(f);
//	return arbore;
//}
//
//void afisareMasiniDinArborePreordine(Nod* radacina) {
//	//parcurgerea arborelui poate fi realizata in TREI moduri
//	//-preordine = radacina -> stanga -> dreapta  (RSD)
//	//-postordine = stanga -> dreapta -> radacina (SDR) -----> elementele sunt parcurse descrescator
//	//-inordine = stanga -> radacina -> dreapta (SDR) -----> elementele sunt parcurse crescator
//	//folositi toate cele TREI moduri de parcurgere
//	if (radacina) {
//		afisareMasina(radacina->info);
//		afisareMasiniDinArborePreordine(radacina->stanga);
//		afisareMasiniDinArborePreordine(radacina->dreapta);
//	}
//
//}
//
//void afisareMasiniDinArboreInordine(Nod* radacina) {
//	if (radacina) {
//		afisareMasiniDinArboreInordine(radacina->stanga);
//		afisareMasina(radacina->info);
//		afisareMasiniDinArboreInordine(radacina->dreapta);
//	}
//
//}
//
//void dezalocareArboreDeMasini(Nod** radacina) {
//	if (*radacina) {
//		dezalocareArboreDeMasini(&(*radacina)->stanga);
//		dezalocareArboreDeMasini(&(*radacina)->dreapta);
//		if (((*radacina)->info.model)) free((*radacina)->info.model);
//		if (((*radacina)->info.numeSofer)) free((*radacina)->info.numeSofer);
//		free(*radacina);
//		(*radacina) = NULL;
//	}
//}
//
//Masina getMasinaByID(Nod* radacina, int idCautat) {
//	if (radacina) {
//		if (radacina->info.id == idCautat) {
//			Masina m = radacina->info;
//			m.numeSofer = (char*)malloc(sizeof(char) * (strlen(radacina->info.numeSofer) + 1));
//			strcpy(m.numeSofer, radacina->info.numeSofer);
//			m.model = (char*)malloc(sizeof(char) * (strlen(radacina->info.model) + 1));
//			strcpy(m.model, radacina->info.model);
//			return m;
//		}
//		if (radacina->info.id < idCautat) {
//			return getMasinaByID(radacina->dreapta, idCautat);
//		}
//		if (radacina->info.id > idCautat) {
//			return getMasinaByID(radacina->stanga, idCautat);
//		}
//	}
//	else {
//		Masina m;
//		m.id = -1;
//		return m;
//	}
//}
//
//int determinaNumarNoduri(Nod* radacina) {
//	if (radacina) {
//		/*int nrNoduriStanga = determinaNumarNoduri(radacina->stanga);
//		int nrNoduriDreapta = determinaNumarNoduri(radacina->dreapta);
//		return nrNoduriDreapta + nrNoduriDreapta + 1;*/
//		return determinaNumarNoduri(radacina->stanga) + determinaNumarNoduri(radacina->dreapta) + 1;
//	}
//	return 0;
//}
//
//int calculeazaInaltimeArbore(Nod* radacina) {
//	if (radacina) {
//		return max(calculeazaInaltimeArbore(radacina->stanga), calculeazaInaltimeArbore(radacina->dreapta)) + 1;
//	}
//	return 0;
//}
//
//float calculeazaPretTotal(Nod* radacina) {
//	if (radacina) {
//		return calculeazaPretTotal(radacina->stanga) + calculeazaPretTotal(radacina->dreapta) + radacina->info.pret;
//	}
//	return 0;
//}
//
//float calculeazaPretulMasinilorUnuiSofer(Nod* radacina, const char* numeSofer) {
//	if (radacina) {
//		if (strcmp(radacina->info.numeSofer, numeSofer) == 0) {
//			return calculeazaPretulMasinilorUnuiSofer(radacina->stanga, numeSofer) + calculeazaPretulMasinilorUnuiSofer(radacina->dreapta, numeSofer) + radacina->info.pret;
//		}
//		else {
//			return calculeazaPretulMasinilorUnuiSofer(radacina->stanga, numeSofer) + calculeazaPretulMasinilorUnuiSofer(radacina->dreapta, numeSofer);
//		}
//
//	}
//	return 0;
//}
//
//int main() {
//	Nod* radacina = citireArboreDeMasiniDinFisier("masini_arbore.txt");
//	afisareMasiniDinArboreInordine(radacina);
//
//	int id = 7;
//	Masina m = getMasinaByID(radacina, id);
//	printf("Masina cu id-ul %d:\n", id);
//	afisareMasina(m);
//	printf("\n");
//	printf("Numarul de noduri din arbore este %d\n", determinaNumarNoduri(radacina));
//	printf("\n");
//	printf("Inaltimea arborelui este %d\n", calculeazaInaltimeArbore(radacina));
//	printf("\n");
//	printf("Pretul total este %5.2f\n", calculeazaPretTotal(radacina));
//	printf("\n");
//	char* nume = "Ionescu";
//	printf("Pretul masinilor pe care le detine %s este %5.2f\n", nume, calculeazaPretulMasinilorUnuiSofer(radacina, nume));
//	dezalocareArboreDeMasini(&radacina);
//	printf("Arbore dupa dezalocare: \n");
//	afisareMasiniDinArborePreordine(radacina);
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
//
//struct Nod {
//	Carte info;
//	struct Nod* stanga;
//	struct Nod* dreapta;
//};typedef struct Nod Nod;
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
//
//void adaugaCarteInArbore(Nod** radacina, Carte carteNoua) {
//	if (*radacina)
//	{
//		if ((*radacina)->info.id < carteNoua.id) {
//			adaugaCarteInArbore(&(*radacina)->dreapta, carteNoua);
//		}
//		if ((*radacina)->info.id > carteNoua.id) {
//			adaugaCarteInArbore(&(*radacina)->stanga, carteNoua);
//		}
//	}
//	else {
//		Nod* nou = (Nod*)malloc(sizeof(Nod));
//		nou->info = carteNoua;
//		nou->stanga = NULL;
//		nou->dreapta = NULL;
//		*radacina = nou;
//	}
//}
//
//Nod* citireArboreDeCartiDinFisier(const char* numeFisier) {
//	FILE* f = fopen(numeFisier, "r");
//	Nod* arbore = NULL;
//	while (!feof(f)) {
//		adaugaCarteInArbore(&arbore, citireCarteFisier(f));
//	}
//	fclose(f);
//	return arbore;
//}
//
//void afisareCartiDinArbore(Nod* radacina) {
//	if (radacina) {
//		afisareCarte(radacina->info);
//		afisareCartiDinArbore(radacina->stanga);
//		afisareCartiDinArbore(radacina->dreapta);
//	}
//
//}
//
//void dezalocareArboreDeCarti(Nod** radacina) {
//	if (*radacina) {
//		dezalocareArboreDeCarti(&(*radacina)->stanga);
//		dezalocareArboreDeCarti(&(*radacina)->dreapta);
//		if (((*radacina)->info.titlu)) free((*radacina)->info.titlu);
//		if (((*radacina)->info.autor)) free((*radacina)->info.autor);
//		free(*radacina);
//		(*radacina) = NULL;
//	}
//}
//
//Carte getCarteByID(Nod* radacina, int id) {
//	if (radacina == NULL) {
//		Carte c;
//		c.id = -1;
//		return c;
//	}
//	else
//	{
//		if (radacina->info.id == id) {
//			Carte c = radacina->info;
//			c.titlu = (char*)malloc(sizeof(char) * (strlen(radacina->info.titlu) + 1));
//			strcpy(c.titlu, radacina->info.titlu);
//			c.autor = (char*)malloc(sizeof(char) * (strlen(radacina->info.autor) + 1));
//			strcpy(c.autor, radacina->info.autor);
//			return c;
//		}
//		if (radacina->info.id < id) {
//			return getCarteByID(radacina->dreapta, id);
//		}
//		if (radacina->info.id > id) {
//			return getCarteByID(radacina->stanga, id);
//		}
//	}
//
//}
//
//int determinaNumarNoduri(Nod* radacina) {
//	if (radacina) {
//		return determinaNumarNoduri(radacina->stanga) + determinaNumarNoduri(radacina->dreapta) + 1;
//	}
//	return 0;
//}
//
//int calculeazaInaltimeArbore(Nod* radacina) {
//	if (radacina) {
//		return max(calculeazaInaltimeArbore(radacina->stanga), calculeazaInaltimeArbore(radacina->dreapta)) + 1;
//	}
//	return 0;
//}
//
//float calculeazaPretTotal(Nod* radacina) {
//	if (radacina) {
//		return calculeazaPretTotal(radacina->stanga) + calculeazaPretTotal(radacina->dreapta) + radacina->info.pret;
//	}
//	return 0;
//}
//
//float calculeazaPretulCartilorUnuiAutor(Nod* radacina, const char* numeAutor) {
//	if (radacina) {
//		if (strcmp(radacina->info.autor, numeAutor) == 0) {
//			return calculeazaPretulCartilorUnuiAutor(radacina->stanga, numeAutor) + calculeazaPretulCartilorUnuiAutor(radacina->dreapta, numeAutor) + radacina->info.pret;
//		}
//		else {
//			return calculeazaPretulCartilorUnuiAutor(radacina->stanga, numeAutor) + calculeazaPretulCartilorUnuiAutor(radacina->dreapta, numeAutor);
//		}
//	}
//	return 0;
//}
//
//int main() {
//	Nod* radacina = citireArboreDeCartiDinFisier("Carti_arbore.txt");
//	afisareCartiDinArbore(radacina);
//
//	int id = 8;
//	Carte c = getCarteByID(radacina, id);
//	printf("Cartea cu id-ul %d:\n", id);
//	afisareCarte(c);
//	printf("\n");
//
//	printf("Numarul de noduri din arbore este: %d\n", determinaNumarNoduri(radacina));
//	printf("\n");
//	printf("Inaltimea arborelui este: %d\n", calculeazaInaltimeArbore(radacina));
//	printf("\n");
//	printf("Pretul total este: %5.2f\n", calculeazaPretTotal(radacina));
//	printf("\n");
//
//	char* autor = "Liviu Rebreanu";
//	printf("Pretul total al cartilor autorului %s este %5.2f\n", autor, calculeazaPretulCartilorUnuiAutor(radacina, autor));
//	printf("\n");
//
//	dezalocareArboreDeCarti(&radacina);
//	printf("Arbore dupa dezalocare: \n");
//	afisareCartiDinArbore(radacina);
//
//
//	return 0;
//}