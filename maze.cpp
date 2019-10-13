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
        //position();
        position(int x1, int y1) {                                                       //constructor position that sets x and y coordinates
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
        //maze();
        maze(vector<string> lines) {                                                     //constructor maze that sets the current vector to the vector given as input in the argument
            line = lines;
        }
        bool isWall(position& coordinates) {                                                     //method isWall returning true or false 
            cout << line.at(coordinates.getX());            //REMOVE
            return line.at(coordinates.getX()).at(coordinates.getY()) == 'l';
        }
        bool isWithinBounds(position& coordinates) {                                             //method isWithinBounds returning true or false
            return coordinates.getX() >= 0 && coordinates.getX() < line.size()
            && coordinates.getY() >= 0 && coordinates.getY() < line.at(coordinates.getX()).length();
        }
        void print(position& playerPosition) {                                                          //method print with input player position
            cout << "Print called";                         //REMOVE
            for (int i = 0; i < line.size(); ++i) {
                for (int j = 0; i < line.at(i).length(); ++j) {
                    if (i == playerPosition.getX() && j == playerPosition.getY()) {
                        cout << 'P';
                    }
                    else {
                        cout << line.at(i).at(j);
                    }
                }
                cout << endl;
            }
        }
};

class gameState {
    private:
        maze& mymaze;
    
    public:
        gameState(maze maze1) : mymaze(maze1) {}
        /*gameState(maze& maze1) {
            mymaze = maze1;
        }*/
       
        
        position performMoves(string moves, position& coordinates) {
            cout << "performMoves" << endl;
            for (int i = 0; i < moves.length(); ++i) {
                cout << moves.at(i) << endl;
                coordinates = performMove(moves.at(i), coordinates);
            }
            return coordinates;
        }
        position performMove(char move, position& coordinates) {
            //position nextPosition;
            
            switch (move)
            {
            case 'u':
                cout << "U";
                coordinates = position(coordinates.getX() - 1, coordinates.getY());
                break;
            case 'r':
                cout << "R";
                coordinates = position(coordinates.getX(), coordinates.getY() + 1);
                break;
            case 'd':
                cout << "D";
                coordinates = position(coordinates.getX() + 1, coordinates.getY());
                break;
            case 'l':
                cout << "L";
                coordinates = position(coordinates.getX(), coordinates.getY() - 1);
                break;
            default:
                throw runtime_error("an error occurred: invalid move");
                break;
            }
            if (mymaze.isWall(coordinates)) {
                throw runtime_error("an error occured: player outside maze or off the path");
            }
            if (!mymaze.isWithinBounds(coordinates)) {
                throw runtime_error("an erro occured: player outside maze or off the path");
            }
            return coordinates;
        }
};


//Parsing input from a string to integers
void stringToInteger(string line, int& first, int& second) {
    stringstream ss;
    ss << line;
    ss >> first >> second;
    if (ss.fail()) {
        throw runtime_error("an error occured: could not read height and width of the maze");
        ss.clear();
    }
}

int main(int argc, char* argv[]) {
    try {
        string inFile = "";
        if (argc == 2) {
            inFile = argv[1];
        }
        else {
            throw runtime_error("an error occured: no input file name given \n");
        }
    
        ifstream inputFile;
        inputFile.open(argv[1]);
        if (!inputFile.is_open()) {
            string error = "an error occured: could not open input file ";
            error.append(argv[1]);
            throw runtime_error(error);
            
        }
        //File is now open

        string line;

        //Width and height of the maze
        getline(inputFile, line);
        int height, width;
        stringToInteger(line, height, width);

        vector<string> lines;
        for (int i = 0; i < height; ++i) {
            getline(inputFile, line);
            lines.push_back(line);
        }

        int x, y;   
        getline(inputFile, line);
        stringToInteger(line, x, y);
        position start(x, y);                   //Starting position 
        getline(inputFile, line);
        stringToInteger(line, x, y);
        position end(x, y);                     //Ending position 
        string moves;                           //Player moves
        getline(inputFile, moves);
        

        maze maze(lines);                       //Creating object maze for class maze with vector<string> as input
        gameState state(maze);                  //Creating object state for class gameState with maze as input
        maze.print(start);

        cout << endl;
        
        gameState GameState = gameState(maze);
        position result = GameState.performMoves(moves, start);
        maze.print(result);
        
        inputFile.close();
    }

    catch (runtime_error& exception) {
        cout << exception.what() << endl;
    }

    return 0;
}