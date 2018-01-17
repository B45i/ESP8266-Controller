#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char *ssid     = "ESP8266 Controller";
const char *password = "helloworld";

int pin1 = D1;
int pin2 = D2;


ESP8266WebServer server(80);

void handleRoot() {
	server.send(200, "text/html",
		"<!DOCTYPE html>\n"
		"<html>\n"
		"\t<head>\n"
		"\t\t<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"> \n"
		"\t\t<title>Welcome | ESP8266 Controller</title>\n"
		"\t\t<style>\n"
		"\t\t\tbody{\n"
		"\t\t\t\tbackground: rgb(39, 55, 70);\n"
		"\t\t\t\tfont-family: helvetica;\n"
		"\t\t\t\tfont-weight: 400;\n"
		"\t\t\t\tfont-size: 15px;\n"
		"\t\t\t\tcolor: #333;\n"
		"\t\t\t\t-webkit-font-smoothing: antialiased;\n"
		"\t\t\t\toverflow-y: scroll;\n"
		"\t\t\t\toverflow-x: hidden;\n"
		"\t\t\t}\n"
		"\t\t\ta{\n"
		"\t\t\t\tcolor: #555;\n"
		"\t\t\t\ttext-decoration: none;\n"
		"\t\t\t}\n"
		"\t\t\t.container{\n"
		"\t\t\t\twidth: 100%;\n"
		"\t\t\t\tposition: relative;\n"
		"\t\t\t}\n"
		"\t\t\t.clr{\n"
		"\t\t\t\tclear: both;\n"
		"\t\t\t\tpadding: 0;\n"
		"\t\t\t\theight: 0;\n"
		"\t\t\t\tmargin: 0;\n"
		"\t\t\t}\n"
		"\t\t\t.main{\n"
		"\t\t\t\twidth: 90%;\n"
		"\t\t\t\tmargin: 0 auto;\n"
		"\t\t\t\tposition: relative;\n"
		"\t\t\t}\n"
		"\t\t\t.container > header{\n"
		"\t\t\t\tmargin: 10px;\n"
		"\t\t\t\tpadding: 20px 10px 10px 10px;\n"
		"\t\t\t\tposition: relative;\n"
		"\t\t\t\tdisplay: block;\n"
		"\t\t\t\ttext-align: center;\n"
		"\t\t\t}\n"
		"\t\t\t.container > header h1{\n"
		"\t\t\t\tfont-size: 36px;\n"
		"\t\t\t\tline-height: 36px;\n"
		"\t\t\t\tmargin: 0;\n"
		"\t\t\t\tposition: relative;\n"
		"\t\t\t\tfont-weight: 300;\n"
		"\t\t\t\tcolor: rgb(255, 255, 255);\n"
		"\t\t\t}\n"
		"\n"
		"\t\t\t.switch {\n"
		"\t\t\t\tmargin: 50px auto;\n"
		"\t\t\t\tposition: relative;\n"
		"\t\t\t}\n"
		"\n"
		"\t\t\t.switch label {\n"
		"\t\t\t\twidth: 100%;\n"
		"\t\t\t\theight: 100%;\n"
		"\t\t\t\tposition: relative;\n"
		"\t\t\t\tdisplay: block;\n"
		"\t\t\t}\n"
		"\n"
		"\t\t\t.switch input {\n"
		"\t\t\t\ttop: 0; \n"
		"\t\t\t\tright: 0; \n"
		"\t\t\t\tbottom: 0; \n"
		"\t\t\t\tleft: 0;\n"
		"\t\t\t\topacity: 0;\n"
		"\t\t\t\tz-index: 100;\n"
		"\t\t\t\tposition: absolute;\n"
		"\t\t\t\twidth: 100%;\n"
		"\t\t\t\theight: 100%;\n"
		"\t\t\t\tcursor: pointer;\n"
		"\t\t\t}\n"
		"\n"
		"\t\t\t.switch.btn-oval {\n"
		"\t\t\t\twidth: 180px;\n"
		"\t\t\t\theight: 50px;\n"
		"\t\t\t}\n"
		"\n"
		"\t\t\t.switch.btn-oval label {\n"
		"\t\t\t\tdisplay: block;\n"
		"\t\t\t\twidth: 100%;\n"
		"\t\t\t\theight: 100%;\n"
		"\t\t\t\tbackground: #a5a39d;\n"
		"\t\t\t\tborder-radius: 40px;\n"
		"\t\t\t\tbox-shadow:\n"
		"\t\t\t\t\t\tinset 0 3px 8px 1px rgba(0,0,0,0.2),\n"
		"\t\t\t\t\t\t0 1px 0 rgba(255,255,255,0.5);\n"
		"\t\t\t}\n"
		"\n"
		"\t\t\t.switch.btn-oval label:after {\n"
		"\t\t\t\tcontent: \"\";\n"
		"\t\t\t\tposition: absolute;\n"
		"\t\t\t\tz-index: -1;\n"
		"\t\t\t\ttop: -8px; right: -8px; bottom: -8px; left: -8px;\n"
		"\t\t\t\tborder-radius: inherit;\n"
		"\t\t\t\tbackground: #ababab;\n"
		"\t\t\t\tbackground: -moz-linear-gradient(#f2f2f2, #ababab);\n"
		"\t\t\t\tbackground: -ms-linear-gradient(#f2f2f2, #ababab);\n"
		"\t\t\t\tbackground: -o-linear-gradient(#f2f2f2, #ababab);\n"
		"\t\t\t\tbackground: -webkit-gradient(linear, 0 0, 0 100%, from(#f2f2f2), to(#ababab));\n"
		"\t\t\t\tbackground: -webkit-linear-gradient(#f2f2f2, #ababab);\n"
		"\t\t\t\tbackground: linear-gradient(#f2f2f2, #ababab);\n"
		"\t\t\t\tbox-shadow: 0 0 10px rgba(0,0,0,0.3),\n"
		"\t\t\t\t\t\t\t0 1px 1px rgba(0,0,0,0.25);\n"
		"\t\t\t}\n"
		"\n"
		"\t\t\t.switch.btn-oval label:before {\n"
		"\t\t\t\tcontent: \"\";\n"
		"\t\t\t\tposition: absolute;\n"
		"\t\t\t\tz-index: -1;\n"
		"\t\t\t\ttop: -18px; right: -18px; bottom: -18px; left: -18px;\n"
		"\t\t\t\tborder-radius: inherit;\n"
		"\t\t\t\tbackground: #eee;\n"
		"\t\t\t\tbackground: -moz-linear-gradient(#e5e7e6, #eee);\n"
		"\t\t\t\tbackground: -ms-linear-gradient(#e5e7e6, #eee);\n"
		"\t\t\t\tbackground: -o-linear-gradient(#e5e7e6, #eee);\n"
		"\t\t\t\tbackground: -webkit-gradient(linear, 0 0, 0 100%, from(#e5e7e6), to(#eee));\n"
		"\t\t\t\tbackground: -webkit-linear-gradient(#e5e7e6, #eee);\n"
		"\t\t\t\tbackground: linear-gradient(#e5e7e6, #eee);\n"
		"\t\t\t\tbox-shadow:\n"
		"\t\t\t\t\t\t0 1px 0 rgba(255,255,255,0.5);\n"
		"\t\t\t\t-webkit-filter: blur(1px);\n"
		"\t\t\t\t-moz-filter: blur(1px);\n"
		"\t\t\t\t-ms-filter: blur(1px);\n"
		"\t\t\t\t-o-filter: blur(1px);\n"
		"\t\t\t\tfilter: blur(1px);\n"
		"\t\t\t}\n"
		"\n"
		"\t\t\t.switch.btn-oval label i {\n"
		"\t\t\t\tdisplay: block;\n"
		"\t\t\t\theight: 100%;\n"
		"\t\t\t\twidth: 60%;\n"
		"\t\t\t\tborder-radius: inherit;\n"
		"\t\t\t\tbackground: silver;\n"
		"\t\t\t\tposition: absolute;\n"
		"\t\t\t\tz-index: 2;\n"
		"\t\t\t\tright: 40%;\n"
		"\t\t\t\ttop: 0;\n"
		"\t\t\t\tbackground: #b2ac9e;\n"
		"\t\t\t\tbackground: -moz-linear-gradient(#f7f2f6, #b2ac9e);\n"
		"\t\t\t\tbackground: -ms-linear-gradient(#f7f2f6, #b2ac9e);\n"
		"\t\t\t\tbackground: -o-linear-gradient(#f7f2f6, #b2ac9e);\n"
		"\t\t\t\tbackground: -webkit-gradient(linear, 0 0, 0 100%, from(#f7f2f6), to(#b2ac9e));\n"
		"\t\t\t\tbackground: -webkit-linear-gradient(#f7f2f6, #b2ac9e);\n"
		"\t\t\t\tbackground: linear-gradient(#f7f2f6, #b2ac9e);\n"
		"\t\t\t\tbox-shadow:\n"
		"\t\t\t\t\t\tinset 0 1px 0 white,\n"
		"\t\t\t\t\t\t0 0 8px rgba(0,0,0,0.3),\n"
		"\t\t\t\t\t\t0 5px 5px rgba(0,0,0,0.2);\n"
		"\t\t\t}\n"
		"\n"
		"\t\t\t.switch.btn-oval label i:after {\n"
		"\t\t\t\tcontent: \"\";\n"
		"\t\t\t\tposition: absolute;\n"
		"\t\t\t\tleft: 15%;\n"
		"\t\t\t\ttop: 25%;\n"
		"\t\t\t\twidth: 70%;\n"
		"\t\t\t\theight: 50%;\n"
		"\t\t\t\tbackground: #d2cbc3;\n"
		"\t\t\t\tbackground: -moz-linear-gradient(#cbc7bc, #d2cbc3);\n"
		"\t\t\t\tbackground: -ms-linear-gradient(#cbc7bc, #d2cbc3);\n"
		"\t\t\t\tbackground: -o-linear-gradient(#cbc7bc, #d2cbc3);\n"
		"\t\t\t\tbackground: -webkit-gradient(linear, 0 0, 0 100%, from(#cbc7bc), to(#d2cbc3));\n"
		"\t\t\t\tbackground: -webkit-linear-gradient(#cbc7bc, #d2cbc3);\n"
		"\t\t\t\tbackground: linear-gradient(#cbc7bc, #d2cbc3);\n"
		"\t\t\t\tborder-radius: inherit;\n"
		"\t\t\t}\n"
		"\n"
		"\t\t\t.switch.btn-oval label i:before {\n"
		"\t\t\t\tcontent: \"off\";\n"
		"\t\t\t\ttext-transform: uppercase;\n"
		"\t\t\t\tfont-style: normal;\n"
		"\t\t\t\tfont-weight: bold;\n"
		"\t\t\t\tcolor: rgba(0,0,0,0.4);\n"
		"\t\t\t\ttext-shadow: 0 1px 0 #bcb8ae, 0 -1px 0 #97958e;\n"
		"\t\t\t\tfont-family: Helvetica, Arial, sans-serif;\n"
		"\t\t\t\tfont-size: 24px;\n"
		"\t\t\t\tposition: absolute;\n"
		"\t\t\t\ttop: 50%;\n"
		"\t\t\t\tmargin-top: -12px;\n"
		"\t\t\t\tright: -50%;\n"
		"\t\t\t}\n"
		"\n"
		"\t\t\t.switch.btn-oval input:checked ~ label {\n"
		"\t\t\t\tbackground: #9abb82;\n"
		"\t\t\t}\n"
		"\n"
		"\t\t\t.switch.btn-oval input:checked ~ label i {\n"
		"\t\t\t\tright: -1%;\n"
		"\t\t\t}\n"
		"\n"
		"\t\t\t.switch.btn-oval input:checked ~ label i:before {\n"
		"\t\t\t\tcontent: \"on\";\n"
		"\t\t\t\tright: 115%;\n"
		"\t\t\t\tcolor: #82a06a;\n"
		"\t\t\t\ttext-shadow: \n"
		"\t\t\t\t\t0 1px 0 #afcb9b,\n"
		"\t\t\t\t\t0 -1px 0 #6b8659;\n"
		"\t\t\t}\n"
		"\n"
		"\t\t</style>\n"
		"\t</head>\n"
		"\t<body>\n"
		"\t\t<div class=\"container\">\n"
		"\t\t\t<header>\n"
		"\t\t\t\t<h1>ESP8266 Controller</h1>\n"
		"\t\t\t</header>\n"
		"\t\t\t<section class=\"main\">\n"
		"\t\t\t\t<div class=\"switch btn-oval\">\n"
		"\t\t\t\t\t<input type=\"checkbox\" name=\"pinOne\" onclick=\"handleClick(this)\";>\n"
		"\t\t\t\t\t<label><i></i></label>\n"
		"\t\t\t\t</div>\n"
		"\t\t\t\t<div class=\"switch btn-oval\">\n"
		"\t\t\t\t\t<input type=\"checkbox\" name=\"pinTwo\" onclick=\"handleClick(this)\">\n"
		"\t\t\t\t\t<label><i></i></label>\n"
		"\t\t\t\t</div>\n"
		"\t\t\t</section>\n"
		"\t\t</div>\n"
		"\t\t<script>\n"
		"\t\t\tfunction handleClick(cb) {\n"
		"\t\t\t\tif(cb.checked) {\n"
		"\t\t\t\t\tthis.path = cb.name + \"On\";\n"
		"\t\t\t\t}\n"
		"\t\t\t\telse{\n"
		"\t\t\t\t\tthis.path = cb.name + \"Off\";\n"
		"\t\t\t\t}\n"
		"\t\t\t\txhttp = new XMLHttpRequest();\n"
		"\t\t\t\txhttp.open(\"GET\", path, true);\n"
		"\t\t\t\txhttp.send();\n"
		"\t\t\t}\n"
		"\t\t</script>\n"
		"\t</body>\n"
		"</html>"
	);
}

