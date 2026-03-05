#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//trebuie sa folositi fisierul masini.txt
//sau va creati un alt fisier cu alte date

struct StructuraMasina {
	int id;
	int nrUsi;
	float pret;
	char* model;
	char* numeSofer;
	unsigned char serie;
};
typedef struct StructuraMasina Masina;

void afisareMasina(Masina masina) {
	printf("\nID: %d\n", masina.id);
	printf("Numar usi: %d\n", masina.nrUsi);
	printf("Pret: %2f\n", masina.pret);
	printf("Model: %s\n", masina.model);
	printf("Sofer: %s\n", masina.numeSofer);
	printf("Serie: %c\n\n", masina.serie);

}

void afisareVectorMasini(Masina* masini, int nrMasini) {
	for (int i = 0;i < nrMasini;i++)
	{
		afisareMasina(masini[i]);
	}
}

void adaugaMasinaInVector(Masina** masini, int* nrMasini, Masina masinaNoua) //vector masini - pointer transmis prin adresa
{

	Masina* temp = (Masina*)malloc(sizeof(Masina) * ((*nrMasini) + 1));//aici am o sg steluta => accesam direct
	for (int i = 0; i < *nrMasini;i++)
	{
		temp[i] = (*masini)[i];//pt ca masini e pointer la pointer si tr dereferentiat mai intai

	}
	//shallow copy -  va copia adresele doar pt model si sofer, dar daca fac deep copy voi avea 2 adrese distincte

	temp[*nrMasini] = masinaNoua;
	free(*masini);
	(*masini) = temp;//ca sa pointeze spre adresa de inceput a lui temp
	(*nrMasini)++;

}

Masina citireMasinaFisier(FILE* file) {

	//fscanf - citeste pene la spatiu => daca numele masinii ar avea spatiu in el ar citi doar primul cuvant

	Masina m;
	char buffer[50];//alocare statica, deoarece il folosesc doar in cazul aceste functii,
	//iar 50 pt ca in buffer salvam un sir de caractere a carui lungime nu o cunoastem si sa fie mai mare decatcea mai lunga linie de caractere din fisier
	fgets(buffer, 50, file);//50 = nr max de caractere
	char var[3] = " ,\n";//3 - cu 1 mai mult decat nr de val pe care poate sa il aiba(, si \n)
	//strtok(buffer, var) //1-sirul pe care urmeaza sa il sparg, 2 - delimitatorul
	m.id = atoi(strtok(buffer, var));//atoi	- face transformarea de la sir de caractere in intreg
	m.nrUsi = atoi(strtok(NULL, var)); //ca sa inceapa de unde si-a lasat flag-ul, nu iarasi de la inceput
	m.pret = atof(strtok(NULL, var));
	char* aux = strtok(NULL, var);//nu tr sa dezalocam zona asta de mem pt ca ce se afla acolo e pe stiva(pe care o dezaloca compilatorul)
	m.model = (char*)malloc(sizeof(char) * (strlen(aux) + 1));
	strcpy(m.model, aux);
	aux = strtok(NULL, var);
	m.numeSofer = (char*)malloc(sizeof(char) * (strlen(aux) + 1));
	strcpy(m.numeSofer, aux);
	m.serie = (strtok(NULL, var))[0];

	return m;

}

Masina* citireVectorMasiniFisier(const char* numeFisier, int* nrMasiniCitite) {

	FILE* file;
	file = fopen(numeFisier, "r");

	Masina* masini = NULL;
	*nrMasiniCitite = 0; //ca sa ma asigur ca pleaca de la 0 si nu conteaza valoarea pe care o dau in main

	while (!feof(file))
	{
		//ar mai tr verificat daca exista fisierul
		adaugaMasinaInVector(&masini, nrMasiniCitite, citireMasinaFisier(file));
	}
	fclose(file);
	return masini;

}

void dezalocareVectorMasini(Masina** vector, int* nrMasini) {
	//este dezalocat intreg vectorul de masini
	for (int i = 0;i < (*nrMasini);i++)
	{
		free((*vector)[i].model);
		free((*vector)[i].numeSofer);//deref+deplasare+deref+accesare
	}

	free(*vector);
	(*vector) = NULL;
	nrMasini = 0;

}

int main() {
	int nrMasini = 0;
	Masina* masini = NULL;
	masini = citireVectorMasiniFisier("masini.txt", &nrMasini);
	afisareVectorMasini(masini, nrMasini);
	dezalocareVectorMasini(&masini, &nrMasini);
	return 0;
}