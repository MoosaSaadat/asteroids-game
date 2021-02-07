/*
 * Board.cpp
 *
 *  Created on: May 2, 2014
 *      Author: Sibt ul Hussain
 */

#include "Board.h"
#include <cstdio>

// Asteroids board
int Board::secCount = 0;
int Board::bombTimer = 0;
// Note that all these enum constants from NILL onwards
// have been given numbers in increasing order
// e.g. NILL=0, and so on
// and these numbers are represented in the board array...
enum BoardParts {
	NILL, S_BRICK, G_BRICK, R_BRICK
};
// defining some utility functions...

/* board_array[Board::BOARD_Y][Board::BOARD_X] = { { 0 } };*/

#ifdef WITH_TEXTURES
const int nbricks = 3;

GLuint texture[nbricks];
GLuint tid[nbricks];
string tnames[] = {"solid.png", "brick.png", "brick-green.png"};
GLuint mtid[nbricks];
int cwidth = 60, cheight = 60; // 60x60 pixels bricks...

void RegisterTextures()
/*Function is used to load the textures from the
 * files and display*/
{
	// allocate a texture name
	glGenTextures(nbricks, tid);

	vector<unsigned char> data;
	//ofstream ofile("image-data.bin", ios::binary | ios::out);
	// now load each bricks data...

	for (int i = 0; i < nbricks; ++i) {

		// Read current brick

		ReadImage(tnames[i], data);
		if (i == 0) {
			int length = data.size();
			//ofile.write((char*) &length, sizeof(int));
		}
		//ofile.write((char*) &data[0], sizeof(char) * data.size());

		cout << " Texture Id=" << tid[i] << endl;
		mtid[i] = tid[i];
		// select our current texture
		glBindTexture(GL_TEXTURE_2D, tid[i]);

		// select modulate to mix texture with color for shading
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

		// when texture area is small, bilinear filter the closest MIP map
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
				GL_LINEAR_MIPMAP_NEAREST);
		// when texture area is large, bilinear filter the first MIP map
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		// if wrap is true, the texture wraps over at the edges (repeat)
		//       ... false, the texture ends at the edges (clamp)
		bool wrap = true;
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
				wrap ? GL_REPEAT : GL_CLAMP);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,
				wrap ? GL_REPEAT : GL_CLAMP);

		// build our texture MIP maps
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, cwidth, cheight, GL_RGB,
				GL_UNSIGNED_BYTE, &data[0]);
	}
	//ofile.close();

}
void Drawbrick(const BoardParts &cname, float fx, float fy, float fwidth,
		float fheight)
/*Draws a specfic brick at given position coordinate
 * sx = position of x-axis from left-bottom
 * sy = position of y-axis from left-bottom
 * cwidth= width of displayed brick in pixels
 * cheight= height of displayed bricki pixels.
 * */
{

	glPushMatrix();
	glEnable (GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, mtid[cname - 1]);
//	glTranslatef(0, 0, 0);
//	glRotatef(-M_PI / 2, 0, 0, 1);
	glBegin (GL_QUADS);
	glTexCoord2d(0.0, 0.0);
	glVertex2d(fx, fy);
	glTexCoord2d(1.0, 0.0);
	glVertex2d(fx + fwidth, fy);
	glTexCoord2d(1.0, 1.0);
	glVertex2d(fx + fwidth, fy + fheight);
	glTexCoord2d(0.0, 1.0);
	glVertex2d(fx, fy + fheight);
	glEnd();

	glColor4f(1, 1, 1, 1);

//	glBindTexture(GL_TEXTURE_2D, 0);

	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	//glutSwapBuffers();
}
#endif
// Destructor
Board::~Board(void) {
}
void Board::InitalizeBoard(int w, int h) {
	cout<<"Initialize board"<<endl;
	width = w;
	height = h;
	for (int i = 0; i < BOARD_Y - 1; ++i) {
		for (int j = 0; j < BOARD_X; ++j) {
			// can use G_BRICK, R_BRICK, or S_BRICK here
			board_array[i][j] = NILL;
		}
	}
}

Board::Board(const Board& obj) {

//	xcellsize = obj.xcellsize;
//	ycellsize = obj.ycellsize;
//	width = obj.width;
//	height = obj.height;
//	pcolor = obj.pcolor;
//	bcolor = obj.bcolor;
//	gcolor = obj.gcolor;
	Board();
}

