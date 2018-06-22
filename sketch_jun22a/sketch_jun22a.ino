void setup() 
{



  Serial.begin(9600);
}
void loop(){
  const int pinLDR = A0;
  const int pinLED = 8;

  int m[7][12];
  int V;
  int c=0;
  int f=0;
  //CARGAR LA MATRIZ
  for(f=0;f<7;f++ ){
    for(c=0; c<12;c++){
  V = analogRead(pinLDR);
  Serial.println("Valor obtenido en el LDR");  
  Serial.println(V);
    m[f][c]=V;
  Serial.println("Valor cargado en Matriz");  
     Serial.print("Fila: ");
     Serial.print(f);
     Serial.print(" Columna: ");
     Serial.print(c);
     Serial.print("  ");
     Serial.println(m[f][c]);
//    Serial.println("Fila: "+f+" Columna: "+c+" :"+m[f][c]);
    delay(2000);
    
    }
  }
  
  Serial.println("-------------------------------------------------------------------------------");
  for(f=0; f<7; f++){
    for(c=0; c<12;c++){
      Serial.print("||");
      Serial.print(m[f][c]);
      Serial.print("    ");
    }
    Serial.println("||");
   }
  int hora = 0;
  int maxE[12] ={0,0,0,0,0,0,0,0,0,0,0,0};
  int PROM = 0;
  

for(c=0; c<12;c++){
    for(f=0; f<7; f++){
      maxE[c] = maxE [c] + m[f][c];
      if( f==6){
        maxE [c] = maxE[c] / 7;
      }
    }
}  
hora=0;
PROM = maxE[0];
for(c=0; c<12; c++){
  if (maxE[c] > PROM){
   // if(){
    PROM = maxE[c];
    hora=c;
   // }
  }
}  
Serial.println("Calcular promedio");
for(c=0; c<12; c++){
 Serial.print("|Hora|");
 Serial.print(c);
 Serial.print("|promedio|");
 Serial.print(maxE[c]);
 Serial.println("|");
}  
Serial.println("Mejor hora: ");
Serial.print("Energia: ");
Serial.println(PROM);
Serial.print("hora: ");
Serial.println(hora);


}
