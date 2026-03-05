//// [] indexare = deplasare + dereferentiere
//// -> = dereferentiere + accesare
//
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//
//
//
//struct Biblioteca {
//	int id;
//	int nrCarti;
//	char* nume;
//	float suprafata;
//	char sector;
//};
//struct Biblioteca initializare(int id, int nrCarti, char* nume, float suprafata, char sector) {
//	struct Biblioteca s;
//	s.id = id;
//	s.nrCarti = nrCarti;
//	s.nume = (char*)malloc(sizeof(char) * (strlen(nume) + 1));
//	strcpy(s.nume, nume);
//	s.suprafata = suprafata;
//	s.sector = sector;
//	return s;
//}
//
//struct Biblioteca copiazaBiblioteca(struct Biblioteca sursa) {
//	return initializare(sursa.id, sursa.nrCarti, sursa.nume, sursa.suprafata, sursa.sector);
//
//}
//
//void afisare(struct Biblioteca s) {
//	printf("ID-ul: %d\t\n Numarul de carti: %d\n Denumire: %s\n Suprafata: %5.2f\n Sector: %c\n", s.id, s.nrCarti, s.nume, s.suprafata, s.sector);
//}
//
//void afisareVector(struct Biblioteca* vector, int nrElemente) {
//	for (int i = 0; i < nrElemente; i++) {
//		afisare(vector[i]);
//	}
//}
//
//struct Biblioteca* copiazaPrimeleNElemente(struct Biblioteca* vector, int nrElemente, int nrElementeCopiate) {
//
//	struct Biblioteca* vectorNou = NULL;
//	if (nrElementeCopiate > nrElemente) {
//		nrElementeCopiate = nrElemente;
//	}
//
//	vectorNou = (struct Biblioteca*)malloc(sizeof(struct Biblioteca) * nrElementeCopiate);
//	for (int i = 0; i < nrElementeCopiate; i++) {
//		vectorNou[i] = copiazaBiblioteca(vector[i]);
//	}
//
//	return vectorNou;
//}
//
//void dezalocare(struct Biblioteca** vector, int* nrElemente) {
//
//	for (int i = 0; i < *nrElemente; ++i) {
//		free((*vector)[i].nume);
//
//
//	}
//	free((*vector));
//	*vector = NULL;
//	*nrElemente = 0;
//
//
//}
//
//void copiazaBibcuSupMare(struct Biblioteca* vector, char nrElemente, float supMin, struct Biblioteca** vectorNou, int* dimensiune) {
//
//	*dimensiune = 0;
//	for (int i = 0; i < nrElemente; ++i) {
//		if (vector[i].suprafata > supMin) {
//			(*dimensiune)++;
//		}
//	}
//
//	*vectorNou = (struct Biblioteca*)malloc(sizeof(struct Biblioteca) * (*dimensiune));
//
//	int contor = 0;
//	for (int i = 0; i < nrElemente; ++i) {
//		if (vector[i].suprafata > supMin) {
//			(*vectorNou)[contor++] = copiazaBiblioteca(vector[i]);
//		}
//	}
//}
//
//struct Biblioteca getPrimulElementConditionat(struct Biblioteca* vector, int nrElemente, const char* conditie) {
//
//	struct Biblioteca s;
//	s.id = 1;
//	
//	return s;
//}
//
//
//
//int main() {
//	struct Biblioteca b;
//	b = initializare(1, 100, "Biblioteca nationala", 500.5, '3');
//	//afisare(b);
//
//	int numarBiblioteci = 5;
//	struct Biblioteca* vectorBiblioteci = (struct Biblioteca*)malloc(sizeof(struct Biblioteca) * numarBiblioteci);
//
//	//o biblioteca ocupa 21 de octeti, iar malloc aloca 40 octeti => acum ocupa 205 octeti
//	vectorBiblioteci[0] = copiazaBiblioteca(b);
//	vectorBiblioteci[1] = initializare(2, 200, "Biblioteca ASE", 200.6, '1');
//	vectorBiblioteci[2] = initializare(3, 300, "Biblioteca Sadoveanu", 234.8, '4');
//	vectorBiblioteci[3] = initializare(4, 400, "Biblioteca Creanga", 345.6, '5');
//	vectorBiblioteci[4] = initializare(5, 500, "Biblioteca I.L.Caragiale", 456.9, '6');
//
//	afisareVector(vectorBiblioteci, numarBiblioteci);
//	int nrCopiate = 3;
//	struct Biblioteca* copie = copiazaPrimeleNElemente(vectorBiblioteci, numarBiblioteci, nrCopiate);
//	printf("\nElementele vect cu primele %d elemente copiate\n", nrCopiate);
//	afisareVector(copie, nrCopiate);
//
//	dezalocare(&copie, &nrCopiate);
//
//	struct Biblioteca* vBibcuSupMAre = NULL;
//	int nrBibCuSupM = 0;
//	copiazaBibcuSupMare(vectorBiblioteci, numarBiblioteci, 300.00, &vBibcuSupMAre, &nrBibCuSupM);
//	printf("\nElementele vect biblioteci cu suprafata mare\n");
//	afisareVector(vBibcuSupMAre, nrBibCuSupM);
//
//	dezalocare(&vBibcuSupMAre, &nrBibCuSupM);
//	dezalocare(&vectorBiblioteci, &numarBiblioteci);
//
//	
//	return 0;
//}
//


