#include "Board.h"

Board :: Board(){
    
}

Board :: Board(Board& other){//copy c'tor
    this->boardSize = other.boardSize;
    this -> mat = new Character*[other.boardSize];
    
    for (int i = 0; i < this->boardSize; ++i){
        this->mat[i] = new Character[other.boardSize];
    }
    for(int i = 0; i < this->boardSize; i++){
        for(int j = 0; j < this->boardSize; j++){
            this->mat[i][j] = other.mat[i][j];
        }
    }
}

Board :: Board (int size){
    this-> boardSize = size;
    this -> mat = new Character*[this->boardSize];
    
    for (int i = 0; i < this->boardSize; ++i)
        this->mat[i] = new Character[this->boardSize];

    init();//initial Board
}

void Board :: create(int size){
	this->boardSize = size;

	this->mat = new Character*[boardSize];
	for(int i = 0; i < boardSize; i++){
		this->mat[i] = new Character[boardSize];
	}
	init();
}

Board :: ~Board(){
    del();
}

void Board:: del(){  //distructor

    for (int i = 0; i < boardSize; i++){ //free
	    delete[] mat[i];
    }
	delete[] mat;
}

void Board :: init(){ //to initial board
    for (int i = 0; i < boardSize; i++){
        for (int j = 0; j < boardSize; j++){
            this->mat[i][j] = '.';
        }
    }
}

int Board :: size() const{
    return this->boardSize;
}

Character& Board :: operator [] (Coordinate c) {
    
    if (c.getRow() >= boardSize || c.getColumn() >= boardSize || c.getRow() < 0 || c.getColumn() < 0 ){
        IllegalCoordinateException coordinateException;
        coordinateException.set_f(c.getRow());
        coordinateException.set_s(c.getColumn());
        throw coordinateException;
    }
    return this -> mat[c.getRow()][c.getColumn()];
}

Character Board :: operator [] (Coordinate c) const {//read only
    if (c.getRow() >= boardSize || c.getColumn() >= boardSize || c.getRow() < 0 || c.getColumn() < 0 ){
        IllegalCoordinateException coordinateException;
        coordinateException.set_f(c.getRow());
        coordinateException.set_s(c.getColumn());
        throw coordinateException;
    }
    return this -> mat[c.getRow()][c.getColumn()];
}

Board& Board::operator=(char place){//play turn
    if (place == '.'){
        init();
    }
    
    else if (place != 'X' && place != 'O' && place != '.'){
        IllegalCharException charException;
        charException.set_t(place);
        throw charException;
    }
    
    else{
        for(int i = 0; i < boardSize; i++)
            for(int j = 0; j < boardSize; j++)
                mat[i][j] = place;
    }
    
    return *this;
}

Board& Board::operator=(const Board& board){//copy Board

    if (this==&board){
        return *this;
    }
    
    del();
    
    boardSize = board.size();
    mat = new Character*[boardSize];  
	for (int i = 0; i < boardSize; i++){
		mat[i] = new Character[boardSize];
        for (int j = 0; j < boardSize; j++) 
            mat[i][j] = board.mat[i][j];
    }
    return *this;
}

bool operator== (Board const& board1, Board const& board2){
    if (board1.size() != board2.size())
        return false;

    for (int i = 0; i < board1.size() ; ++i) {
        for (int j = 0; j < board2.size() ; ++j) {
            if(board1.mat[i][j].getChar() != board2.mat[i][j].getChar())
                return false;
        }
    }
    return true;
}

bool operator!= (Board const& board1, Board const& board2){
    if (board1.size() != board2.size())
        return true;

    for (int i = 0; i <board1.size() ; ++i) {
        for (int j = 0; j <board2.size() ; ++j) {
            if(board1.mat[i][j].getChar() != board2.mat[i][j].getChar())
                return true;
        }
    }
    return false;
}

