#ifndef MYWEBSERVER_H_
#define MYWEBSERVER_H_

#include <WebServer.h>

class MyWebServer {
public:
  // Constructor que acepta el puerto como argumento
  MyWebServer(int port);
  
  // Métodos públicos
  void initEndpoints();
  void handleClient();
  void stop();

private:
  // Atributos privados
  WebServer server;

  // Métodos privados
  void handleHealth();
  void handleIndex();
  void handleOutput(int val);
  void handleConfig();
  void handleApp();
};
#endif // MYWEBSERVER_H_