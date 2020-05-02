#include "Board.h"
#include "Level.h"
#include <iostream>

Board::Board(Player& player, Level& level, const std::string fileName)
	:m_file(std::ifstream(fileName)),m_sprite(*(Resource::getInstance()[Background]))
{
	m_sprite = Object::create(sf::Vector2f(BOARD_WIDTH/2,BOARD_HEIGHT/2), sf::Vector2f(BOARD_WIDTH, BOARD_HEIGHT), Background);
	readFile(player,level);
}


void Board::draw(sf::RenderWindow& window) 
{
	window.draw(m_sprite);
	for (int row = 0; row < m_rows; row++) {
		for (int col=0; col<m_cols; col++)
			if (m_statics[row][col])
				m_statics[row][col]->draw(window);
	}
}



StaticObject* Board::getContentOf(const sf::Vector2i& cell) const
{
	std::cout << cell.y << " " << cell.x << std::endl;
	/*if (cell.y > m_cols+1 || cell.y < 0 || cell.x > m_rows+1 || cell.x < 0)
		return nullptr;*/
	return m_statics[cell.y][cell.x];
}

void Board::deleteCell(const sf::Vector2i& cell)
{
	m_statics[cell.y][cell.x] = nullptr;
}

Board::~Board()
{
	for (int row = 0; row < m_rows + 1; row++)
		for (int col = 0; col < m_cols + 1; col++)
			if (m_statics[row][col])
				delete m_statics[row][col];
}

//add a present to the matrix vector by random a type of present
void Board::addPresent(sf::Vector2f position, sf::Vector2f size, int row, Board& board)
{
	int presentType = rand() % 3;
	if (presentType == Time)
		m_statics[row].push_back(new (std::nothrow) TimePresent(position, size,board));
	else if (presentType == Score)
		m_statics[row].push_back(new (std::nothrow) ScorePresent(position, size,board));
	else if (presentType == Stones)
		m_statics[row].push_back(new (std::nothrow) StonesPresent(position, size,board));
}

sf::Vector2f Board::indexToPixel(int row, int col)
{
	return { col * (BOARD_WIDTH / m_cols) + (BOARD_WIDTH/m_cols)/2, 
		row * (BOARD_HEIGHT / m_rows) + (BOARD_HEIGHT/m_rows)/2 };
}

void Board::readFile(Player& player, Level& level)
{
	int stones, timeLimit, diamonds = 0;
	sf::Vector2f playersPosition;
	char character;
	std::string line;

	m_file >> m_rows >> m_cols >> stones >> timeLimit;
	
	std::getline(m_file, line);
	int col , row=-1 ;
	//std::vector<StaticObject*> upperBoarder;
	//for (col = -1; col < m_cols + 1; col++)
	//	upperBoarder.push_back(new (std::nothrow) Wall(indexToPixel(row, col), { BOARD_WIDTH / m_cols,BOARD_HEIGHT / m_rows }));
	for ( row = 0; row < m_rows; row++)
	{
		std::vector<StaticObject*> vctor;
		m_statics.push_back(vctor);
		for ( col = 0; col < m_cols; col++)
		{
			m_file.get(character);
			switch (character)
			{
			case DIAMOND:
			{
				m_statics[row].push_back( new (std::nothrow) Diamond(indexToPixel(row, col), { BOARD_WIDTH / m_cols,BOARD_HEIGHT / m_rows },*this));
				diamonds++;
				break;
			}
			case STON:
				m_statics[row].push_back(new (std::nothrow) Stone(indexToPixel(row, col), { BOARD_WIDTH / m_cols,BOARD_HEIGHT / m_rows },*this));
				break;
			case WALL:
				m_statics[row].push_back(new (std::nothrow) Wall(indexToPixel(row, col), { BOARD_WIDTH / m_cols,BOARD_HEIGHT / m_rows }));
				break;
			case PRESENT:
				addPresent(indexToPixel(row, col), { BOARD_WIDTH / m_cols,BOARD_HEIGHT / m_rows },row,*this);
				break;
			case MONSTER:
				level.addMonster(indexToPixel(row, col), { BOARD_WIDTH / m_cols,BOARD_HEIGHT / m_rows },player);
				m_statics[row].push_back(nullptr);
				break;
			case PLAYER:
				playersPosition = indexToPixel(row, col);
				m_statics[row].push_back(nullptr);        
				break;
			default:
				m_statics[row].push_back(nullptr);
				break;
			}
		}
		//boarder of right of board
		m_statics[row].push_back(new (std::nothrow) Wall(indexToPixel(row, col), { BOARD_WIDTH / m_cols,BOARD_HEIGHT / m_rows }));
		std::getline(m_file,line ); //skip to the nxt line
	}
	std::vector<StaticObject*> lowerBoarder;
	for (col = 0; col < m_cols + 1; col++)
		lowerBoarder.push_back(new (std::nothrow) Wall(indexToPixel(m_rows+1, col), { BOARD_WIDTH / m_cols,BOARD_HEIGHT / m_rows }));
	m_statics.push_back(lowerBoarder);
	//update all data of player that recieves from file
	player.initDataForLevel(playersPosition, { BOARD_WIDTH / m_cols,BOARD_HEIGHT / m_rows },timeLimit, stones, diamonds);
	m_file.close();
}
