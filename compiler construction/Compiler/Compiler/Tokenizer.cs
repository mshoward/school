using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Compiler
{
	public static class Tokenizer
	{
		public static Token PROGRAM = new Token("program");

		public static Token BEGIN = new Token("begin");
		public static Token END = new Token("end.");
		public static Token INTEGER = new Token("integer");
		public static Token ARRAY = new Token("array");
		public static Token OPENPAREN = new Token("(");
		public static Token CLOSEPAREN = new Token(")");
		public static Token WHITESPACE = new Token(" ");
		public static Token COMMA = new Token(",");
		public static Token COMMENT = new Token("/**/");
		public static Token SYMBOL = new Token("id");
		public static Token ID = new Token("id");
		public static Token CONS = new Token("num");
		public static Token DO = new Token("do");
		public static Token ASSIGN = new Token("assign");
		public static Token TO = new Token("to");
		public static Token UNLESS = new Token("unless");
		public static Token WHEN = new Token("when");
		public static Token SEMICOLON = new Token(";");
		public static Token COLON = new Token(":");
		public static Token IN = new Token("in");
		public static Token OUT = new Token("out");
		public static Token ELSE = new Token("else");
		public static Token ADD = new Token("+");
		public static Token SUBTRACT = new Token("-");
		public static Token MULTIPLY = new Token("*");
		public static Token DIVIDE = new Token("/");
		public static Token LESSTHAN = new Token("<");
		public static Token GREATERTHAN = new Token(">");
		public static Token EQUALS = new Token("=");
		public static Token AND = new Token("and");
		public static Token OR = new Token("or");
		public static Token NOT = new Token("not");

		static Tokenizer()
		{
			PROGRAM = new Token("program");
			PROGRAM.tokenType = TokenType.PROGRAM;
			BEGIN = new Token("begin");
			BEGIN.tokenType = TokenType.BEGIN;
			END = new Token("end.");
			END.tokenType = TokenType.END;
			INTEGER = new Token("integer");
			INTEGER.tokenType = TokenType.INTEGER;
			ARRAY = new Token("array");
			ARRAY.tokenType = TokenType.ARRAY;
			OPENPAREN = new Token("(");
			OPENPAREN.tokenType = TokenType.OPENPAREN;
			CLOSEPAREN = new Token(")");
			CLOSEPAREN.tokenType = TokenType.CLOSEPAREN;
			WHITESPACE = new Token(" ");
			WHITESPACE.tokenType = TokenType.WHITESPACE;
			COMMA = new Token(",");
			COMMA.tokenType = TokenType.COMMA;
			COMMENT = new Token("/**/");
			COMMENT.tokenType = TokenType.COMMENT;
			SYMBOL = new Token("id");
			SYMBOL.tokenType = TokenType.SYMBOL;
			ID = new Token("id");
			ID.tokenType = TokenType.ID;
			CONS = new Token("num");
			CONS.tokenType = TokenType.CONS;
			DO = new Token("do");
			DO.tokenType = TokenType.DO;
			ASSIGN = new Token("assign");
			ASSIGN.tokenType = TokenType.ASSIGN;
			TO = new Token("to");
			TO.tokenType = TokenType.TO;
			UNLESS = new Token("unless");
			UNLESS.tokenType = TokenType.UNLESS;
			WHEN = new Token("when");
			WHEN.tokenType = TokenType.WHEN;
			SEMICOLON = new Token(";");
			SEMICOLON.tokenType = TokenType.SEMICOLON;
			COLON = new Token(":");
			COLON.tokenType = TokenType.COLON;
			IN = new Token("in");
			IN.tokenType = TokenType.IN;
			OUT = new Token("out");
			OUT.tokenType = TokenType.OUT;
			ELSE = new Token("else");
			ELSE.tokenType = TokenType.ELSE;
			ADD = new Token("+");
			ADD.tokenType = TokenType.ADD;
			SUBTRACT = new Token("-");
			SUBTRACT.tokenType = TokenType.SUBTRACT;
			MULTIPLY = new Token("*");
			MULTIPLY.tokenType = TokenType.MULTIPLY;
			DIVIDE = new Token("/");
			DIVIDE.tokenType = TokenType.DIVIDE;
			LESSTHAN = new Token("<");
			LESSTHAN.tokenType = TokenType.LESSTHAN;
			GREATERTHAN = new Token(">");
			GREATERTHAN.tokenType = TokenType.GREATERTHAN;
			EQUALS = new Token("=");
			EQUALS.tokenType = TokenType.EQUALS;
			AND = new Token("and");
			AND.tokenType = TokenType.AND;
			OR = new Token("or");
			OR.tokenType = TokenType.OR;
			NOT = new Token("not");
			NOT.tokenType = TokenType.NOT;
		}

		public static void setType(Token A)
		{
			//first, keywords

			if (A.Equals(PROGRAM))
			{
				A.tokenType = TokenType.PROGRAM;
			}
			else if (A.Equals(BEGIN))
			{
				A.tokenType = TokenType.BEGIN;
			}
			else if (A.Equals(END))
			{
				A.tokenType = TokenType.END;
			}
			else if (A.Equals(INTEGER))
			{
				A.tokenType = TokenType.INTEGER;
			}
			else if (A.Equals(ARRAY))
			{
				A.tokenType = TokenType.ARRAY;
			}
			else if (A.Equals(OPENPAREN))
			{
				A.tokenType = TokenType.OPENPAREN;
			}
			else if (A.Equals(CLOSEPAREN))
			{
				A.tokenType = TokenType.CLOSEPAREN;
			}
			else if (A.Equals(COMMA))
			{
				A.tokenType = TokenType.COMMA;
			}
			else if (A.Equals(DO))
			{
				A.tokenType = TokenType.DO;
			}
			else if (A.Equals(ASSIGN))
			{
				A.tokenType = TokenType.ASSIGN;
			}
			else if (A.Equals(TO))
			{
				A.tokenType = TokenType.TO;
			}
			else if (A.Equals(UNLESS))
			{
				A.tokenType = TokenType.UNLESS;
			}
			else if (A.Equals(WHEN))
			{
				A.tokenType = TokenType.WHEN;
			}
			else if (A.Equals(SEMICOLON))
			{
				A.tokenType = TokenType.SEMICOLON;
			}
			else if (A.Equals(COLON))
			{
				A.tokenType = TokenType.COLON;
			}
			else if (A.Equals(IN))
			{
				A.tokenType = TokenType.IN;
			}
			else if (A.Equals(OUT))
			{
				A.tokenType = TokenType.OUT;
			}
			else if (A.Equals(ELSE))
			{
				A.tokenType = TokenType.ELSE;
			}
			else if (A.Equals(ADD))
			{
				A.tokenType = TokenType.ADD;
			}
			else if (A.Equals(SUBTRACT))
			{
				A.tokenType = TokenType.SUBTRACT;
			}
			else if (A.Equals(MULTIPLY))
			{
				A.tokenType = TokenType.MULTIPLY;
			}
			else if (A.Equals(DIVIDE))
			{
				A.tokenType = TokenType.DIVIDE;
			}
			else if (A.Equals(LESSTHAN))
			{
				A.tokenType = TokenType.LESSTHAN;
			}
			else if (A.Equals(GREATERTHAN))
			{
				A.tokenType = TokenType.GREATERTHAN;
			}
			else if (A.Equals(EQUALS))
			{
				A.tokenType = TokenType.EQUALS;
			}
			else if (A.Equals(AND))
			{
				A.tokenType = TokenType.AND;
			}
			else if (A.Equals(OR))
			{
				A.tokenType = TokenType.OR;
			}
			else if (A.Equals(NOT))
			{
				A.tokenType = TokenType.NOT;
			}
			//
			else
			{
				//none of the keywords.  Find out if it's somehow null or whitespace or if it's a comment.
				//if it's not a comment, check if it's a constant
				//if it starts like a constant but isn't, it's not a constant
				//if it doesn't start like a constant, it's probably an id
				//if it doesn't start with a letter and it's none of the others, I don't know what it is
				if (string.IsNullOrWhiteSpace(A.lexeme) ||
					A.lexeme.Length < 1)
					A.tokenType = TokenType.NO_TYPE;
				else if (A.lexeme[0] == '/')
					A.tokenType = TokenType.COMMENT;
				else
				{
					bool IS_CONSTANT = true;

					if (char.IsDigit(A.lexeme[0]))
					{
						for (int i = 0; (i < A.lexeme.Length) && IS_CONSTANT; i++)
						{
							IS_CONSTANT = IS_CONSTANT && char.IsDigit(A.lexeme[i]);
						}
						if (!IS_CONSTANT)
						{
							A.tokenType = TokenType.NO_TYPE;
						}
						else
							A.tokenType = TokenType.CONS;
					}
					else
					{
						bool isAlphaNumeric = char.IsLetter(A.lexeme[0]);
						for (int i = 0; (i < A.lexeme.Length) && isAlphaNumeric; i++)
						{
							isAlphaNumeric = isAlphaNumeric && char.IsLetterOrDigit(A.lexeme[i]);
						}
						if (!isAlphaNumeric)
							A.tokenType = TokenType.NO_TYPE;
						else
							A.tokenType = TokenType.ID;
					}
				}
			}
			

		}
	}
}