void handelePinOneOn() {
	digitalWrite(pin1, HIGH);
	server.send(200, "text/html", "Pin one turned on");
}

void handelePinOneOff() {
	digitalWrite(pin1, LOW);
	server.send(200, "text/html", "Pin one turned off");
}

void handelePinTwoOn() {
	digitalWrite(pin2, HIGH);
	server.send(200, "text/html", "Pin two turned on");
}

void handelePinTwoOff() {
	digitalWrite(pin2, LOW);
	server.send(200, "text/html", "Pin two turned off");
}

void setup() {
	delay(1000);

	pinMode(pin1, OUTPUT);
	pinMode(pin2, OUTPUT);

	Serial.begin(115200);
	Serial.println();
	Serial.print("Configuring access point...");
	/* uncomment the passeord to make the AP closed */
	//WiFi.softAP(ssid, password);
	WiFi.softAP(ssid);

	IPAddress myIP = WiFi.softAPIP();
	Serial.print("AP IP address: ");
	Serial.println(myIP);

	server.on("/", handleRoot);
	server.on("/pinOneOn", handelePinOneOn);
	server.on("/pinOneOff", handelePinOneOff);
	server.on("/pinTwoOn", handelePinTwoOn);
	server.on("/pinTWoOff", handelePinTwoOff);

	server.begin();
	Serial.println("HTTP server started");
}

void loop() {
	server.handleClient();
}
