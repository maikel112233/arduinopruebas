/*  TITULO: Reloj en tiempo real Tiny RTC I²C con LCD 2004.

    AUTOR:
    
    MARIANO DEL CAMPO GARCÍA (@2016) --> INGENIERO TÉCNICO INDUSTRIAL ESPECIALIDAD ELECTRÓNICA
    - FACEBOOK: https://www.facebook.com/mariano.delcampogarcia
    - TWITTER: https://twitter.com/MarianoCampoGa
    - CORREO: marianodc83@gmail.com
    
    
    DESCRIPCIÓN DEL PROGRAMA
    
    Con este programa obtenemos un reloj en tiempo real gracias al Tiny RTC I²C que mostrará los valores
    de hora y fecha a través de un display LCD 2004 que hemos conectado a nuestro Arduino mediante 
    comunicación I²C al igual que el RTC.
    
 
    ESQUEMA DE CONEXION
    
                                      +-----+
         +----[PWR]-------------------| USB |--+
         |                            +-----+  |
         |         GND/RST2  [ ][ ]            |
         |       MOSI2/SCK2  [ ][ ]  A5/SCL[ ] |  SCL del LCD 2004 / SCL del Tiny RTC I²C  
         |          5V/MISO2 [ ][ ]  A4/SDA[ ] |  SDA del LCD 2004 / SDA del Tiny RTC I²C 
         |                             AREF[ ] |
         |                              GND[ ] |
         | [ ]N/C                    SCK/13[ ] |   
         | [ ]IOREF                 MISO/12[ ] |   
         | [ ]RST                   MOSI/11[ ]~|   
         | [ ]3V3    +---+               10[ ]~|   
         | [ ]5v    -| A |-               9[ ]~|   
         | [ ]GND   -| R |-               8[ ] |   
         | [ ]GND   -| D |-                    |
         | [ ]Vin   -| U |-               7[ ] |   
         |          -| I |-               6[ ]~|   
         | [ ]A0    -| N |-               5[ ]~|   
         | [ ]A1    -| O |-               4[ ] |   
         | [ ]A2     +---+           INT1/3[ ]~|  
         | [ ]A3                     INT0/2[ ] |   
         | [ ]A4/SDA  RST SCK MISO     TX>1[ ] |   
         | [ ]A5/SCL  [ ] [ ] [ ]      RX<0[ ] |   
         |            [ ] [ ] [ ]              |
         |  UNO_R3    GND MOSI 5V  ____________/
          \_______________________/

  NOTAS:
   - La alimentación y la masa del módulo LCM 2004 I²C V1 van directamente conectadas a +5V y GND
     respectivamente.
   - La alimentación y la masa del Tiny RTC I²C también van directamente conectadas a +5V y GND
     respectivamente.
*/

  // Importar librerías
  #include <Wire.h> // Librería para la comunicación I²C
  #include <LiquidCrystal_I2C.h> // Librería para el LCD I²C 
  #include "RTClib.h" // Librería para el RTC
  
  // Declaración del objeto para el LCD 2004 I²C
  // Poner la dirección del LCD a 0x20 para display 20x4 (A0=0, A1=0, A2=0)
  // Terminales de conexión del LCD
  //                    addr, en,rw,rs,d4,d5,d6,d7,bl,blpol
  LiquidCrystal_I2C lcd(0x3f,16,2);
  
  // Declaración del objeto para el RTC
  DS1307 RTC;
  
  void setup () 
  {
   lcd.begin(20,4); // Inicializamos el LCD para 20x4    
   Wire.begin(); // Inicializamos la comunicación I²C para el RTC
   RTC.begin(); // Inicializamos el RTC
   
   // Si quitamos el comentario de la línea siguiente, se ajusta la hora y la fecha con la del PC
   // RTC.adjust(DateTime(__DATE__, __TIME__));
   //lcd.display();
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("RELOJ EN TIEMPO REAL");
   lcd.setCursor(0,1);
   lcd.print("********************");
  }
    
  void loop () 
  {
   // Obtenemos la hora y la fecha del Tiny RTC I²C  
   DateTime now = RTC.now();
   
   lcd.setCursor(0,2);
   // Imprimimos la hora (HH:MM:SS)
   lcd.print("> HORA: ");
   // Imprimimos las HORAS
   if(now.hour()<=9)
   {
     lcd.print("0");
   }
   lcd.print(now.hour(), DEC);
   lcd.print(':');
   // Imprimimos los MINUTOS
   if(now.minute()<=9)
   {
     lcd.print("0");
   }
   lcd.print(now.minute(), DEC);
   lcd.print(':');
   // Imprimimos los SEGUNDOS
   if(now.second()<=9)
   {
     lcd.print("0");
   }
   lcd.print(now.second(), DEC);
   
   lcd.setCursor(0,3);
   // Imprimimos la fecha (DÍA/MES/AÑO)
   lcd.print("> FECHA: ");
   // Imprimimos el DÍA
   if(now.day()<=9)
   {
     lcd.print("0");
   }
   lcd.print(now.day(), DEC);
   lcd.print('/');
   // Imprimimos el MES
   if(now.month()<=9)
   {
     lcd.print("0");
   }
   lcd.print(now.month(), DEC);
   lcd.print('/');
   // Imprimimos el AÑO
   lcd.print(now.year(), DEC);
  }
