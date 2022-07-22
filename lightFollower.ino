

// the setup function runs once when you press reset or power the board
int IN1=11;
int IN2=9;
int IN3=5;//left motor
int IN4=3;

//Motor Speed
int basicSpeed=90;
int basicSpeed2 =90;

void setup() {
  // put your setup code here, to run once:
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(A2,INPUT);
  pinMode(A4,INPUT);
  Serial.begin(9600);
}
void loop()
{
int in1 = analogRead(A4);//left
 int in2 = analogRead(A2);//right
 int t1=in1;
 int t2=in2;
 in1=map(in1,230,1024,500,0)+75;
 in2=map(in2,50,1024,500,0);
 Serial.print(in1);
 Serial.print("  ");
 Serial.println(in2);
 //delay(1000);
 
if(t1>800&&t2>600)
{
  stop(); 
}
else
{
int dif=(in1>in2)?in1-in2:in2-in1;
dif=map(dif,0,500,0,50);
if(dif<10)
{forward();

}
else if(in1<in2)
 {
  leftTurn(dif);
 }
 else
 rightTurn(dif);
//delay(1000);
}
}
void forward()
{ Serial.println("FORWARD");
          analogWrite(IN1,0);
          analogWrite(IN2,basicSpeed);
          analogWrite(IN3,0);
          analogWrite(IN4,basicSpeed);
  
}
void leftTurn(int diff)
{
  Serial.print("LEFT");
  Serial.println(diff);
          analogWrite(IN1,0);
          analogWrite(IN2,basicSpeed-diff);
          analogWrite(IN3,0);
         if(basicSpeed+diff>250)
          analogWrite(IN4,250);
         else
          analogWrite(IN4,basicSpeed+diff);
}
void rightTurn(int diff)
{
  Serial.print("RIGHT");
  Serial.println(diff);
  diff=diff*1.25;
          analogWrite(IN1,0);
          if(basicSpeed+diff>250)
          analogWrite(IN2,250);
          else
          analogWrite(IN2,basicSpeed+diff);
          analogWrite(IN3,0);
          analogWrite(IN4,basicSpeed-diff); 
}
void stop()
{
  Serial.println("STOP");
 analogWrite(IN1,0);
 analogWrite(IN2,0);
          analogWrite(IN3,0);
          analogWrite(IN4,0); 
}