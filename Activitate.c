//SEMINAR1 1 - STRUCTURI SI FUNCTII
// 
// #include<stdio.h>
//#include<stdlib.h>
//
//struct Haina {
//	int marime;
//	char* marca;
//	float pret;
//	char gender;
//};
//
//void afiseazaHaina(struct Haina h) {
//	if (h.marca != NULL) {
//		printf("Marca: %s\n", h.marca);
//	}
//	printf("Marime: %d\n", h.marime);
//	printf("Pret: %5.2f\n", h.pret);
//	printf("Gen:%c\n\n", h.gender);
//}
//
//struct Haina initializareHaina(int marime, const char* marca, float pret, char gen) {
//	struct Haina h;
//	h.marime = marime;
//	if (marca != NULL && strlen(marca) > 0) {
//		h.marca = malloc(strlen(marca) + 1);
//		strcpy(h.marca, marca);
//	}
//	else {
//		h.marca = NULL;
//	}
//	h.pret = pret;
//	h.gender = gen;
//	return h;
//}
//
//void dezalocareHaina(struct Haina *h) {
//	free(h->marca);
//	(*h).marca = NULL;
//}
//
//void main() {
//	struct Haina haina1;
//	haina1.marime = 33;
//	haina1.marca = (char*)malloc(sizeof(char) * (strlen("Nike") + 1));
//	strcpy(haina1.marca, "Nike");
//	haina1.pret = 45;
//	haina1.gender = 'M';
//
//	afiseazaHaina(haina1);
//
//	dezalocareHaina(&haina1);
//
//	struct Haina haina2 = initializareHaina(27, "Addidas", 23.6, 'F');
//
//	afiseazaHaina(haina2);
//	
//	dezalocareHaina(&haina2);
//	afiseazaHaina(haina2);
//
//}

// SEMINAR 2 - VECTORI

//#include<stdio.h>
//#include<malloc.h>
//
//struct Avion {
//	int nrPasageri;
//	char* companie;
//	float pretBilet;
//};
//
//struct Avion initializareAvion(int nrPasageri, const char* companie, float pretBilet) {
//	struct Avion avion;
//	avion.nrPasageri = nrPasageri;
//	avion.companie = (char*)malloc(sizeof(char) * (strlen(companie) + 1));
//	strcpy(avion.companie, companie);
//	avion.pretBilet = pretBilet;
//
//	return avion;
//}
//
//void afisareAvion(struct Avion avion) {
//	printf("%s are un avion de %d locuri cu pretul de %5.2f RON pe loc\n", avion.companie, avion.nrPasageri, avion.pretBilet);
//}
//
//void afisareVectorAvioane(struct Avion* vector, int nrAvioane) {
//	if (vector != NULL) {
//		for (int i = 0; i < nrAvioane; i++) {
//			afisareAvion(vector[i]);
//		}
//	}
//}
//
//struct Avion* copiazaPrimeleNAvioane(struct Avion* avioane, int nrAvioane, int nrAvioaneCopiate) {
//	if (nrAvioaneCopiate < nrAvioane && nrAvioaneCopiate>0) {
//		struct Avion* avioaneCopiate = (struct Avion*)malloc(sizeof(struct Avion) * nrAvioaneCopiate);
//		for (int i = 0; i < nrAvioaneCopiate; i++) {
//			avioaneCopiate[i] = initializareAvion(avioane[i].nrPasageri, avioane[i].companie, avioane[i].pretBilet);
//		}
//		return avioaneCopiate;
//	}
//	else {
//		return NULL;
//	}
//}
//
//void dezalocare(struct Avion** avioane, int* nrAvioane) {
//	if ((*avioane) != NULL) {
//		for (int i = 0; i < *nrAvioane; i++) {
//			free((*avioane)[i].companie);
//		}
//		free(*avioane);
//		*nrAvioane = 0;
//		*avioane = NULL;
//	}
//}
//
//void copiazaAvioaneCuBileteReduse(struct Avion* avioane, int nrAvioane, float pragPret, struct Avion** avioaneNou, int* dimensiune) {
//	if (*avioaneNou != NULL) {
//		dezalocare(avioaneNou, dimensiune);
//	}
//	else {
//		*dimensiune = 0;
//	}
//	for (int i = 0; i < nrAvioane; i++) {
//		if (avioane[i].pretBilet < pragPret) {
//			(*dimensiune)++;
//		}
//	}
//	
//	*avioaneNou = (struct Avion*)malloc(sizeof(struct Avion) * (*dimensiune));
//	int k = 0;
//	for (int i = 0; i < nrAvioane; i++) {
//		if (avioane[i].pretBilet < pragPret) {
//			(*avioaneNou)[k++] = initializareAvion(avioane[i].nrPasageri, avioane[i].companie, avioane[i].pretBilet);
//		}		
//	}
//}
//
//struct Avion getPrimulAvionDupaCompanie(struct Avion* avioane, int nrAvioane, const char* companie) {
//	if (avioane != NULL && companie != NULL) {
//		for (int i = 0; i < nrAvioane; i++) {
//			if (avioane[i].companie != NULL) {
//				if (strcmp(avioane[i].companie, companie) == 0) {
//					return initializareAvion(avioane[i].nrPasageri,avioane[i].companie,avioane[i].pretBilet);
//				}
//			}			
//		}
//
//	}
//	
//	return initializareAvion(-1, "N/A", -1);
//	
//}
//	
//
//
//void main() {
//
//	int nrAvioane = 5;
//	struct Avion* avioane = (struct Avion*)malloc(sizeof(struct Avion) * nrAvioane);
//	for (int i = 0; i < nrAvioane; i++) {
//		avioane[i] = initializareAvion(i + 50, "Tarom", 10 * i + 40);
//	}
//	afisareVectorAvioane(avioane, nrAvioane);
//
//	int nrAvioaneCopiate = 3;
//
//	struct Avion* avioaneCopiate = copiazaPrimeleNAvioane(avioane, nrAvioane, nrAvioaneCopiate);
//
//	printf("\n\n");
//	afisareVectorAvioane(avioaneCopiate, nrAvioaneCopiate);
//
//	struct Avion* avioaneCuBileteReduse = NULL;
//	int nrAvioaneCuBileteReduse = 0;
//
//	avioane[4].pretBilet = 30;
//
//	copiazaAvioaneCuBileteReduse(avioane, nrAvioane, 60, &avioaneCuBileteReduse, &nrAvioaneCuBileteReduse);
//	printf("\n\n");
//	afisareVectorAvioane(avioaneCuBileteReduse, nrAvioaneCuBileteReduse);
//
//
//	struct Avion avion = getPrimulAvionDupaCompanie(avioane, nrAvioane, "Tarom");
//
//	printf("Avion cautat:\n");
//	afisareAvion(avion);
//
//
//	dezalocare(&avioane, &nrAvioane);
//	dezalocare(&avioaneCopiate, &nrAvioaneCopiate);
//	dezalocare(&avioaneCuBileteReduse, &nrAvioaneCuBileteReduse);
//	free(avion.companie);
//
//	
//
//}

