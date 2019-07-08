# PRÁCTICA DE LABORATORIO 

**NOMBRE:** José Quinde-Franklin Orellana
            
**CARRERA:** Computación	

**ASIGNATURA:** Programación Aplicada

**NRO. PRÁCTICA:**	10	

**TÍTULO PRÁCTICA:** Conexión Java-Arduino

## OBJETIVO ALCANZADO:
Como objetivo Principal de esta práctica es poder aprender del funcionamiento de arduino y su programación.

También se aprendió a realizar una conexión de arduino con Java y se realizó una interfaz para poder controlar el circuito desde arduino y desde java.

##ACTIVIDADES DESARROLLADAS

**1.Crear un repositorio en GitHub.**

**Perfil:** JoseQ1996

**URL del proyecto:** https://github.com/JoseQ1996/Java_Arduino.git

-Se procedió a crear un repositorio con el nombre de Java Arduino
 
![image](https://user-images.githubusercontent.com/49071271/60775684-38126880-a0eb-11e9-8543-6a3ae7a80a35.png)

**2. Sincronizar el repositorio creado con un proyecto en NetBeans. Realizar un commit y push por cada requerimiento de los puntos a continuación descritos (incluir un mensaje que identifique claramente los commits realizados a GitHub).**

-Se realizaron 4 commits en el proyecto

-Aquí se puede revisar los commits realizados y que hizo cada uno en específico.
 
![image](https://user-images.githubusercontent.com/49071271/60775687-3d6fb300-a0eb-11e9-9902-5bb121d1a734.png)

**3. Crear clase en el paquete**

- Se proceido a crear 2 paquetes uno para las imágenes y otro para la ventana principal.
 
También se implementó la librería njavaserial para poder realizar la conexión con arduino.

![image](https://user-images.githubusercontent.com/49071271/60775689-406aa380-a0eb-11e9-8297-f323a11b5d39.png)

**4. Interfaz Grafica**

El programa cuenta con una Ventana Principal para controlar.

![image](https://user-images.githubusercontent.com/49071271/60775785-2f6e6200-a0ec-11e9-8176-a21193777931.png)

A continuación, se mostrará lo que realiza cada parte del programa

-Primero se mostrará cómo se conecta y desconecta el programa con arduino.
  
![image](https://user-images.githubusercontent.com/49071271/60775789-35fcd980-a0ec-11e9-9e50-c6857b7f06df.png)

Estos métodos mandan a conectar y desconectar el programa con el arduino.

Ahora se mostrar el método que sirve para enviar Dato y el método que sirve para recibir datos.

![image](https://user-images.githubusercontent.com/49071271/60775792-385f3380-a0ec-11e9-9303-f05ff5e2d75b.png)

La Ventana tiene que tener implementada el evento SerialPort

Para poder recibir datos del arduino a través del siguiente método.
 
![image](https://user-images.githubusercontent.com/49071271/60775794-3e551480-a0ec-11e9-90bf-ddb39b3dbd07.png)

Para poder prender y apagar los leds se implementó un método para cada led que en total son 7.
 
![image](https://user-images.githubusercontent.com/49071271/60775801-444af580-a0ec-11e9-972e-73d10c10028c.png)

En cada botón lo único que hace es mandar a llamar el método prenderLed con el label del led que se quiere prender.

Para poder controlar los leds en cada secuencia lo único que se hace es mandar a llamar a través de cada botón el control de cada led que se va prendiendo, en si lo que se controla no es la pulsación sino cuando el led esta prendido y apagado manda un dato a java para poder prender y apagar.

![image](https://user-images.githubusercontent.com/49071271/60775803-49a84000-a0ec-11e9-9332-f0a5d5486135.png)

Así dependiendo el dato que llegue se prende y se apaga el led.

Para poder prender las secuencias desde Java se manda un dato al arduino y asi podemos controlar el circuito desde java y arduino.

Para controlar el potenciómetro desde arduino se manda un Dato dependiendo la condición del if y que valor da el potenciómetro.

![image](https://user-images.githubusercontent.com/49071271/60775838-955ae980-a0ec-11e9-8197-0eb77c490dc5.png)

A continuación, se mostrará una imagen del circuito conectado en Tinkercad
 
![image](https://user-images.githubusercontent.com/49071271/60775841-9ab83400-a0ec-11e9-953d-45d77c5e4d68.png)

-Se mostrará el código implementado en Arduino.
<pre>
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
    if (apagar()==true) break;
    
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
</pre>

El código de arduino también cuenta con la implementación de métodos que son llamados al void que manda a correr el programa que en este caso es el voidLoop();

## RESULTADO(S) OBTENIDO(S):

Para el resultado obtenido se mostrará solo una imagen del circuito y de la interfaz gráfica.

![image](https://user-images.githubusercontent.com/49071271/60775844-a60b5f80-a0ec-11e9-9cdb-714b515242a8.png)

Ahora una foto de la interfaz.

![image](https://user-images.githubusercontent.com/49071271/60775845-aad01380-a0ec-11e9-94dd-1115f11341a2.png)

El funcionamiento del programa se lo puede visualizar el momento de la presentación.

## CONCLUSIONES:

Se aprendió a programar circuitos a través de la ayuda de arduino también se aprendió a manipular circuitos con una librería implementada de arduino en java.

La implementación de la conexión de java y arduino resulta muy útil para poder tener el control de los circuitos y poder llevar un registro de cuando estos están en funcionamiento desde Java.

## RECOMENDACIONES:

Implementar lo aprendido en arduino y lo aprendido en programación de java.

**Nombre de estudiantes:** José Quinde-Franklin Orellana


**Firma de estudiantes:**

![image](https://user-images.githubusercontent.com/49071271/60775849-b9b6c600-a0ec-11e9-83d5-b6703c4121e6.png)



