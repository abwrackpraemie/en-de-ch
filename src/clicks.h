#ifndef clicks_H
#define clicks_H
  
#include <pebble.h>
#include <navigate.h>
#include <logic.h>
  
int i_buttonID = 9; // 0 == UP; 1 == SELECT; 2 == DOWN

// Interaktion ***********************************

//Klicks auswerten



//UP **
void up_click_handler(ClickRecognizerRef recognizer, void *context)
{
  i_buttonID = 1;
  
  //Vokabelmodus: Up-Taste fuer Auswahl
  if(i_inMenu < 4){
    bool b_finished = b_vocCheck(i_buttonID);
    //Wechsel ins Hauptmenue, wenn fertig
    if(b_finished == 1)
    {
      menu_change(99);
    }
  }
  
  //Menuemodus: Up-Taste fuer Navigation
  else{
      //Sprung nach oben (oberstes Element ist markiert) 
      if(i_selection==0){
        text_layer_set_background_color(s_menuButton[i_selection], GColorClear);
        text_layer_set_text_color(s_menuButton[i_selection], GColorBlack);
        i_selection = i_Buttons;
        text_layer_set_background_color(s_menuButton[i_selection], GColorBlack);
        text_layer_set_text_color(s_menuButton[i_selection], GColorWhite);
      }
      else{
        text_layer_set_background_color(s_menuButton[i_selection], GColorClear);
        text_layer_set_text_color(s_menuButton[i_selection], GColorBlack);
        i_selection--;
        text_layer_set_background_color(s_menuButton[i_selection], GColorBlack);
        text_layer_set_text_color(s_menuButton[i_selection], GColorWhite);
      }
  }
  i_buttonID = 9;
}



//DOWN ** 
void down_click_handler(ClickRecognizerRef recognizer, void *context)
{
  i_buttonID = 3; 
  
  //Vokabelmodus: Down-Taste fuer Auswahl
  if(i_inMenu < 4){
    bool b_finished = b_vocCheck(i_buttonID);
    //Wechsel ins Hauptmenue, wenn fertig
    if(b_finished == 1){
      menu_change(99);
    }
  } 
  
  //Menuemodus: Down-Taste fuer Navigation
  else{
    //Sprung nach unten (oberstes Element ist markiert)
    if(i_selection==i_Buttons){
      text_layer_set_background_color(s_menuButton[i_selection], GColorClear);
      text_layer_set_text_color(s_menuButton[i_selection], GColorBlack);
      i_selection = 0;
      text_layer_set_background_color(s_menuButton[i_selection], GColorBlack);
      text_layer_set_text_color(s_menuButton[i_selection], GColorWhite);
     }
    //Markierung des darunterliegenden Elements
    else{
      text_layer_set_background_color(s_menuButton[i_selection], GColorClear);
      text_layer_set_text_color(s_menuButton[i_selection], GColorBlack);
      i_selection++;
      text_layer_set_background_color(s_menuButton[i_selection], GColorBlack);
      text_layer_set_text_color(s_menuButton[i_selection], GColorWhite);
    }
    i_buttonID = 9;
  }
  
}
//SELECT** 
void select_click_handler(ClickRecognizerRef recognizer, void *context)
{
  i_buttonID = 2; 
  
  //Vokabelmodus: Select-Taste fuer Auswahl
  if(i_inMenu < 4){
    bool b_finished = b_vocCheck(i_buttonID);
    //Wechsel ins Hauptmenue, wenn fertig
    if(b_finished == 1){
      menu_change(99);
    }
  }
  
  //Auswahl nach i_inMenu prüfen
  else if(i_inMenu == 40){
    i_selected = i_selection;
    //Markiere ausgewählten Menuepunkt, durch fette und duenne Schrift (Sprache)
    //Sprache 1
    if(i_selected == 0){
      text_layer_set_font(s_menuButton[0], fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD));
      text_layer_set_font(s_menuButton[1], fonts_get_system_font(FONT_KEY_GOTHIC_28));
      //Auswahl speichern!!!!!!!!!!!!!! Englisch
    }
    //Sprache 2
    else if(i_selected == 1){
      text_layer_set_font(s_menuButton[1], fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD));
      text_layer_set_font(s_menuButton[0], fonts_get_system_font(FONT_KEY_GOTHIC_28));
      //Auswahl speichern!!!!!!!!!!!!!! Deutsch
    }
    //Setzte Schriftart zurueck auf Standard
    else{
      //Auswahl aufheben
      text_layer_set_font(s_menuButton[0], fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD));
      text_layer_set_font(s_menuButton[1], fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD));
      i_selected = i_selection;
      //change menu
      menu_change(i_selected);
      //reset selection
      text_layer_set_background_color(s_menuButton[i_selection], GColorClear);
      text_layer_set_text_color(s_menuButton[i_selection], GColorBlack);
      i_selection = 0;
      text_layer_set_background_color(s_menuButton[i_selection], GColorBlack);
      text_layer_set_text_color(s_menuButton[i_selection], GColorWhite);
    }
  }
  
  //Auswahlfunktion
  else{
    i_selected = i_selection;
    //change menu
    menu_change(i_selected);
    //reset selection
    text_layer_set_background_color(s_menuButton[i_selection], GColorClear);
    text_layer_set_text_color(s_menuButton[i_selection], GColorBlack);
    i_selection = 0;
    text_layer_set_background_color(s_menuButton[i_selection], GColorBlack);
    text_layer_set_text_color(s_menuButton[i_selection], GColorWhite);
  }
  i_buttonID = 9; 
}
  



//Klicks definieren
void click_config_provider(void *context)
{
    window_single_click_subscribe(BUTTON_ID_UP, up_click_handler);
    window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler);
    window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
}


#endif /* CLICKS_H */