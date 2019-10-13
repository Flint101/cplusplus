#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<exception>

using namespace std;

class position {
    private:
        int x, y;

    public:
        position(int x1, int y1) {
            x = x1; 
            y = y1;
        }
        int getX() const { return x; }
        int getY() const { return y; }
};

class maze {
    private:
        vector<string> line;

    public:
        maze(vector<string> lines) { 
            line = lines;
        }
        bool isWall(position playercoordinates) { 
            return (line.at(playercoordinates.getX()).at(playercoordinates.getY()) == 'l');   
        }
        void validateExit(position exitcoordinates) {
            if (line.at(exitcoordinates.getX()).at(exitcoordinates.getY()) == 'l') {
                throw runtime_error("an error occurred: exit outside maze or off the path");
            }
        }
        void print(position playerPosition, position endPosition, bool calculation) { 
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

class gameState {
    private:
        maze& mymaze;
    
    public:
        gameState(maze maze1) : mymaze(maze1) {}

        position performMoves(string moves, position coordinates) {
            for (int i = 0; i < moves.length(); ++i) {
                coordinates = performMove(moves.at(i), coordinates);
            }
            return coordinates;
        }
        position performMove(char move, position coordinates) {
            switch (move) {
                case 'u':
                    coordinates = position(coordinates.getX() - 1, coordinates.getY());
                    break;
                case 'r':
                    coordinates = position(coordinates.getX(), coordinates.getY() + 1);
                    break;
                case 'd':
                    coordinates = position(coordinates.getX() + 1, coordinates.getY());
                    break;
                case 'l':
                    coordinates = position(coordinates.getX(), coordinates.getY() - 1);
                    break;
                default:
                    throw runtime_error("an error occurred: invalid move");
                    break;
            } 
            //if (mymaze.isWall(coordinates)) {
                //throw runtime_error("blablabla");
            //}
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

int main(int argc, char* argv[]) {
    try {
        string inFile = "";
        if (argc == 2) {
            inFile = argv[1];
        }
        else {
            throw runtime_error("an error occurred: no input file name given");
        }
    
        ifstream inputFile;
        inputFile.open(argv[1]);
        if (!inputFile.is_open()) {
            string error = "an error occurred: could not open input file ";
            error.append(argv[1]);
            throw runtime_error(error); 
        }

        string line;
        getline(inputFile, line);
        int height, width;
        checkDimensions(line, height, width);

        vector<string> lines;
        for (int i = 0; i < height; ++i) {
            getline(inputFile, line);
            if (line.length() == width) {
                lines.push_back(line);
            }
        }

        if (lines.size() != height) {
            throw runtime_error ("an error occurred: could not read maze layout");
        }

        int x, y;   
        getline(inputFile, line);
        checkCoordinates(line, x, y);
        position end(x, y); 
        getline(inputFile, line);
        checkCoordinates(line, x, y);
        position start(x, y);
        string moves;
        getline(inputFile, moves);
        
        maze maze(lines);
        maze.validateExit(end);
        gameState state(maze); 
        gameState GameState = gameState(maze);
        position result = GameState.performMoves(moves, start);

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
