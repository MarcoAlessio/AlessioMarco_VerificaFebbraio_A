//Dichiaro tutte le variabili di output
int rosso    = 12;
int verde    = 10;
int bianco   = 8;
int giallo   = 6;
//La variabile richiesta andrà incrementa ad ogni nuovo ciclo
int richiesta  = 0;
int tempoRG    = 0;
int tempoBV    = 0;

void setup() {
  Serial.begin(9600);
  pinMode(rosso, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(giallo, OUTPUT);
  pinMode(bianco, OUTPUT);
}

void richiestaValori(){
  //Comando che permette di richiedere il tempo di accensione in millisecondi delle 2 coppie di led
  Serial.println("Quanti millisecondi vuoi che restino accesi il rosso e il giallo?");
  while(Serial.available() == 0);
  tempoRG = Serial.readString().toInt();
  Serial.println("Quanti millisecondi vuoi che restino accesi il bianco e il verde?");
  while(Serial.available() == 0);
  tempoBV = Serial.readString().toInt();
}

void ciclo(int led1, int led2, int tempo){
  //Creo un metodo generale con delle variabili che assumono il "colore" che gli do in input nel ciclo loop()
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  delay(tempo);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
}

void loop() {
  //If che mi permette di richiedere i valori solo al primo avvio
  if(richiesta == 0){
    richiestaValori();
  }
  //Due cicli separati per entrambi i cicli delle due coppie di colori
  ciclo(rosso, giallo, tempoRG);
  ciclo(bianco, verde, tempoBV);
  richiesta++;
}