//SEMINAR 3
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//struct Locuinta {
//	int id;
//	char* strada;
//	int numar;
//};
//
//void inserareLocuinta(struct Locuinta** vector, int* dim,
//	struct Locuinta l)
//{
//	struct Locuinta* copie;
//	copie = malloc(sizeof(struct Locuinta) * 
//		(++(*dim)));
//	for (int i = 0; i < (*dim) - 1; i++)
//	{
//		copie[i] = (*vector)[i];
//	}
//	copie[(*dim) - 1] = l;
//	if ((*vector) != NULL)
//	{
//		free((*vector));
//	}
//	(*vector) = copie;
//}
//
//void citesteFisier(const char* nume_fisier, struct Locuinta** vector,
//	int* dim) {
//	if (nume_fisier != NULL && strlen(nume_fisier) > 0) {
//		FILE* f = fopen(nume_fisier, "r");
//		if (f != NULL) {
//			(*dim) = 0;
//			char buffer[100];
//			char delimitator[] = ",\n";
//			while (fgets(buffer, 100, f) != NULL) {
//				char* token;
//				token = strtok(buffer, delimitator);
//				struct Locuinta locuinta;
//				locuinta.id = atoi(token);
//				token = strtok(NULL, delimitator);
//				locuinta.strada = (char*)malloc(strlen(token) + 1);
//				strcpy(locuinta.strada, token);
//				token = strtok(NULL, delimitator);
//				locuinta.numar = atoi(token);
//				inserareLocuinta(vector, dim, locuinta);
//			}
//			fclose(f);
//		}
//	}
//}
//void afisareLocuinta(struct Locuinta l) {
//	printf("ID-ul: %d\t%s numarul %d\n", 
//		l.id, l.strada, l.numar);
//}
//void afisareVectorLocuinte(struct Locuinta* vector, int dim) {
//	for (int i = 0; i < dim; i++)
//		afisareLocuinta(vector[i]);
//}
//
//
//void stergeLocuinta(struct Locuinta** vector, int* dim, int id) {
//	char flag = 0;
//	for (int i = 0; i < (*dim); i++) {
//		if ((*vector)[i].id == id) {
//			flag = 1;
//			break;
//		}
//	}
//	if (flag==1) { //avem o locuinta de sters
//		struct Locuinta* copie = (struct Locuinta*)malloc(sizeof(struct Locuinta)
//			*((*dim) - 1));
//		int j = 0;
//		for (int i = 0; i < (*dim); i++) {
//			if ((*vector)[i].id != id) {
//				copie[j++] = (*vector)[i];
//			}
//		}
//		(*dim)--;
//		if ((*vector) != NULL)
//		{
//			free((*vector));
//		}
//		(*vector) = copie;
//	}
//}
//
//
//void main() {
//	struct Locuinta *locuinte = NULL;
//	int dim = 3;
//	citesteFisier("locuinte.txt", &locuinte, &dim);
//	printf("Initial\n\n");
//	afisareVectorLocuinte(locuinte, dim);
//	
//	printf("\n\nUlterior\n\n");
//	stergeLocuinta(&locuinte, &dim, 22);
//	afisareVectorLocuinte(locuinte, dim);
// 
// 
//}


