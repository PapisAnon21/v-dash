/*
Auteur : Anon 21

premiere journée de travail : 23/02/2025
*/

#define SOUND_SPEED 0.034 // vitesse du son en cm/us ---> on convertit 340m/s en cm/us
long durationSensor1;


#define triggerPinSensor1 2
#define echoPinSensor1 15






const float hauteurMax = 1.0; // 100 cm -- 1m
const float Surface_a_la_base = 316.0; // la surface de base en m2
float distanceSensor1;
float distanceSensor1EnM;
float volumeComputed;

void setup() {
 
  Serial.begin(115200);

  pinMode(triggerPinSensor1, OUTPUT);
  pinMode(echoPinSensor1, INPUT);

}

void loop() {
  
  // fist we set off all the trigger pin
  digitalWrite(triggerPinSensor1, LOW);
  delayMicroseconds(2);

  // after we set on all the trigger pin for 10
  digitalWrite(triggerPinSensor1, HIGH);
  delayMicroseconds(10);

  // we calculate the duration for the signal to coming back
  durationSensor1 = pulseIn(echoPinSensor1, HIGH);
  

  // and then we calculate the distance
  distanceSensor1 = durationSensor1 * SOUND_SPEED * 0.5;

  // and we print the distance
  Serial.println("---------- DISTANCE ------------");
  Serial.print("Distance capteur 1 (cm) :");
  Serial.println(distanceSensor1);
  Serial.print("Distance capteur 1 (m) :");

  
  distanceSensor1EnM = distanceSensor1 * 0.01;
  Serial.println(distanceSensor1EnM);

  // calcul du volume
  volumeComputed = compute_volume(distanceSensor1EnM, hauteurMax, Surface_a_la_base);
  
  // and we print the volume
  Serial.println("---------- VOLUME ------------");
  Serial.print("Volume en m3 :");
  Serial.println(volumeComputed);

  delay(3000);

}



float compute_volume(float distanceSensorEnM, float hauteurMax, float SurfaceDeBase){

  float volume = SurfaceDeBase * (hauteurMax - distanceSensorEnM);
  return volume;

}