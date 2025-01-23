# getOpenWeather.py - To get the weather forecast of a city given using command line arguments.
# Usage: python getOpenWeather.py <city name>, <country code>
import requests, json, pyinputplus, sys
api_key = "060f2e1a403f84f602b153b871d61e3c"    # Enter your OpenWeatherMap API key here
if api_key == "":  
    api_key = str(pyinputplus.inputPassword("Enter your OpenWeatherMap API key: ", limit = 3))

if len(sys.argv) < 2: print("Usage: python getOpenWeather.py <city name>, <country code>"); exit()
location = str("".join(sys.argv[1: ]))
location = location[: -2] + "," + location[-2: ]
# Download the JSON data from OpenWeatherMap.org's API
try:
    url = f"https://api.openweathermap.org/data/2.5/forecast?cnt=3&q={location}&appid={api_key}"
    response = requests.get(url)
    response.raise_for_status()
    weatherData = json.loads(response.text)
    w = weatherData["list"]
    print(f"Current weather in {location}: ")
    print(w[0]["weather"][0]["main"], "-", w[0]["weather"][0]["description"])
    print(f"Tomorrow: ")
    print(w[1]["weather"][0]["main"], "-", w[1]["weather"][0]["description"])
    print(f"Day after tomorrow: ")
    print(w[2]["weather"][0]["main"], "-", w[2]["weather"][0]["description"])
except requests.exceptions.RequestException as e: print(f"An error occurred: {e}")