#include <WiFi.h>

#define orange_led 25
#define green_led 26
#define Relay_1 27
#define Relay_2 14
#define Relay_3 12
#define Relay_4 13

const char* ssid = "Akotosinatoy";
const char* password = "dinosaur";

WiFiServer server(80);

void setup() {
  Serial.begin(115200);

  pinMode(orange_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(Relay_1, OUTPUT);
  pinMode(Relay_2, OUTPUT);
  pinMode(Relay_3, OUTPUT);
  pinMode(Relay_4, OUTPUT);

  delay(10);

  // Connect to Wi-Fi
  Serial.println();
  Serial.println("Connecting to Wi-Fi");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(orange_led, !digitalRead(orange_led));
    delay(500);
    Serial.print(".");
  }

  digitalWrite(orange_led, LOW);
  digitalWrite(green_led, HIGH);
  Serial.println("\nWiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {
  WiFiClient client = server.available(); // Listen for incoming clients

  if (client) {
    Serial.println("New Client.");
    String currentLine = "";

    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);

        if (c == '\n') {
          if (currentLine.length() == 0) {
            // Send the HTTP response
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // HTML Content
            client.println("<!DOCTYPE html>");
            client.println("<html>");
            client.println("<head>");
            client.println("<title>ESP32 Web Server</title>");
            client.println("<style>");
            client.println("body { font-family: Arial, sans-serif; margin: 0; padding: 0; background-color: #f4f4f9; }");
            client.println("h1 { text-align: center; color: #333; margin-top: 20px; }");
            client.println(".container { display: flex; flex-wrap: wrap; justify-content: center; margin: 20px auto; gap: 20px; }");
            client.println(".box { background: white; padding: 20px; box-shadow: 0 4px 8px rgba(0,0,0,0.2); border-radius: 8px; width: 200px; text-align: center; }");
            client.println(".button { display: inline-block; padding: 10px 20px; margin: 10px 5px; text-decoration: none; color: white; background-color: #007BFF; border: none; border-radius: 5px; cursor: pointer; }");
            client.println(".button:hover { background-color: #0056b3; }");
            client.println("</style>");
            client.println("</head>");
            client.println("<body>");
            client.println("<h1>ESP32 Web Server</h1>");
            client.println("<div class='container'>");

            // LED 1
            client.println("<div class='box'>");
            client.println("<h2>Relay 1</h2>");
            client.println("<a href=\"/1/on\" class=\"button\">Turn ON</a>");
            client.println("<a href=\"/1/off\" class=\"button\">Turn OFF</a>");
            client.println("</div>");

            // LED 2
            client.println("<div class='box'>");
            client.println("<h2>Relay 2</h2>");
            client.println("<a href=\"/2/on\" class=\"button\">Turn ON</a>");
            client.println("<a href=\"/2/off\" class=\"button\">Turn OFF</a>");
            client.println("</div>");

            // LED 3
            client.println("<div class='box'>");
            client.println("<h2>Relay 3</h2>");
            client.println("<a href=\"/3/on\" class=\"button\">Turn ON</a>");
            client.println("<a href=\"/3/off\" class=\"button\">Turn OFF</a>");
            client.println("</div>");

            // LED 4
            client.println("<div class='box'>");
            client.println("<h2>Relay 4</h2>");
            client.println("<a href=\"/4/on\" class=\"button\">Turn ON</a>");
            client.println("<a href=\"/4/off\" class=\"button\">Turn OFF</a>");
            client.println("</div>");

            client.println("</div>"); // Close container
            client.println("</body>");
            client.println("</html>");

            // End the HTTP response
            client.println();
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }

        // Handle requests for each LED
        if (currentLine.endsWith("GET /1/on")) digitalWrite(Relay_1, HIGH);
        if (currentLine.endsWith("GET /1/off")) digitalWrite(Relay_1, LOW);
        if (currentLine.endsWith("GET /2/on")) digitalWrite(Relay_2, HIGH);
        if (currentLine.endsWith("GET /2/off")) digitalWrite(Relay_2, LOW);
        if (currentLine.endsWith("GET /3/on")) digitalWrite(Relay_3, HIGH);
        if (currentLine.endsWith("GET /3/off")) digitalWrite(Relay_3, LOW);
        if (currentLine.endsWith("GET /4/on")) digitalWrite(Relay_4, HIGH);
        if (currentLine.endsWith("GET /4/off")) digitalWrite(Relay_4, LOW);
      }
    }
    client.stop();
    Serial.println("Client Disconnected.");
  }
}
