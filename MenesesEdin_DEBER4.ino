 /* 
 * CAPITULO IV: PERIFÉRICOS ESPECIALES
 * DEBER 4.1: CAD Y PWM  
 * OBJETIVO: Realizar un sistema en el cual se conecten 2 motores. Los datos de CAD, V y PWM se deben visulizar en una LCD para cada motor. 
 * FUNCIONES: analogRead(conversor)
 *            conversor-> A0-A5
 *            analogWrite(pin, dutty)
 *            pin-> pines con ~, dutty -> 0-255
 * NOMBRE: Meneses Edin                  
 */
 
#include <LiquidCrystal.h>              //llamamos libreria para las LCD
LiquidCrystal lcd(13,12,5,4,3,2);       //seleccion de pines para la LCD 1
const int btn=A4;                       //creacion de la variables
int conversor;                          //variable para adquirir datos del conversor
float voltaje;                          //variable de conversion de voltaje
int  dutty;                             //variable para el uso del PWM

LiquidCrystal lcd1(A2,A3,9,8,7,6);      //seleccion de pines para la LCD 2
const int SW=A5;                        //creacion del boton para encender LCD 2
int conversor1;                         //variable para adquirir datos del conversor
float voltaje1;                         //variable de conversion de voltaje
int  dutty1;                            //variable para el uso del PWM
 
void setup() {
  lcd.begin(16,2);                      //inicalizamos la lcd 1
  lcd1.begin(16,2);                     //inicalizamos la lcd 2
  pinMode(btn,INPUT);                   //definición del botón como entrada de lcd 1
  pinMode(SW,INPUT);                    //definición del switch como entrada en lcd 2

}

void loop() {
  if(digitalRead(btn)==LOW)                 //control mediante el botón
  {
      conversor=analogRead(A1);             //lectura del canal analogo A1
      voltaje=(conversor*5.0)/1023.0;       //conversion del voltaje
      dutty=conversor/4;                    //cambio de escala para el ciclo de la variable dutty
      analogWrite(11,dutty);                //envio del valor al pin analogo(11)
      lcd.setCursor(0,0);                  
      lcd.print("CAD: " );               
      lcd.setCursor(5,0);                   
      lcd.print(conversor);                
      lcd.setCursor(0,1);                  
      lcd.print("V: ");                   
      lcd.setCursor(3,1);                 
      lcd.print(voltaje);                  
      lcd.setCursor(9,1);                
      lcd.print("PWM: ");                  
      lcd.setCursor(13,1);              
      lcd.print((dutty*100)/255);        
      delay(300);
      lcd1.clear();
  }else{
    lcd1.clear();
  }

  if(digitalRead(SW)==HIGH)                   //Control mediante Switch
  {
      conversor1=analogRead(A0);              //lectura del canal analogo A0
      voltaje1=(conversor1*5.0)/1023.0;       //conversion de voltaje
      dutty1=conversor1/4;                    //cambio de escala para el ciclo de la variable dutty
      analogWrite(10,dutty1);                 //envio del valor al pin analogo(10)
      lcd1.setCursor(0,0);                    //ubicacion del cursor en la lcd
      lcd1.print("CAD: " );                   //impresion del mensaje en la LCD
      lcd1.setCursor(5,0);                    //ubicacion del cursor en la lcd
      lcd1.print(conversor1);                
      lcd1.setCursor(0,1);                    
      lcd1.print("V: ");                    
      lcd1.setCursor(3,1);                   
      lcd1.print(voltaje1);               
      lcd1.setCursor(9,1);                   
      lcd1.print("PWM: ");                    
      lcd1.setCursor(13,1);                   
      lcd1.print((dutty1*100)/255);          
      delay(300);
      lcd1.clear();
  }
}
