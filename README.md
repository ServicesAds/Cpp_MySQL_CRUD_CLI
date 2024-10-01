Étapes pour exécuter du code C++ MySQL dans Code::Blocks :
1. Installer MySQL Server et MySQL Connector/C++ :
	- MySQL Server : Si vous n'avez pas déjà installé MySQL, téléchargez-le et installez-le depuis MySQL Downloads.
	- MySQL Connector C++ : Vous avez besoin de la bibliothèque qui permet de connecter votre programme C++ à la base de données MySQL. Téléchargez-le depuis MySQL Connector C++.
2. Configurer Code::Blocks :
	a.	Installer MinGW (si ce n'est pas déjà fait) :
		- Si vous avez installé Code::Blocks avec MinGW (Minimalist GNU for Windows), assurez-vous qu'il est configuré correctement.
		- Si vous utilisez une autre version, vérifiez que MinGW est installé sur votre machine.
	b.	Vérifier que les fichiers MySQL sont prêts :
		- Dans le répertoire où vous avez installé MySQL ou MySQL Connector/C++, vous trouverez les bibliothèques et les fichiers d'en-tête nécessaires.
		- Localisez les fichiers d'en-tête (comme mysql.h), en général dans un répertoire comme 
			> C:\Program Files\MySQL\MySQL Server <version>\include 
			ou 
			> C:\Program Files\MySQL\MySQL Connector C++ <version>\include.
		- Les fichiers de bibliothèque (libmysql.lib ou libmysql.dll) se trouvent dans un répertoire comme C:\Program Files\MySQL\MySQL Server <version>\lib.
3. Configurer un projet dans Code::Blocks :
	a.	Créer un nouveau projet :
		- Ouvrez Code::Blocks et créez un nouveau projet C++ en choisissant "File" > "New" > "Project" > "Console application" > "C++".
		- Donnez un nom à votre projet et choisissez un emplacement de sauvegarde.
	b.	Ajouter les fichiers d'en-tête MySQL :
		- Dans votre projet, accédez à Project > Build Options.
		- Sous l'onglet "Search directories", cliquez sur "Compiler" et ajoutez le chemin vers le dossier contenant les fichiers d'en-tête MySQL (comme C:\Program Files\MySQL\MySQL Server <version>\include).
		- Cliquez ensuite sur "Linker" et ajoutez le chemin vers le dossier contenant les bibliothèques MySQL (.lib et .dll), souvent situé dans un dossier lib comme C:\Program Files\MySQL\MySQL Server <version>\lib.
	c.	Ajouter les bibliothèques MySQL :
		- Toujours dans "Build Options", allez dans l'onglet "Linker settings".
		- Cliquez sur "Add" et ajoutez libmysql.lib ou libmysql.dll selon ce que vous avez.
		- Parfois, il est nécessaire d'ajouter également ws2_32.lib pour les connexions réseau sous Windows.
	d.	Configurer les options de compilation :
		- Dans l'onglet "Compiler settings", ajoutez les options suivantes dans la section "Other options" si nécessaire.
4. Ajouter le fichier source avec le code :
	1.	Ajouter le code source :
		- Copiez le code source que vous avez fourni dans le fichier main.cpp de votre projet.
	2.	Compiler et exécuter :
		- Cliquez sur "Build" pour compiler le projet.
		- Si tout est configuré correctement, vous devriez pouvoir voir les messages de la base de données s'afficher dans la console.
5. Problèmes potentiels et solutions :
	a- Erreur de connexion MySQL : Si vous obtenez une erreur lors de la connexion à la base de données, assurez-vous que :
		- MySQL est en cours d'exécution.
		- Vous utilisez le bon nom d'utilisateur, mot de passe, et base de données.
		- Le serveur MySQL fonctionne sur localhost (ou autre hôte si configuré différemment).
	b- Fichier .dll manquant : Si Code::Blocks affiche une erreur concernant une bibliothèque manquante (comme libmysql.dll), copiez ce fichier dans le répertoire où votre exécutable est généré (souvent le répertoire bin\Debug ou bin\Release de votre projet).
6. Tester le programme :
	- Après avoir compilé le programme avec succès, vous pouvez tester les fonctionnalités CRUD et vérifier que le programme interagit correctement avec la base de données MySQL.
	
Résumé des chemins :
	- Include Directory : Chemin vers les fichiers d'en-tête MySQL (mysql.h).
	- Library Directory : Chemin vers les fichiers .lib ou .dll de MySQL.
	- Librairies à ajouter : libmysql.lib et peut-être ws2_32.lib.

Conclusion :
Avec ces étapes, vous devriez être capable de compiler et exécuter votre programme C++ avec MySQL dans Code::Blocks. 
N'hésitez pas à vérifier que toutes les bibliothèques sont correctement configurées et que la connexion à la base de données fonctionne comme attendu.


SCHEMA :
	base name: ecole
	table : etudiant
	
	CODE MySQL :
		CREATE DATABASE `dbEcole` /*!40100 COLLATE 'utf8mb4_0900_ai_ci' */;
		USE `dbecole`;

		CREATE TABLE `etudiant` (
			`id` INT NOT NULL AUTO_INCREMENT,
			`nom` VARCHAR(50) NULL DEFAULT NULL,
			`prenom` VARCHAR(50) NULL DEFAULT NULL,
			`age` INT NULL DEFAULT NULL,
			PRIMARY KEY (`id`) USING BTREE
		) COLLATE='utf8mb4_0900_ai_ci' 	ENGINE=InnoDB ;