//SEMIANR 4

//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//struct Locuinta {
//	int id;
//	char* strada;
//	int numar;
//};
//
//void inserareLocuinta(struct Locuinta** vector, int* dim,
//	struct Locuinta l)
//{
//	struct Locuinta* copie;
//	copie = malloc(sizeof(struct Locuinta) * 
//		(++(*dim)));
//	for (int i = 0; i < (*dim) - 1; i++)
//	{
//		copie[i] = (*vector)[i];
//	}
//	copie[(*dim) - 1] = l;
//	if ((*vector) != NULL)
//	{
//		free((*vector));
//	}
//	(*vector) = copie;
//}
//
//void citesteFisier(const char* nume_fisier, struct Locuinta** vector,
//	int* dim) {
//	if (nume_fisier != NULL && strlen(nume_fisier) > 0) {
//		FILE* f = fopen(nume_fisier, "r");
//		if (f != NULL) {
//			(*dim) = 0;
//			char buffer[100];
//			char delimitator[] = ",\n";
//			while (fgets(buffer, 100, f) != NULL) {
//				char* token;
//				token = strtok(buffer, delimitator);
//				struct Locuinta locuinta;
//				locuinta.id = atoi(token);
//				token = strtok(NULL, delimitator);
//				locuinta.strada = (char*)malloc(strlen(token) + 1);
//				strcpy(locuinta.strada, token);
//				token = strtok(NULL, delimitator);
//				locuinta.numar = atoi(token);
//				inserareLocuinta(vector, dim, locuinta);
//			}
//			fclose(f);
//		}
//	}
//}
//void afisareLocuinta(struct Locuinta l) {
//	printf("ID-ul: %d\t%s numarul %d\t", 
//		l.id, l.strada, l.numar);
//}
//void afisareVectorLocuinte(struct Locuinta* vector, int dim) {
//	for (int i = 0; i < dim; i++)
//		afisareLocuinta(vector[i]);
//}
//
//
//void stergeLocuinta(struct Locuinta** vector, int* dim, int id) {
//	char flag = 0;
//	for (int i = 0; i < (*dim); i++) {
//		if ((*vector)[i].id == id) {
//			flag = 1;
//			break;
//		}
//	}
//	if (flag==1) { //avem o locuinta de sters
//		struct Locuinta* copie = (struct Locuinta*)malloc(sizeof(struct Locuinta)
//			*((*dim) - 1));
//		int j = 0;
//		for (int i = 0; i < (*dim); i++) {
//			if ((*vector)[i].id != id) {
//				copie[j++] = (*vector)[i];
//			}
//		}
//		(*dim)--;
//		if ((*vector) != NULL)
//		{
//			free((*vector));
//		}
//		(*vector) = copie;
//	}
//}
//
//void dezalocareMatrice(struct Locuinta*** matrice, int* nr_linii, int** nr_coloane) {
//	for (int i = 0; i < (*nr_linii); i++) {
//		for(int j = 0; j < (*nr_coloane)[i]; j++) {
//			free((*matrice)[i][j].strada);
//			(*matrice)[i][j].strada = NULL;
//		}
//		free((*matrice)[i]);
//
//	}
//	free(*matrice);
//	*matrice = NULL;
//
//	(*nr_linii) = 0;
//	free(*nr_coloane);
//	*nr_coloane = NULL;
//
//
//}
//
//void citesteMatriceFisier(const char* nume_fisier, struct Locuinta** matrice, int nr_linii, int* nr_coloane) {
//	if (nume_fisier != NULL && strlen(nume_fisier) > 0) {
//		FILE* f = fopen(nume_fisier, "r");
//		if (f != NULL) {
//			char buffer[100];
//			char delimitator[] = ",\n";
//			while (fgets(buffer, 100, f) != NULL) {
//				char* token;
//				token = strtok(buffer, delimitator);
//				struct Locuinta locuinta;
//				locuinta.id = atoi(token);
//				token = strtok(NULL, delimitator);
//				locuinta.strada = (char*)malloc(strlen(token) + 1);
//				strcpy(locuinta.strada, token);
//				token = strtok(NULL, delimitator);
//				locuinta.numar = atoi(token);
//				int pozitie = locuinta.numar % 2;
//				inserareLocuinta(&(matrice[pozitie]), &(nr_coloane[pozitie]), locuinta);
//			}
//			fclose(f);
//		}
//	}
//}
//
//void afisareMatrice(struct Locuinta** matrice, int nr_linii, int* nr_coloane)
//{
//	for (int i = 0; i < nr_linii; i++)
//	{
//		for (int j = 0; j < nr_coloane[i]; j++)
//		{
//			afisareLocuinta(matrice[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//void afisareIdDePeOParte(int paritate, struct Locuinta** matrice, int nr_linii, int* nr_coloane) {
//	paritate = paritate % 2;
//
//		for (int j = 0; j < nr_coloane[paritate]; j++) {
//				printf("%d ", matrice[paritate][j].id);
//		}
//
//}
//
//struct Locuinta cautareLocuintaDupaID(int idCautat, struct Locuinta** matrice, int nr_linii, int* nr_coloane) {
//	for (int i = 0; i < nr_linii; i++) {
//		for (int j = 0; j < nr_coloane[i]; j++) {
//			if (matrice[i][j].id == idCautat) {
//				return matrice[i][j];
//			}
//		}
//	}
//
//	struct Locuinta copie;
//	copie.id = -1;
//	copie.numar = -1;
//	copie.strada = NULL;
//	
//	return copie;
//	
//}
//
//void schimbareNumarLocuinta(struct Locuinta** matrice, int nrLinii, int* nrColoane, int numarLocuinta) {
//	int pozitie = numarLocuinta % 2;
//	int idLocuinta = -1;
//	int indexInVector = -1;
//	for (int i = 0; i < nrColoane[pozitie]; i++) {
//		if (matrice[pozitie][i].numar == numarLocuinta) {
//			matrice[pozitie][i].numar++;
//			idLocuinta = matrice[pozitie][i].id;
//			indexInVector = i;
//		}
//	}
//
//	if (idLocuinta != -1) {
//		int index = (numarLocuinta + 1) % 2;
//		inserareLocuinta(&(matrice[index]), &(nrColoane[index]), matrice[pozitie][indexInVector]);
//		stergeLocuinta(&(matrice[pozitie]), &(nrColoane[pozitie]), idLocuinta);
//	}
//}
//
//
//void main() {
//	int nr_linii;
//	int* nr_coloane;
//	struct Locuinta** matrice;
//
//	nr_linii = 2;
//	nr_coloane = (int*)malloc(sizeof(int) * nr_linii);
//	matrice = (struct Locuinta**)malloc(sizeof(struct Locuinta*) * nr_linii);
//	for (int i = 0; i < nr_linii; i++) {
//		matrice[i] = NULL;
//		nr_coloane[i] = 0;
//	}
//	citesteMatriceFisier("locuinte.txt", matrice, nr_linii, nr_coloane);
//	afisareMatrice(matrice, nr_linii, nr_coloane);
//	int paritate = 11;
//	printf("Id-urile cu paritate impara a numarului: \n");
//	afisareIdDePeOParte(paritate, matrice, nr_linii, nr_coloane);
//
//	struct Locuinta locuinta1 = cautareLocuintaDupaID(17, matrice, nr_linii, nr_coloane);
//	afisareLocuinta(locuinta1);
//
//	schimbareNumarLocuinta(matrice, nr_linii, nr_coloane, 5);
//
//	printf("\n\n dupa mutare\n");
//	afisareMatrice(matrice, nr_linii, nr_coloane);
//
//	dezalocareMatrice(&matrice, &nr_linii, &nr_coloane);
//}

