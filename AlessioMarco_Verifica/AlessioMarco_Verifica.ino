//Dichiaro tutte le variabili di output
int rosso        = 12;
int verde        = 10;
int bianco       = 8;
int giallo       = 6;
int richiesta    = 0;
int numCicliMAX  = 0;
int tempo1       = 0;
int tempo2       = 0;

void setup() {
  Serial.begin(9600);
  pinMode(rosso, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(giallo, OUTPUT);
  pinMode(bianco, OUTPUT);
  richiestaCicli();
}

void richiestaCicli(){
  //Comando che permette di richiedere il tempo di accensione in millisecondi delle 2 coppie di led
  Serial.println("Dopo quanti cicli vuoi che il programma ricominci?");
  while(Serial.available() == 0);
  numCicliMAX = Serial.readString().toInt();
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
  //If che mi permette di richiedere i valori solo se la variabile richiesta è uguale al numero di cicli massimo assegnato dall'utente
  if(richiesta == numCicliMAX){
    tempo1 = random(1000, 10000);
    tempo2 = random(1000, 10000);
    richiesta = 0;
  }
  ciclo(rosso, giallo, tempo1);
  ciclo(bianco, verde, tempo2);
  richiesta++;
}
