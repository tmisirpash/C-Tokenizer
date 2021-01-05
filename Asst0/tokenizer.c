#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void tokenize(char * inputString);
int word(char * inputString, int i);
int positiveDigits(char * inputString, int i);
int floatFinder(char * inputString, int i);
int floatPrint(char * inputString, int i);
int decimalPrint(char * inputString, int i);
int numPrint(char * inputString, int i);
int hexCheck(char * inputString, int i);
int zeroHandler(char * inputString, int i);
int hexPrint(char * inputString, int i);
int octalCheck(char * inputString, int i);
int octalPrint(char * inputString, int i);
int operator(char * inputString, int i);   
int wordPrint(char * inputString, int i);
int singleLineComment(char * inputString, int i);
int multiLineComment(char * inputString, int i);
int multiLineCommentChecker(char * inputString, int i);
int quoteFinder(char * inputString, int i);
int quotePrint(char * inputString, int i);

//main
int main(int argc, char ** argv)
{
  /*Tokenizer returns 0 if main has an invalid number
   of arguments or if the input string is empty.*/
  if (argc != 2)
    {
      printf("Please enter the correct number of arguments\n");
      return 0;
    }
  if (strcmp(argv[1], "") == 0) return 0;
  
  /*At this point, we have valid input.*/

  tokenize(argv[1]);
  
  //Input strings can also be tested here directly
  //tokenize("INPUT_STRING");
  
  return 0;
}
// Given inputString[i], determines and prints the operator. Prints "unknown operator: <operator>" otherwise. Returns starting index of next token to tokenize.
int operator(char * inputString, int i)
{
  switch (inputString[i])
    {
      //LEFT PARENTHESIS
    case '(':
      printf("left parenthesis: \"(\"");
      break;
      // RIGHT PARENTHESIS
    case ')':
      printf("right parenthesis: \")\"");
      break;
      //LEFT BRACKET
    case '[':
      printf("left bracket: \"[\"");
      break;
      //RIGHT BRACKET
    case ']':
      printf("right bracket: \"]\"");
      break;
      //STRUCTURE MEMBER
    case '.':
      printf("structure member: \".\"");
      break;
      //MINUS/SUBSTRACT OPERATOR, DECREMENT, STRUCTURE POINTER, MINUS EQUALS
    case '-':
      if (i == strlen(inputString)-1)
	{
	  printf("minus/subtract operator: \"-\"");
	}
      else
	{
	  switch(inputString[i+1])
	    {
	    case '-':
	      printf("decrement: \"--\"");
	      i++;
	      break;
	    case '>':
	      printf("structure pointer: \"->\"");
	      i++;
	      break;
	    case '=':
	      printf("minus equals: \"-=\"");
	      i++;
	      break;
	    default:
	      printf("minus/subtract operator: \"-\"");
	      break;
	    }
	}
      break;
      //ADDITION, INCREMENT, PLUS EQUALS
    case '+':
      if (i == strlen(inputString)-1)
	{
	  printf("addition: \"+\"");
	}
      else
	{
	  switch(inputString[i+1])
	    {
	    case '+':
	      printf("increment: \"++\"");
	      i++;
	      break;
	    case '=':
	      printf("plus equals: \"+=\"");
	      i++;
	      break;
	    default:
	      printf("addition: \"+\"");
	      break;
	    }
	}
      break;
      //MULTIPLY/DEREFERENCE OPERATOR, TIMES EQUALS
       case '*':
      if (i == strlen(inputString)-1)
	{
	  printf("multiply/dereference operator: \"*\"");
	}
      else
	{
	  switch(inputString[i+1])
	    {
	    case '=':
	      printf("times equals: \"*=\"");
	      i++;
	      break;
	    default:
	      printf("multiply/dereference operator: \"*\"");
	      break;
	    }
	}
      break;
      //DIVISION, DIVIDE EQUALS
     case '/':
      if (i == strlen(inputString)-1)
	{
	  printf("division: \"/\"");
	}
      else
	{
	  switch(inputString[i+1])
	    {
	    case '=':
	      printf("divide equals: \"/=\"");
	      i++;
	      break;
	    default:
	      printf("division: \"/\"");
	      break;
	    }
	}
      break;
      //MOD, MOD EQUALS
       case '%':
      if (i == strlen(inputString)-1)
	{
	  printf("mod: \"%%\"");
	}
      else
	{
	  switch(inputString[i+1])
	    {
	    case '=':
	      printf("mod equals: \"%%=\"");
	      i++;
	      break;
	    default:
	      printf("mod: \"%%\"");
	      break;
	    }
	}
      break;
      //BITWISE XOR, BITWISE XOR EQUALS
    case '^':
      if (i == strlen(inputString)-1)
	{
	  printf("bitwise XOR: \"^\"");
	}
      else
	{
	  switch(inputString[i+1])
	    {
	    case '=':
	      printf("bitwise XOR equals: \"^=\"");
	      i++;
	      break;
	    default:
	      printf("bitwise XOR: \"^\"");
	      break;
	    }
	}
      break;
      //BITWISE OR, LOGICAL OR, BITWISE OR EQUALS
    case '|':
      if (i == strlen(inputString)-1)
	{
	  printf("bitwise OR: \"|\"");
	}
      else
	{
	  switch(inputString[i+1])
	    {
	    case '|':
	      printf("logical OR: \"||\"");
	      i++;
	      break;
	    case '=':
	      printf("bitwise OR equals: \"|=\"");
	      i++;
	      break;
	    default:
	      printf("bitwise OR: \"|\"");
	      break;
	    }
	}
      break;
      // AND/ADDRESS OPERATOR, LOGICAL AND, BITWISE AND EQUALS
       case '&':
      if (i == strlen(inputString)-1)
	{
	  printf("AND/address operator: \"&\"");
	}
      else
	{
	  switch(inputString[i+1])
	    {
	    case '&':
	      printf("logical AND: \"&&\"");
	      i++;
	      break;
	    case '=':
	      printf("bitwise AND equals: \"&=\"");
	      i++;
	      break;
	    default:
	      printf("AND/address operator: \"&\"");
	      break;
	    }
	}
      break;
      //CONDITIONAL TRUE
    case '?':
      printf("conditional true: \"?\"");
      break;
      //CONDITIONAL FALSE
    case ':':
      printf("conditional false: \":\"");
      break;
      //ASSIGNMENT, EQUALITY TEST
    case '=':
      if (i == strlen(inputString)-1)
	{
	  printf("assignment: \"=\"");
	}
      else
	{
	  switch(inputString[i+1])
	    {
	    case '=':
	      printf("equality test: \"==\"");
	      i++;
	      break;
	    default:
	      printf("assignment: \"=\"");
	      break;
	    }
	}
      break;
      // COMMA  
    case ',':
      printf("comma: \",\"");
      break;
      //INEQUALITY TEST, NEGATE
    case '!':
      if (i != strlen(inputString)-1 && inputString[i+1] == '=')
	{
	  printf("inequality test: \"!=\"");
	  i++;
	}
      else
	{
	  printf("negate: \"!\"");
	}
      break;
      //1S COMPLEMENT
    case '~':
      printf("1s complement: \"~\"");
      break;
      //GREATER THAN TEST, SHIFT RIGHT, GREATER THAN OR EQUAL TEST, SHIFT RIGHT EQUALS
    case '>':
      if (i == strlen(inputString) - 1)
	{
	  printf("greater than test: \">\"");
	}
      else
	{
	  if (i == strlen(inputString) - 2)
	    {
	      switch(inputString[i+1])
		{
		case '>':
		  printf("shift right: \">>\"");
		  i++;
		  break;
		case '=':
		  printf("greater than or equal test: \">=\"");
		  i++;
		  break;
		default:
		  printf("greater than test: \">\"");
		  break;
		}
	    }
	  else
	    {
	      switch(inputString[i+1])
		{
		case '>':
		  if (inputString[i+2] == '=')
		    {
		      printf("shift right equals: \">>=\"");
		      i+=2;
		    }
		  else
		    {
		      printf("shift right: \">>\"");
		      i++;
		    }
		  break;
		case '=':
		  printf("greater than or equal test: \">=\"");
		  i++;
		  break;
		default:
		  printf("greater than test: \">\"");
		  break;
		}
	    }
	}
      break;
      // LESS THAN TEST, SHIFT LEFT, LESS THAN OR EQUAL TEST, SHIFT LEFT EQUALS
     case '<':
      if (i == strlen(inputString) - 1)
	{
	  printf("less than test: \"<\"");
	}
      else
	{
	  if (i == strlen(inputString) - 2)
	    {
	      switch(inputString[i+1])
		{
		case '<':
		  printf("shift left: \"<<\"");
		  i++;
		  break;
		case '=':
		  printf("less than or equal test: \"<=\"");
		  i++;
		  break;
		default:
		  printf("less than test: \"<\"");
		  break;
		}
	    }
	  else
	    {
	      switch(inputString[i+1])
		{
		case '<':
		  if (inputString[i+2] == '=')
		    {
		      printf("shift left equals: \"<<=\"");
		      i+=2;
		    }
		  else
		    {
		      printf("shift left: \"<<\"");
		      i++;
		    }
		  break;
		case '=':
		  printf("less than or equal test: \"<=\"");
		  i++;
		  break;
		default:
		  printf("less than test: \"<\"");
		  break;
		}
	    }
	}
      break;
      //NONE OF THE ABOVE
    default:
      printf("unknown operator: \"%c\"", inputString[i]);
      break;
    }
  printf("\n");
  //An operator is guaranteed to be one character long.
  return i+1;
}
//Loops through the characters of inputString and sends jobs off to more specialized functions. Receives a new index for the beginning of the next token.
void tokenize(char * inputString)
{
  int i = 0;
  while (i < strlen(inputString))
    {
      //Is the current character a whitespace character?
      if (isspace(inputString[i]))
	{
	  //Move on to the next character.
	  i++;
	}
      //Is the current character the beginning of a single-line comment?
      else if (i < strlen(inputString) - 1 && inputString[i] == '/'
	  && inputString[i+1] == '/')
	{
	  i = singleLineComment(inputString, i);
	}
      //Is the current character the beginning of a multi-line comment?
      else if (i < strlen(inputString) - 3 && inputString[i] == '/'
	       && inputString[i+1] == '*' && multiLineCommentChecker(inputString, i+2) == 1)
	{
	  i = multiLineComment(inputString, i);
	}
      //Is the current character a string surrounded by single or double quotes?
      else if ((inputString[i] == '\"' || inputString[i] == '\'') &&
	       quoteFinder(inputString, i) == 1)
	{
	  i = quotePrint(inputString, i);
	}
      
      //Is the current character alphabetical? If so, it must be a word or C keyword.
      else if (isalpha(inputString[i]))
	{
	  i = word(inputString, i);
	}
      //Is the current character a digit?
      else if (isdigit(inputString[i]))
	{
	  //Is the current digit greater than 0?
	  if (inputString[i]-'0' > 0)
	    {
	      i = positiveDigits(inputString, i);
	    }
	  //Is the current digit 0?
	  else
	    {
	      i = zeroHandler(inputString, i);
	    }
	}
      //If the current character is none of the above, it must be an operator that is either known or unknown.
      else
	{
	  i = operator(inputString, i);
	}
    }
  return;
}
//Given that i marks the first / of a single-line comment, ignores characters until end of string is reached or newline characer found. Returns index of the beginning of the next token.
int singleLineComment(char * inputString, int i)
{
  while (i < strlen(inputString) && inputString[i] != '\n')
    {
      i++;
    }
  return i;
}
//Given that i marks the first / of a multi-line comment, ignores characters until */ is reached. Returns the index of the beginning of the next token.
int multiLineComment(char * inputString, int i)
{
  while (i < strlen(inputString) - 1)
    {
      if (inputString[i] == '*' && inputString[i+1] == '/')
	{
	  return i+2;
	}
      i++;
    }
  return i;
}
//Given that an initial /* has been detected at indices i and i+1, returns 1 if a closing */ is found and 0 otherwise.
int multiLineCommentChecker(char * inputString, int i)
{
  while (i < strlen(inputString) - 1)
    {
      if (inputString[i] == '*' && inputString[i+1] == '/')
	{
	  return 1;
	}
      i++;
    }
  return 0;
}
//Given that there is an opening quote at index i, returns 1 if there is a closing quote and 0 otherwise.
int quoteFinder(char * inputString, int i)
{
  char quoteType = inputString[i];
  i++;
  while (i < strlen(inputString))
    {
      if (inputString[i] == quoteType)
	{
	  return 1;
	}
      i++;
    }
  return 0;
}
//Given that i is the first quotation mark of a quote string, prints the quote.
int quotePrint(char * inputString, int i)
{
  char quoteType = inputString[i];
  printf("quote string: %c", quoteType);
  i++;
  while (inputString[i] != quoteType)
    {
      printf("%c", inputString[i]);
      i++;
    }
  printf("%c\n", quoteType);
  return i+1;
}

