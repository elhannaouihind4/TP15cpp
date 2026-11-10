
#include <iostream>
#include <string>
#include <exception>
using namespace std;

// Exception personnalisee
class PileVideException : public exception {
public:
    const char* what() const noexcept override {
        return "Erreur : la pile est vide !";
    }
};

// Classe Pile generique
template <typename T>
class Pile {

private:
    // Structure Noeud
    struct Noeud {
        T element;
        Noeud* suivant;

        Noeud(T e) {
            element = e;
            suivant = nullptr;
        }
    };

    Noeud* tete;

public:

    // Constructeur
    Pile() {
        tete = nullptr;
    }

    // Verifier si la pile est vide
    bool estVide() const {
        return tete == nullptr;
    }

    // Empiler un element
    void empiler(T element) {
        Noeud* nouveau = new Noeud(element);

        nouveau->suivant = tete;
        tete = nouveau;
    }

    // Depiler un element
    T depiler() {
        if (estVide()) {
            throw PileVideException();
        }

        Noeud* temp = tete;
        T element = temp->element;

        tete = tete->suivant;

        delete temp;

        return element;
    }

    // Consulter le sommet
    T sommet() const {
        if (estVide()) {
            throw PileVideException();
        }

        return tete->element;
    }

    // Inverser la pile
    void inverser() {
        Noeud* precedent = nullptr;
        Noeud* courant = tete;
        Noeud* suivant = nullptr;

        while (courant != nullptr) {
            suivant = courant->suivant;
            courant->suivant = precedent;
            precedent = courant;
            courant = suivant;
        }

        tete = precedent;
    }

    // Afficher la pile
    void afficher() const {
        Noeud* temp = tete;

        if (estVide()) {
            cout << "Pile vide !" << endl;
            return;
        }

        cout << "Sommet -> ";

        while (temp != nullptr) {
            cout << temp->element << " -> ";
            temp = temp->suivant;
        }

        cout << "NULL" << endl;
    }

    // Destructeur
    ~Pile() {
        while (tete != nullptr) {
            Noeud* temp = tete;
            tete = tete->suivant;
            delete temp;
        }
    }
};

int main() {

    try {

        // Test avec int
        cout << " PILE D'ENTIERS " << endl;

        Pile<int> p1;

        p1.empiler(38);
        p1.empiler(27);
        p1.empiler(37);

        p1.afficher();

        cout << "Sommet : " << p1.sommet() << endl;
        cout << "Element retire : " << p1.depiler() << endl;

        p1.afficher();

        // Inverser la pile
        p1.inverser();

        cout << "Apres inversion : ";
        p1.afficher();


        // Test avec string
        cout << "\n PILE DE CHAINES " << endl;

        Pile<string> p2;

        p2.empiler("Hind");
        p2.empiler("Reda");
        p2.empiler("Ahmed");

        p2.afficher();


        // Test avec double
        cout << "\n PILE DE REELS " << endl;

        Pile<double> p3;

        p3.empiler(8.5);
        p3.empiler(2.5);
        p3.empiler(7.5);

        p3.afficher();


        // Test de l'exception
        cout << "\n TEST EXCEPTION " << endl;

        Pile<int> p4;

        cout << p4.depiler() << endl;

    }

    catch (const PileVideException& e) {
        cout << e.what() << endl;
    }

    return 0;
}
