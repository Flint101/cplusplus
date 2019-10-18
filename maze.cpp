#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<exception>

using namespace std;

class Position {
    private:
        int x, y;

    public:
        Position(int x1, int y1) : x(x1), y(y1) {}

        int getX() const { return x; }
        int getY() const { return y; }
};

class Maze {
    private:
        vector<string> line;

    public:
        Maze(vector<string> lines) { 
            line = lines;
        }
        bool isWall(Position playercoordinates) { 
            return (line.at(playercoordinates.getX()).at(playercoordinates.getY()) == 'l');   
        }
        void validateExit(Position exitcoordinates) {
            if (line.at(exitcoordinates.getX()).at(exitcoordinates.getY()) == 'l') {
                throw runtime_error("an error occurred: exit outside maze or off the path");
            }
        }
        void print(Position playerPosition, Position endPosition, bool calculation) { 
            for (int i = 0; i < line.size(); i++) {
                for (int j = 0; j < line.at(i).length(); j++) {
                    if (i == playerPosition.getX() && j == playerPosition.getY()) {
                        cout << "P";
                    }
                    else if (i == endPosition.getX() && j == endPosition.getY()) {
                        cout << "x";
                    }
                    else {
                    cout << line.at(i).at(j);
                    }
                }
                cout << endl;
            }
            if (calculation == true) {
                if (playerPosition.getX() == endPosition.getX() && playerPosition.getY() == endPosition.getY()) {
                    cout << endl << "The player reached the exit!" << endl;
                }
                else {
                    cout << endl << "The player did not reach the exit." << endl;
                }
            }
        }
};

class GameState {
    private:
        Maze& mymaze;
    
    public:
        GameState(Maze maze1) : mymaze(maze1) {}

        Position performMoves(const string moves, Position coordinates) {
            for (int i = 0; i < moves.length(); ++i) {
                coordinates = performMove(moves.at(i), coordinates);
            }
            return coordinates;
        }
        Position performMove(const char move, Position coordinates) {
            switch (move) {
                case 'u':
                    coordinates = Position(coordinates.getX() - 1, coordinates.getY());
                    break;
                case 'r':
                    coordinates = Position(coordinates.getX(), coordinates.getY() + 1);
                    break;
                case 'd':
                    coordinates = Position(coordinates.getX() + 1, coordinates.getY());
                    break;
                case 'l':
                    coordinates = Position(coordinates.getX(), coordinates.getY() - 1);
                    break;
                default:
                    throw runtime_error("an error occurred: invalid move");
                    break;
            } 
            return coordinates;
        }
};

//Checks if both coordinates are integers
void checkCoordinates(string line, int& first, int& second) {
    stringstream ss;
    ss << line;
    ss >> first >> second;
    if (ss.fail()) {
        throw runtime_error("an error occurred: could not read coordinates");
        ss.clear();
    }
}

//Checks if height and width are valid
void checkDimensions(string line, int& first, int& second) {
    istringstream iss(line);
    if (!(iss >> first >> second)) {
        throw runtime_error("an error occurred: could not read height and width of the maze");
    }
}

//Opening file
void handleFile(int argc, char *argv, ifstream& inputFile) {
    string inFile = "";
    if (argc == 2) {
        inFile = argv;
    }
    else {
        throw runtime_error("an error occurred: no input file name given");
    }
    inputFile.open(inFile);
    if (!inputFile.is_open()) {
        string error = "an error occurred: could not open input file ";
        error.append(inFile);
        throw runtime_error(error); 
    }
}

//Creates a vector with the layout of the maze
vector<string> mazeLayoutIntoVector(int height, int width, ifstream& inputFile) {
    vector<string> lines;
    string line;
    for (int i = 0; i < height; ++i) {
        getline(inputFile, line);
        if (line.length() == width) {
            lines.push_back(line);
        }
    }
    if (lines.size() != height) {
        throw runtime_error ("an error occurred: could not read maze layout");
    }
    return lines;
}


int main(int argc, char* argv[]) {
    try {
        ifstream inputFile;
        handleFile(argc, argv[1], inputFile);

        //storing width and height
        string line;
        getline(inputFile, line);
        int height, width;
        checkDimensions(line, height, width);

        //Reading maze layout into the vector lines
        vector<string> lines = mazeLayoutIntoVector(height, width, inputFile);

        //storing begin, end and moves
        int x, y;   
        getline(inputFile, line);
        checkCoordinates(line, x, y);
        Position end(x, y); 
        getline(inputFile, line);
        checkCoordinates(line, x, y);
        Position start(x, y);
        string moves;
        getline(inputFile, moves);
        
        //creating objects for the classes
        Maze maze(lines);
        maze.validateExit(end);
        GameState state(maze); 
        GameState gameState = GameState(maze);
        Position result = gameState.performMoves(moves, start);

        //Printing the maze start and end
        maze.print(start, end, false);
        cout << endl;
        if (maze.isWall(result)) {
            throw runtime_error("an error occurred: player outside maze or off the path");
        }
        maze.print(result, end, true);

        inputFile.close();
    }

    catch (runtime_error& exception) {
        cout << exception.what() << endl;
    }

    return 0;
}
