#include <iostream>
#include <vector>
using namespace std;

enum Direction { N, S, E, W, Up, Down };

class Spacecraft {
private:
    int x, y, z;
    Direction currentDirection;

public:
    Spacecraft(int startX, int startY, int startZ, Direction startDirection)
        : x(startX), y(startY), z(startZ), currentDirection(startDirection) {}

    void moveForward() {
        if (currentDirection == N) y++;
        else if (currentDirection == S) y--;
        else if (currentDirection == E) x++;
        else if (currentDirection == W) x--;
        else if (currentDirection == Up) z++;
        else if (currentDirection == Down) z--;
    }

    void moveBackward() {
        if (currentDirection == N) y--;
        else if (currentDirection == S) y++;
        else if (currentDirection == E) x--;
        else if (currentDirection == W) x++;
        else if (currentDirection == Up) z--;
        else if (currentDirection == Down) z++;
    }

    void turnLeft() {
        if (currentDirection == Up) currentDirection = N;
        else if (currentDirection == N) currentDirection = W;
        else if (currentDirection == S) currentDirection = E;
        else if (currentDirection == E) currentDirection = N;
        else if (currentDirection == W) currentDirection = S;
        else if (currentDirection == Down) currentDirection = S;
    }

    void turnRight() {
        if (currentDirection == Up) currentDirection = S;
        else if (currentDirection == N) currentDirection = E;
        else if (currentDirection == S) currentDirection = W;
        else if (currentDirection == E) currentDirection = S;
        else if (currentDirection == W) currentDirection = N;
        if (currentDirection == Down) currentDirection = N;
    }

    void turnUp() {
        if (currentDirection == N) currentDirection = Up;
        else if (currentDirection == S) currentDirection = Down;
        else if (currentDirection == E || currentDirection == W) currentDirection = Up;
    }

    void turnDown() {
        if (currentDirection == N) currentDirection = Down;
        else if (currentDirection == S) currentDirection = Up;
        else if (currentDirection == E || currentDirection == W) currentDirection = Down;
    }

    void executeCommands(const vector<char>& commands) {
        for (char command : commands) {
            if (command == 'f') moveForward();
            else if (command == 'b') moveBackward();
            else if (command == 'l') turnLeft();
            else if (command == 'r') turnRight();
            else if (command == 'u') turnUp();
            else if (command == 'd') turnDown();
        }
    }

    void printPosition() {
        cout << "Final Position: (" << x << ", " << y << ", " << z << ")\n";
        cout << "Final Direction: ";
        if (currentDirection == N) cout << "N";
        else if (currentDirection == S) cout << "S";
        else if (currentDirection == E) cout << "E";
        else if (currentDirection == W) cout << "W";
        else if (currentDirection == Up) cout << "Up";
        else if (currentDirection == Down) cout << "Down";
        cout << "\n";
    }
};

int main() {
    int initialX,initialY,initialZ;
    cout<<"Enter initial Position in X,Y and Z: ";cin>>initialX;cin>>initialY;cin>>initialZ;
    Spacecraft chandrayaan3(initialZ, initialY, initialZ, N);
    int N;
    cout<<"Enter the number of commands: ";cin>>N;
    cout<<"Enter the commands (ex:- 'f','r','b','l','u','d'): ";
    vector<char> commands(N);
    for(int i=0;i<N;i++){cin>>commands[i];}
    chandrayaan3.executeCommands(commands);
    chandrayaan3.printPosition();
    return 0;
}