//Constructor
Board::Board(int xsize, int ysize) {
	cout<<"Constructor board"<<endl;
	xcellsize = xsize;
	ycellsize = ysize;
	pcolor = CHOCOLATE;
	bcolor = ORANGE_RED;
	gcolor = PINK;
	for(int i=0; i  < BOARD_Y; ++i )
		for(int j=0; j < BOARD_X; ++j)
			board_array[i][j]=0;
//set up board
	level = 1;
	score = 0;
	lives = 3;
	arrCount = 8;
	arr=new Shape*[arrCount];
	arr[0] = new SpaceShip(500,400);
	int x, y, side, rad, type;
	for (int i = 1; i < arrCount; i += 1)
	{
		if (i < 6)
		{
			x = GetRandInRange(0, 1030);
			cout << i <<  ". (" << x << ", ";
			while (x >= 400 && x <= 600) {
				x = GetRandInRange(0, 1020);
			}
			y = GetRandInRange(0, 850);
			cout << y << ", ";
			while (y >= 300 && y <= 600) {
				y = GetRandInRange(0, 840);
			}
			side = GetRandInRange(4,8);
			cout << side << ", ";
			rad = GetRandInRange(30, 51);
			cout << rad << ", ";
			type = GetRandInRange(0, 2);
			cout << type << ")" << endl;
			arr[i] = new Asteroid(x, y, side, rad, type);
		}
		else
		{
			x = GetRandInRange(0, 1030);
			cout << i <<  ". (" << x << ", ";
			while (x >= 400 && x <= 600) {
				x = GetRandInRange(0, 1020);
			}
			y = GetRandInRange(0, 850);
			cout << y << ", ";
			while (y >= 300 && y <= 600) {
				y = GetRandInRange(0, 840);
			}
			type = GetRandInRange(0, 2);
			cout << type << ")" << endl;
			arr[i] = new Saucers(x, y, 40, type);
		}
	}
}
void Board::Draw() {
	glColor3f(0, 0, 1);
	glPushMatrix();

#ifdef WITH_TEXTURES
	for (int i = BOARD_Y - 2, y = 0; i >= 0; --i, y += xcellsize) {
		for (int j = 0, x = 0; j < BOARD_X; j++, x += (ycellsize)) {
			//			cout << " " << board_array[i][j] << " " << flush;
			switch (board_array[i][j]) {
				case NILL:
				// Empty space
				break;
				case S_BRICK:
				case G_BRICK:
				case R_BRICK:
				float fwidth = (float) (xcellsize) / width * 2, fheight =
				(float) ycellsize / height * 2;
				float fx = (float) (x - 10) / width * 2 - 1, fy = (float) y
				/ height * 2 - 1;

				/*Drawbrick((BoardParts) board_array[i][j], fx, fy, fwidth,
				 fheight);*/
				Drawbrick((BoardParts) board_array[i][j], (float)x/width-1, (float)y/height-1, fwidth,
						fheight);
				break;
			}
		}
	}
#else
	for (int i = BOARD_Y - 2, y = 0; i >= 0; --i, y += xcellsize) {
		for (int j = 0, x = 0; j < BOARD_X; j++, x += (ycellsize)) {
			//			cout <<      " " << board_array[i][j] << " " << flush;
			switch (board_array[i][j]) {
			case NILL:
				// Empty space
				break;
			case S_BRICK:
				DrawRectangle(x - 10, y, ycellsize, xcellsize,
						colors[SLATE_GRAY]);
				//DrawLine(x - 10, y, x - 10 + ycellsize, y, 4, colors[BLACK]);
				break;
			case G_BRICK:
				DrawRectangle(x - 10, y, ycellsize, xcellsize,
						colors[LIGHT_GREEN]);
				break;
			case R_BRICK:
				DrawRectangle(x - 10, y, ycellsize, xcellsize, colors[RED]);
				break;
			}
		}
	}
#endif
	glPopMatrix();
}

