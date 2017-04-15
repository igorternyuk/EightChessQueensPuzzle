#ifndef _QUEENS_H_
#define _QUEENS_H_

void setQ(int**, const int&, const int&, const int&);
void resetQ(int**, const int& ,const int& ,const int&);
bool tryQ(int**,const int&, const int&);
void drawBoard(int**, const int&);
void writeToFile(int**, const int&);

#endif
