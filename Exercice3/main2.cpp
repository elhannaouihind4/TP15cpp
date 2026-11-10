
#include <iostream>
#include <string>
using namespace std;

// Classe TableHachage
class TableHachage {

private:
    // Structure Noeud
    struct Noeud {
        int cle;
        string valeur;
        Noeud* suivant;

        Noeud(int c, string v) {
            cle = c;
            valeur = v;
            suivant = nullptr;
        }
    };

    static const int TAILLE = 10;
    Noeud* table[TAILLE];

    // Fonction de hachage
    int hachage(int cle) {
        return cle % TAILLE;
    }

public:

    // Constructeur
    TableHachage() {
        for (int i = 0; i < TAILLE; i++) {
            table[i] = nullptr;
        }
    }

    // Inserer une valeur
    void inserer(int cle, string valeur) {
        int index = hachage(cle);

        Noeud* temp = table[index];

        // Verifier si la cle existe deja
        while (temp != nullptr) {
            if (temp->cle == cle) {
                temp->valeur = valeur;
                cout << "Valeur mise a jour !" << endl;
                return;
            }
            temp = temp->suivant;
        }

        // Ajouter un nouveau noeud
        Noeud* nouveau = new Noeud(cle, valeur);
        nouveau->suivant = table[index];
        table[index] = nouveau;

        cout << "Insertion reussie !" << endl;
    }

    // Rechercher une cle
    void rechercher(int cle) {
        int index = hachage(cle);
        Noeud* temp = table[index];

        while (temp != nullptr) {
            if (temp->cle == cle) {
                cout << "Cle trouvee : "
                     << temp->valeur << endl;
                return;
            }

            temp = temp->suivant;
        }

        cout << "Cle introuvable !" << endl;
    }

    // Supprimer une cle
    void supprimer(int cle) {
        int index = hachage(cle);

        Noeud* temp = table[index];
        Noeud* precedent = nullptr;

        while (temp != nullptr) {

            if (temp->cle == cle) {

                if (precedent == nullptr) {
                    table[index] = temp->suivant;
                } else {
                    precedent->suivant = temp->suivant;
                }

                delete temp;
                cout << "Suppression reussie !" << endl;
                return;
            }

            precedent = temp;
            temp = temp->suivant;
        }

        cout << "Cle introuvable !" << endl;
    }

    // Afficher la table
    void afficher() {
        cout << "\n TABLE DE HACHAGE " << endl;

        for (int i = 0; i < TAILLE; i++) {
            cout << "Case " << i << " : ";

            Noeud* temp = table[i];

            while (temp != nullptr) {
                cout << "[" << temp->cle
                     << " : " << temp->valeur << "] -> ";

                temp = temp->suivant;
            }

            cout << "NULL" << endl;
        }
    }

    // Destructeur
    ~TableHachage() {
        for (int i = 0; i < TAILLE; i++) {
            Noeud* temp = table[i];

            while (temp != nullptr) {
                Noeud* aSupprimer = temp;
                temp = temp->suivant;
                delete aSupprimer;
            }
        }
    }
};

int main() {
    TableHachage t;
    int choix, cle;
    string valeur;

    do {
        cout << "\n MENU TABLE DE HACHAGE " << endl;
        cout << "1. Inserer" << endl;
        cout << "2. Rechercher" << endl;
        cout << "3. Supprimer" << endl;
        cout << "4. Afficher la table" << endl;
        cout << "0. Quitter" << endl;

        cout << "Votre choix : ";
        cin >> choix;

        switch (choix) {

        case 1:
            cout << "Donner la cle : ";
            cin >> cle;

            cout << "Donner la valeur : ";
            cin >> valeur;

            t.inserer(cle, valeur);
            break;

        case 2:
            cout << "Donner la cle a rechercher : ";
            cin >> cle;

            t.rechercher(cle);
            break;

        case 3:
            cout << "Donner la cle a supprimer : ";
            cin >> cle;

            t.supprimer(cle);
            break;

        case 4:
            t.afficher();
            break;

        case 0:
            cout << "Fin du programme." << endl;
            break;

        default:
            cout << "Choix invalide !" << endl;
        }

    } while (choix != 0);

    return 0;
}
