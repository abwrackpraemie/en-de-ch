#ifndef logic_H
#define logic_H

#include <pebble.h>
#include <string.h>
//#include <mainmenu.h>
//#include <navigate.h>
#include <vocab.h>
#include <time.h>
static TextLayer *s_menuButton[5];
int i_vocCount = 0;       //Vokabeln zaehlen
int i_vocScore = 0;       //Richtige Vokabeln
char c_score[7] = "Score: ";  //Score Text Teil 1
char c_vocScore[14];          //Score Text (gesamt) ******** geht nur mit >13
char c_genVoc[2][30][25];     //Ablage der anzuzeigenden Vokabeln
int i_limit = 10;
int i_false = 0;
int i_randStart23A = 0;      //erste Koordinate zur Bestimmung der Zufallszahlen
int i_randStart23B = 0;      //zweite Koordinate zur Bestimmung der Zufallszahlen
int i_randStart3A = 0;
int i_randStart3B = 0;
int i_randN = 3;           //Zufallszahlbereich
int i_random3temp = -1;    //Zufallzahl zur Buttonvergabe
int i_inMenu = 99;




int i_vocMode(int i_inMenu)
{
    switch(i_inMenu)
     {
      case 0 :
        return 0;//j_vocMode = 1;
        break;
      case 1 :
        return 1;//j_vocMode = 0;
        break;
      case 2 :
        return 2
        break;
      case 3 :
        return 3;
        break;
     }
  return 0;
}




//Ausgabe einer vorab generierten Zufallszahl der Reihe nach im Bereich von 1 bis 3
int i_random3()
{
  //naechsten Wert ausgeben
  if(i_randStart3B == 22)
  {
    i_randStart3B = 0;
  }
  else
  {
    i_randStart3B++;
  }
  //Liste an Zufallszahlen (keine doppelten)
  int i_3list[8][23] = 
  {
    {1, 2, 2, 2, 3, 1, 3, 2, 2, 1, 2, 3, 2, 1, 2, 3, 2, 3, 3, 2, 3, 2, 3 },
    {2, 3, 2, 1, 1, 2, 3, 2, 1, 2, 2, 1, 2, 1, 3, 1, 2, 2, 3, 2, 3, 2, 1 },
    {1, 2, 2, 1, 1, 2, 2, 3, 1, 1, 2, 1, 2, 3, 1, 3, 3, 1, 2, 1, 2, 2, 2 },
    {3, 2, 1, 2, 3, 2, 2, 3, 2, 3, 1, 1, 1, 2, 1, 2, 3, 2, 3, 3, 3, 1, 1 },
    {3, 1, 3, 2, 1, 2, 1, 3, 2, 3, 2, 1, 3, 2, 3, 1, 2, 2, 3, 1, 3, 1, 1 },
    {3, 1, 1, 2, 2, 1, 2, 2, 3, 3, 1, 2, 2, 1, 1, 3, 2, 1, 1, 1, 1, 2, 3 },
    {3, 2, 2, 3, 3, 2, 1, 3, 2, 1, 3, 3, 1, 3, 1, 2, 3, 2, 3, 1, 1, 1, 3 },
    {2, 3, 1, 3, 3, 2, 2, 1, 3, 2, 1, 1, 2, 3, 1, 3, 2, 1, 3, 2, 2, 2, 2 },
  };
  //gibt Zahl in Reihe i_randstartA und Spalte i_randStartB aus
  return i_3list[i_randStart3A][i_randStart3B];
}


//Ausgabe einer vorab generierten Zufallszahl der Reihe nach im Bereich von 0 bis 23
int i_random23()
{
  //naechsten Wert ausgeben
  if(i_randStart23B == 22)
  {
    i_randStart23B = 0;
  }
  else
  {
    i_randStart23B++;
  }
  //Liste an Zufallszahlen (keine doppelten)
  int i_23list[8][23] = 
  {
    {11, 3, 18, 0, 22, 8, 14, 2, 20, 10, 1, 17, 7, 15, 4, 21, 13, 16, 6, 9, 5, 19 },
    {19, 14, 6, 21, 3, 8, 22, 1, 11, 2, 5, 18, 15, 0, 16, 20, 7, 9, 17, 13, 10, 4 },
    {12, 6, 17, 2, 16, 8, 22, 3, 0, 19, 18, 20, 14, 4, 21, 5, 13, 7, 11, 15, 1, 9 },
    {4, 16, 17, 14, 11, 18, 0, 15, 3, 13, 10, 1, 7, 8, 2, 12, 20, 5, 9, 19, 21, 22 },
    {21, 0, 12, 14, 11, 20, 13, 7, 15, 9, 2, 16, 6, 18, 19, 3, 5, 17, 4, 10, 8, 1 },
    {7, 16, 12, 14, 22, 18, 10, 15, 1, 9, 3, 13, 0, 21, 19, 11, 17, 6, 2, 20, 8, 5 },
    {10, 9, 15, 11, 19, 21, 6, 3, 5, 20, 17, 0, 4, 2, 16, 22, 14, 12, 8, 13, 7, 1 },
    {6, 18, 17, 8, 21, 20, 12, 22, 0, 19, 13, 1, 9, 5, 16, 14, 10, 15, 4, 2, 11, 3 },
  };
  //gibt Zahl in Reihe i_randstartA und Spalte i_randStartB aus
  return i_23list[i_randStart23A][i_randStart23B];
}