void Board::DrawShape() {
	for (int i = 0; i < arrCount; i += 1)
	{
		arr[i]->Draw();
	}
	int x,y;
	GetInitTextPosition(x, y);
	DrawString(x, y, "Score = " + Num2Str(score), colors[WHITE]);
	if (lives >= 3)
	{
		DrawString(700, y, "Remaining Lives = " + Num2Str(lives), colors[GREEN]);
	}
	else if (lives >= 1)
	{
		DrawString(700, y, "Remaining Lives = " + Num2Str(lives), colors[YELLOW]);
	}
	else if (lives == 0)
	{
		DrawString(700, y, "Remaining Lives = " + Num2Str(lives), colors[RED]);
	}
}

void Board::MoveShip() {
	arr[0]->Move();
}

void Board::StopShip() {
	SpaceShip * a = (SpaceShip *)arr[0];
	if (int( a->getAcceleration() ) > 0)
	{
		a->setAcceleration(a->getAcceleration() - 0.23);
		a->Move();
	}
}

void Board::Move() {
	for (int i = 1; i < arrCount; i += 1)
	{
		arr[i]->Move();
	}
}

void Board::RotateShip(int ang) {
	SpaceShip * a = (SpaceShip*)arr[0];
	a->Rotate(ang);
}

void Board::Rotate(int ang) {
	for (int i = 1; i < arrCount; i += 1)
	{
		Asteroid * a = (Asteroid *)arr[i];
		a->Rotate(ang);
	}
}

void Board::ShootShip() {
	SpaceShip * a = (SpaceShip *)arr[0];
	a->Shoot();
}

void Board::KillShip() {
	if (lives > 0)
	{
		float x, y;
		x = arr[0]->getXCor();
		y = arr[0]->getYCor();
		delete arr[0];
		arr[0] = new SpaceShip(x, y);
		lives --;
	}
}

void Board::GameEnd() {
	if (lives == 0)
	{
		for (int i = 0; i < arrCount; i += 1)
		{
			arr[i]->setIsAlive(false);
		}
		DrawString(400, 500, "GAME OVER!", colors[RED]);
		DrawString(400, 450, "Total Score: " + Num2Str(score), colors[GREEN]);
		DrawRectangle(350, 300, 250, 100, colors[BLUE]);
		DrawString(400, 340, "PLAY AGAIN?", colors[WHITE]);
	}
}

void Board::RestartGame() {
}

void Board::CollisionDetection() {
	float curDistance, minDistance;
	float x, y, sides, radius;
	int death;
	bool status;
	for (int i = 1; i < arrCount; i += 1)
	{
		if (arr[i]->getIsAlive() == true)
		{
			minDistance = arr[0]->getRadius() + arr[i]->getRadius();
			curDistance = pow( pow( arr[0]->getXCor()-arr[i]->getXCor(), 2)
						+ pow( arr[0]->getYCor()-arr[i]->getYCor(), 2), 0.5 );
			if (curDistance <= minDistance)
			{
				if (i < 6)
				{
					Asteroid *a = (Asteroid*)arr[i];

					x = a->getXCor();
					y = a->getYCor();
					sides = GetRandInRange(4,7);
					radius = GetRandInRange(15,25);
					death = a->getDeathCount();
					status = a->getIsSimple();
					KillShip();
					if (death == 0)
					{
						delete arr[i];
						status?arrCount++:arrCount+=2;
						arr[i] = new Asteroid(x, y, sides, radius, !status, 1);
						sides = GetRandInRange(4,7);
						radius = GetRandInRange(15,25);
						arr[arrCount -1- (1 * !status)] = new Asteroid(x, y, sides, radius, !status, 1);
						if (!status)
						{
							sides = GetRandInRange(4,7);
							radius = GetRandInRange(15,25);
							arr[arrCount -1] = new Asteroid(x, y, sides, radius, !status, 1);
						}
					}
					else if (death == 1)
					{
						arr[i]->setIsAlive(false);
					}
				}
				else
				{
					KillShip();
					arr[i]->setIsAlive(false);
				}
			}
		}
	}
}

void Board::SaucerShoot() {
	Saucers * a = (Saucers *)arr[6];
	Saucers * b = (Saucers *)arr[7];
	if (Board::bombTimer <= a->getTimer() *10)
	{
		a->Shoot();
	}
	if (Board::bombTimer <= b->getTimer() *10)
	{
		b->Shoot();
	}
}

void Board::GetInitTextPosition(int &x, int &y) {
	x = xcellsize;
	y = (BOARD_Y - 1) * ycellsize + ycellsize / 2;
}