//SEMINAR 5 

//#include<stdio.h>
//#include <malloc.h>
//typedef struct CafeneaMea Cafenea;
//typedef struct Nod Nod;
//
//struct CafeneaMea
//{
//    char* nume;
//    int nrLocuri;
//    float suprafata;
//};
//
//struct Nod
//{
//    Cafenea info;
//    Nod* next;
//};
//
//Cafenea initializareCafenea(const char* nume, int nrLocuri, float suprafata)
//{
//    Cafenea cafenea;
//    cafenea.nrLocuri = nrLocuri;
//    cafenea.suprafata = suprafata;
//    cafenea.nume = (char*)malloc(sizeof(char) * (strlen(nume) + 1));
//    strcpy(cafenea.nume, nume);
//
//    return cafenea;
//}
//Nod* inserareInceput(Cafenea c, Nod* cap)
//{
//    Nod* nou = malloc(sizeof(Nod));
//    nou->next = cap;
//    nou->info = initializareCafenea(c.nume, c.nrLocuri, c.suprafata);
//    return nou;
//
//}
//void afisareCafenea(Cafenea c)
//{
//    printf("\nDenumire: %s Nr scaune: %i Suprafara %.2f\n", c.nume, c.nrLocuri, c.suprafata);
//}
//void afisareCafenele(Nod* lista)
//{
//    while (lista != NULL)
//    {
//        afisareCafenea(lista->info);
//        lista = lista->next;
//    }
//}
////numele cafenelei cu densitatea cea mai mica
//char* numeCafeneaDensitateMinima(Nod* lista)
//{
//    if (lista != NULL)
//    {
//        if (lista->info.suprafata != 0)
//        {
//            float minim = lista->info.nrLocuri / lista->info.suprafata;
//            Nod* adresa = lista;
//            lista = lista->next;
//            while (lista != NULL)
//            {
//                if (lista->info.nrLocuri / lista->info.suprafata < minim)
//                {
//                    minim = lista->info.nrLocuri / lista->info.suprafata;
//                    adresa = lista;
//                }
//                lista = lista->next;
//            }
//            char* nume;
//            nume = malloc(sizeof(char) * (strlen(adresa->info.nume) + 1));
//            strcpy(nume, adresa->info.nume);
//            return nume;
//        }
//    }
//    return NULL;
//}
//void stergeLista(Nod** nod) {
//    while (*nod != NULL) {
//        Nod* aux;
//        aux = *nod;
//        *nod = (*nod)->next;
//        free(aux->info.nume);
//        free(aux);
//
//
//    }
//    *nod = NULL;
//}
//void inserareFinal(Nod** lista, Cafenea c) {
//    if ((*lista) == NULL) {
//        (*lista) = inserareInceput(c,*lista);
//    }
//    else {
//        Nod* curent = (*lista);
//        while (curent->next!=NULL) {
//            curent = curent->next;
//        }
//        Nod* n = (Nod*)malloc(sizeof(Nod));
//       
//        n->info = initializareCafenea(c.nume,c.nrLocuri,c.suprafata);
//        n->next = NULL;
//        curent->next = n;
//    }
//
//}
//
//void main()
//{
//    Nod* cap = NULL;
//    Cafenea cafenea = initializareCafenea("Tucano", 12, 20);
//    Cafenea cafenea2 = initializareCafenea("Teds", 17, 17.3);
//    Cafenea cafenea3 = initializareCafenea("Urban", 65, 33);
//    Cafenea sb = initializareCafenea("Sb", 25, 43);
//    cap = inserareInceput(cafenea, cap);
//    cap = inserareInceput(cafenea2, cap);
//    cap = inserareInceput(cafenea3, cap);
//    afisareCafenele(cap);
//    char* numeMinim = numeCafeneaDensitateMinima(cap);
//    printf("\nCafenea cu dens minima: %s", numeMinim);
//    inserareFinal(&cap, sb);
//    afisareCafenele(cap);
//    stergeLista(&cap);
//    
//    afisareCafenele(cap);
//
//    free(cafenea.nume);
//    cafenea.nume = NULL;
//
//    free(cafenea2.nume);
//    cafenea2.nume = NULL;
//
//    free(cafenea3.nume);
//    cafenea3.nume = NULL;
//
//    free(numeMinim);
//    numeMinim = NULL;
//}