//Augabe einer Zufallszahl zwischen 0 und i_randN
int i_random0(int i_randN)
{
  time_t t;
  time(&t);
  srand((int)t);              /* Zufallsgenerator initialisieren */
  return (rand() % 3);   /* Wuerfeln */
}




//Augabe einer Zufallszahl zwischen 1 und i_randN
int i_random1(int i_randN)
{
  time_t t;
  time(&t);
  srand((int)t);              /* Zufallsgenerator initialisieren */
  return (rand() % 3 + 1);   /* Wuerfeln */
}




//Pruefen einer Vokabel auf Richtigkeit  
bool b_vocCheck(int i_buttonID, int i_inMenu)
{
  //wenn richtig, i_vocScore++
  if(i_random3temp == i_buttonID)
  {
    i_vocScore++;
  }
  //Score zentrieren
  text_layer_set_text_alignment(s_menuButton[4], GTextAlignmentCenter);
  //Score ausgeben
  snprintf(c_vocScore, sizeof(c_vocScore), "%s%i", c_score, i_vocScore);
  text_layer_set_text(s_menuButton[4], c_vocScore);
  
  i_vocCount++;
  
  //Vokabelliste aktualisieren
  if(i_vocCount > 0)
  {
    //Antwortmoeglichkeiten generieren
    i_random3temp = i_random3();
    for(int i=1; i<4; i++)
    {
      if(i_random3temp == i)
      {
        text_layer_set_text(s_menuButton[i],c_genVoc[1][i_vocCount]); //i_inMenu = 1 im Modus 1
      }
      else
      {
        text_layer_set_text(s_menuButton[i],c_genVoc[1][i_false]);    //i_inMenu = 1 im Modus 1
        if(i_false < 21)
        {
          i_false++;
        }
        else
        {
          i_false = i_limit +1;
        }
      }
    }
    //Vokabel aktualisieren
    text_layer_set_text(s_menuButton[0],c_genVoc[0][i_vocCount]); //i_inMenu = 0 im Modus 0
  }


  //Weiter oder Ende
  if(i_vocCount == i_limit)
  {
    i_vocCount = 0;
    i_vocScore = 0;   
    //Wechsel zu Hauptmenue
    text_layer_set_text_alignment(s_menuButton[4], GTextAlignmentLeft);
    return 1;
  }
  return 0;
}




//Vokabelliste erstellen
void vocMixer(int i_inMenu)
{
  i_randStart23B = i_random0(23);   //Zufallszahl zwischen 0 und 23
  i_randStart23A = i_random0(8);    //Zufallszahl zwischen 0 und 8

  //Vokabeln nach Schwierigkeitsgrad auswaehlen ***
  //Vokabeln aussuchen
  
  //Abfrageliste initialisieren
  for(int i = 0; i<25; i++)
    {
      for(int j = 0; j<25; j++)
        {
        c_genVoc[0][i][j] = 0;
        c_genVoc[1][i][j] = 0;
        }
    }
  int i_randTemp23;
  //Vokabeln mit 1 markieren (10 Vokabeln werden gesucht)

  
  for(int i=0; i<23; i++)
  {
    
    i_randTemp23 = i_random23();
    
    //markiere freie Vokabel 
    
    for(int j = 0; j<25; j++)
    {
      c_genVoc[0][i][j] = c3_list1[3][i_randTemp23][j]; //Vokabel
      c_genVoc[1][i][j] = c3_list1[2][i_randTemp23][j]; //Loesung
    }
  }
  
  //Listen erfassen
  
  //Vokabelliste initialisieren
  //Antwortmoeglichkeiten generieren

  i_randStart3B = i_random0(23);   //Zufallszahl zwischen 0 und 23
  i_randStart3A = i_random0(8);    //Zufallszahl zwischen 0 und 8
  i_random3temp = i_random23();    //richtige Antwort
  for(int i=1; i<4; i++)
  {
    if(i_random3temp == i)
    {
      text_layer_set_text(s_menuButton[i],c_genVoc[1][0]);
    }
    else
    {
      text_layer_set_text(s_menuButton[i],c_genVoc[1][i_false]);
      i_false++;
    }
  }
  //Vokabel initialisieren
  text_layer_set_text(s_menuButton[0],c_genVoc[0][0]);
  //Score initialisieren
  text_layer_set_text_alignment(s_menuButton[4], GTextAlignmentCenter);
  text_layer_set_text(s_menuButton[4], "Score: 0");
  //Gewaehlte Vokabeln markieren
  //Falsche Vokabeln waehlen
}





#endif /* LOGIC_H */