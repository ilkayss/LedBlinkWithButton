#define RightButton 7
#define LeftButton 8

byte dizi[5] = {2,3,4,5,6};
int i;

byte level = 0;

void setup() {


  pinMode(LeftButton , INPUT);
  pinMode(RightButton,INPUT);

  for(i=0;i<5;i++){
    pinMode(dizi[i],OUTPUT);
  }

}
void loop() {
 buttonControl();
 levelControl();

}
void buttonControl(){
  if(digitalRead(LeftButton) == HIGH){ // sol butona basildigi zaman

  while(digitalRead(LeftButton) == HIGH);  //Buton arkini onlemek icin 
  if(level>1)
    level --;
  }
  if(digitalRead(RightButton) == HIGH){
  while(digitalRead(RightButton) == HIGH); //Buton arkını engellemek için!
  if(level < 5)
  level++;
  }
}

void levelControl(){
  for(byte i = 0; i < 5; i++){
  digitalWrite(dizi[i], LOW); //Bütün ledleri söndürüyoruz
  }
  if(level > 0)
  digitalWrite(dizi[level - 1], HIGH); //Kademeye göre ilgili ledi yakıyoruz
}