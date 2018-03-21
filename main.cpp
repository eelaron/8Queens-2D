#include <iostream>
using namespace std;

int main() {
  int b[8][8] = {0};
  int r, c = 0;
  b[r][c] = 1; 
  
  nextCol: 
  c++; 
  if( c == 8 ) goto print;
  else r = -1;
  
  nextRow: 
  r++; 
  if ( r == 8 ) goto backtrack;
  
  for ( int i = 0; i < c; i++ )
    if ( b[r][i] == 1 ) goto nextRow;
  
  for ( int i = 1; (r-i) >= 0 && (c-i) >= 0; i++ )
    if ( b[r-i][c-i] == 1 ) goto nextRow;
  
  for ( int i = 1; (r+i) < 8 && (c-i) >= 0; i++ )
    if ( b[r+i][c-i] == 1 ) goto nextRow;
    
    b[r][c] = 1;
    goto nextCol;
    
  backtrack: 
    c--; 
    if ( c == -1 ) return 0;
    r = 0;
    while( b[r][c] != 1 ) r++;
    b[r][c]=0;
	goto nextRow;

    
  print: 
  static int numSolutions = 0;
      cout << "Solution #" << ++numSolutions << ":\n";
  for(int r = 0; r < 8; r++)
	{
		for( int c = 0; c < 8; c++)
		cout << b[r][c];
		cout << endl;
	}
	cout << endl;
    goto backtrack;

return 0;  
}