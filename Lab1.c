/**
 *  FILE:   Lab1.c
 *  AUTHOR: Madilyn Simons
 */

 #include <stdio.h>
 
 int GetLength( char string[] );
 int IsLowerCase( char c );
 char ToUpperCase( char c);
 void SetStringInput( char string [] );
 void Reverse( char string[], int length );
 int Capitalize( char string[], int length );
 void Print( char string[], int length, int capitalized );

int main()
{
   char input[100];
   int length;
 
   printf("Enter a string: ");
   
   SetStringInput( input );
   length = GetLength( input );
   Reverse(input, length);
   int capitalized = Capitalize(input, length);
   Print(input, length, capitalized);
   
   return 0;
}

/**
 *  returns the length of a given string
 */
int GetLength( char string[] )
{
   int length = 0;
   while(string[length] != '\0')
   {
	   length++;
   }
   return length - 1;
}

/**
 *  returns true (1) if a given char is lowercase
 *  if not, returns false (0)
 */
int IsLowerCase( char c )
{
	return (c > 96) && (c < 123);
}

/**
 *  converts given char to uppercase
 */
char ToUpperCase( char c )
{
	c = c - 32;
	return c;
}

/**
 *  returns input as a char array
 */
void SetStringInput( char string[] )
{
   fgets( string, 100, stdin );
   return;
}

/**
 *  reverses a given string
 */
void Reverse( char string[], int length )
{
	int left = 0;
	int right = length - 1;
	
	while(left < right)
	{
		char temp = string[left];
		string[left] = string[right];
		string[right] = temp;
		left++;
		right--;
	}
	
	return;
}

/**
 *  capitalizes all alpha chars
 *  returns number of chars capitalized
 */
int Capitalize( char string[], int length )
{
	int x;
	int count = 0;
	for(x = 0; x < length; x++)
	{
		if(IsLowerCase(string[x]))
		{
			string[x] = ToUpperCase(string[x]);
			count++;
		}
	}
	return count;
}

/**
 *  prints output
 */
void Print( char string[], int length, int capitalized )
{
	int x;
	for(x = 0; x < length; x++)
	{
		printf("%c\n", string[x]);
	}
	
	printf("The string is %d chars and %d chars were capitalized", length, capitalized);
	return;
}