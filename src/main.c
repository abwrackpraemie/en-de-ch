#include <pebble.h>
#include <navigate.h>
#include <clicks.h>
#include <mainmenu.h>

//essential 2
static void init()
{
  // Create main Window element and assign to pointer
  s_main_window = window_create();
 
  // Set handlers to manage the elements inside the Window
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });
  
  //Tasten einbinden
  window_set_click_config_provider(s_main_window, click_config_provider);
  window_stack_push(s_main_window, true);
}

void deinit()
{
  window_destroy(s_main_window);
}
  


//essential 1
int main(void)
{
  init();
  app_event_loop();
  deinit();
}