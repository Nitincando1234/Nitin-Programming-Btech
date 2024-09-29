#include <iostream>
#include <string>
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
using namespace std;
using namespace http;
using namespace web;
using namespace web::http::client;
int main()
{
    cout << "\t+o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o+" << endl;
    cout << "\t\tWeather App (ver: 0.0.0001\1)\n";
    cout << "\t+o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o+" << endl;
    cout << "Enter your city: ";
    string city;
    getline(city, cin);
    http_client client(U("https://api.openweathermap.org/data/2.5"));
    uri_builder builder(U("/weather"));
    builder.append_query(U("q"), utility::conversions::to_string_t(city));
    builder.append_query(U("appid"), U("dd26e4b52941c1a129649325f59e162f"));
    http_request request(methods::GET);
    request.set_request_uri(builder.to_string());
    client.request(request).then([](http_response response){
        return response.extract_json();
    }).then([](web::json::value body) {
        cout << "Temperature: " << body[U("main")][U("temp")].as_double() << endl;
        cout << "Humidity: " << body[U("main")][U("humidity")].as_double() << "\n";
        cout << "Weather: " << utility::conversions::to_utf8string(body["weather"][0]["main"]) << "\n";

    }).wait();
    return 0;
}   

