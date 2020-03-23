#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

inline int X (int pos) {
	return pos / 3;
}

inline int Y (int pos) {
	return pos % 3 - 1;
}

string rule(40, '_');

class Grid
{
private:
	char subgrid[3][3];
	char left, right;

public:
	Grid();
	void set (int x, int y, char cell);
	char get (int x, int y);
};

Grid::Grid()
{
	for (size_t i = 0; i < 3; ++i)
	for (size_t j = 0; j < 3; ++j)
	{
		set(i, j, '.');
	}
}

void Grid::set (int x, int y, char cell) {
	subgrid[x][y] = cell;
}

char Grid::get(int x, int y) {
	return subgrid[x][y];
}

class Game
{
private:
	Grid grid[3][3];
	char player;
	size_t cur, loaded;

public:
	Game();
	void display(); 
	void play();
	void save();
	void load();
	void input (int g);
	bool checkWin (Grid grid);
	void showScore();
};

Game::Game()
{
	player = 'x';
	loaded = cur = 0;
}

void Game::play()
{
	int g=0;
	
	if (loaded) {
		g = cur;
	}
	else {
		display();
		while (1) {
			display();
			cout << "\n  Player " << player << " - Enter Grid: ";
			cin >> cur;
			if (cur > 0 && cur < 10) {
				break;
			}
			display();
			cout << "\n  Try again.";
			cin.get();
		}
	}
	while (1) {
		display();
		g = cur;
		input(g);
		if (checkWin(grid[X(g)][Y(g)])) {
			cur = g;
			display();
			cout << "\n  Player " << player << " won!";
			cin.get();
			cin.ignore();
			break;
		}
		else {
			player = player == 'x' ? 'o' : 'x';
		}
		
	}

}

void Game::save() {
	std::ofstream fout;
	fout.open("savegame.txt");
	for (size_t i = 0; i < 3; ++i)
	for (size_t j = 0; j < 3; ++j)
	for (size_t k = 0; k < 3; ++k)
	for (size_t l = 0; l < 3; ++l)
	{
		fout << grid[i][j].get(k, l);
	}
	fout << player;
	fout << cur;
	fout.close();
}

void Game::load() {
	char c;
	std::ifstream fin;
	fin.open("savegame.txt");
	for (size_t i = 0; i < 3; ++i)
	for (size_t j = 0; j < 3; ++j)
	for (size_t k = 0; k < 3; ++k)
	for (size_t l = 0; l < 3; ++l)
	{
		fin >> c;
		grid[i][j].set(k, l, c);
	}
	fin >> c;
	player = c;
	fin >> c;
	cur = atoi(&c);
	loaded = 1;
	fin.close();
}

void Game::display()
{
	system("cls");
	cout << "\n  ULTIMATE TIC TAC TOE\n" << rule;

	for (size_t i = 0; i < 3; ++i)
	{
		for (size_t k = 0; k < 3; ++k)
		{
			cout << "\n";
			char left, right;
			left = right = ' ';

			for (size_t j = 0; j < 3; ++j)
			{
				if (k == 1)
				{
					if (3*i + j + 1  == cur) {
						left = '>';
						right = '<';
					}
					else {
						left = right = ' ';
					}
				}
				cout << "  " << left << " ";
				for (size_t l = 0; l < 3; ++l) {
					cout << grid[i][j].get(k, l) << " ";
				}
				cout << right;
			}
		}
		cout << "\n\n";
	}
	cout << "\n";
}

void Game::input(int g)
{
	char c;
	int s;
	while (1) {
		display();
		cout << "\n  Player " << player << " - Enter subgrid: ";
		cin >> c;
		if (isdigit(c)) {
			s = atoi(&c);
			if (s > 0 && s <= 9)
			{
				if (grid[X(g)][Y(g)].get(X(s), Y(s)) == '.') {
					cur = s;
					break;
				}
			}
		}
		else if (c == 's' || c == 'S') {
			display();
			cout << "\n  Game saved.";
			save();
			std::exit(0);
		}
		else if (c == 'q' || c == 'Q') {
			display();
			cout << "\n  Game not saved.";
			std::exit(0);
		}
		display();
		cout << "\n  Try again.";
		cin.ignore(); cin.get();
	}
	grid[X(g)][Y(g)].set(X(s), Y(s), player);
	g = s;
}

bool Game::checkWin(Grid grid)
{
	char p = player;
	// check for col and row wins
	for (int i = 0; i < 3; ++i) {
		if ((p == grid.get(i, 0) &&
			 p == grid.get(i, 1) &&
			 p == grid.get(i, 2)) ||
			(p == grid.get(0, i) &&
			 p == grid.get(1, i) &&
			 p == grid.get(2, i))) {
			return true;
		}
	}
	// check diagonals
	return  (p == grid.get(1, 1) &&
			((p == grid.get(0, 0) && p == grid.get(2, 2)) ||
			(p == grid.get(0, 2) && p == grid.get(2, 0)))
	);
	return 0;
}

int main()
{
	Game game;
	game.display();
	cout << "\n  Welcome to Ultimate Tic Tac Toe." <<
		"\n  Press Enter to start.";
	cin.get();

	int input, error = 0;
	enum menu { play = 1, load, quit };
	do {
		game.display();
		if (error) {
			cout << "  Invalid option. Try again.\n";
			error = 0;
		}
		else {
			cout << "  Select an option: \n";
		}
		cout << "    1) Play\n    2) Load\n    3) Quit\n" << "\n> ";
		cin >> input;
		switch (input) {
			case play:
				game.play(); break;
			case load:
				game.load();
				game.play();
			case quit:
				std::exit(0);
			default:
				error = 1;
		}
		system("cls");
	} while (error);

	system("pause");
	return 0;
}