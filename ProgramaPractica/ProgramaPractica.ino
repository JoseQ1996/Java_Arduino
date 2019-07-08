//Definimos variables
int pinArray[] = {5,6,7, 8, 9, 10, 11}; 
int valor; 
int count=0;
int tailLength = 3;
int lineSize = 7;
int pulsante1= 12;
int pulsante2=4;
int pulsante3=3;
int pulsante4=2;
int espera=0;
int valorUSB=0;

void setup()
//Inicializamos Variables
{
  for (count=0;count<7;count++){ // Configuramos todos los PINs
  pinMode(pinArray[count], OUTPUT);
  }
pinMode(pulsante1,INPUT);
pinMode(pulsante2,INPUT);
pinMode(pulsante3,INPUT);
pinMode(pulsante4,INPUT);
Serial.begin(9600);  

}

void loop()
//Corremos programa
{  
  obtenerValor();
 int a=digitalRead(pulsante1);
 int b= digitalRead(pulsante2);                   
 int c=digitalRead(pulsante3); 
 int d=digitalRead(pulsante4); 
 
 if(valorUSB>=60){
  potenJava();
  
 }
 else{
  valorPot();
 }
 prendeLeds();
 obtenerValor();  
  if(a==1||valorUSB==55){      
        Progra1(); 
        obtenerValor();     
    apagarLedsd();
  }
  if(b==1||valorUSB==56){ 
        Progra2();
        obtenerValor();   
    apagarLedsd();
  }
  if(c==1||valorUSB==57){ 
        Progra3();
        obtenerValor();
    apagarLedsd();
  }

}
  /*
   * Este programa prende los led de afuera hacia dentro.
   */
void Progra1(){
  while(apagar()==false){
    int t=6;
  for (count=0;count<4;count++) { 
    
  digitalWrite(pinArray[count],HIGH); //encendemos el led rojo
  Serial.write(count+1);
  digitalWrite(pinArray[t],HIGH); //encendemos el led rojo
  Serial.write(t+1);
  delay(espera);             //esperamos 2 segundos
  digitalWrite(pinArray[count],LOW);  //apagamos el led rojo
  Serial.write(7+count+1);
  digitalWrite(pinArray[t],LOW); 
  Serial.write(7+t+1);   
    t--;
    if(count==3){
      t=6;
    }
      //apagamos el led rojo
 delay(espera); 
    obtenerValor();  
     if(valorUSB>=60){
  potenJava();
 }
 else{
  valorPot();
 }
    if (apagar()==true) break;
  } 
  }
}
  /*
   * Programa que prende los led como el auto Fantastico
   */
void Progra2(){

    int p=0;
    while(apagar()==false){
      for (count=0;count<7;count++) { // utilizando la secuencia de control for(;;) 
    digitalWrite(pinArray[count], HIGH); // Recorrido de ida
    Serial.write(count+1);
    delay(espera);
    digitalWrite(pinArray[count], LOW);
    Serial.write(8+count);
    delay(espera);
    obtenerValor();
     if(valorUSB>=60){
  potenJava();
 }
 else{
  valorPot();
 }
    if (apagar()==true) {
    p=1;  
    break;    
    }
    }
    if(p==1){
      break;
    }    
    for (count=6;count>=0;count--) {
    digitalWrite(pinArray[count], HIGH); // Recorrido de vuelta
    Serial.write(count+1);
    delay(espera);
    digitalWrite(pinArray[count], LOW);
    Serial.write(8+count);
    delay(espera);
    obtenerValor(); 
 if(valorUSB>=60){
  potenJava();
 }
 else{
  valorPot();
 }
    if (apagar()==true) break;
    }
    obtenerValor();
    valorPot();
    
    
}
}
 /*
   * Programa que enciende los leds como una estrella fugaz
   */
void Progra3(){
 
  int p=0;
  while(apagar()==false){
int tailCounter = tailLength;
for (count=0; count<lineSize; count++)
{
digitalWrite(pinArray[count],HIGH);
Serial.write(count+1);
delay(espera);
if (tailCounter == 0)
{
digitalWrite(pinArray[count-tailLength],LOW);
Serial.write(8+count-tailLength);
}
else
if (tailCounter > 0)
tailCounter--;
obtenerValor();
 if(valorUSB>=60){
  potenJava();
 }
 else{
  valorPot();
 }
  if (apagar()==true) {
    p=1;
    break;
  }
}
if(p==1){
      break;
    }  
for (count=(lineSize-tailLength); count<lineSize; count++)
{
digitalWrite(pinArray[count],LOW);// Se apagan los LED
Serial.write(8+count);
delay(espera);
obtenerValor();
 if(valorUSB>=60){
  potenJava();
 }
 else{
  valorPot();
 }
  if (apagar()==true) break;
}
  }
}
/**
 * Apaga los leds del arduino y de java.
 */
void apagarLeds(){
Serial.write(50);
for (count=7;count>=0;count--) {
digitalWrite(pinArray[count], LOW);

}
}
/**
 * Apaga los leds
 */
void apagarLedsd(){
for (count=7;count>=0;count--) {
digitalWrite(pinArray[count], LOW);

}  
}
boolean apagar(){
if(digitalRead(pulsante4) == HIGH||valorUSB==58) {
  return true;
} else {
  return false;

}
  delay(10);
}
 /*
   * Leemos el valor del potenciometro
   */
void valorPot(){
  
 
  // leemos del pin A0 valor
  
  valor = analogRead(A0);
  //Serial.println(valor);
  delay(10);
  if(valor<200 && valor>0){
    Serial.write(71);
    espera=100;
  }
  else if(valor<400 && valor>201){
    espera=300;
    Serial.write(72);
  }
  else if(valor<600 && valor>401){
    espera=700;
    Serial.write(73);
  }
  else if(valor>601){
    espera=1000;
    Serial.write(74);
  }
  
  /*
    0-1024
    entre 0 y 400 - 100
    entre 401 y 600 - 300
    entre 601 y 800 - 700
    entre > 901 - 1000
  */
}
/**
 * Prende los led con conexion de Java
 */
void prendeLeds(){
  
 obtenerValor();
  if(valorUSB==5){
    digitalWrite(pinArray[0],HIGH);
  }
  if(valorUSB==6){
    digitalWrite(pinArray[1],HIGH);
  }
  if(valorUSB==7){
    digitalWrite(pinArray[2],HIGH);
  }
  if(valorUSB==8){
    digitalWrite(pinArray[3],HIGH);
  }
  if(valorUSB==9){
    digitalWrite(pinArray[4],HIGH);
  }
  if(valorUSB==10){
    digitalWrite(pinArray[5],HIGH);
  }
  if(valorUSB==11){
    digitalWrite(pinArray[6],HIGH);
  }

  if(valorUSB==19){
    apagarLedsd();
  }
 
}
/**
 * Se obtiene el valor enviado desde Java
 */
void obtenerValor(){

  if(Serial.available()>0){
    valorUSB=Serial.read();
    //Serial.write(valorUSB);
  }
  }
  /**
   * Manipulacion de potenciometro virtual de java a arduino
   */
void potenJava(){
    obtenerValor();
    if(valorUSB==60){
    espera=100;
  }
  else if(valorUSB==61){
    espera=300;
  }
  else if(valorUSB==62){
    espera=700;
  }
  else if(valorUSB==63){
    espera=1000;
  }
   
}
  