//SEMINAR 6 

//#include<stdio.h>
//#include <malloc.h>
//typedef struct CafeneaMea Cafenea;
//typedef struct Nod Nod;
//typedef struct ListaDubla ListaDubla;
//
//struct CafeneaMea
//{
//    char* nume;
//    int nrLocuri;
//    float suprafata;
//};
//
//struct Nod {
//    Cafenea cafenea;
//    Nod* anterior;
//    Nod* urmator;
//};
//
//struct ListaDubla {
//    Nod* cap;
//    Nod* coada;
//};
//
//void inserareInceput(ListaDubla* listaDubla, Cafenea cafenea) {
//    Nod* nou = malloc(sizeof(Nod));
//    nou->anterior = NULL;
//    nou->cafenea = cafenea;
//    nou->urmator = listaDubla->cap;
//    if (listaDubla->cap != NULL) {
//      listaDubla->cap->anterior = nou;
//    } 
//    else {
//        listaDubla->coada = nou;
//    }
//    listaDubla->cap = nou;
//}
//
//Cafenea initializareCafenea(const char* nume, int nrLocuri, float suprafata)
//{
//    Cafenea cafenea;
//    cafenea.nrLocuri = nrLocuri;
//    cafenea.suprafata = suprafata;
//    cafenea.nume = (char*)malloc(sizeof(char) * (strlen(nume) + 1));
//    strcpy(cafenea.nume, nume);
//
//    return cafenea;
//}
//
//void afisareCafenea(Cafenea c)
//{
//    printf("\nDenumire: %s Nr scaune: %i Suprafara %.2f\n", c.nume, c.nrLocuri, c.suprafata);
//}
//
//void afisareLista(ListaDubla listaDubla) {
//    Nod* nod = listaDubla.cap;
//    while (nod) {
//        afisareCafenea(nod->cafenea);
//        nod = nod->urmator;
//    }
//    printf("\n\n");
//}
//
//ListaDubla stergeCafeneaDupaNume(ListaDubla listaDubla, const char* nume){
//    if (nume == NULL) {
//        return listaDubla;
//    }
//    Nod* nod = listaDubla.cap;
//
//    while (nod && strcmp(nod->cafenea.nume, nume) != 0) {
//        nod = nod->urmator;
//    }
//    if (nod != NULL) {
//        if (nod->urmator == NULL && nod->anterior == NULL) {
//            listaDubla.cap = NULL;
//            listaDubla.coada = NULL;
//        }
//        else {
//            if (nod->anterior == NULL) {
//                listaDubla.cap = nod->urmator;
//                listaDubla.cap->anterior = NULL;
//            }
//            else if (nod->urmator == NULL) {
//                listaDubla.coada = nod->anterior;
//                listaDubla.coada->urmator = NULL;
//            }
//            else {
//                nod->anterior->urmator = nod->urmator;
//                nod->urmator->anterior = nod->anterior;
//            }
//        }
//        free(nod->cafenea.nume);
//        free(nod);
//    }
//    return(listaDubla);
//}
//int NrTotalLocuri(ListaDubla lista) {
//    if (lista.cap == NULL) {
//        return 0;
//    }
//    int nrLocuri = 0;
//    Nod* nod = lista.coada;
//    while (nod != NULL) {
//        nrLocuri += nod->cafenea.nrLocuri;
//        nod = nod->anterior;
//    }
//    return nrLocuri;
//}
//ListaDubla stergeLista(ListaDubla listaDubla) {
//    while (listaDubla.cap != NULL) {
//        free(listaDubla.cap->cafenea.nume);
//        Nod* temp = listaDubla.cap;
//        listaDubla.cap = listaDubla.cap->urmator;
//        free(temp);
//    }
//    listaDubla.cap = NULL;
//    listaDubla.coada = NULL;
//    return listaDubla;
//}
//
//void main()
//{
//    Cafenea cafenea = initializareCafenea("Tucano", 12, 20);
//    Cafenea cafenea2 = initializareCafenea("Teds", 17, 17.3);
//    Cafenea cafenea3 = initializareCafenea("Urban", 65, 33);
//    Cafenea sb = initializareCafenea("Sb", 25, 43);
//
//    ListaDubla listaDubla;
//    listaDubla.cap = NULL;
//    listaDubla.coada = NULL;
//
//    inserareInceput(&listaDubla, cafenea);
//    inserareInceput(&listaDubla, cafenea2);
//    inserareInceput(&listaDubla, cafenea3);
//    inserareInceput(&listaDubla, sb);
//    afisareLista(listaDubla);
//    /*listaDubla = stergeCafeneaDupaNume(listaDubla, "Teds");
//    afisareLista(listaDubla);
//    listaDubla = stergeCafeneaDupaNume(listaDubla, "Tucano");
//    afisareLista(listaDubla);
//    listaDubla = stergeCafeneaDupaNume(listaDubla, "Starbucks");
//    afisareLista(listaDubla);
//    listaDubla = stergeCafeneaDupaNume(listaDubla, "Sb");
//    afisareLista(listaDubla);
//    listaDubla = stergeCafeneaDupaNume(listaDubla, "Urban");
//    afisareLista(listaDubla)*/;
//    printf("Nr locuri totale:%d", NrTotalLocuri(listaDubla));
//    listaDubla = stergeLista(listaDubla);
//    //afisareLista(listaDubla);
//}

