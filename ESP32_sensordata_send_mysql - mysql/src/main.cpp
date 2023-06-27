#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>
#include <DHT.h>
#include <Update.h>
#include <WebServer.h>
#include <DNSServer.h>
#include "device_config.h"
#include <ArduinoJson.h>

#include <WiFi.h>
#include <PubSubClient.h>

// Replace with your network credentials
const char* ssid = "mFi_03A4B8";
const char* password = "Shani19951";

// Replace with your GCP project ID and MQTT broker details
const char* projectID = "artful-guru-390609";
const char* mqttServer = "mqtt.googleapis.com";
const int mqttPort = 8883;
const char* mqttUsername = "tushariakalanka@artful-guru-390609.iam.gserviceaccount.com";
const char* mqttPassword = "-----BEGIN PRIVATE KEY-----\nMIIEvQIBADANBgkqhkiG9w0BAQEFAASCBKcwggSjAgEAAoIBAQC9WkUFsR2wOfWq\nIXlACvmvrEn0aOfFiTX/PHMudD9PoJTsF608iUCP+IBtfX4hiAykcb0hFXMzVd53\nA7qG36lRF1jUcRbEJgfdlIRMhPkHTb1AfEgbcXo9RTWupa0ITDiQwOQqWPhYayyd\nEea3OzIU6w94sfifcTrUHdYUYa4RcMXZV/uy/9ih+UUGU6kMzZxZa1BsRLbP6zvm\nFBfGGBzoS2MZhuOrazTE3Q0g+UDT/rQ+nAel9bsmHvFGOmXQ0764/ZzDqENenbsn\nfnVU6u3Tz8KSzSRKPj7G0uKxVYTYjDK2n0GuIGXxc1Lo4W9vx692xp5Q+jrdC0il\nK+u3zAK/AgMBAAECggEALUgflndfMqwBqEBeByc4w76PZwAJYS9pdtLFdrf9BfVQ\nd89HseDezC8wwz5OAgXPhCnhAT7ocD/aNhrxqdxl2MsdBpzOxXSUz/P62XO5O/pm\nxjuSYOG3ylw5NL1RDllv84n1Zn0lUru6jQthYbMpzF/UMNharQJ+f4htEC2121xz\n3iXWgHVZreF6+lfJDMvhC1F84KoqZm2FiqiDYfmzr6YGK14n5lKDxP0F3MIiW63o\nZpjpGRKgtJWNga8h0j9fFDTGJYpRMmpz2gTTelkaX1Vl3JDwqTr4D69RCNrnsYTb\nQNEzwHayJ8J6Yi6uipQaWYytM7y8RwdiRvYpheUkuQKBgQDcuVVbTfvp5Ikmn29Q\nQAtfcpkHpoI3t35All2g0zoiwco9lGO7owzHhX/J7gEj8mxqbohY2exZEx62jZbE\ntY5SIe+Oh/Sxg8vYDRdwWPrPhTc2B1nb3//hpzk8gnCUV22E4U58xv+1bbUIU6oe\n/yZxducsAapG7kfQkBOMTI4jZwKBgQDbnWnwVpQGE/dvTPcPQuPOvVb/Y1Hzp+AM\nqeblMpHU++rbdCkfSTe0Zl2udDd/D89DXFOe0oJwx6NgFQpQqW8apcZI7wdUEPlU\nh38hBwDO+N5slDmgiTg1iN5t8wvWwz+lPRJtkY2MPJz9zxAmI08SzQPzHZ24bjWq\nZyKr+h+m6QKBgQCVDDW+fS+yZpfS0/DX8Rd88aayyta+BxOjS6aX9msYk2IdKTob\nt+PmS5jaY/SzMH3TdSZvUWFPWSDxRzVbSfp8LdxVlCtBP+2DzHtaa0uanKuGuXoN\nhvqEh2aYHMEm+s7C314f1kVQX2/S2qRTYBq2ngNG7SztzvQBu3jn0b5d2wKBgDal\n8RqxMJxik4vKpx/REUb8ro1Wdaof+AyuqpoV/1v0Y/i/6wux+H6XinBC0xx3Hqgw\nbU50K6lMxEbAdZSk1NTYs4KqmDQ/FQwHu4bIa1cVbqOuLrjX7HjF2jOZ6zRB2bCQ\nhell8scWvioaQHZ9Cswu3/C7Sef+5LPGfkY1M3MhAoGAAsaOx5WKRLdxZ7iczTNF\npnb//g9WQub5WbJSG+BRjUu1jNWkgzVim4YgN/WV8OWPhuMWeQXRLnCKP6OE3HJg\nRtmC1kvWAXxQWYPEjkL/pSb6o/WxYx7QLnwIIrtW63430fYky4YYbyFIWKnONPHe\nWnCcAexZvpkusg4eE90pEFM=\n-----END PRIVATE KEY-----\n";

// Replace with your LED pin
const int ledPin = 12;

WiFiClientSecure wifiClient;
PubSubClient mqttClient(wifiClient);

// Function to handle incoming MQTT messages
void messageReceived(char* topic, byte* payload, unsigned int length) {
  // Process the received message here
  // You can add your logic to control the LED based on the message
}

// Function to connect to MQTT broker
void connectToMQTTBroker() {
  while (!mqttClient.connected()) {
    Serial.println("Connecting to MQTT broker...");
    if (mqttClient.connect("ESP32Client", mqttUsername, mqttPassword)) {
      Serial.println("Connected to MQTT broker!");
      mqttClient.subscribe("led_control_topic");
    } else {
      Serial.print("MQTT connection failed. Error code = ");
      Serial.println(mqttClient.state());
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi!");

  mqttClient.setServer(mqttServer, mqttPort);
  mqttClient.setCallback(messageReceived);

  connectToMQTTBroker();
}

void loop() {
  if (!mqttClient.connected()) {
    connectToMQTTBroker();
  }
  mqttClient.loop();
}

