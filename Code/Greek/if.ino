/*
Αυτός ο κωδικός σχεδιάστηκε από τον Κωνσταντίνο Σάκκα.
Προορίζεται για ακαδημαϊκή χρήση στο Τμήμα Πληροφορικής και Τηλεπικοινωνιών του Πανεπιστημίου
Ιωαννίνων και του github https://ksakkas.github.io/Learn-Wiring-with-Arduino-Mega/.
*/
/*
Αυτός ο κώδικας σχεδιάστηκε και εκτελέστηκε στο πρόγραμμα Arduino έκδοσης 1.8.13
Σχεδιάστηκε για χρήση με το Arduino Mega 2560
*/

//To led ανάβει εαν δώσουμε 1

#define led 10      //Αρχικοποίηση led =  10 pin


void setup() {
    Serial.begin(9600);                    //Είναι ο ρυθμός μετάδοσης σε bits ανά δευτερόλεπτο (για Serial).
    pinMode(led, OUTPUT);                //Δηλώση led ως έξοδο 

}

void loop() {
  int x = Serial.parseInt();        //Διαβάζει από το σειριακό και το μετατρέπει σε ακέραιο

  if(x==1)                         //Αν x = 1
  {
      digitalWrite(led, HIGH);   //Δίνει λογική τιμή 1 (HIGH) στο led, δηλαδή το ανάβει.
  }
  else                           //αλλιώς
  {
      digitalWrite(led, LOW);  //Δίνει λογική τιμή 0 (LOW) στο led, δηλαδή το απενεργοποιεί.
  }
}