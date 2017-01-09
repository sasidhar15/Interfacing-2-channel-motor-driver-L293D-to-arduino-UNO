/*This code is to control the two gear motors of the prototype. Used total 4 limit switches
2 limit switches for controlling elevation angle and 2 limit switches for controlling azimuth angle

Used 2 channel motor driver to control the two gear motors */


// conected digital pins of arduino uno 3 & 4 to motor driver channel-1 to control motor1 (Eleveation angle)
int motor1pin1 = 3;
int motor1pin2 = 4;


// conected digital pins of arduino uno 5 & 6 to motor driver channel-2 to control motor2 (Eleveation angle)
int motor2pin1 = 5;
int motor2pin2 = 6;

// conected digital pins 8,9 of arduino to limit switch 1 & 2 of motor1
int motor1switch1_input = 8;
int motor1switch2_input = 9;

// conected digital pins 10,11 of arduino to limit switch 1 & 2 of motor2
int motor2switch1_input = 10;
int motor2switch2_input = 11;

/*Taking four variables which tells the state if the switches*/
int motor1switch1_state = 0;
int motor1switch2_state = 0;

int motor2switch1_state = 0;
int motor2switch2_state = 0;

void setup()
{

/*Making digital pins connected to channel-1 of motor driver as OUTPUT*/  
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);

/*Making digital pins connected to limit switches of motor-1 as INPUT */
  pinMode(motor1switch1_input, INPUT);
  pinMode(motor1switch2_input, INPUT);

/*Making digital pins connected to channel-2 of motor driver as OUTPUT*/  
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

/*Making digital pins connected to limit switches of motor-1 as INPUT */

  pinMode(motor2switch1_input, INPUT);
  pinMode(motor2switch2_input, INPUT);
  
  Serial.begin(9600);
}

void loop()
{

/* Reading all values of digital pins connected to the switches*/  
  motor1switch1_state = digitalRead(motor1switch1_input);
  motor1switch2_state = digitalRead(motor1switch2_input);

  motor2switch1_state = digitalRead(motor2switch1_input);
  motor2switch2_state = digitalRead(motor2switch2_input);

/*if limit switch1 of motor1 is high that means switch is pressed, so rotate the motor in opposite direction
and operating it in the same way for all the other limit switches*/
  if(motor1switch1_state == HIGH)
  {
     digitalWrite(motor1pin1, HIGH);
     digitalWrite(motor1pin2, LOW); 
     Serial.println("Motor1 ROTATE ANTICLOCK");  
  }
  else if(motor1switch2_state == HIGH)
  {
     digitalWrite(motor1pin1, LOW);
     digitalWrite(motor1pin2, HIGH);     
     Serial.println("Motor1 ROTATE CLOCk");
  }

  if(motor2switch1_state == HIGH)
  {
     digitalWrite(motor2pin1, HIGH);
     digitalWrite(motor2pin2, LOW); 
     Serial.println("Motor2 ROTATE ANTICLOCK");  
  }
  else if(motor2switch2_state == HIGH)
  {
     digitalWrite(motor2pin1, LOW);
     digitalWrite(motor2pin2, HIGH);     
     Serial.println("Motor2 ROTATE CLOCk");
  }
  
}

