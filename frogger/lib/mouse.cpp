#include "video.h"
#include "mouse.h"
#include "libreria.h"


// Variable que guarda el estado del rat�n
struct T_MOUSE g_Mouse ;


// ------------------------------------------------------------------------------------------------
// Esta funci�n no est� pensada para usarse directamente. Avisa de que se acaba de pulsar un 
// bot�n del rat�n
//
void Mouse_ProcessButtonDown(int boton)
{
  g_Mouse.trg[boton] = TRUE ;
  g_Mouse.cnt[boton] = TRUE ;
}




// ------------------------------------------------------------------------------------------------
// Esta funci�n no est� pensada para usarse directamente. Avisa de que se acaba de soltar un 
// bot�n del rat�n
//
void Mouse_ProcessButtonUp(int boton)
{
  g_Mouse.cnt[boton] = FALSE ;
}




// ------------------------------------------------------------------------------------------------
// Esta funci�n procesa los datos de haber movido la rueda del rat�n
//
void Mouse_ProcessWheel(int wheelx, int wheely)
{
  if(wheely > 0) {
  
    g_Mouse.bWheelUp = TRUE ;
  }
  else {
  
    if(wheely < 0) {
    
      g_Mouse.bWheelDown = TRUE ;
    }
  }

  if(wheelx < 0) {
  
    g_Mouse.bWheelLeft = TRUE ;
  }
  else {
  
    if(wheelx > 0) {
    
      g_Mouse.bWheelRight = TRUE ;
    }
  }
}




// ------------------------------------------------------------------------------------------------
// Inicializa la estructura de datos de rat�n para poderla usar
//
void Mouse_Init()
{
  memset(&g_Mouse, 0, sizeof(struct T_MOUSE)) ;
}




// ------------------------------------------------------------------------------------------------
// Procesa los datos que tenemos del rat�n para que luego podamos leer algo con sentido
//
void Mouse_Tick()
{
  Uint8 button_bitmask ;
  int var_boton ;

  // Leemos las coordenadas, y de paso la m�scara de botones pulsados

  g_Mouse.last_x = g_Mouse.x ;
  g_Mouse.last_y = g_Mouse.y ;

  button_bitmask = SDL_GetMouseState(&g_Mouse.x, &g_Mouse.y) ;

  g_Mouse.offset_x = g_Mouse.x - g_Mouse.last_x ;
  g_Mouse.offset_y = g_Mouse.y - g_Mouse.last_y ;

  // Hay que vigilar que el rat�n est� dentro de la pantalla, si no lo est� lo ignoramos

  // Hacer la comprobaci�n con (unsigned)pos > tam ?

  if(g_Mouse.x >= g_Video.resx) g_Mouse.x = g_Video.resx - 1 ;
  if(g_Mouse.x < 0) g_Mouse.x = 0 ;
  
  if(g_Mouse.y >= g_Video.resy) g_Mouse.y = g_Video.resy - 1 ;
  if(g_Mouse.y < 0) g_Mouse.y = 0 ;

  for(var_boton = BUTTON_1; var_boton < MAX_NUM_POINTER_BUTTONS; var_boton++) {

    if(button_bitmask & SDL_BUTTON(var_boton)) {
    
      Mouse_ProcessButtonDown(var_boton) ;
    }
  }

  // Borramos los triggers

  memset(g_Mouse.trg, 0, sizeof(int) * MAX_NUM_POINTER_BUTTONS) ;
  
  g_Mouse.bWheelUp = FALSE ;
  g_Mouse.bWheelDown = FALSE ;

  g_Mouse.bWheelLeft = FALSE ;
  g_Mouse.bWheelRight = FALSE ;
}
