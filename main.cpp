/*
 * Nom : correcteur_scribe
 * Description : Correcteur de faute de copie de scribe pour trouver des triangles rectangles aux côtés entiers
 * Auteur : Pierre BIDET
 * Organisation : Veagle
 * Repository : https://github.com/pierrbt/correcteur_scribe
 * Licence : GNU General Public License v3.0
 */

#include <iostream> // pour cout
#include <cmath> // pour sqrt
#include <string> // pour string
#include <vector> // pour vector
#include <algorithm> // pour sort

using namespace std;
int input(string question) { // fonction pour demander un nombre
    int buff = -1; // valeur par défaut
    do { // tant que l'utilisateur n'a pas entré un nombre
        cout << question; cin >> buff; cout << endl; // on lui demande de le faire
    } while(buff <= 0); // tant que le nombre est négatif ou nul
    return buff;
}
void analyzeResults(vector<int> vec) { // fonction pour analyser les résultats
    sort(vec.begin(), vec.end()); // on trie les résultats
    vec.erase(unique(vec.begin(), vec.end()), vec.end()); // on supprime les doublons
    for(int i : vec) { // pour chaque résultat
        cout << i << " "; // on l'affiche
    }
}
double c(int a) { return a * a; } // fonction pour calculer le carré d'un nombre
bool isMatching(int const h, int const side) {  // fonction pour vérifier si les valeurs sont correctes
    return ((h != side) && (sqrt(c(h) - c(side)) == round(sqrt(c(h) - c(side))))); // on vérifie que le résultat est un entier naturel
}
void tryConstHypo(int const hypo, int const side) { // fonction pour trouver les valeurs possibles des cotés
    std::vector<int> possibleValues; // tableau pour stocker les valeurs possibles
    if(side > 3600) {  // si le côté est > 3600
        int test_val =  side; // on teste la valeur du côté
        while(test_val > 3600) { // tant que la valeur est > 3600
            test_val -= 3600; // on enlève 3600
            if(isMatching(hypo, test_val)) // si la valeur est correcte
                possibleValues.push_back(test_val); // on l'ajoute au tableau
        }
        test_val =  side; // on teste la valeur du côté
        while(test_val < side + 3600*2) { // tant que la valeur est < 3600*2
            test_val += 3600; // on ajoute 3600
            if(isMatching(hypo, test_val)) // si la valeur est correcte
                possibleValues.push_back(test_val); // on l'ajoute au tableau
        }
    }
    if(side > 60) { // si le côté est > 60
        int test_val =  side; // on teste la valeur du côté
        while(test_val > 60) { // tant que la valeur est > 60
            test_val -= 60; // on enlève 60
            if(isMatching(hypo, test_val)) // si la valeur est correcte
                possibleValues.push_back(test_val); // on l'ajoute au tableau
        }
        test_val =  side; // on teste la valeur du côté
        while(test_val < side + 60*2) { // tant que la valeur est < 60*2
            test_val += 60; // on ajoute 60
            if(isMatching(hypo, test_val)) // si la valeur est correcte
                possibleValues.push_back(test_val); // on l'ajoute au tableau
        }
    }
    int test_val =  side; // on teste la valeur du côté
    while(test_val > 1) { // tant que la valeur est > 1
        test_val -= 1; // on enlève 1
        if(isMatching(hypo, test_val)) // si la valeur est correcte
            possibleValues.push_back(test_val); // on l'ajoute au tableau
    }
    test_val =  side; // on teste la valeur du côté
    while(test_val < side + 1*2) { // tant que la valeur est < 1*2
        test_val += 1; // on ajoute 1
        if(isMatching(hypo, test_val)) // si la valeur est correcte
            possibleValues.push_back(test_val); // on l'ajoute au tableau
    }
    if(possibleValues.empty()) // si le tableau est vide
        cout << "Aucune valeur de cote n'a ete trouvee !"; // on affiche un message d'erreur
    else { // sinon
        cout << "Voici les cotes possibles avec une hypotenuse de " << hypo << " : ";  // on affiche un message
        analyzeResults(possibleValues); // on analyse les résultats
    }

}

void tryConstSide(int hypo, int const side) // Pareil mail avec les hypoténuses
{
    std::vector<int> possibleValues;
    if(hypo > 3600) {
        int test_val = hypo;
        while(test_val > 3600) {
            test_val -= 3600;
            if(isMatching(test_val, side))
                possibleValues.push_back(test_val);
        }
        test_val =  hypo;
        while(test_val < hypo + 3600*2) {
            test_val += 3600;
            if(isMatching(test_val, side))
                possibleValues.push_back(test_val);
        }
    }
    if(side > 60) {
        int test_val = hypo;
        while(test_val > 60) {
            test_val -= 60;
            if(isMatching(test_val, side))
                possibleValues.push_back(test_val);
        }
        test_val = hypo;
        while(test_val < hypo + 60*2) {
            test_val += 60;
            if(isMatching(test_val, side))
                possibleValues.push_back(test_val);
        }
    }
    int test_val =  hypo;
    while(test_val > 1) {
        test_val -= 1;
        if(isMatching(test_val, side))
            possibleValues.push_back(test_val);
    }
    test_val =  hypo;
    while(test_val < hypo + 1*2) {
        test_val += 1;
        if(isMatching(test_val, side))
            possibleValues.push_back(test_val);
    }
    if(possibleValues.empty())
        cout << "Aucune valeur de hypo n'a ete trouvee !";
    else {
        cout << "Voici les hypotenuses possibles avec un cote de " << side << " : ";
        analyzeResults(possibleValues);
    }
}
int main() {
    cout << "Bienvenue sur le correcteur de scribes !\n"; // on affiche un message de bienvenue
    int mayHypo = input("Entrez la valeur possible de l'hypotenuse : "); // on demande la valeur possible de l'hypotenuse
    int maySide = input("Entrez la valeur possible du coté : "); // on demande la valeur possible du coté
    tryConstSide(mayHypo, maySide); cout << endl; // on teste les valeurs possibles des hypoténuses
    tryConstHypo(mayHypo, maySide); cout << endl; // on teste les valeurs possibles des cotés
}
