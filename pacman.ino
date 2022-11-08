//Le programe est un PACMAN qui efface le texte ou un personage

#include <Wire.h>              // On inclue les librérie Wire.h utile pour notre code
#include "rgb_lcd.h"           // On inclue les librérie de l'ecrant lcd utiliser pour l'écrant

int y = 0;                     // On integre notre variable pour les déplacements de nos personages

rgb_lcd lcd;                   //l’initialisation de l’écran LCD permet de déclarer l’objet en temps que RGB.

byte PacManChar[8] = {         //Notre premier personage ici le pacman normal
  B01110,                      //Ici les pixel des personages en binaire
  B11111,                      //C'est le dessin du personnage
  B11101,
  B11111,
  B11111,
  B11000,
  B11111,
  B01110
};

byte PacMan2Char[8] = {         //Notre 2eme perso ici le pacman qui mange 
  B01110,                       //Ici les pixel des personages en binaire
  B11111,
  B11101,
  B11110,
  B11100,
  B11000,
  B11111,
  B01110
};

byte fantomChar[8]= {           //Le dernier perso ici le fantome 
  B01110,                       //Ici les pixel des personages en binaire
  B11111,
  B10101,
  B10101,
  B11111,
  B11111,
  B11111,
  B10101
};


void setup() {                           //Commandes qui doivent être exécutées uniquement au moment du chargement du programme

    lcd.begin(16, 2);                    //Initialisation de l’écran LCD pour permettre la gestion de l'affichage et du contraste
    
    lcd.createChar(1, PacManChar);        //On crée les charactéres de notre pacman que l'on a definis plus haut (byte)
    lcd.createChar(2, PacMan2Char);       //On crée les charactéres de notre pacman que l'on a definis plus haut (byte)
    lcd.createChar(3, fantomChar);        //On crée les charactéres de notre pacman que l'on a definis plus haut (byte)

}

void loop() {                   //Fonction Boucle qui se répéte tout le longs du script
    int y = 0;                  // On integre notre variable pour les déplacements
    //lcd.setCursor(8, 0);      Pour faire ajouter le texte
    //lcd.print("hello");       Pour écrire le texte
    lcd.setCursor(8, 0);        //On place le "fantomChar"(perso qui se fais manger) au millieux du lcd 
    lcd.write(3);               //On ajoute le "fantomChar" (perso qui se fais manger)
    while( y <= 16){            //Boucle qui fait avancer le pacman
      lcd.setCursor(y, 0);      // Positionne le curseur de l'écran LCD à la localisation voulue (colonne,ligne)
      lcd.write(1);             //On afiche le pacman n1 avec la bouche fermé
      delay(300);               //On met un delay entre l'afichage des deux pacman
      lcd.setCursor(y, 0);      // Positionne le curseur de l'écran LCD à la localisation voulue (colonne,ligne)
      lcd.write(2);             //On affiche le pacman n2 avec la bouche ouverte
      delay(300);               //On met un delay entre l'afichage des deux pacman
      lcd.setCursor(y, 0);      // Positionne le curseur de l'écran LCD à la localisation voulue (colonne,ligne)
      lcd.write(" ");           //Permet d'éviter que notre pacman reste sur la casse ou il est passer (on le suprime)
      y = y +1;                 //On fait avancer notre pacman d'une casse
    }
}

//Termier 👍
