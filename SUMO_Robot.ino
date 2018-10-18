#define Up_Button     2  //กำหนดให้ขา 2 ของไมโครคอนโทรลเลอร์มีค่าเท่ากับ Up_Button 
#define Down_Button   4  //กำหนดให้ขา 4 ของไมโครคอนโทรลเลอร์มีค่าเท่ากับ Down_Button 
#define Right_Button  3  //กำหนดให้ขา 3 ของไมโครคอนโทรลเลอร์มีค่าเท่ากับ Right_Button 
#define Left_Button   5  //กำหนดให้ขา 5 ของไมโครคอนโทรลเลอร์มีค่าเท่ากับ Left_Button 
#define motor1_A 9    //กำหนดให้ขา 9 ของไมโครคอนโทรลเลอร์มีค่าเท่ากับ motor1_A 
#define motor1_B 10   //กำหนดให้ขา 10 ของไมโครคอนโทรลเลอร์มีค่าเท่ากับ motor1_B
#define motor2_A 11   //กำหนดให้ขา 11 ของไมโครคอนโทรลเลอร์มีค่าเท่ากับ motor2_A
#define motor2_B 12   //กำหนดให้ขา 12 ของไมโครคอนโทรลเลอร์มีค่าเท่ากับ motor2_B



void setup() 
{  
  pinMode(motor1_A,OUTPUT);  //กำหนดหน้าที่ของขาไมโครคอนโทรลเลอร์ motor1_A ให้ทำหน้าที่เป็น OUTPUT (ขาสั่งงาน)
  pinMode(motor1_B,OUTPUT);
  pinMode(motor2_A,OUTPUT);
  pinMode(motor2_B,OUTPUT);

  pinMode(Up_Button,INPUT);  //กำหนดหน้าที่ของขาไมโครคอนโทรลเลอร์ Up_Button ให้ทำหน้าที่เป็น INPUT (ขารับสัญญาณ)
  pinMode(Down_Button,INPUT);
  pinMode(Left_Button,INPUT);
  pinMode(Right_Button,INPUT);
  
  Serial.begin(9600);
}

void loop() {
  

  bool Push_Up    = !digitalRead(Up_Button);    //สร้างตัวแปรเพื่อเก็บค่า และอ่านค่าสถานะของการกดปุ่ม Up โดยมีชื่อว่า Push_Up
  bool Push_Down  = !digitalRead(Down_Button);
  bool Push_Right = !digitalRead(Right_Button);
  bool Push_Left  = !digitalRead(Left_Button);

  if(Push_Up) // ตรวจสอบเงื่อนไขสถานะการกดปุ่ม Push_Up ถ้ามีการกดปุ่มจึงจะทำตามเงื่อนไขที่กำหนด
  {
    Serial.println("Go Straight");  //ส่งค่ากลับไปยังคอมพิวเตอร์ว่า Go Straight (วื่งไปด้านหน้า)
    analogWrite(motor1_A,255);      //สั่งให้ขา motor1_A มีสถานะไฟฟ้าเป็น 100 % (วิ่งเต็มกำลัง)
    analogWrite(motor2_A,255);
  }

  else if(Push_Down)
  {
    Serial.println("Go Back");
    analogWrite(motor1_B,255);
    analogWrite(motor2_B,255);
  }

  else if(Push_Right)
  {
    Serial.println("Turn Right");
    analogWrite(motor1_B,128);
    analogWrite(motor2_A,128);
  }

  else if(Push_Left)
  {
    Serial.println("Turn Left");
    analogWrite(motor1_A,128);
    analogWrite(motor2_B,128);
  }
  else // ถ้าหากไม่มีการกดปุ่มใด ๆ 
  {
    Serial.println("Stop");     //ส่งค่ากลับไปยังคอมพิวเตอร์ว่า Stop (หยุด)
    digitalWrite(motor1_A,LOW); //กำหนดค่าสถานะไฟฟ้าของขา motor1_A ให้มีค่าเป็น 0 โวลต์
    digitalWrite(motor1_B,LOW);
    digitalWrite(motor2_A,LOW);
    digitalWrite(motor2_B,LOW);
  }

}
