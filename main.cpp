#include <iostream>  // Pour les entrées/sorties standard
#include <Windows.h> // Pour l'intégration avec l'API Windows
#include <mysql.h>   // Pour utiliser la bibliothèque MySQL
#include <sstream> // Pour manipuler les chaînes de caractères en flux

using namespace std;

MYSQL *conn;    // Pointeur pour gérer la connexion à la base de données
MYSQL_ROW row;  // Représente une ligne de résultat de la requête SQL
MYSQL_RES *res; // Représente le résultat d'une requête SQL

// Déclaration des fonctions CRUD et de recherche
void afficher();
void ajouter();
void modifier();
void supprimer();
void rechercher();

int main()
{
    // Configuration pour l'affichage en UTF-8
    SetConsoleOutputCP(CP_UTF8);

    // Initialisation et connexion à la base de données MySQL
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "root", "", "dbEcole", 0, NULL, 0);

    // Vérification de la connexion à la base de données
    if (conn)
    {
        cout << "Connexion à la base de données réussie !" << endl;
        int choix;

        // Boucle du menu principal
        do
        {
            cout << "\n=== Menu Principal ===" << endl;
            cout << "1. Afficher tous les enregistrements" << endl;
            cout << "2. Ajouter un nouvel enregistrement" << endl;
            cout << "3. Modifier un enregistrement existant" << endl;
            cout << "4. Supprimer un enregistrement" << endl;
            cout << "5. Rechercher un enregistrement par ID" << endl;
            cout << "6. Quitter" << endl;
            cout << "Sélectionnez une option: ";
            cin >> choix;

            // Gestion des choix de l'utilisateur via un switch
            switch (choix)
            {
            case 1:
                afficher();
                break;
            case 2:
                ajouter();
                break;
            case 3:
                modifier();
                break;
            case 4:
                supprimer();
                break;
            case 5:
                rechercher();
                break;
            case 6:
                cout << "Fermeture du programme..." << endl;
                break;
            default:
                cout << "Option invalide, veuillez réessayer." << endl;
                break;
            }
        } while (choix != 6); // Le programme continue tant que l'utilisateur ne choisit pas de quitter
    }
    else
    {
        cout << "Erreur de connexion à la base de données..." << endl;
    }

    // Fermeture de la connexion à la base de données
    mysql_close(conn);
    return 0;
}

// Fonction pour afficher tous les enregistrements de la table 'Etudiant'
void afficher()
{
    int qstate = mysql_query(conn, "SELECT * FROM Etudiant");
    if (!qstate)
    {
        res = mysql_store_result(conn);
//        cout << "ID: \t\t| Nom: \t\t| Prénom: \t\t| Âge: " << endl;
        while (row = mysql_fetch_row(res))
        {
             cout << "ID: " << row[0] << "\t| Nom: " << row[1] << "\t| Prénom: " << row[2] << "\t| Âge: " << row[3] << endl;
            // cout <<  row[0] << "\t\t| " << row[1] << "\t\t| " << row[2] << "\t\t| " << row[3] << endl;
        }
    }
    else
    {
        cout << "Erreur lors de l'affichage des enregistrements." << endl;
    }
}

// Fonction pour ajouter un nouvel enregistrement à la table 'Etudiant'
void ajouter()
{
    string nom, prenom;
    int age;
    cout << "Saisir le nom: ";
    cin >> nom;
    cout << "Saisir le prénom: ";
    cin >> prenom;
    cout << "Saisir l'âge: ";
    cin >> age;

    stringstream ss;
    ss << "INSERT INTO Etudiant (nom, prenom, age) VALUES ('" << nom << "','" << prenom << "','" << age << "')";
    string query = ss.str();
    int qstate = mysql_query(conn, query.c_str());

    if (!qstate)
    {
        cout << "Enregistrement ajouté avec succès !" << endl;
    }
    else
    {
        cout << "Erreur lors de l'ajout de l'enregistrement." << endl;
    }
}

// Fonction pour modifier un enregistrement existant dans la table 'Etudiant'
void modifier()
{
    int id;
    string nom, prenom;
    int age;

    cout << "Saisir l'ID de l'enregistrement à modifier: ";
    cin >> id;
    cout << "Saisir le nouveau nom: ";
    cin >> nom;
    cout << "Saisir le nouveau prénom: ";
    cin >> prenom;
    cout << "Saisir le nouvel âge: ";
    cin >> age;

    stringstream ss;
    ss << "UPDATE Etudiant SET nom='" << nom << "', prenom='" << prenom << "', age=" << age << " WHERE id=" << id;
    string query = ss.str();
    int qstate = mysql_query(conn, query.c_str());

    if (!qstate)
    {
        cout << "Enregistrement modifié avec succès !" << endl;
    }
    else
    {
        cout << "Erreur lors de la modification de l'enregistrement." << endl;
    }
}

// Fonction pour supprimer un enregistrement de la table 'Etudiant'
void supprimer()
{
    int id;
    cout << "Saisir l'ID de l'enregistrement à supprimer: ";
    cin >> id;

    stringstream ss;
    ss << "DELETE FROM Etudiant WHERE id=" << id;
    string query = ss.str();
    int qstate = mysql_query(conn, query.c_str());

    if (!qstate)
    {
        cout << "Enregistrement supprimé avec succès !" << endl;
    }
    else
    {
        cout << "Erreur lors de la suppression de l'enregistrement." << endl;
    }
}

// Fonction pour rechercher un enregistrement spécifique dans la table 'Etudiant' par ID
void rechercher()
{
    int id;
    cout << "Saisir l'ID de l'enregistrement à rechercher: ";
    cin >> id;

    stringstream ss;
    ss << "SELECT * FROM Etudiant WHERE id=" << id;
    string query = ss.str();
    int qstate = mysql_query(conn, query.c_str());

    if (!qstate)
    {
        res = mysql_store_result(conn);
        if (row = mysql_fetch_row(res))
        {
            cout << "ID: " << row[0] << " | Nom: " << row[1] << " | Prénom: " << row[2] << " | Âge: " << row[3] << endl;
        }
        else
        {
            cout << "Aucun enregistrement trouvé avec cet ID." << endl;
        }
    }
    else
    {
        cout << "Erreur lors de la recherche de l'enregistrement." << endl;
    }
}
