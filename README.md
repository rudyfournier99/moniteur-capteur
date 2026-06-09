# Moniteur de Capteur Embarqué (C++ / Arduino)

Petit projet d'initiation à l'électronique et aux systèmes embarqués réalisé pour me préparer à l'entrée en BTS CIEL. 
Le but est de lire les données envoyées par un capteur analogique, de traiter l'information et de déclencher une alerte visuelle si un seuil est dépassé.

## Matériel simulé / utilisé :
* Carte microcontrôleur (type Arduino Uno)
* Capteur analogique (LDR pour la luminosité ou Thermistance pour la température)
* Une LED pour l'affichage de l'alerte

## Fonctions du programme :
1. Initialisation de la liaison série à 9600 bauds.
2. Lecture en continu de la broche analogique A0.
3. Conversion mathématique de la valeur brute en pourcentage.
4. Gestion d'une alerte matérielle (allumage de la LED sur la broche 13) si la valeur dépasse le seuil fixé.

## Ce que ce projet m'a permis de comprendre :
* La différence entre un signal analogique (qui varie) et un signal numérique (0 ou 1 / HIGH ou LOW).
* L'importance du `delay()` pour temporiser les cycles de lecture d'un processeur.
* La structure de base d'un programme embarqué (`setup()` pour la configuration et `loop()` pour la boucle infinie).

## Idées d'évolutions :
* [ ] Remplacer la simple LED par un écran LCD I2C pour afficher directement le pourcentage.
* [ ] Utiliser des interruptions matérielles à la place du `delay()` pour optimiser la consommation d'énergie de la carte.