//SEMINAR 6
//#include<stdio.h>
//#include <malloc.h>
//typedef struct CafeneaMea Cafenea;
//typedef struct Nod Nod;
//typedef struct ListaDubla ListaDubla;
//
//struct CafeneaMea
//{
//    char* nume;
//    int nrLocuri;
//    float suprafata;
//};
//
//struct Nod {
//    Cafenea cafenea;
//    Nod* anterior;
//    Nod* urmator;
//};
//
//struct ListaDubla {
//    Nod* cap;
//    Nod* coada;
//};
//
//void inserareInceput(ListaDubla* listaDubla, Cafenea cafenea) {
//    Nod* nou = malloc(sizeof(Nod));
//    nou->anterior = NULL;
//    nou->cafenea = cafenea;
//    nou->urmator = listaDubla->cap;
//    if (listaDubla->cap != NULL) {
//      listaDubla->cap->anterior = nou;
//    } 
//    else {
//        listaDubla->coada = nou;
//    }
//    listaDubla->cap = nou;
//}
//
//Cafenea initializareCafenea(const char* nume, int nrLocuri, float suprafata)
//{
//    Cafenea cafenea;
//    cafenea.nrLocuri = nrLocuri;
//    cafenea.suprafata = suprafata;
//    cafenea.nume = (char*)malloc(sizeof(char) * (strlen(nume) + 1));
//    strcpy(cafenea.nume, nume);
//
//    return cafenea;
//}
//
//void afisareCafenea(Cafenea c)
//{
//    printf("\nDenumire: %s Nr scaune: %i Suprafara %.2f\n", c.nume, c.nrLocuri, c.suprafata);
//}
//
//void afisareLista(ListaDubla listaDubla) {
//    Nod* nod = listaDubla.cap;
//    while (nod) {
//        afisareCafenea(nod->cafenea);
//        nod = nod->urmator;
//    }
//    printf("\n\n");
//}
//
//ListaDubla stergeCafeneaDupaNume(ListaDubla listaDubla, const char* nume){
//    if (nume == NULL) {
//        return listaDubla;
//    }
//    Nod* nod = listaDubla.cap;
//
//    while (nod && strcmp(nod->cafenea.nume, nume) != 0) {
//        nod = nod->urmator;
//    }
//    if (nod != NULL) {
//        if (nod->urmator == NULL && nod->anterior == NULL) {
//            listaDubla.cap = NULL;
//            listaDubla.coada = NULL;
//        }
//        else {
//            if (nod->anterior == NULL) {
//                listaDubla.cap = nod->urmator;
//                listaDubla.cap->anterior = NULL;
//            }
//            else if (nod->urmator == NULL) {
//                listaDubla.coada = nod->anterior;
//                listaDubla.coada->urmator = NULL;
//            }
//            else {
//                nod->anterior->urmator = nod->urmator;
//                nod->urmator->anterior = nod->anterior;
//            }
//        }
//        free(nod->cafenea.nume);
//        free(nod);
//    }
//    return(listaDubla);
//}
//int NrTotalLocuri(ListaDubla lista) {
//    if (lista.cap == NULL) {
//        return 0;
//    }
//    int nrLocuri = 0;
//    Nod* nod = lista.coada;
//    while (nod != NULL) {
//        nrLocuri += nod->cafenea.nrLocuri;
//        nod = nod->anterior;
//    }
//    return nrLocuri;
//}
//ListaDubla stergeLista(ListaDubla listaDubla) {
//    while (listaDubla.cap != NULL) {
//        free(listaDubla.cap->cafenea.nume);
//        Nod* temp = listaDubla.cap;
//        listaDubla.cap = listaDubla.cap->urmator;
//        free(temp);
//    }
//    listaDubla.cap = NULL;
//    listaDubla.coada = NULL;
//    return listaDubla;
//}
//
//void main()
//{
//    Cafenea cafenea = initializareCafenea("Tucano", 12, 20);
//    Cafenea cafenea2 = initializareCafenea("Teds", 17, 17.3);
//    Cafenea cafenea3 = initializareCafenea("Urban", 65, 33);
//    Cafenea sb = initializareCafenea("Sb", 25, 43);
//
//    ListaDubla listaDubla;
//    listaDubla.cap = NULL;
//    listaDubla.coada = NULL;
//
//    inserareInceput(&listaDubla, cafenea);
//    inserareInceput(&listaDubla, cafenea2);
//    inserareInceput(&listaDubla, cafenea3);
//    inserareInceput(&listaDubla, sb);
//    afisareLista(listaDubla);
//    /*listaDubla = stergeCafeneaDupaNume(listaDubla, "Teds");
//    afisareLista(listaDubla);
//    listaDubla = stergeCafeneaDupaNume(listaDubla, "Tucano");
//    afisareLista(listaDubla);
//    listaDubla = stergeCafeneaDupaNume(listaDubla, "Starbucks");
//    afisareLista(listaDubla);
//    listaDubla = stergeCafeneaDupaNume(listaDubla, "Sb");
//    afisareLista(listaDubla);
//    listaDubla = stergeCafeneaDupaNume(listaDubla, "Urban");
//    afisareLista(listaDubla)*/;
//    printf("Nr locuri totale:%d", NrTotalLocuri(listaDubla));
//    listaDubla = stergeLista(listaDubla);
//    //afisareLista(listaDubla);
//}