//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//struct Eveniment {
//	int id;
//	char* nume;
//	int locuriDisponibile;
//	float pretBilet;
//	char tip; // 'C' - Concert, 'F' - Festival, 'T' - Teatru
//};
//
//
//
//struct Eveniment initializare(int id, int locuriDisponibile, char* nume, float pretBilet, char tip) {
//	struct Eveniment s;
//	s.id = id;
//	s.nume = (char*)malloc(sizeof(char) * (strlen(nume) + 1));
//	if (nume != NULL)
//	{
//		strcpy_s(s.nume, strlen(nume) + 1, nume);
//	}
//	s.locuriDisponibile = locuriDisponibile;
//	s.pretBilet = pretBilet;
//	s.tip = tip;
//	return s;
//}
//struct Eveniment copiazaEveniment(struct Eveniment e)
//{
//	return initializare(e.id, e.locuriDisponibile, e.nume, e.pretBilet, e.tip);
//}
//
//void afisare(struct Eveniment s) {
//	printf("\nID: %d\n", s.id);
//	printf("Nume: %s\n", s.nume);
//	printf("Locuri Disponibile: %d\n", s.locuriDisponibile);
//	printf("Pret Bilet: %5.2f\n", s.pretBilet);
//	printf("Tip eveniment: %c\n", s.tip);
//}
//
//void afisareVector(struct Eveniment* vector, int nrElemente) {
//	for (int i = 0;i < nrElemente;i++)
//	{
//		afisare(vector[i]);
//	}
//}
//
//struct Eveniment* copiazaPrimeleNElemente(struct Eveniment* vector, int nrElemente, int nrElementeCopiate) {
//
//	struct Eveniment* vectorNou = NULL;
//	if (nrElementeCopiate > nrElemente)
//	{
//		nrElementeCopiate = nrElemente;
//	}
//
//	vectorNou = (struct Eveniment*)malloc(sizeof(struct Eveniment) * nrElementeCopiate);
//	for (int i = 0;i < nrElementeCopiate;i++)
//	{
//		vectorNou[i] = copiazaEveniment(vector[i]);
//	}
//
//	return vectorNou;
//}
//
//void dezalocare(struct Eveniment** vector, int* nrElemente) {
//	for (int i = 0; i < *nrElemente;i++)
//	{
//		free((*vector)[i].nume);
//	}
//	free(*vector);
//	*vector = NULL;
//	*nrElemente = 0;
//}
//
//void copiazaAnumiteElemente(struct Eveniment* vector, char nrElemente, int prag, struct Eveniment** vectorNou, int* dimensiune) {
//	*dimensiune = 0;
//
//	for (int i = 0; i < nrElemente;i++)
//	{
//		if (vector[i].locuriDisponibile > prag)
//		{
//			(*dimensiune)++;
//		}
//	}
//
//	*(vectorNou) = (struct Eveniment*)malloc(sizeof(struct Eveniment) * (*dimensiune));
//
//	int contor = 0;
//	for (int i = 0; i < nrElemente;i++)
//	{
//		if (vector[i].locuriDisponibile > prag)
//		{
//			(*vectorNou)[contor++] = copiazaEveniment(vector[i]);
//		}
//	}
//
//}
//
//struct Eveniment getPrimulElementConditionat(struct Eveniment* vector, int nrElemente, const char* nume) {
//
//	for (int i = 0;i < nrElemente;i++)
//	{
//		if (strcmp(vector[i].nume, nume) == 0)
//		{
//			return copiazaEveniment(vector[i]);
//		}
//	}
//	struct Eveniment s;
//	s.id = -1;
//	s.nume = "Inexistent";
//	s.locuriDisponibile = 0;
//	s.pretBilet = 0;
//	s.tip = 'X';
//	return s;
//}
//
//
//
//int main() {
//	struct Eveniment e;
//	e = initializare(1, 150, "Concert Rock", 85.5, 'C');
//	//afisare(e);
//
//	int numarEvenimente = 6;
//	struct Eveniment* vectorEvenimente = (struct Eveniment*)malloc(sizeof(struct Eveniment) * numarEvenimente);
//
//	vectorEvenimente[0] = copiazaEveniment(e);
//	vectorEvenimente[1] = initializare(2, 5000, "Untold Festival", 450.0, 'F');
//	vectorEvenimente[2] = initializare(3, 200, "O scrisoare pierduta", 120.0, 'T');
//	vectorEvenimente[3] = initializare(4, 50, "Jazz Night", 65.0, 'C');
//	vectorEvenimente[4] = initializare(5, 1200, "Summer Well", 350.5, 'F');
//	vectorEvenimente[5] = initializare(6, 800, "Opera Aida", 210.0, 'T');
//
//	printf("\nEvementele vectorului de evenimente sunt:\n");
//	afisareVector(vectorEvenimente, numarEvenimente);
//
//	int nrElCopiate = 4;
//	struct Eveniment* vecNouEv = copiazaPrimeleNElemente(vectorEvenimente, numarEvenimente, nrElCopiate);
//	printf("\nEvementele noului vector de %d evenimente sunt:\n", nrElCopiate);
//	afisareVector(vecNouEv, nrElCopiate);
//
//	struct Eveniment* vecEvDisponibile = NULL;
//	int nrEvDisp = 0;
//	copiazaAnumiteElemente(vectorEvenimente, numarEvenimente, 700, &vecEvDisponibile, &nrEvDisp);
//	printf("\nEvementele vectorului cu evenimente disponibile:\n");
//	afisareVector(vecEvDisponibile, nrEvDisp);
//
//	struct Eveniment e1 = getPrimulElementConditionat(vectorEvenimente, numarEvenimente, "Sum");
//	printf("\nPrimul element conditionat este:\n");
//	afisare(e1);
//
//	dezalocare(&vecEvDisponibile, &nrEvDisp);
//	dezalocare(&vecNouEv, &nrElCopiate);
//	dezalocare(&vectorEvenimente, &numarEvenimente);
//	return 0;
//}
