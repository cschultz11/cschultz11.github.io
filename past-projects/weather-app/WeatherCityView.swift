//WeatherCityView.swift
//WeatherCities
//Created by Christopher Schultz

import SwiftUI

struct WeatherCityView: View {

	@State var cityCode:String
	
	@State private var title:String = ""
	@State private var cityPicture:String = ""
	@State private var xmlWeatherTagData:String = ""
	@State private var weatherPicture:String = ""
	@State private var xmlData:String = ""
	
	var body: some View {
	
		VStack {
		
			Text(title)
				.fontWeight(.medium)
			
			Image(cityPicture)
				.resizable()
				
			Text(xmlWeatherTagData)
			
			Image(weatherPicture)
				.resizable()
				
		}
		.task {	
			await fetchWeatherData(cityCode: cityCode)
		}
	} //end body
	
	func fetchWeatherData(cityCode: String) async {
		//create URL
		
		let urlString = "http://w1.weather.gov/xml/current_obs/" + cityCode + ".xml"
		
		guard let url = URL(string: urlString)
		
		else {
			print("Hey Man, THIS URL DOES NOT WORK")
			return
		}
		
		//Perform HTTP Request
		let task = URLSession.shared.dataTask(with: url) { (data, response, error) in
		
			//Check for Error
			if let error = error {
				print("Error took place \(error)")
			}
			
			//variables to use
			var tempString = ""
			var weatherTagData = ""
			
			//Convert HTTP Response Data to a String
			if let data = data, let dataString = String(data: data, encoding: .utf8) {
			
				//get the <weather> tag data
				let tokens = dataString.components(separatedBy: "weather>")
				let arraySize = tokens.count
				if arraySize >= 2 {
				
					var counter = 1
					for xmlWeatherLine in tokens {
						if counter == 2 {
							tempString = xmlWeatherLine
						}
					counter = counter + 1
					}
					
					weatherTagData = tempString.replacingOccurrences(of: "</", with: "", options: .literal, range: nil)
				}
				
				if cityCode == "KBOS" {
					title = "BOSTON SKYLINE"
					cityPicture = "Boston"
					xmlWeatherTagData = weatherTagData
					weatherPicture = xmlWeatherTagData
					xmlData = dataString
				}
				
				else if cityCode == "KNYC" {
					title = "NEW YORK CITY SKYLINE"
					cityPicture = "nyc"
					xmlWeatherTagData = weatherTagData
					weatherPicture = xmlWeatherTagData
					xmlData = dataString
				}
				else if cityCode == "KMIA" {
					title = "MIAMI SKYLINE"
					cityPicture = "Miami"
					xmlWeatherTagData = weatherTagData
					weatherPicture = xmlWeatherTagData
					xmlData = dataString
				}
                else if cityCode == "KDAL" {
                    title = "DALLAS SKYLINE"
                    cityPicture = "dallas"
                    xmlWeatherTagData = weatherTagData
                    weatherPicture = xmlWeatherTagData
                    xmlData = dataString
                }
                else if cityCode == "KDEN" {
                    title = "DENVER SKYLINE"
                    cityPicture = "Denver"
                    xmlWeatherTagData = weatherTagData
                    weatherPicture = xmlWeatherTagData
                    xmlData = dataString
                }
                
                else if cityCode == "KLAX" {
                    title = "LOS ANGELES SKYLINE"
                    cityPicture = "la"
                    xmlWeatherTagData = weatherTagData
                    weatherPicture = xmlWeatherTagData
                    xmlData = dataString
                }
                else if cityCode == "KSEA" {
                    title = "SEATTLE SKYLINE"
                    cityPicture = "seattle"
                    xmlWeatherTagData = weatherTagData
                    weatherPicture = xmlWeatherTagData
                    xmlData = dataString
                }
                else if cityCode == "KDET" {
                    title = "DETROIT SKYLINE"
                    cityPicture = "Detroit"
                    xmlWeatherTagData = weatherTagData
                    weatherPicture = xmlWeatherTagData
                    xmlData = dataString
                }
                
                else if cityCode == "KORD" {
                    title = "CHICAGO SKYLINE"
                    cityPicture = "chicago"
                    xmlWeatherTagData = weatherTagData
                    weatherPicture = xmlWeatherTagData
                    xmlData = dataString
                }
                else if cityCode == "KFAR" {
                    title = "FARGO SKYLINE"
                    cityPicture = "fargo"
                    xmlWeatherTagData = weatherTagData
                    weatherPicture = xmlWeatherTagData
                    xmlData = dataString
                }
			} //end let data
			
		} //end let task
		task.resume()
		
	} //end func
}//end struct

struct WeatherCityView_Previews: PreviewProvider {
	
	@State static var cityCode: String = ""
	
	static var previews: some View {
		WeatherCityView(cityCode: cityCode)
	}

}