string Board::draw(int pixel) {

    int picNum=1;
    string fileName = "boardPic"+to_string(picNum)+".ppm";

    while(true){
        ifstream f("board"+to_string(picNum)+".ppm");
        if(!f.good())
            break;
        else{
            picNum++;
        }
    }
    fileName = "board"+to_string(picNum)+".ppm";

    ofstream thePic(fileName, ios::out | ios::binary);
    thePic << "P6" << endl << pixel <<" " << pixel << endl << 255 << endl;

    RGB image[pixel*pixel];

    for (int j = 0; j < pixel; ++j)  {  // row
        for (int i = 0; i < pixel; ++i) { // column
            image[pixel*j+i].red = (255);
            image[pixel*j+i].green = (255);
            image[pixel*j+i].blue = (255);
        }
    }

    //Drawing rows and columns

    //Drawing the columns
    for (int i = 0; i < boardSize; ++i) {
        int Xfrom = i * (pixel/boardSize);
        for (int r = 0; r < pixel ; ++r) {
            image[pixel * (r) + Xfrom].red = (121);
            image[pixel * (r) + Xfrom].green = (160);
            image[pixel * (r) + Xfrom].blue = (40);
        }
    }

    //Drawing the rows
    for (int j = 0; j < boardSize; ++j) {
        int Yfrom = j * (pixel/boardSize) ;
        for (int r = 0; r < pixel ; ++r) {
            image[(r) + Yfrom * pixel].red = (121);
            image[(r) + Yfrom * pixel].green = (160);
            image[(r) + Yfrom * pixel].blue = (40);
        }
    }

    for (int row = 0; row < boardSize; ++row) {
        for (int column = 0; column < boardSize; ++column) {
            int Xfrom = column * (pixel/boardSize);
            int Xto = (column + 1) * (pixel/boardSize);
            int Yfrom = row * (pixel/boardSize) ;
            int Yto = (row + 1) * (pixel/boardSize);

            if (mat[row][column] == 'X') {

                //Drawing X
                for (int r = 10; r < Yto - Yfrom - 10 ; ++r) {

                    //Drawing \ diagonal of X
                    image[pixel * (r + Yfrom) + Xfrom + r].red = (44);
                    image[pixel * (r + Yfrom) + Xfrom + r].green = (133);
                    image[pixel * (r + Yfrom) + Xfrom + r].blue = (91);

                    //Drawing / diagonal of X
                    image[pixel * (r + Yfrom) + Xto - (r)].red = (44);
                    image[pixel * (r + Yfrom) + Xto - (r)].green = (133);
                    image[pixel * (r + Yfrom) + Xto - (r)].blue = (91);

                }
            }
            else if(mat[row][column] == 'O'){
                int R = (Xto - Xfrom) / 2;
                int Ox = (Xto - Xfrom) / 2;
                int Oy = (Yto - Yfrom) / 2;

                for (int X = 10; X < Yto - Yfrom  ; ++X) {
                    auto Y = static_cast<int>(sqrt(R * R - (X - Ox) * (X - Ox)) + Oy);
                    int attach = 20;

                    //Drawing bottom size of the circle
                    image[pixel * (Y + Yfrom - attach) + Xfrom + X].red = (0);
                    image[pixel * (Y + Yfrom - attach) + Xfrom + X].green = (25);
                    image[pixel * (Y + Yfrom - attach) + Xfrom + X].blue = (15);
                    image[pixel * (Yto - Y + attach) + Xfrom + X].red = (0);
                    image[pixel * (Yto - Y + attach) + Xfrom + X].green = (28);
                    image[pixel * (Yto - Y + attach) + Xfrom + X].blue = (15);
                }
            }
        }
    }

    thePic.write(reinterpret_cast<char*>(&image), 3*pixel*pixel);
    thePic.close();

    return fileName;
}

istream& operator>>(istream& in, Board& board){
 /*   cout << "enter board size: ";
    in >> board.boardSize;
    
    board.create(board.size());
    for(int i=0; i<board.size(); i++){
        
    }*/
    
    int counter=0,tempSize=0;
    char c;
    bool flag = true;
    vector<char> allChars;
    while(cin.get(c)){
        if(flag&&(c=='\n')){
            tempSize = counter;
            flag = false;
        }
        counter++;
        allChars.push_back(c);
    }
    Board temp{tempSize};
    int k = 0;

    for(int i=0;i<temp.size();++i){
        for(int j=0;j<temp.size();++j){
            if(allChars.at(k)!='\n'){
                temp.mat[i][j] = allChars.at(k);
            }
            else{
                temp.mat[i][j] = allChars.at(++k);
            }
            k++;
        }
    }
    board = temp;
    return in;
}
