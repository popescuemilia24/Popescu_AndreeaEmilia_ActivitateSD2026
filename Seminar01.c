#include<stdio.h>
#include<stdlib.h>

struct Produs {
	int id;
	int stoc;//4 octeti
	char* denumire; //8 octeti
	float pret; //4 octeti
	char categorie; //1 octet
};

struct Produs initializare(int id, int stoc, char* denumire, float pret, char categorie) {
	struct Produs s;
	s.id = id;
	s.stoc = stoc;
	s.denumire = (char*)malloc(sizeof(char) * (strlen(denumire) + 1));//sizeof calculeaza marimea unui anumit TIP
	strcpy(s.denumire, denumire);
	s.pret = pret;
	s.categorie = categorie;

	return s;
}

void afisare(struct Produs s) {
	printf("\nID: %d\n", s.id);
	printf("STOC: %d\n", s.stoc);
	printf("DENUMIRE: %s\n", s.denumire);
	printf("PRET: %5.2f\n", s.pret);
	printf("CATEGORIE: %c\n", s.categorie);
}

void modifica_Denumire(struct Produs* s, char* nouaDenumire) {
	free((*s).denumire);
	(*s).denumire = (char*)malloc(sizeof(char) * (strlen(nouaDenumire) + 1));
	strcpy(s->denumire, nouaDenumire);

}

void dezalocare(struct Produs* s) {
	if (s->denumire != NULL)
	{
		free(s->denumire);
		s->denumire = NULL;
	}
}

float CalculeazaTotal(struct Produs p)
{
	return p.stoc * p.pret;
}

int main() {
	struct Produs s;

	////verificare nr octeti
	//char* c;
	//printf("Un pointer ocupa: %d octeti", sizeof(c));

	s = initializare(1, 20, "Telefon smart", 2000, 'A'); //daca il las cu A cu "A" ocupa mai mult - va avea 2 octeti- l-ar vedea ca un sir si ar lua si sfarsitul, cu 'A' vom avea un singur caracter
	afisare(s);

	modifica_Denumire(&s, "Mouse");
	afisare(s);
	printf("\nValoarea totala pentru %s este %5.2f RON\n", s.denumire, CalculeazaTotal(s));

	//struct Produs* ps = &s;//retine o adresa de pe stack
	//struct Produs* pp = malloc (sizeof(struct Produs));//are o adresa de pe heap
	////eu nu am voie sa modific o adresa de pe stack...
	//free(pp);
	//free(ps);

	dezalocare(&s);
	return 0;
}