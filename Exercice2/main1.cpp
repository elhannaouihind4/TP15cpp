
#include <iostream>
#include <exception>
using namespace std;

// Exception personnalisee
class FileVideException : public exception {
public:
    const char* what() const noexcept override {
        return "Erreur : la file est vide !";
    }
};

// Classe File
class File {
private:
    // Structure Noeud
    struct Noeud {
        int valeur;
        Noeud* suivant;

        Noeud(int v) {
            valeur = v;
            suivant = nullptr;
        }
    };

    Noeud* debut;
    Noeud* fin;

public:
    // Constructeur
    File() {
        debut = nullptr;
        fin = nullptr;
    }

    // Verifier si la file est vide
    bool estVide() {
        return debut == nullptr;
    }

    // Ajouter un element
    void enfiler(int valeur) {
        Noeud* nouveau = new Noeud(valeur);

        if (estVide()) {
            debut = nouveau;
            fin = nouveau;
        } else {
            fin->suivant = nouveau;
            fin = nouveau;
        }

        cout << "Element ajoute avec succes !" << endl;
    }

    // Retirer un element
    int defiler() {
        if (estVide()) {
            throw FileVideException();
        }

        Noeud* temp = debut;
        int valeur = temp->valeur;

        debut = debut->suivant;

        if (debut == nullptr) {
            fin = nullptr;
        }

        delete temp;

        return valeur;
    }

    // Verifier si la file est pleine
    bool estPleine() {
        // Une liste chainee n'a pas de capacite fixe.
        return false;
    }

    // Afficher la file
    void afficher() {
        Noeud* temp = debut;

        if (estVide()) {
            cout << "La file est vide." << endl;
            return;
        }

        cout << "File : ";

        while (temp != nullptr) {
            cout << temp->valeur << " ";
            temp = temp->suivant;
        }

        cout << endl;
    }

    // Destructeur
    ~File() {
        while (!estVide()) {
            Noeud* temp = debut;
            debut = debut->suivant;
            delete temp;
        }

        fin = nullptr;
    }
};

int main() {
    File f;
    int choix, valeur;

    do {
        cout << "\n MENU FILE D'ATTENTE " << endl;
        cout << "1. Enfiler (Ajouter)" << endl;
        cout << "2. Defiler (Retirer)" << endl;
        cout << "3. Afficher la file" << endl;
        cout << "4. Verifier si la file est vide" << endl;
        cout << "0. Quitter" << endl;

        cout << "Votre choix : ";
        cin >> choix;

        try {
            switch (choix) {

            case 1:
                cout << "Donner une valeur : ";
                cin >> valeur;
                f.enfiler(valeur);
                break;

            case 2:
                valeur = f.defiler();
                cout << "Element retire : " << valeur << endl;
                break;

            case 3:
                f.afficher();
                break;

            case 4:
                if (f.estVide())
                    cout << "La file est vide." << endl;
                else
                    cout << "La file n'est pas vide." << endl;
                break;

            case 0:
                cout << "Fin du programme." << endl;
                break;

            default:
                cout << "Choix invalide !" << endl;
            }

        } catch (const FileVideException& e) {
            cout << e.what() << endl;
        }

    } while (choix != 0);

    return 0;
}
