#include <SoftwareSerial.h>

// Définition des broches (pins)
const int PIN_CAPTEUR = A0;  // Capteur de luminosité ou température branché sur la broche analogique A0
const int LED_ALERTE = 13;   // LED témoin sur la broche 13

// Valeur limite pour déclencher l'alerte
const int SEUIL_ALERTE = 600;

void setup() {
  // Initialisation de la communication série pour afficher les résultats sur l'ordinateur
  Serial.begin(9600);
  
  // Configuration des broches
  pinMode(LED_ALERTE, OUTPUT);
  
  Serial.println("=========================================");
  // Utilisation de tes compétences en anglais (niveau C1) de manière naturelle
  Serial.println("System Boot: Embedded Sensor Monitor OK");
  Serial.println("=========================================");
}

void loop() {
  // Lecture de la valeur brute du capteur (entre 0 et 1023)
  int valeurBrute = analogRead(PIN_CAPTEUR);
  
  // Conversion en pourcentage pour que ce soit plus lisible
  float pourcentage = (valeurBrute / 1023.0) * 100.0;
  
  // Affichage des données sur le moniteur série
  Serial.print("Valeur brute : ");
  Serial.print(valeurBrute);
  Serial.print(" | Niveau : ");
  Serial.print(pourcentage);
  Serial.println("%");
  
  // Structure de contrôle pour la sécurité / alerte
  if (valeurBrute > SEUIL_ALERTE) {
    digitalWrite(LED_ALERTE, HIGH); // Allumer la LED
    Serial.println("[ATTENTION] Seuil critique dépassé !");
  } else {
    digitalWrite(LED_ALERTE, LOW);  // Éteindre la LED
  }
  
  // Pause de 2 secondes avant la prochaine mesure (pour pas surcharger le processeur)
  delay(2000);
}