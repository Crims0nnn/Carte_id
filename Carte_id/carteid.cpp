#include <stdio.h>
#include <string>
#include <string.h>

#define T 255

typedef struct date {
	int jour = 1;
	int mois = 1;
	int an = 1;
}date;

typedef struct adress {
	char* str_rue;
	int n_cp = 0;
	char* str_ville;
}adress;

typedef enum class genre { M, Mme }civ;

typedef struct carteid {
	int n_id;
	civ E_civ = {};
	char* str_nom;
	char* str_prenom;
	date* t_date;
	adress* t_adress;
}carteid;

void Date(date* t_date);
void Adress(adress* t_adress);
void Genre(civ* E_civ);
void CarteID(carteid* t_carteid);
void Affichage(date* t_date, adress* t_adress, civ* E_civ, carteid* t_carteid);
int main() {

	date* t_date;
	t_date = nullptr;
	t_date = (date*)malloc(T * sizeof(date));
	adress* t_adress;
	t_adress = (adress*)malloc(T * sizeof(adress));
	carteid* t_carteid;
	t_carteid = nullptr;
	t_carteid = (carteid*)malloc(T * sizeof(carteid));
	civ* E_civ;
	E_civ = (civ*)malloc(T * sizeof(civ));
	E_civ = nullptr;
	
	

	Date(t_date);
	Adress(t_adress);
	CarteID(t_carteid);
	Genre(E_civ);
	Affichage(t_date, t_adress, E_civ, t_carteid);

	return 0;
}
//Fonction Date
void Date(date* t_date) {
	int n_jour = 0;
	int n_mois = 0;
	int n_an = 0;
	int i = 0;
	do {
		printf_s("Quel jour? \n");
		scanf_s("%d", &n_jour);
		if (n_jour <= 0) {
			printf_s("Quel jour? \n");
			scanf_s("%d", &n_jour);
		}
		printf_s("Quel mois? \n");
		scanf_s("%d", &n_mois);
		if (n_mois <= 0) {
			printf_s("Quel mois \n");
			scanf_s("%d", &n_mois);
		}
		printf_s("Quel annee? \n");
		scanf_s("%d", &n_an);
		if (n_an <= 0) {
			printf_s("Quel an \n");
			scanf_s("%d", &n_an);
		}
		t_date[i].jour = n_jour;
		t_date[i].mois = n_mois;
		t_date[i].an = n_an;
		i++;
	} while (i != 1);
};
//Fonction Adress
void Adress(adress* t_adress) {
	adress str_ok;
	int n_codep = 0;
	for (int i = 0; i < 1; i++) {
		printf_s("Quel est le nom de votre rue\n");
		str_ok.str_rue = (char*)malloc(T * sizeof(char));
		if (str_ok.str_rue != nullptr) {
		scanf_s("%s", str_ok.str_rue,T);
		}
		printf_s("Quel est votre code postale");
		scanf_s("%d", &n_codep);
		printf_s("Quel est le nom de votre ville");
		str_ok.str_ville = (char*)malloc(T * sizeof(char));
		if (str_ok.str_ville != nullptr) {
			scanf_s("%s", str_ok.str_ville,T);
		}
		t_adress[i].str_rue = str_ok.str_rue;
		t_adress[i].n_cp = n_codep;
		t_adress[i].str_ville = str_ok.str_ville;
		i++;
	}
};
//Fonction Genre
void Genre(civ* E_civ) {
	char str_G;
	char str_test;
	int i = 0;
	printf_s("Quel est votre genre Homme ou Femme,Tapez M ou F  ?");
	scanf_s(" %c", &str_G,1);
	if (str_G == 'M') {
		civ E_civ = civ::M;
		printf_s("M \n");
	}
	else {
		civ E_civ = civ::Mme;
		printf_s("Mme\n");
	}
};
//Fonction Affichage
carteid ok;
int n_iden = 0;
int i = 0;

void CarteID(carteid* t_carteid) {
	for (i; i < 1; i++) {
		printf_s("Quel est votre id");
		scanf_s("%d", &n_iden);
		printf_s("Quel est votre nom?\n");
		ok.str_nom = (char*)malloc(T * sizeof(char));
		if (ok.str_nom != nullptr) {
			scanf_s("%s", ok.str_nom, T);
		}
		printf_s("Quel est votre prenom?\n");
		ok.str_prenom = (char*)malloc(T * sizeof(char));
		if (ok.str_prenom != nullptr) {
			scanf_s("%s", ok.str_prenom, T);
		}
		t_carteid[i].str_nom = ok.str_nom;
		t_carteid[i].str_prenom = ok.str_prenom;
		t_carteid[i].n_id = n_iden;
		i++;
		}
	};
void Affichage(date* t_date, adress* t_adress, civ* E_civ, carteid* t_carteid) {
	printf_s(" %d", E_civ);
	printf_s("Votre Nom:%s / votre prenom:%s / votre id:%d \n", t_carteid->str_nom, t_carteid->str_prenom, t_carteid->n_id);
	printf_s("Date:%d/%d/%d \n", t_date->jour, t_date->mois, t_date->an);
	printf_s("Rue:%s/adress:%d/ville:%s \n", t_adress->str_rue, t_adress->n_cp, t_adress->str_ville);
};