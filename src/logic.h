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
int i_randStart28A = 0;
int i_randStart28B = 0;
int i_randStart3A = 0;
int i_randStart3B = 0;
int i_randN = 3;           //Zufallszahlbereich
int i_random3temp = -1;    //Zufallzahl zur Buttonvergabe
int i_inMenu = 99;




int i_vocModeQ(int i_inMenu)  //0 == DE; 1== Sym; 2 == Frei; 3 == Frei
{
    switch(i_inMenu)
     {
      case 0 :
        return 0;
        break;
      case 1 :
        return 1;
        break;
      case 2 :
        return 0;
        break;
      case 3 :
        return 1;
        break;
     }
  return 0;
}

int i_vocModeA(int i_inMenu)  //0 == DE; 1== Sym; 2 == Frei; 3 == Frei
{
    switch(i_inMenu)
     {
      case 0 :
        return 1;
        break;
      case 1 :
        return 0;
        break;
      case 2 :
        return 1;
        break;
      case 3 :
        return 0;
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




//Ausgabe einer vorab generierten Zufallszahl der Reihe nach im Bereich von 0 bis 27
int i_random28()
{
  //naechsten Wert ausgeben
  if(i_randStart28B == 27)
  {
    i_randStart28B = 0;
  }
  else
  {
    i_randStart28B++;
  }
  //Liste an Zufallszahlen (keine doppelten)
  int i_28list[8][28] = 
  {
    {16, 2, 3, 24, 1, 14, 10, 25, 17, 9, 5, 20, 12, 4, 23, 27, 26, 15, 21, 6, 22, 19, 18, 8, 11, 13, 0, 7 },
    {2, 17, 1, 18, 16, 15, 11, 4, 22, 21, 9, 25, 23, 12, 27, 8, 24, 26, 7, 14, 6, 13, 3, 5, 10, 19, 20, 0 },
    {12, 2, 10, 22, 4, 17, 3, 16, 0, 1, 11, 13, 19, 20, 14, 21, 26, 27, 6, 9, 24, 23, 7, 25, 5, 18, 15, 8 },
    {24, 13, 23, 3, 27, 9, 25, 1, 8, 18, 11, 0, 5, 17, 7, 4, 14, 2, 15, 12, 16, 21, 20, 6, 10, 26, 19, 22 },
    {2, 4, 7, 26, 0, 3, 15, 22, 13, 12, 14, 9, 20, 27, 17, 23, 25, 21, 1, 5, 24, 6, 10, 11, 19, 8, 16, 18 },
    {13, 22, 23, 3, 0, 12, 5, 6, 18, 21, 16, 8, 2, 26, 27, 19, 1, 20, 17, 24, 11, 9, 15, 14, 10, 25, 4, 7 },
    {4, 24, 9, 11, 7, 21, 13, 1, 8, 6, 12, 16, 3, 23, 2, 0, 19, 15, 14, 18, 22, 20, 25, 26, 10, 17, 5, 27 },
    {11, 21, 6, 27, 0, 15, 14, 26, 5, 19, 1, 16, 7, 22, 25, 3, 2, 4, 23, 18, 17, 13, 24, 9, 10, 8, 20, 12 },
  };
  //gibt Zahl in Reihe i_randstartA und Spalte i_randStartB aus
  return i_28list[i_randStart28A][i_randStart28B];
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
        text_layer_set_text(s_menuButton[i],c_genVoc[i_vocModeA(i_inMenu)][i_vocCount]); //i_inMenu = 1 im Modus 1
      }
      else
      {
        text_layer_set_text(s_menuButton[i],c_genVoc[i_vocModeA(i_inMenu)][i_false]);    //i_inMenu = 1 im Modus 1
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
    text_layer_set_text(s_menuButton[0],c_genVoc[i_vocModeQ(i_inMenu)][i_vocCount]); //i_inMenu = 0 im Modus 0
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
  //i_randStart23B = i_random0(23);   //Zufallszahl zwischen 0 und 23
  //i_randStart23A = i_random0(8);    //Zufallszahl zwischen 0 und 8
  i_randStart28B = i_random0(28);   //Zufallszahl zwischen 0 und 28
  i_randStart28A = i_random0(8);    //Zufallszahl zwischen 0 und 8
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
  //int i_randTemp23;
  int i_randTemp28;
  
  for(int i=0; i<23; i++)
  {
    
    //i_randTemp23 = i_random23();
    i_randTemp28 = i_random28();
    
    //markiere freie Vokabel 
    
    for(int j = 0; j<25; j++)
    {
      //c_genVoc[0][i][j] = c3_list1[3][i_randTemp23][j]; //Vokabel
      //c_genVoc[1][i][j] = c3_list1[2][i_randTemp23][j]; //Loesung
      c_genVoc[0][i][j] = c3_list2[3][i_randTemp28][j]; //Vokabel
      c_genVoc[1][i][j] = c3_list2[2][i_randTemp28][j]; //Loesung
    }
  }
  
  //Listen erfassen
  
  //Vokabelliste initialisieren
  //Antwortmoeglichkeiten generieren

  //i_randStart3B = i_random0(23);   //Zufallszahl zwischen 0 und 23
  //i_randStart3A = i_random0(8);    //Zufallszahl zwischen 0 und 8
  //i_random3temp = i_random23();    //richtige Antwort
  i_randStart3B = i_random0(28);   //Zufallszahl zwischen 0 und 23
  i_randStart3A = i_random0(8);    //Zufallszahl zwischen 0 und 8
  i_random3temp = i_random28();    //richtige Antwort
  for(int i=1; i<4; i++)
  {
    if(i_random3temp == i)
    {
      text_layer_set_text(s_menuButton[i],c_genVoc[i_vocModeA(i_inMenu)][0]);
    }
    else
    {
      text_layer_set_text(s_menuButton[i],c_genVoc[i_vocModeA(i_inMenu)][i_false]);
      i_false++;
    }
  }
  //Vokabel initialisieren
  text_layer_set_text(s_menuButton[0],c_genVoc[i_inMenu][0]);
  //Score initialisieren
  text_layer_set_text_alignment(s_menuButton[4], GTextAlignmentCenter);
  text_layer_set_text(s_menuButton[4], "Score: 0");
  //Gewaehlte Vokabeln markieren
  //Falsche Vokabeln waehlen
}





#endif /* LOGIC_H */