//Handles numbers that do not begin with zero, given that inputString[i] is a non-zero digit. These numbers can be either floats or decimals. Returns index of next token to tokenize.
int positiveDigits(char * inputString, int i)
{
  if (floatFinder(inputString, i) == 1)
    {
      i = floatPrint(inputString, i);
    }
  else
    {
      i = decimalPrint(inputString, i);
    }
  return i;
}
//Handles numbers that begin with zero, given that inputString[i] is '0'. These numbers can be hex integers, floats, octal integers, or decimals. Returns index of next token to tokenize.
int zeroHandler(char * inputString, int i)
{
  if (hexCheck(inputString, i) == 1)
    {
      i = hexPrint(inputString, i);
    }
  else if (floatFinder(inputString, i) == 1)
    {
      i = floatPrint(inputString, i);
    }
  else if (octalCheck(inputString, i) == 1)
    {
      i = octalPrint(inputString, i);
    }
  else
    {
      i = decimalPrint(inputString, i);
    }
  return i;
}
//Given that inputString[i] is a digit, keeps printing digits until the first non-digit character is ecountered. Returns stopping index.
int numPrint(char * inputString, int i)
{
  while (i < strlen(inputString) && isdigit(inputString[i]))
    {
      printf("%c", inputString[i]);
      i++;
    }
  return i;
}
//Given that inputString[i] = '0' and inputString[i+1] = 'x' OR 'X', keeps printing hexadecimal characters until first non-hexadecimal character is encountered. Returns stopping index.
int hexPrint(char * inputString, int i)
{
  printf("hexadecimal integer: \"%c%c", inputString[i], inputString[i+1]);
  i += 2;
  while (isdigit(inputString[i]) || ('a' <= inputString[i] && inputString[i] <= 'f') || ('A' <= inputString[i] && inputString[i] <= 'F'))
    {
      printf("%c", inputString[i]);
      i++;
    }
  printf("\"\n");
  return i;
  
}
//Given that i marks the beginning of a decimal integer, prints the decimal integer. Returns stopping index.
int decimalPrint(char * inputString, int i)
{
  printf("decimal integer: \"");
  i = numPrint(inputString, i);
  printf("\"\n");
  return i;
}
//Given that i marks the initial '0' of an octal integer, prints the octal integer. Returns stopping index.
int octalPrint(char * inputString, int i)
{
  printf("octal integer: \"");
  while (isdigit(inputString[i]) && inputString[i]-'0' <= 7)
    {
      printf("%c", inputString[i]);
      i++;
    }
  printf("\"\n");
  return i;
}
//Given that i marks the first digit of a float, prints the float. Returns stopping index.
int floatPrint(char * inputString, int i)
{
  printf("floating point: \"");
  i = numPrint(inputString, i) + 1;
  printf(".");
  while (i < strlen(inputString) && isdigit(inputString[i]))
    {
      printf("%c", inputString[i]);
      i++;
    }
  /*Checks if end of string is reached. If so, no exponential notation possible. */
  if (i != strlen(inputString))
    {
      /*Checks for exponential notation*/
      if ((inputString[i] == 'e' || inputString[i] == 'E') && i <= strlen(inputString)-2)
	{
	  if ((inputString[i+1] == '-' || inputString[i+1] == '+') && i+1 != strlen(inputString)-1
	      && isdigit(inputString[i+2]))
	    {
	      printf("%c%c",inputString[i], inputString[i+1]);
	      i+=2;
	      i = numPrint(inputString, i);
	    }
	  else if (isdigit(inputString[i+1]))
	    {
	      printf("%c", inputString[i]);
	      i++;
	      i = numPrint(inputString, i);
	    }
	}
    }
  printf("\"\n");
  return i;
}
//Given that inputString[i] is a digit, returns 1 if i marks the beginning of a float and 0 otherwise.
int floatFinder(char * inputString, int i)
{
  while (i < strlen(inputString) && isdigit(inputString[i]))
    {
      i++;
    }
  /*End of string reached, no decimal point found. */
  if (i == strlen(inputString)) return 0;

  if (inputString[i] == '.')
    {
      /*'.' is the last character of the string. No float possible.*/
      if (i == strlen(inputString)-1) return 0;

      if (isdigit(inputString[i+1]))
	{
	  /*There exists a digit to the right of the point. Float exists.*/
	  return 1;
	}
    }
  return 0;
}
//Given that inputString[i] = '0', returns 1 if i marks the beginning of a hexadecimal integer and 0 otherwise.
int hexCheck(char * inputString, int i)
{
  /*If 0, 0x or 0X are the last characters of the input, we cannot have a hex.*/
  if (i >= strlen(inputString)-2) return 0;

  if (inputString[i+1] == 'x' || inputString[i+1] == 'X')
    {
      if (isdigit(inputString[i+2]) || ('a'<=inputString[i+2] &&
					inputString[i+2] <= 'f') ||
	  ('A' <= inputString[i+2] && inputString[i+2] <= 'F'))
	{
	  return 1;
	}
    }
  return 0;
}
//Given that inputString[i] = '0', returns 1 if i marks the beginning of an octal integer and 0 otherwise.
int octalCheck(char * inputString, int i)
{
  while (i < strlen(inputString) && isdigit(inputString[i]) && inputString[i]-'0' <= 7)
    {
      i++;
    }
  /*We have reached the end of the string and all digits are octal.*/
    if (i == strlen(inputString)) return 1;

    /*We have stopped at a non-octal digit; token must be a decimal.*/
    if (isdigit(inputString[i])) return 0;

    /*At this point, there must be an octal.*/
    return 1;
}
//Given that inputString[i] is alphabetical, keeps printing alphanumeric characters until a non-alphanumeric characters is reached. Returns stopping index.
int wordPrint(char * inputString, int i)
{
  while (i < strlen(inputString) && isalnum(inputString[i]))
    {
      printf("%c", inputString[i]);
      i++;
    }
  return i;
}
//Given that inputString[i] is alphabetical, checks if i marks the beginning of a C keyword. If not, a regular word token is printed. Returns updated index to tokenize.
int word(char * inputString, int i)
{
  int startIndex = i;
  int wordLength = 0;
  while (i < strlen(inputString) && isalnum(inputString[i]))
    {
      wordLength++;
      i++;
    }
  char currWord[wordLength+1];
  for (i = 0; i < wordLength; i++)
    {
      currWord[i] = inputString[startIndex+i];
    }
  currWord[i] = '\0';
  if (strcmp(currWord, "if") == 0 ||
      strcmp(currWord, "do") == 0 ||
      strcmp(currWord, "for") == 0 ||
      strcmp(currWord, "int") == 0 ||
      strcmp(currWord, "auto") == 0 ||
      strcmp(currWord, "case") == 0 ||
      strcmp(currWord, "char") == 0 ||
      strcmp(currWord, "else") == 0 ||
      strcmp(currWord, "enum") == 0 ||
      strcmp(currWord, "goto") == 0 ||
      strcmp(currWord, "long") == 0 ||
      strcmp(currWord, "void") == 0 ||
      strcmp(currWord, "break") == 0 ||
      strcmp(currWord, "const") == 0 ||
      strcmp(currWord, "float") == 0 ||
      strcmp(currWord, "short") == 0 ||
      strcmp(currWord, "union") == 0 ||
      strcmp(currWord, "while") == 0 ||
      strcmp(currWord, "double") == 0 ||
      strcmp(currWord, "extern") == 0 ||
      strcmp(currWord, "return") == 0 ||
      strcmp(currWord, "signed") == 0 ||
      strcmp(currWord, "static") == 0 ||
      strcmp(currWord, "sizeof") == 0 ||
      strcmp(currWord, "struct") == 0 ||
      strcmp(currWord, "switch") == 0 ||
      strcmp(currWord, "default") == 0 ||
      strcmp(currWord, "typedef") == 0 ||
      strcmp(currWord, "continue") == 0 ||
      strcmp(currWord, "register") == 0 ||
      strcmp(currWord, "volatile") == 0 ||
      strcmp(currWord, "unsigned") == 0)
    printf("%s: \"", currWord);
  else
    printf("word: \"");
  i = wordPrint(inputString, startIndex);
  printf("\"\n");
  return i;
}
