#include <iostream>
#include <map>
#include <string>

using namespace std;

// Function to get the player for a specific position and team
string getPlayer(const map<string, map<string, string>>& nbaTeams, const string& team, const string& position) {
    if (nbaTeams.find(team) != nbaTeams.end()) { // Check if the specified team exists in the map
        const map<string, string>& teamLineup = nbaTeams.at(team); // Retrieve the lineup for the specified team
        if (teamLineup.find(position) != teamLineup.end()) { // Check if the specified position exists in the lineup
            return teamLineup.at(position); // Show the player at the specified position
        } else {
            return "Position not found. Please input PG, SG, SF, PF, C."; // Show an error message if the position is not found
        }
    } else {
        return "Team not found."; // Show an error message if the team is not found
    }
}

int main() {
    // Map to store NBA teams and their starting lineups
    map<string, map<string, string>> nbaTeams = {
            {"76ers",{{"PG","Tyrese Maxey"},{"SG","Kyle Lowry"},{"SF","Kelly Oubre"},{"PF", "Tobias Harris"},{"C", "Joel Embiid"}}},
            {"Bucks",{{"PG", "Damian Lillard"},{"SG", "Mallik Beasley"},{"SF","Khris Middleton"},{"PF","Giannis Antetokounmpo"},{"C", "Brook Lopez"}}},
            {"Bulls",{{"PG","Coby White"},{"SG","Ayo Dosunmu"},{"SF","Alex Caruso"},{"PF", "DeMar DeRozan"},{"C", "Nikola Vucevic"}}},
            {"Cavaliers",{{"PG","Darius Garland"},{"SG","Donovan Mitchell"},{"SF","Max Strus"},{"PF", "Evan Mobley"},{"C", "Jarett Allen"}}},
            {"Celtics",{{"PG","Jrue Holiday"},{"SG","Derick White"},{"SF","Jaylen Brown"},{"PF", "Jason Tatum"},{"C", "Kristaps Porzingis"}}},
            {"Clippers",{{"PG","James Harden"},{"SG","Terence Mann"},{"SF","Paul George"},{"PF", "Kawhi Leonard"},{"C", "Ivica Zubac"}}},
            {"Grizzlies",{{"PG","Ja Morant"},{"SG","Desmond Bane"},{"SF","Vince Williams"},{"PF", "Santi Aldama"},{"C", "Jaren Jackson"}}},
            {"Hawks",{{"PG","Trae Young"},{"SG","Bogdan Bogdanovic"},{"SF","DeAndre Hunter"},{"PF", "Jalen Johnson"},{"C", "Clint Capela"}}},
            {"Heat",{{"PG","Terry Rozier"},{"SG","Tyler Herro"},{"SF","Jimmy Butler"},{"PF", "Nikola Jovic"},{"C", "Bam Adabayo"}}},
            {"Hornets",{{"PG","LaMelo Ball"},{"SG","Seth Curry"},{"SF","Brandon Miller"},{"PF", "Grant Williams"},{"C", "Marques Bolden"}}},
            {"Jazz",{{"PG","Keyonte George"},{"SG","Collin Sexton"},{"SF","Jordan Clarkson"},{"PF", "Taylor Hendricks"},{"C", "John Collins"}}},
            {"Kings",{{"PG","DeAaron Fox"},{"SG","Keon Ellis"},{"SF","Harrison Barnes"},{"PF", "Keegan Murray"},{"C", "Domantas Sabonis"}}},
            {"Knicks",{{"PG","Jalen Brunson"},{"SG","Donte DiVincenzo"},{"SF","Josh Hart"},{"PF", "OG Anunoby"},{"C", "Mitchell Robinson"}}},
            {"Lakers",{{"PG","D'Angelo Russell"},{"SG","Austin Reaves"},{"SF","Lebron James"},{"PF", "Rui Hachimura"},{"C", "Anthony Davis"}}},
            {"Magic",{{"PG","Jalen Suggs"},{"SG","Cole Anthony"},{"SF","Franz Wagner"},{"PF", "Pablo Banchero"},{"C", "Wendell Carter"}}},
            {"Mavericks",{{"PG","Luka Doncic"},{"SG","Kyrie Irving"},{"SF","Derrick Jones Jr."},{"PF", "P.J. Washington"},{"C", "Daniel Gafford"}}},
            {"Nets",{{"PG","Dennis Schroder"},{"SG","Cam Thomas"},{"SF","Mikal Bridges"},{"PF", "Dorian Finney-Smith"},{"C", "Nic Claxton"}}},
            {"Nuggets",{{"PG","Jammal Murray"},{"SG","Kentavious Caldwell-Pope"},{"SF","Michael Porter Jr."},{"PF", "AAron Gordan"},{"C", "Nikola Jokic"}}},
            {"Pacers",{{"PG","Tyrese Haliburton"},{"SG","Andrew Nembhard"},{"SF","Aaron Nesmith"},{"PF", "Pascal Siakam"},{"C", "Myles Turner"}}},
            {"Pelicans",{{"PG","CJ MoCollum"},{"SG","Brandon Ingram"},{"SF","Herbert Jones"},{"PF", "Zion Williamson"},{"C", "Jonas Valanciunas"}}},
            {"Pistons",{{"PG","Cade Cunningham"},{"SG","Jaden Ivey"},{"SF","Ausar Thompson"},{"PF", "Simone Fontecchio"},{"C", "Jalen Duren"}}},
            {"Raptors",{{"PG","Immanuel Quickley"},{"SG","Gary Trent Jr."},{"SF","RJ Barret"},{"PF", "Scottie Barnes"},{"C", "Jakob Poeltl"}}},
            {"Rockets",{{"PG","Fred VanVleet"},{"SG","Jalen Green"},{"SF","Dillon Brooks"},{"PF", "Jabari Smith Jr."},{"C", "Alperen Sengun"}}},
            {"Spurs",{{"PG","Tre Jones"},{"SG","Devin Vassell"},{"SF","Julian Champagnie"},{"PF", "Jeremy Sochan"},{"C", "Victor Wembenyama"}}},
            {"Suns",{{"PG","Devin Booker"},{"SG","Bradley Beal"},{"SF","Grayson Allen"},{"PF", "Kevin Durant"},{"C", "Jusuf Nurkic"}}},
            {"Thunder",{{"PG","Shai Gilgeous-Alexander"},{"SG","Josh Giddy"},{"SF","Luguentz Dort"},{"PF", "Jalen Williams"},{"C", "Chet Holmgren"}}},
            {"Timberwolves",{{"PG","Mike Conley"},{"SG","Anthony Edwards"},{"SF","Jaden McDaniels"},{"PF", "Karl-Anthony Towns"},{"C", "Rudy Gobert"}}},
            {"Trailblazers",{{"PG","Scoot Henderson"},{"SG","Anfernee Simmons"},{"SF","Shaedon Sharpe"},{"PF", "Jerami Grant"},{"C", "Deandre Ayton"}}},
            {"Warriors", {{"PG", "Stephen Curry 26.5 PPG, 4.4 RPG, 5.0 APG"}, {"SG", "Klay Thompson 17.4 PPG 3.3 RPG 2.3 APG"}, {"SF", "Andrew Wiggins 13.0 PPG, 4.5 RPG, 1.7 APG"}, {"PF", "Draymond Green 8.7 PPG, 7.2 RPG, 5.9 APG"}, {"C", "James Wiseman 7.0 PPG, 5.1 RPG, 0.8 APG"}}},
            {"Wizards",{{"PG","Tyus Jones"},{"SG","Jordan Poole"},{"SF","Deni Avdija"},{"PF", "Kyle Kuzma"},{"C", "Marvin Bagley III"}}},
    };

    string team, position, response;
    bool keepAsking = true;

    while(keepAsking){
        cout << "Enter the NBA Team: ";
        getline(cin, team);
        cout << "Enter the Position (PG, SG, SF, PF, C): ";
        getline(cin, position);

        string player =
                getPlayer(nbaTeams, team, position);
        cout << "The " << position << " for the " << team << " is " << player <<endl;

        cout << "Do you want to view another player? (yes/no): ";
        getline (cin, response);
        if (response != "yes") {
            keepAsking = false;
        }
    }

    return 0;
}
