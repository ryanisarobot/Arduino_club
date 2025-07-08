int rowPin[] = {2,3,4,5,6,7,8,9};
int colPin[] = {17,16,15,14,13,12,11,10};
byte smile[] = {
  B00111100,
  B01000010,
  B10100101,
  B10000001,
  B10100101,
  B10011001,
  B01000010,
  B00111100};

void setup() 
{
  for(int i = 0; i <8; i++){
    pinMode(rowPin[i], OUTPUT);
    pinMode(colPin[i], OUTPUT);
  }
}

void loop() 
{
 displaySprite(); 
}


void displaySprite(){
  for(int count = 0; count < 8; count ++){
    for(int i = 0; i < 8 i++){
      digitalWrite(rowPin[i], LOW);
    }
    for(int i = 0; i < 8; i++){

      if(i == count){
        digitalWrite(colPin[i], LOW);
      }
      else{
        digitalWrite(colPin[i], HIGH);
      }
    }
    for(int row = 0; row < 8; row++){
      int bit = (smile[count] >> row) & 1;
      if(bit == 1){
        digitalWrite(rowPin[row], HIGH);
      }
    }
  }
}
