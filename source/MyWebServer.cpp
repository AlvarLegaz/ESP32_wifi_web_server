#include "MyWebServer.h"

// Constructor que acepta el puerto
MyWebServer::MyWebServer(int port) : server(port) {
}

void MyWebServer::initEndpoints() {

  server.on("/", [this]() { handleIndex(); });

  server.on("/health", [this]() { handleHealth(); });
  
  server.on("/output_on", [this]() { handleOutput(1); });

  server.on("/output_off", [this]() { handleOutput(0); });

  server.on("/config", HTTP_GET, [this]() { handleConfig(); });

  server.on("/config", HTTP_POST, [this]() {
    String ssid = server.arg("ssid");
    String password = server.arg("password");
    server.send(200, "text/html", "<html><body><h1>Configuración Guardada. Reinicie el dispositivo.</h1></body></html>");
    // Guardar ssid y password en memoria
    // (E.g., en la memoria EEPROM, o en la flash)
  });

  server.begin();
}

void MyWebServer::handleClient() {
  server.handleClient();
}

void MyWebServer::stop() {
  server.stop();
}

void MyWebServer::handleHealth() {
  server.send(200, "text/html", "<html><body><h1>ESP32 is healthy!</h1></body></html>");
}

void MyWebServer::handleIndex() {
  server.send(200, "text/html", "<html><body><h1>¡Bienvenido al servidor ESP32!</h1></body></html>");
}

void MyWebServer::handleConfig() {
  server.send(200, "text/html", R"rawliteral(
    <html>
    <body>
      <form action="/config" method="post">
        <label for="ssid">SSID:</label><br>
        <input type="text" id="ssid" name="ssid"><br>
        <label for="password">Password:</label><br>
        <input type="text" id="password" name="password"><br><br>
        <input type="submit" value="Submit">
      </form>
    </body>
    </html>
  )rawliteral");
}

void MyWebServer::handleOutput(int val) {
  const int outPin = 4; // Pin GPIO de salida

  if (val == 1) {
    digitalWrite(outPin, HIGH);
    server.send(200, "text/html", "<html><body><h1>Output On</h1></body></html>");
  } else {
    digitalWrite(outPin, LOW);
    server.send(200, "text/html", "<html><body><h1>Output Off</h1></body></html>");
  }
}
   