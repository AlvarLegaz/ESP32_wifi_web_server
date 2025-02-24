const char* health_response = "<!DOCTYPE HTML><html><h1>ESP32 is healthy</h1></html>";
const char* index_response = "<!DOCTYPE HTML><html><h1>Hola desde servidor web</h1></html>";
const char* app_response = R"rawliteral(
    <html>
    <head>
      <style>
        body {
          font-family: Arial, sans-serif;
          display: flex;
          justify-content: center;
          align-items: center;
          height: 100vh;
          background-color: #f0f0f0;
        }
        .container {
          text-align: center;
          background: #fff;
          padding: 20px;
          border-radius: 10px;
          box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
        }
	button {
            background-color: #4CAF50; /* Verde */
            border: none;
            color: white;
            padding: 15px 32px;
            text-align: center;
            text-decoration: none;
            display: inline-block;
            font-size: 16px;
            margin: 4px 2px;
            cursor: pointer;
            border-radius: 12px;
            box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
            transition: background-color 0.3s ease;
        }

        button:hover {
            background-color: #45a049; /* Verde más oscuro */
        }
      </style>
    </head>
    <body>
      <div class="container">
        <h1>Control de Salida</h1>
        <button onclick="hacerSolicitudGETEncender()">Encender</button>
        <button onclick="hacerSolicitudGETApagar()">Apagar</button>
      </div>
    
      <script>
        function hacerSolicitudGETEncender() {
            fetch('/output_on')
                .then(response => {
                    if (response.status === 200) {
                        document.getElementById('resultado').innerText = "La solicitud fue exitosa (código 200)";
                    } else {
                        document.getElementById('resultado').innerText = `Error: Código de estado ${response.status}`;
                    }
                })
                .catch(error => {
                    console.error('Error:', error);
                    document.getElementById('resultado').innerText = "Ocurrió un error durante la solicitud.";
                });
        }
	function hacerSolicitudGETApagar() {
            fetch('/output_off')
                .then(response => {
                    if (response.status === 200) {
                        document.getElementById('resultado').innerText = "La solicitud fue exitosa (código 200)";
                    } else {
                        document.getElementById('resultado').innerText = `Error: Código de estado ${response.status}`;
                    }
                })
                .catch(error => {
                    console.error('Error:', error);
                    document.getElementById('resultado').innerText = "Ocurrió un error durante la solicitud.";
                });
        }
       </script>
    
    </body>
    </html>
  )rawliteral";