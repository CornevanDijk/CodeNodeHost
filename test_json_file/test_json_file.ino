// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2018
// MIT License

#include <ArduinoJson.h>
#include <SoftwareSerial.h>

#define rxPin 2
#define txPin 3

SoftwareSerial mySerial =  SoftwareSerial(rxPin, txPin);

//char json[] = "{\"sensor\":\"gps\",\"time\":1351824120,\"data\":[48.756080,2.302038]}";

void setup() {
  // Initialize serial port
  Serial.begin(9600);
}


void loop() {
  // not used in this example
  while (!Serial.available())
  {
    delay(500);
  }

  tests();

}

void tests() {
  // Memory pool for JSON object tree.
  //
  // Inside the brackets, 200 is the size of the pool in bytes.
  // Don't forget to change this value to match your JSON document.
  // Use arduinojson.org/assistant to compute the capacity.
  StaticJsonDocument<200> doc;

  // StaticJsonBuffer allocates memory on the stack, it can be
  // replaced by DynamicJsonBuffer which allocates in the heap.
  //
  // DynamicJsonBuffer  jsonBuffer(200);

  // JSON input string.
  //
  // It's better to use a char[] as shown here.
  // If you use a const char* or a String, ArduinoJson will
  // have to make a copy of the input in the JsonBuffer.
  //char json[] = Wire.read();

  // Root of the object tree.
  //
  // It's a reference to the JsonObject, the actual bytes are inside the
  // JsonBuffer with all the other nodes of the object tree.
  // Memory is freed when jsonBuffer goes out of scope.
  DeserializationError error = deserializeJson(doc, Serial);
  //DeserializationError error2 = deserializeJson(doc, json2);

  // Test if parsing succeeds.
  if (error ) {
    Serial.print("deserializeJson() failed whit code");
    Serial.println(error.c_str());
    return;
  }

  // Fetch values.
  //
  // Most of the time, you can rely on the implicit casts.
  // In other case, you can do root["time"].as<long>();
  int SensNr = doc["SensNr"];
  int InstNr = doc["InstNr"];
  int BRet = doc["BRet"];
  //int[] Data = doc["Data"];

  // Print values.
  Serial.println(SensNr);
  Serial.println(InstNr);
  Serial.println(BRet);
  //Serial.println(longitude, 6);
}
