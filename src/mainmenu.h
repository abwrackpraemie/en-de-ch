#ifndef mainmenu_H
#define mainmenu_H
#include <pebble.h>
#include <navigate.h>

//Auswahl

//add Text Layer

static Window *s_main_window;

  static void main_window_load(Window *window) {
  for(int i=0; i<5; i++){
    //Gestaltung der Button
    s_menuButton[i] = text_layer_create(GRect(0, 0+33*i, 144, 35));  
    text_layer_set_background_color(s_menuButton[i], GColorClear);  
    text_layer_set_text_color(s_menuButton[i], GColorBlack);
    
    //Layout der Button
    text_layer_set_font(s_menuButton[i], fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD));
    text_layer_set_text_alignment(s_menuButton[i], GTextAlignmentLeft);

    //Verknüpfung mit Window
    layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_menuButton[i]));  
  } 
  
  text_layer_set_background_color(s_menuButton[i_selection], GColorBlack);
  text_layer_set_text_color(s_menuButton[i_selection], GColorWhite);
  //Beschriftung
  text_layer_set_text(s_menuButton[0], "X->简化字");
  text_layer_set_text(s_menuButton[1], "简化字->X");
  text_layer_set_text(s_menuButton[2], "X->Pinyin");
  text_layer_set_text(s_menuButton[3], "Pinyin->X");
  text_layer_set_text(s_menuButton[4], "Settings");
}


static void main_window_unload(Window *window) {
  // Destroy TextLayer
  for(int i=0; i<5; i++){
    text_layer_destroy(s_menuButton[i]);
  } 
}

#endif /* MAINMENU_H */
