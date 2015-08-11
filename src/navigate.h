#ifndef navigate_H
#define navigate_H
#include <pebble.h>
#include <logic.h> //s_menuButton und so ....
  
//int i_inMenu = 99;     // 0 == X->Sym, 1 == Sym->X, 2 == Sym->X, 3 == Sym->X, 4 == Sym->X, 99 == Hauptmenue
int i_Buttons = 4;
int i_selection = 0;  // markiert
int i_selected = 99;  // ist ausgewaehlt

//static TextLayer *s_menuButton[5];

void menu_change(int i_selected){

  //Verhalten im Hauptmenue
  if(i_inMenu == 99){
    switch(i_selected)
      {
      case 0:
          i_inMenu = i_selected;
          vocMixer(i_inMenu);
         /* text_layer_set_text(s_menuButton[0], "Vokabel");
          text_layer_set_text(s_menuButton[1], "Symbol 1");
          text_layer_set_text(s_menuButton[2], "Symbol 2");
          text_layer_set_text(s_menuButton[3], "Symbol 3");
          text_layer_set_text_alignment(s_menuButton[4], GTextAlignmentCenter);
          text_layer_set_text(s_menuButton[4], "Score: 0");
          text_layer_set_text(s_menuButton[i_random3temp],c3_list1[2][0]);*/
          
        break;
      case 1:
          i_inMenu = i_selected;
          vocMixer(i_inMenu);
          /*text_layer_set_text(s_menuButton[0], "Symbol");
          text_layer_set_text(s_menuButton[1], "Vokabel 1");
          text_layer_set_text(s_menuButton[2], "Vokabel 2");
          text_layer_set_text(s_menuButton[3], "Vokabel 3");
          text_layer_set_text_alignment(s_menuButton[4], GTextAlignmentCenter);
          text_layer_set_text(s_menuButton[4], "Score: 0");*/

        break;
      case 2:
          text_layer_set_text(s_menuButton[0], "Vokabel");
          text_layer_set_text(s_menuButton[1], "Pinyin 1");
          text_layer_set_text(s_menuButton[2], "Pinyin 2");
          text_layer_set_text(s_menuButton[3], "Pinyin 3");
          text_layer_set_text_alignment(s_menuButton[4], GTextAlignmentCenter);
          text_layer_set_text(s_menuButton[4], "Score: 0");
          i_inMenu = i_selected;
        break;
      case 3:
          text_layer_set_text(s_menuButton[0], "Pinyin");
          text_layer_set_text(s_menuButton[1], "Vokabel 1");
          text_layer_set_text(s_menuButton[2], "Vokabel 2");
          text_layer_set_text(s_menuButton[3], "Vokabel 3");
          text_layer_set_text_alignment(s_menuButton[4], GTextAlignmentCenter);
          text_layer_set_text(s_menuButton[4], "Score: 0");
          i_inMenu = i_selected;    
        break;
      case 4:
          text_layer_set_text(s_menuButton[0], "Language");
          text_layer_set_text(s_menuButton[1], "Lists");
          text_layer_set_text(s_menuButton[2], "Scope");
          text_layer_set_text(s_menuButton[3], "Method");
          text_layer_set_text(s_menuButton[4], "<- back");
          i_inMenu = i_selected;
        break;
      default:
          text_layer_set_text(s_menuButton[0], "X->简化字");
          text_layer_set_text(s_menuButton[1], "简化字->X");
          text_layer_set_text(s_menuButton[2], "X->Pinyin");
          text_layer_set_text(s_menuButton[3], "Pinyin->X");
          text_layer_set_text(s_menuButton[4], "Settings");
          i_inMenu = 99;
        break;
      }
  }
  
  
  
  //Verhalten im Settings-Menue
  else if(i_inMenu == 4){
    switch(i_selected)
      {
      case 0:
          text_layer_set_text(s_menuButton[0], "English"); //Auswahl pruefen und ggf. fett machen
          text_layer_set_text(s_menuButton[1], "German");  //Auswahl pruefen und ggf. fett machen
          text_layer_set_text(s_menuButton[2], "<- back");
          text_layer_set_text(s_menuButton[3], "<- back");
          text_layer_set_text(s_menuButton[4], "<- back");
          i_inMenu = 40;
        break;
      case 1:
          text_layer_set_text(s_menuButton[0], "List 1"); //Auswahl pruefen und ggf. fett machen
          text_layer_set_text(s_menuButton[1], "List 2"); //Auswahl pruefen und ggf. fett machen
          text_layer_set_text(s_menuButton[2], "List 3"); //Auswahl pruefen und ggf. fett machen
          text_layer_set_text(s_menuButton[3], "List 4"); //Auswahl pruefen und ggf. fett machen
          text_layer_set_text(s_menuButton[4], "<- back");
          i_inMenu = 41;
        break;
      case 2:
          text_layer_set_text(s_menuButton[0], "10");
          text_layer_set_text(s_menuButton[1], "15");
          text_layer_set_text(s_menuButton[2], "20");
          text_layer_set_text(s_menuButton[3], "25");
          text_layer_set_text(s_menuButton[4], "<- back");
          i_inMenu = 42;
        break;
      case 3:
          text_layer_set_text(s_menuButton[0], "Intelligent"); //Auswahl pruefen und ggf. fett machen
          text_layer_set_text(s_menuButton[1], "All");         //Auswahl pruefen und ggf. fett machen
          text_layer_set_text(s_menuButton[2], "New");         //Auswahl pruefen und ggf. fett machen
          text_layer_set_text(s_menuButton[3], "<- back");
          text_layer_set_text(s_menuButton[4], "<- back");
          i_inMenu = 43;
        break;
      default:
          text_layer_set_text(s_menuButton[0], "X->简化字");
          text_layer_set_text(s_menuButton[1], "简化字->X");
          text_layer_set_text(s_menuButton[2], "X->Pinyin");
          text_layer_set_text(s_menuButton[3], "Pinyin->X");
          text_layer_set_text(s_menuButton[4], "Settings");
          i_inMenu = 99;
        break;
    }
  }
  
    
    
    //Zurück zum Hauptmenue
  else{
    //Back-Button
    text_layer_set_text(s_menuButton[0], "X->简化字");
    text_layer_set_text(s_menuButton[1], "简化字->X");
    text_layer_set_text(s_menuButton[2], "X->Pinyin");
    text_layer_set_text(s_menuButton[3], "Pinyin->X");
    text_layer_set_text(s_menuButton[4], "Settings");
    i_inMenu = 99;
  }
  
}



#endif /* NAVIGATE_H */