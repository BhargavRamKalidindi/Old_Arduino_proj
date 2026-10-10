#include <DHT.h>

#define DHTPIN 11
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
	Serial.begin(9600);
	dht.begin();
}

void loop()
{
		float humidity = dht.readHumidity();
		float temperatureC = dht.readTemperature(true);
		float temperatureF = dht.readTemperature(true);
		float temperatureK = temperatureC + 273.15;
		if (isnan(humidity)||isnan(temperatureC)){
			Serial.println("Error reading data!");
			return;
		}
		Serial.print("Temperature: ");
		Serial.print(temperatureC);
		Serial.print("°C, ");
		Serial.print(temperatureF);
		Serial.print("°F, ");
		Serial.print(temperatureK);
		Serial.println("K");

		Serial.print("Humidity: ");
		Serial.print(humidity);
		Serial.println("%");
		Serial.println();
		delay(2000); // Delay between readings
}