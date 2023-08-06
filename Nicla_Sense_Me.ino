#include "Arduino.h"
#include "Arduino_BHY2.h"

//SensorXYZ accel(SENSOR_ID_ACC);
//SensorXYZ gyro(SENSOR_ID_GYRO);
Sensor temp(SENSOR_ID_TEMP);
Sensor gas(SENSOR_ID_GAS);
Sensor press(SENSOR_ID_BARO);
Sensor hum(SENSOR_ID_HUM);
//SensorQuaternion rotation(SENSOR_ID_RV);

float temperature, gas_pph, pressure, humidity;

void setup()
{
  Serial.begin(115200);
  while(!Serial);

  BHY2.begin();

  //accel.begin();
  //gyro.begin();
  temp.begin();
  gas.begin();
  press.begin();
  hum.begin();
  //rotation.begin();
}

void loop()
{
  static auto printTime = millis();

  // Update function should be continuously polled
  BHY2.update();

  if (millis() - printTime >= 1000) {
    printTime = millis();
    temperature = temp.value();   //Temperature: -40 - +85°C
    gas_pph = gas.value();        //bVOC - CO2 - equivalents (ppm)
    pressure = press.value();     //Pressure: 300-1100 hPa
    humidity = hum.value();       //Humidity: 0-100%


    Serial.println(String("Temperature = ")+String(temperature) + String(" C"));
    Serial.println(String("Gas Value = ")+String(gas_pph) + String(" ppm"));
    Serial.println(String("Pressure = ")+String(pressure) + String(" hPa"));
    Serial.println(String("Humidity = ")+String(humidity) + String("%"));
    

    /*Serial.println(String("acceleration: ") + accel.toString());
    Serial.println(String("gyroscope: ") + gyro.toString());
    Serial.println(String("temperature: ") + String(temp.value(),3));
    Serial.println(String("gas: ") + String(gas.value(),3));
    Serial.println(String("rotation: ") + rotation.toString());*/
  }
}
