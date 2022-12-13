//Uses the 2022NFLOdds.json File

import SwiftUI

struct Game: Decodable {
    var date:		String	//Game Date
    var team1:  	String 	//Home Team
    var team2:  	String 	//Away Team
	var elo_prob1:	Float 	//Team 1 Chance of Winning
	var elo_prob2:	Float 	//Team 2 Chance of Winning
	var score1:		Int		//Team 1 Score
	var score2:		Int		//Team 2 Score
}

struct NFLGameView: View {
    @State private var games = [Game]()
    
    var body: some View {
        NavigationView {
            List(games, id: \.date) { g in
                VStack (alignment: .leading) { //Start VStack
					//HStack (alignment: .leading) {
					Text(g.team1)
                    .font(.headline)
                    .foregroundColor(.black)
					
					Text(g.team2)
                    .font(.headline)
                    .foregroundColor(.black)
					//} //End HStack1 for Teams
					
					//HStack (alignment: .leading) {
					Text(g.elo_prob1)
                    .font(.headline)
                    .foregroundColor(.black)
					
					Text(g.elo_prob2)
                    .font(.headline)
                    .foregroundColor(.black)
					//} //end HStack2 for Win Chances
					
					//HStack (alignment: .leading) {
					Text(g.score1)
                    .font(.headline)
                    .foregroundColor(.black)
					
					Text(g.score2)
                    .font(.headline)
                    .foregroundColor(.black)
					//} //end HStack3 for Scores
                    
                } //end VStack
            }
            .navigationTitle("NFL Games List")
            .task {
                await fetchData()
            }
        }
    }
//Read Local File   
/*	func readLocalFile(forName name: String) -> Data? {
		do {
			if let bundlePath = Bundle.main.path(forResource: name,
													ofType: "json"),
				let jsonData = try String(contentsOfFile: bundlePath).data(using: .utf8) {
				return jsonData
			}
		} catch {
			print(error)
		}
		
		return nil
	}*/
//End Read Local File


	//If needed, will make webpage fetch with custom API
    
    func fetchData() async {
        // create the URL
        guard let url = URL(string: "https://cschultz11.github.io/past-projects/nfl-odds/") else {
            print("Hey Man, THIS URL DOES NOT WORK!")
            return
        }
        
        // fetch the data
        do {
            let (data, _) = try await URLSession.shared.data(from: url)
            
            // decode that data
            if let decodedResponse = try? JSONDecoder().decode([Quote].self, from: data) {
                quotes = decodedResponse
            }
        } catch {
            print("Bad news ... This data is not valid :-(")
        }
        
        // ecode the data
    }
}

struct NFLGameView_Previews: PreviewProvider {
    static var previews: some View {
        NFLGameView()
    }
}