//SEMINAR 7 

//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//typedef struct Galerie Galerie;
//struct Galerie {
//	int cod;
//	char* nume;
//	float pretIntrare;
//};
//
//typedef struct nod nod;
//struct nod {
//	Galerie info;
//	nod* next;
//};
//
//typedef struct hashTable HashTable;
//struct hashTable {
//	nod** vector;
//	int dim;
//};
//
//HashTable initializareHashTable(int dimensiune) {
//	HashTable hash;
//	hash.dim = dimensiune;
//	hash.vector = (nod**)malloc(sizeof(nod*) * dimensiune);
//	for (int i = 0; i < dimensiune; i++) {
//		hash.vector[i] = NULL;
//	}
//
//	return hash;
//}
//
//Galerie initGalerie(int cod, const char* nume, float pret) {
//	Galerie g;
//	g.cod = cod;
//	g.nume = (char*)malloc(strlen(nume) + 1);
//	strcpy(g.nume, nume);
//	g.pretIntrare = pret;
//	return g;
//}
//
//int calculHash(int cod, const char* nume, int dimensiune) {
//	if (dimensiune > 0) {
//		int rez = cod * strlen(nume);
//		return rez % dimensiune;
//	}
//	return -1;
//}
//
//void inserareLaFinal(nod** cap, Galerie galerie) {
//	nod* temp = (nod*)malloc(sizeof(nod));
//	temp->info = galerie;
//	temp->next = NULL;
//	if (*cap) {
//		nod* aux = *cap;
//		while (aux->next != NULL) {
//			aux = aux->next;
//		}
//		aux->next = temp;
//	}
//	else {
//		*cap = temp;
//	}
//}
//
//void inserareGalerieInTabela(HashTable hash, Galerie galerie) {
//	if (hash.dim > 0) {
//		int pozitie = calculHash(galerie.cod, galerie.nume, hash.dim);
//		if (hash.vector[pozitie] != NULL) {
//			//acest if este aici doar pentru a prezenta situatia de coliziune
//			inserareLaFinal(&(hash.vector[pozitie]), galerie);
//		}
//		else {
//			//acelasi ca mai sus
//			inserareLaFinal(&(hash.vector[pozitie]), galerie);
//		}
//	}
//}
//
//void afisareGalerie(Galerie g) {
//	printf("%d. Intrarea la galeria %s costa %.2f\n", g.cod, g.nume, g.pretIntrare);
//}
//
//void afisareListaGalerii(nod* cap) {
//	while (cap) {
//		afisareGalerie(cap->info);
//		cap = cap->next;
//	}
//}
//
//void afisareTabela(HashTable tabela) {
//	for (int i = 0; i < tabela.dim; i++) {
//		if (tabela.vector[i] != NULL) {
//			printf("Clusterul: %d\n", (i + 1));
//			afisareListaGalerii(tabela.vector[i]);
//		}
//	}
//}
//
//
//
//Galerie cautaGalerieDupaCheie(int cod, const char* nume, HashTable tabela) {
//	int pozitie = calculHash(cod, nume, tabela.dim);
//	if (pozitie >= 0 && pozitie < tabela.dim) {
//		nod* p = tabela.vector[pozitie];
//		while (p && p->info.cod != cod && strcmp(p->info.nume, nume) != 0) {
//			p = p->next;
//		}
//		if (p) {
//			return p->info;//shallow copy
//		}
//		else {
//			return initGalerie(-1, "", 0);
//		}
//	}
//	else {
//		return initGalerie(-1, "", 0);
//	}
//
//}
//
//
//void main() {
//
//	Galerie g1 = initGalerie(1, "Orizont", 10);
//	Galerie g2 = initGalerie(2, "Cercul armatei", 6);
//	Galerie g3 = initGalerie(3, "Louvre", 30);
//	Galerie g4 = initGalerie(4, "Antipa", 20);
//	Galerie g5 = initGalerie(5, "Istorie", 15);
//	Galerie g6 = initGalerie(6, "Geologie", 17);
//
//	HashTable tabela = initializareHashTable(5);
//
//	inserareGalerieInTabela(tabela, g1);
//	inserareGalerieInTabela(tabela, g2);
//	inserareGalerieInTabela(tabela, g3);
//	inserareGalerieInTabela(tabela, g4);
//	inserareGalerieInTabela(tabela, g5);
//	inserareGalerieInTabela(tabela, g6);
//
//	afisareTabela(tabela);
//
//	Galerie g = cautaGalerieDupaCheie(1, "Orizont", tabela);
//	printf("cautare:\n");
//	afisareGalerie(g);
//}
