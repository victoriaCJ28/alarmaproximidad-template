/*Variables zone*/
#define BUZZER 13
#include <cintametrica.h>
//construimos el objeto Ultrasonido(pintrigger, pinecho)
Ultrasonido sensor(11,10); /*Instancia de la clase ultrasonido*/
byte pines[7]={2,3,4,5,6,7,8}; //pines para el display 7 seg
Display7 pantalla;
int distancia;
void setup() {
  //configuramos la pantalla
  Serial.begin(9600);
  /*Serial.begin(115200);*//*wemos*/
  pantalla.configurar(pines);
  pinMode(BUZZER,OUTPUT);  
}

void loop() {
  distancia=sensor.medirCM(); //medimos distancia  
  Serial.println(distancia);
  distancia=(byte) distancia /10;
  Serial.println(distancia);
  pantalla.mostrar(distancia); //mostramos en display  
  digitalWrite(BUZZER,1);
  delay(500);
  digitalWrite(BUZZER,0);
  delay(120 * distancia);

}