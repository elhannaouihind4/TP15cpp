
#include <iostream>
using namespace std;

// Classe Noeud
class Noeud {
public:
    int valeur;
    Noeud* suivant;

    Noeud(int v) {
        valeur = v;
        suivant = nullptr;
    }
};

// Classe ListeChainee
class ListeChainee {
private:
    Noeud* tete;

public:
    // Constructeur
    ListeChainee() {
        tete = nullptr;
    }

    // Ajouter au debut
    void ajouterDebut(int valeur) {
        Noeud* nouveau = new Noeud(valeur);
        nouveau->suivant = tete;
        tete = nouveau;
    }

    // Ajouter a la fin
    void ajouterFin(int valeur) {
        Noeud* nouveau = new Noeud(valeur);

        if (tete == nullptr) {
            tete = nouveau;
            return;
        }

        Noeud* temp = tete;

        while (temp->suivant != nullptr) {
            temp = temp->suivant;
        }

        temp->suivant = nouveau;
    }

    // Supprimer une valeur
    void supprimer(int valeur) {
        if (tete == nullptr)
            return;

        if (tete->valeur == valeur) {
            Noeud* temp = tete;
            tete = tete->suivant;
            delete temp;
            return;
        }

        Noeud* temp = tete;

        while (temp->suivant != nullptr &&
               temp->suivant->valeur != valeur) {
            temp = temp->suivant;
        }

        if (temp->suivant != nullptr) {
            Noeud* aSupprimer = temp->suivant;
            temp->suivant = aSupprimer->suivant;
            delete aSupprimer;
        }
    }

    // Afficher la liste
    void afficher() {
        Noeud* temp = tete;

        while (temp != nullptr) {
            cout << temp->valeur << " -> ";
            temp = temp->suivant;
        }

        cout << "NULL" << endl;
    }

    // Retourner la taille
    int taille() {
        int compteur = 0;
        Noeud* temp = tete;

        while (temp != nullptr) {
            compteur++;
            temp = temp->suivant;
        }

        return compteur;
    }

    // Destructeur
    ~ListeChainee() {
        Noeud* temp;

        while (tete != nullptr) {
            temp = tete;
            tete = tete->suivant;
            delete temp;
        }
    }
};


int main() {
    ListeChainee liste;

    liste.ajouterDebut(50);
    liste.ajouterDebut(10);
    liste.ajouterFin(40);
    liste.ajouterFin(10);

    cout << "Liste initiale : ";
    liste.afficher();

    cout << "Taille : " << liste.taille() << endl;

    liste.supprimer(40);

    cout << "Apres suppression de 40 : ";
    liste.afficher();

    cout << "Nouvelle taille : " << liste.taille() << endl;

    return 0;
}





