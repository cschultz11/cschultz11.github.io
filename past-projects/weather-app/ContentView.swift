//ContentView.Swift
//weatherCities
//Created by Christopher Schultz

import SwiftUI

struct ContentView: View {
	
	@State private var cityCode: String = ""
	
	var body: some View {
	
		NavigationView {
           
            ScrollView {
                
			VStack {
			
				//DIV--------------------------------------------------------------
				Button(action: {
					//add code here
				}, label: {
					NavigationLink(destination: WeatherCityView(cityCode: "KBOS")) {
						Text("BOSTON")
							.padding()
							.foregroundColor(Color.blue)
							.font(.largeTitle)
						}
					}) //end Button
					
					
				//DIV--------------------------------------------------------------
				Button(action: {
					//add code here
				}, label: {
					NavigationLink(destination: WeatherCityView(cityCode: "KNYC")) {
						Text("NEW YORK CITY")
							.padding()
							.foregroundColor(Color.blue)
							.font(.largeTitle)
						}
					}) //end Button
					
					
				//DIV--------------------------------------------------------------
				Button(action: {
					//add code here
				}, label: {
					NavigationLink(destination: WeatherCityView(cityCode: "KMIA")) {
						Text("MIAMI")
							.padding()
							.foregroundColor(Color.blue)
							.font(.largeTitle)
						}
					}) //end Button
					
				//DIV--------------------------------------------------------------
				Button(action: {
					//add code here
				}, label: {
					NavigationLink(destination: WeatherCityView(cityCode: "KDAL")) {
						Text("DALLAS")
							.padding()
							.foregroundColor(Color.blue)
							.font(.largeTitle)
						}
					}) //end Button
					
					
				//DIV--------------------------------------------------------------
				Button(action: {
					//add code here
				}, label: {
					NavigationLink(destination: WeatherCityView(cityCode: "KDEN")) {
						Text("DENVER")
							.padding()
							.foregroundColor(Color.blue)
							.font(.largeTitle)
						}
					}) //end Button
				} //end VStack1
				
				//NEW VSTACK ---------VSTACK 2 START----------
				
				VStack {
			
				//DIV--------------------------------------------------------------
				Button(action: {
					//add code here
				}, label: {
					NavigationLink(destination: WeatherCityView(cityCode: "KLAX")) {
						Text("LOS ANGELES")
							.padding()
							.foregroundColor(Color.blue)
							.font(.largeTitle)
						}
					}) //end Button
					
					
				//DIV--------------------------------------------------------------
				Button(action: {
					//add code here
				}, label: {
					NavigationLink(destination: WeatherCityView(cityCode: "KSEA")) {
						Text("SEATTLE")
							.padding()
							.foregroundColor(Color.blue)
							.font(.largeTitle)
						}
					}) //end Button
					
					
				//DIV--------------------------------------------------------------
				Button(action: {
					//add code here
				}, label: {
					NavigationLink(destination: WeatherCityView(cityCode: "KDET")) {
						Text("DETROIT")
							.padding()
							.foregroundColor(Color.blue)
							.font(.largeTitle)
						}
					}) //end Button
					
				//DIV--------------------------------------------------------------
				Button(action: {
					//add code here
				}, label: {
					NavigationLink(destination: WeatherCityView(cityCode: "KORD")) {
						Text("CHICAGO")
							.padding()
							.foregroundColor(Color.blue)
							.font(.largeTitle)
						}
					}) //end Button
					
					
				//DIV--------------------------------------------------------------
				Button(action: {
					//add code here
				}, label: {
					NavigationLink(destination: WeatherCityView(cityCode: "KFAR")) {
						Text("FARGO")
							.padding()
							.foregroundColor(Color.blue)
							.font(.largeTitle)
						}
					}) //end Button
				} //end VStack2
				
				
				.navigationTitle("WEATHER - CITIES")
            }//end ScrollView
				
			} //end NavView
			
		} //end body
		
	} //end Struct
	
struct ContentView_Previews: PreviewProvider {
	static var previews: some View {
		ContentView()
		}
	}
