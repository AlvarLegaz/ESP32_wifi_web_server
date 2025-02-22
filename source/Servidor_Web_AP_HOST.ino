#include <WiFi.h>
#include <MyWebServer.h>

#define SERIAL_SPEED 115200
#define SERVER_PORT 80

const char *ssid_apmode = "ESP32-AP";
const char *password_apmode= "12345678";

const char *ssid = "ESP32-AP";
const char *password= "12345678";

const int outPin = 4; // Pin GPIO de salida.

MyWebServer server(SERVER_PORT);

void setup() {

  pinMode(outPin, OUTPUT);

  Serial.begin(SERIAL_SPEED);

  if(true){
    WiFi.softAP(ssid_apmode, password_apmode);
    Serial.println("AP iniciado");
    Serial.print("Dirección IP: ");
    Serial.println(WiFi.softAPIP());
  }
  else{
    // Conéctate a la red WiFi
    WiFi.begin(ssid, password);
    Serial.print("Conectando a ");
    Serial.println(ssid);
    // Espera hasta que el ESP32 se conecte a la red WiFi
    while (WiFi.status() != WL_CONNECTED) {
      delay(1000);
      Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi conectado");
    Serial.print("Dirección IP: ");
    Serial.println(WiFi.localIP());
  }

  server.initEndpoints();
  Serial.println("HTTP server started");
}


void loop() {
  // Maneja las solicitudes del servidor
  server.handleClient();
}
